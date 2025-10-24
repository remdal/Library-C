/* necessary for all PostgreSQL client programs, should be first */
#include <libpq-fe.h>
#include <stdio.h>
#include <string.h>

#ifdef TRACE
#define TRACEFILE "trace.out"
#endif

// clang C_API_PostgreSQL.c  -I$(pg_config --includedir) -L$(pg_config --libdir) -lpq
int main(int argc, char *argv[])
{
#ifdef TRACE
    FILE        *trc;
#endif
    PGconn      *conn;
    PGresult    *res;
    int         rowcount, colcount, i, j, firstcol;
    /* parameter type should be guessed by PostgreSQL */
    const Oid paramTypes[1] = { 0 };
    /* parameter value */
    const char * const paramValues[1] = { "pg_database" };
    /*
     * Using an empty connectstring will use default values for everything.
     * If set, the environment variables PGHOST, PGDATABASE, PGPORT and
     * PGUSER will be used.
     */
    conn = PQconnectdb("postgresql://localhost");
    /*
     * This can only happen if there is not enough memory
     * to allocate the PGconn structure.
     */
    if (conn == NULL)
    {
        fprintf(stderr, "Out of memory connecting to PostgreSQL.\n");
        return (1);
    }
    /* check if the connection attempt worked */
    if (PQstatus(conn) != CONNECTION_OK)
    {
        fprintf(stderr, "%s\n", PQerrorMessage(conn));
        /*
         * Even if the connection failed, the PGconn structure has been
         * allocated and must be freed.
         */
        PQfinish(conn);
        return (1);
    }
#ifdef TRACE
    if (NULL == (trc = fopen(TRACEFILE, "w")))
    {
        fprintf(stderr, "Error opening trace file \"%s\"!\n", TRACEFILE);
        PQfinish(conn);
        return (1);
    }
    /* tracing for client-server communication */
    PQtrace(conn, trc);
#endif
    /* this program expects the database to return data in UTF-8 */
    PQsetClientEncoding(conn, "UTF8");
    /* perform a query with parameters */
    res = PQexecParams(conn,
                       "SELECT column_name, data_type "
                       "FROM information_schema.columns "
                       "WHERE table_name = $1",
                       1, /* one parameter */
                       paramTypes,
                       paramValues,
                       NULL,/* parameter lengths are not required for strings */
                       NULL,/* all parameters are in text format */
                       0    /* result shall be in text format */
                       );
    /* out of memory or sever communication broken */
    if (NULL == res)
    {
        fprintf(stderr, "%s\n", PQerrorMessage(conn));
        PQfinish(conn);
#ifdef TRACE
        fclose(trc);
#endif
        return (1);
    }
    /* SQL statement should return results */
    if (PGRES_TUPLES_OK != PQresultStatus(res))
    {
        fprintf(stderr, "%s\n", PQerrorMessage(conn));
        PQfinish(conn);
#ifdef TRACE
        fclose(trc);
#endif
        return (1);
    }
    /* get count of result rows and columns */
    rowcount = PQntuples(res);
    colcount = PQnfields(res);
    /* print column headings */
    firstcol = 1;
    printf("Description of the table \"pg_database\"\n");
    for (j = 0; j < colcount; ++j)
    {
        if (firstcol)
            firstcol = 0;
        else
            printf(": ");
        printf("%s\n", PQfname(res, j));
    }
    printf("\n\n");
    /* loop through rosult rows */
    for (i = 0; i < rowcount; ++i)
    {
        /* print all column data */
        firstcol = 1;
        for (j = 0; j < colcount; ++j)
        {
            if (firstcol)
                firstcol = 0;
            else
                printf(": ");
            printf("%s\n", PQgetvalue(res, i, j));
        }
        printf("\n");
    }
    /* this must be done after every statement to avoid memory leaks */
    PQclear(res);
    /* close the database connection and release memory */
    PQfinish(conn);
#ifdef TRACE
    fclose(trc);
#endif
    return (0);
}


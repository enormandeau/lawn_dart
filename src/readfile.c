
char lines[1000][1000];



char buf[MAXLINELEN];
while (fgets(buf, MAXLINELEN, ifp) != NULL) {
    buf[strcspn(buf, "\n")] = '\0';
    if (buf[0] == '\0')
        continue;
}

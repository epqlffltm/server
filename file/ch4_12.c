/*
2026-02-13
문자열 기반 입출력 함수 사용하기
*/

int main(void)
{
  FILE *rfp = NULL, *wfp = NULL;
  char buf[BUFSIZ];

  if((rfp = fopen("linux.txt", "r")) == NULL)
  {
    perror("fopen: linux.txt error");
    exit(1);
  }

  if(wfp = fopen("linux.out", "w")) == NULL)
  {
    perror("fopen: linux.out error");
    exit(1);
  }

  while(fgets(buf, BUFSIZ, rfp) != NULL)
  {
    fputs(buf, wfp);
  }

  fclose(rfp);
  fclose(wfp);
  
  return 0;
}
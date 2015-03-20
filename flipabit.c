#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv)
{
  if (argc != 4)
  {
    fprintf(stderr, "editbinary file newfile pos\n");
    return 1;
  }

  char * infile = argv[1];
  char * outfile  = argv[2];
  int editpos = atoi(argv[3]);

  fprintf(stderr, "Editing \"%s\" into \"%s\" editing byte %d\n", infile, outfile, editpos);

  FILE * in = fopen(infile, "rb");
  FILE * out = fopen(outfile, "wb");

  if (!in) { fprintf(stderr, "Couldnt open %s for reading\n", infile); return 1; }
  if (!out) { fprintf(stderr, "Couldnt open %s for writing\n", outfile); return 1; }

  int buffersize = 1024;
  char buffer[buffersize];

  int bytes = 0;
  int totalbytes = 0;
  int bitsflipped = 0;

  double errorrate = 0.0001;

  while ((bytes = fread(buffer, 1, 1, in)) != 0)
  {
    // float r = ((float)rand()) / RAND_MAX;
    // if (r < errorrate)
    if (totalbytes == editpos)
    {
      fprintf(stderr, "-- flipping a bit in byte %d\n", totalbytes);
      buffer[0] = buffer[0] ^ 0x01;
      bitsflipped++;
    }

    fwrite(buffer, 1, bytes, out);
    totalbytes += bytes;
  }

  fclose(in);
  fclose(out);

  fprintf(stderr, "copied %d bytes and edited %d bits\n", totalbytes, bitsflipped);
  return 0;
}

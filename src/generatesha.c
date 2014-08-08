#include <openssl/sha.h>
/* #include <openssl/evp.h> */

/*
 * unsigned char gen_sha1(char *saltedpass, unsigned char *md_value) 
 * {
 *  EVP_MD_CTX *mdctx; const EVP_MD *md; 
 *  unsigned int md_len;
 * 
 *  OpenSSL_add_all_digests(); 
 *  md = EVP_get_digestbyname("sha1");
 * 
 *  if(!md)
 *    { 
 *      printf("Unknown message digest\n"); 
 *      exit(EXIT_FAILURE); 
 *    }
 * 
 *  mdctx = EVP_MD_CTX_create(); 
 *  EVP_DigestInit_ex(mdctx, md, NULL);
 *  EVP_DigestUpdate(mdctx, saltedpass, strlen(saltedpass));
 *  EVP_DigestFinal_ex(mdctx, md_value, &md_len); 
 *  EVP_MD_CTX_destroy(mdctx);
 * 
 *  printf("hash is: "); 
 *  for (i = 0; i < md_len; i++) printf("%02x",
 *    md_value[i]); printf("\n"); 
 *  return md_value; 
 * }
 */


/*
 * generate_sha1_hash - will generate sha1 hash using openssl sha1 
 *  functions.
 * @data - input message
 * @md_value - will receive the generated hash  otherwise remain NULL if 
 *  SHA_CTX struct was not initialized.
 */
void
generate_sha1_hash(char *data, unsigned char *md_value)
{
	SHA_CTX		ctx;
  SHA1_Init(&ctx);
  if (ctx != NULL)
    {
      SHA1_Update(&ctx, (const void *)data, strlen(data));
	    SHA1_Final(md_value, &ctx);
    }
}

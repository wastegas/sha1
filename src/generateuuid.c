#include <uuid/uuid.h>
#include "generateuuid.h"

/*
 * generate_uuid - generate unique uuid
 * @out - argument to receive uuid as a string if uuid was generated
 *        in a safe manner otherwise it will remain NULL
 */
void
generate_uuid(char *out)
{
  uuid_t    uuid;
  uuid_generate_random(uuid);
  uuid_unparse(uuid, out);
}

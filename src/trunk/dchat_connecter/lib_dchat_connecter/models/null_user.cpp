#include "null_user.h"
#include <libs/apdos/plugins/uuid/null_object_id.h>

using namespace apdos::plugins::uuid;
using namespace apdos::plugins::dchat_connecter::models;

Null_User::Null_User(): User(Null_Object_Id(), "") {
}

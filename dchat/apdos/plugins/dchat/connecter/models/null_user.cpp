#include "null_user.h"
#include <apdos/plugins/uuid/null_object_id.h>

using namespace apdos::plugins::uuid;
using namespace apdos::plugins::dchat_connecter::models;

Null_User::Null_User(): User(Object_Id_Shared_Ptr(new Null_Object_Id()), "") {
}

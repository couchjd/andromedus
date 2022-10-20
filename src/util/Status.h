#pragma once

typedef int status_type;

const int SUCCESS = 0;

const int FAILURE = -1;

#define STATUS_IS_SUCCESS(_status_) (SUCCESS == (_status_))
#define STATUS_IS_FAILURE(_status_) (SUCCESS > (_status_))

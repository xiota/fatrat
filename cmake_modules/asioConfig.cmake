INCLUDE (CheckIncludeFiles)

FIND_PATH(ASIO_INCLUDE_DIR asio/version.hpp)
MARK_AS_ADVANCED(ASIO_INCLUDE_DIR)

IF(ASIO_INCLUDE_DIR)
  SET(ASIO_FOUND 1)
  SET(ASIO_INCLUDE_DIRS ${ASIO_INCLUDE_DIR})
ELSE(ASIO_INCLUDE_DIR)
  SET(ASIO_FOUND 0)
  SET(ASIO_INCLUDE_DIRS)
ENDIF(ASIO_INCLUDE_DIR)

IF(NOT ASIO_FOUND)
  SET(ASIO_DIR_MESSAGE
      "ASIO was not found. Make sure ASIO_INCLUDE_DIR is set.")
  IF(NOT ASIO_FIND_QUIETLY)
    MESSAGE(STATUS "${ASIO_DIR_MESSAGE}")
  ELSE(NOT ASIO_FIND_QUIETLY)
    IF(ASIO_FIND_REQUIRED)
      MESSAGE(FATAL_ERROR "${ASIO_DIR_MESSAGE}")
    ENDIF(ASIO_FIND_REQUIRED)
  ENDIF(NOT ASIO_FIND_QUIETLY)
ENDIF(NOT ASIO_FOUND)


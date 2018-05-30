
DROP TABLE T_TEST_SESSION_PCF_HASH;
CREATE table T_TEST_SESSION_PCF_HASH
(
  SESSION_ID varchar (16) NOT NULL,
  MSISDN varchar (32),
  IMSI varchar (32),
  SESSION_STATUS varchar (1),
  OPEN_DATE varchar (16),
  OPEN_TIME varchar (16),
  LOCATION_ID varchar (16),
  CCR_TYPE varchar (1),
  CCR_RECORD_NO varchar (4),
  IP_ADDR varchar (64),
  CLIENT_HOST varchar (64),
  CLIENT_REALM varchar (32),
  BEARER_ID varchar (32)
) SHARDING BY HASH ( SESSION_ID )
SHARD COUNT 24 AT CLUSTER WIDE
;


alter table T_TEST_SESSION_PCF_HASH add primary key (SESSION_ID) ;
create index IX_T_TEST_SESSION_PCF_HASH  on T_TEST_SESSION_PCF_HASH ( MSISDN ) ;

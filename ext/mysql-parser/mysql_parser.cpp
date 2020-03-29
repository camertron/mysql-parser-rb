#include "iostream"

#include "antlr4-runtime.h"

#include "MySqlParser.h"
#include "MySqlParserBaseVisitor.h"
#include "MySqlLexer.h"

#include "rice/Array.hpp"
#include "rice/Class.hpp"
#include "rice/Constructor.hpp"
#include "rice/Director.hpp"

using namespace std;
using namespace Rice;
using namespace antlr4;

class ContextProxy {
public:
  ContextProxy(tree::ParseTree* orig) {
    this -> orig = orig;
  }

  tree::ParseTree* getOriginal() {
    return this -> orig;
  }

protected:
  tree::ParseTree* orig;
};

class RootContextProxy : public ContextProxy {
public:
  RootContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object sqlStatements();
};

class SqlStatementsContextProxy : public ContextProxy {
public:
  SqlStatementsContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object sqlStatement();
  Object sqlStatementAt(size_t i);
  Object emptyStatement();
  Object emptyStatementAt(size_t i);
};

class SqlStatementContextProxy : public ContextProxy {
public:
  SqlStatementContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object ddlStatement();
  Object dmlStatement();
  Object transactionStatement();
  Object replicationStatement();
  Object preparedStatement();
  Object administrationStatement();
  Object utilityStatement();
};

class EmptyStatementContextProxy : public ContextProxy {
public:
  EmptyStatementContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class DdlStatementContextProxy : public ContextProxy {
public:
  DdlStatementContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object createDatabase();
  Object createEvent();
  Object createIndex();
  Object createLogfileGroup();
  Object createProcedure();
  Object createFunction();
  Object createServer();
  Object createTable();
  Object createTablespaceInnodb();
  Object createTablespaceNdb();
  Object createTrigger();
  Object createView();
  Object alterDatabase();
  Object alterEvent();
  Object alterFunction();
  Object alterInstance();
  Object alterLogfileGroup();
  Object alterProcedure();
  Object alterServer();
  Object alterTable();
  Object alterTablespace();
  Object alterView();
  Object dropDatabase();
  Object dropEvent();
  Object dropIndex();
  Object dropLogfileGroup();
  Object dropProcedure();
  Object dropFunction();
  Object dropServer();
  Object dropTable();
  Object dropTablespace();
  Object dropTrigger();
  Object dropView();
  Object renameTable();
  Object truncateTable();
};

class DmlStatementContextProxy : public ContextProxy {
public:
  DmlStatementContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object selectStatement();
  Object insertStatement();
  Object updateStatement();
  Object deleteStatement();
  Object replaceStatement();
  Object callStatement();
  Object loadDataStatement();
  Object loadXmlStatement();
  Object doStatement();
  Object handlerStatement();
};

class TransactionStatementContextProxy : public ContextProxy {
public:
  TransactionStatementContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object startTransaction();
  Object beginWork();
  Object commitWork();
  Object rollbackWork();
  Object savepointStatement();
  Object rollbackStatement();
  Object releaseStatement();
  Object lockTables();
  Object unlockTables();
};

class ReplicationStatementContextProxy : public ContextProxy {
public:
  ReplicationStatementContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object changeMaster();
  Object changeReplicationFilter();
  Object purgeBinaryLogs();
  Object resetMaster();
  Object resetSlave();
  Object startSlave();
  Object stopSlave();
  Object startGroupReplication();
  Object stopGroupReplication();
  Object xaStartTransaction();
  Object xaEndTransaction();
  Object xaPrepareStatement();
  Object xaCommitWork();
  Object xaRollbackWork();
  Object xaRecoverWork();
};

class PreparedStatementContextProxy : public ContextProxy {
public:
  PreparedStatementContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object prepareStatement();
  Object executeStatement();
  Object deallocatePrepare();
};

class AdministrationStatementContextProxy : public ContextProxy {
public:
  AdministrationStatementContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object alterUser();
  Object createUser();
  Object dropUser();
  Object grantStatement();
  Object grantProxy();
  Object renameUser();
  Object revokeStatement();
  Object revokeProxy();
  Object analyzeTable();
  Object checkTable();
  Object checksumTable();
  Object optimizeTable();
  Object repairTable();
  Object createUdfunction();
  Object installPlugin();
  Object uninstallPlugin();
  Object setStatement();
  Object showStatement();
  Object binlogStatement();
  Object cacheIndexStatement();
  Object flushStatement();
  Object killStatement();
  Object loadIndexIntoCache();
  Object resetStatement();
  Object shutdownStatement();
};

class UtilityStatementContextProxy : public ContextProxy {
public:
  UtilityStatementContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object simpleDescribeStatement();
  Object fullDescribeStatement();
  Object helpStatement();
  Object useStatement();
  Object signalStatement();
  Object resignalStatement();
  Object diagnosticsStatement();
};

class CreateDatabaseContextProxy : public ContextProxy {
public:
  CreateDatabaseContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uid();
  Object ifNotExists();
  Object createDatabaseOption();
  Object createDatabaseOptionAt(size_t i);
};

class CreateEventContextProxy : public ContextProxy {
public:
  CreateEventContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object fullId();
  Object scheduleExpression();
  Object routineBody();
  Object ownerStatement();
  Object ifNotExists();
  Object enableType();
};

class CreateIndexContextProxy : public ContextProxy {
public:
  CreateIndexContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uid();
  Object tableName();
  Object indexColumnNames();
  Object indexType();
  Object indexOption();
  Object indexOptionAt(size_t i);
};

class CreateLogfileGroupContextProxy : public ContextProxy {
public:
  CreateLogfileGroupContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uid();
  Object uidAt(size_t i);
  Object engineName();
  Object fileSizeLiteral();
  Object fileSizeLiteralAt(size_t i);
};

class CreateProcedureContextProxy : public ContextProxy {
public:
  CreateProcedureContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object fullId();
  Object routineBody();
  Object ownerStatement();
  Object procedureParameter();
  Object procedureParameterAt(size_t i);
  Object routineOption();
  Object routineOptionAt(size_t i);
};

class CreateFunctionContextProxy : public ContextProxy {
public:
  CreateFunctionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object fullId();
  Object dataType();
  Object routineBody();
  Object returnStatement();
  Object ownerStatement();
  Object functionParameter();
  Object functionParameterAt(size_t i);
  Object routineOption();
  Object routineOptionAt(size_t i);
};

class CreateServerContextProxy : public ContextProxy {
public:
  CreateServerContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uid();
  Object serverOption();
  Object serverOptionAt(size_t i);
};

class CreateTableContextProxy : public ContextProxy {
public:
  CreateTableContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class CreateTablespaceInnodbContextProxy : public ContextProxy {
public:
  CreateTablespaceInnodbContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uid();
  Object engineName();
  Object fileSizeLiteral();
};

class CreateTablespaceNdbContextProxy : public ContextProxy {
public:
  CreateTablespaceNdbContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uid();
  Object uidAt(size_t i);
  Object engineName();
  Object fileSizeLiteral();
  Object fileSizeLiteralAt(size_t i);
};

class CreateTriggerContextProxy : public ContextProxy {
public:
  CreateTriggerContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object tableName();
  Object routineBody();
  Object fullId();
  Object fullIdAt(size_t i);
  Object ownerStatement();
};

class CreateViewContextProxy : public ContextProxy {
public:
  CreateViewContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object fullId();
  Object selectStatement();
  Object ownerStatement();
  Object uidList();
};

class AlterDatabaseContextProxy : public ContextProxy {
public:
  AlterDatabaseContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class AlterEventContextProxy : public ContextProxy {
public:
  AlterEventContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object fullId();
  Object fullIdAt(size_t i);
  Object ownerStatement();
  Object scheduleExpression();
  Object enableType();
  Object routineBody();
};

class AlterFunctionContextProxy : public ContextProxy {
public:
  AlterFunctionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object fullId();
  Object routineOption();
  Object routineOptionAt(size_t i);
};

class AlterInstanceContextProxy : public ContextProxy {
public:
  AlterInstanceContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class AlterLogfileGroupContextProxy : public ContextProxy {
public:
  AlterLogfileGroupContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uid();
  Object engineName();
  Object fileSizeLiteral();
};

class AlterProcedureContextProxy : public ContextProxy {
public:
  AlterProcedureContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object fullId();
  Object routineOption();
  Object routineOptionAt(size_t i);
};

class AlterServerContextProxy : public ContextProxy {
public:
  AlterServerContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uid();
  Object serverOption();
  Object serverOptionAt(size_t i);
};

class AlterTableContextProxy : public ContextProxy {
public:
  AlterTableContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object tableName();
  Object alterSpecification();
  Object alterSpecificationAt(size_t i);
  Object partitionDefinitions();
};

class AlterTablespaceContextProxy : public ContextProxy {
public:
  AlterTablespaceContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uid();
  Object engineName();
  Object fileSizeLiteral();
};

class AlterViewContextProxy : public ContextProxy {
public:
  AlterViewContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object fullId();
  Object selectStatement();
  Object ownerStatement();
  Object uidList();
};

class DropDatabaseContextProxy : public ContextProxy {
public:
  DropDatabaseContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uid();
  Object ifExists();
};

class DropEventContextProxy : public ContextProxy {
public:
  DropEventContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object fullId();
  Object ifExists();
};

class DropIndexContextProxy : public ContextProxy {
public:
  DropIndexContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uid();
  Object tableName();
};

class DropLogfileGroupContextProxy : public ContextProxy {
public:
  DropLogfileGroupContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uid();
  Object engineName();
};

class DropProcedureContextProxy : public ContextProxy {
public:
  DropProcedureContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object fullId();
  Object ifExists();
};

class DropFunctionContextProxy : public ContextProxy {
public:
  DropFunctionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object fullId();
  Object ifExists();
};

class DropServerContextProxy : public ContextProxy {
public:
  DropServerContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uid();
  Object ifExists();
};

class DropTableContextProxy : public ContextProxy {
public:
  DropTableContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object tables();
  Object ifExists();
};

class DropTablespaceContextProxy : public ContextProxy {
public:
  DropTablespaceContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uid();
  Object engineName();
};

class DropTriggerContextProxy : public ContextProxy {
public:
  DropTriggerContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object fullId();
  Object ifExists();
};

class DropViewContextProxy : public ContextProxy {
public:
  DropViewContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object fullId();
  Object fullIdAt(size_t i);
  Object ifExists();
};

class RenameTableContextProxy : public ContextProxy {
public:
  RenameTableContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object renameTableClause();
  Object renameTableClauseAt(size_t i);
};

class TruncateTableContextProxy : public ContextProxy {
public:
  TruncateTableContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object tableName();
};

class SelectStatementContextProxy : public ContextProxy {
public:
  SelectStatementContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class InsertStatementContextProxy : public ContextProxy {
public:
  InsertStatementContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object tableName();
  Object insertStatementValue();
  Object updatedElement();
  Object updatedElementAt(size_t i);
  Object uidList();
  Object uidListAt(size_t i);
};

class UpdateStatementContextProxy : public ContextProxy {
public:
  UpdateStatementContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object singleUpdateStatement();
  Object multipleUpdateStatement();
};

class DeleteStatementContextProxy : public ContextProxy {
public:
  DeleteStatementContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object singleDeleteStatement();
  Object multipleDeleteStatement();
};

class ReplaceStatementContextProxy : public ContextProxy {
public:
  ReplaceStatementContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object tableName();
  Object insertStatementValue();
  Object updatedElement();
  Object updatedElementAt(size_t i);
  Object uidList();
  Object uidListAt(size_t i);
};

class CallStatementContextProxy : public ContextProxy {
public:
  CallStatementContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object fullId();
  Object constants();
  Object expressions();
};

class LoadDataStatementContextProxy : public ContextProxy {
public:
  LoadDataStatementContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object tableName();
  Object uidList();
  Object decimalLiteral();
  Object assignmentField();
  Object assignmentFieldAt(size_t i);
  Object updatedElement();
  Object updatedElementAt(size_t i);
  Object charsetName();
  Object selectFieldsInto();
  Object selectFieldsIntoAt(size_t i);
  Object selectLinesInto();
  Object selectLinesIntoAt(size_t i);
};

class LoadXmlStatementContextProxy : public ContextProxy {
public:
  LoadXmlStatementContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object tableName();
  Object decimalLiteral();
  Object assignmentField();
  Object assignmentFieldAt(size_t i);
  Object updatedElement();
  Object updatedElementAt(size_t i);
  Object charsetName();
};

class DoStatementContextProxy : public ContextProxy {
public:
  DoStatementContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object expressions();
};

class HandlerStatementContextProxy : public ContextProxy {
public:
  HandlerStatementContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object handlerOpenStatement();
  Object handlerReadIndexStatement();
  Object handlerReadStatement();
  Object handlerCloseStatement();
};

class StartTransactionContextProxy : public ContextProxy {
public:
  StartTransactionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object transactionMode();
  Object transactionModeAt(size_t i);
};

class BeginWorkContextProxy : public ContextProxy {
public:
  BeginWorkContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class CommitWorkContextProxy : public ContextProxy {
public:
  CommitWorkContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class RollbackWorkContextProxy : public ContextProxy {
public:
  RollbackWorkContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class SavepointStatementContextProxy : public ContextProxy {
public:
  SavepointStatementContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uid();
};

class RollbackStatementContextProxy : public ContextProxy {
public:
  RollbackStatementContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uid();
};

class ReleaseStatementContextProxy : public ContextProxy {
public:
  ReleaseStatementContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uid();
};

class LockTablesContextProxy : public ContextProxy {
public:
  LockTablesContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object lockTableElement();
  Object lockTableElementAt(size_t i);
};

class UnlockTablesContextProxy : public ContextProxy {
public:
  UnlockTablesContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class ChangeMasterContextProxy : public ContextProxy {
public:
  ChangeMasterContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object masterOption();
  Object masterOptionAt(size_t i);
  Object channelOption();
};

class ChangeReplicationFilterContextProxy : public ContextProxy {
public:
  ChangeReplicationFilterContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object replicationFilter();
  Object replicationFilterAt(size_t i);
};

class PurgeBinaryLogsContextProxy : public ContextProxy {
public:
  PurgeBinaryLogsContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class ResetMasterContextProxy : public ContextProxy {
public:
  ResetMasterContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class ResetSlaveContextProxy : public ContextProxy {
public:
  ResetSlaveContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object channelOption();
};

class StartSlaveContextProxy : public ContextProxy {
public:
  StartSlaveContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object threadType();
  Object threadTypeAt(size_t i);
  Object untilOption();
  Object connectionOption();
  Object connectionOptionAt(size_t i);
  Object channelOption();
};

class StopSlaveContextProxy : public ContextProxy {
public:
  StopSlaveContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object threadType();
  Object threadTypeAt(size_t i);
};

class StartGroupReplicationContextProxy : public ContextProxy {
public:
  StartGroupReplicationContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class StopGroupReplicationContextProxy : public ContextProxy {
public:
  StopGroupReplicationContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class XaStartTransactionContextProxy : public ContextProxy {
public:
  XaStartTransactionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object xid();
};

class XaEndTransactionContextProxy : public ContextProxy {
public:
  XaEndTransactionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object xid();
};

class XaPrepareStatementContextProxy : public ContextProxy {
public:
  XaPrepareStatementContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object xid();
};

class XaCommitWorkContextProxy : public ContextProxy {
public:
  XaCommitWorkContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object xid();
};

class XaRollbackWorkContextProxy : public ContextProxy {
public:
  XaRollbackWorkContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object xid();
};

class XaRecoverWorkContextProxy : public ContextProxy {
public:
  XaRecoverWorkContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object xid();
};

class PrepareStatementContextProxy : public ContextProxy {
public:
  PrepareStatementContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uid();
};

class ExecuteStatementContextProxy : public ContextProxy {
public:
  ExecuteStatementContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uid();
  Object userVariables();
};

class DeallocatePrepareContextProxy : public ContextProxy {
public:
  DeallocatePrepareContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uid();
};

class CompoundStatementContextProxy : public ContextProxy {
public:
  CompoundStatementContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object blockStatement();
  Object caseStatement();
  Object ifStatement();
  Object leaveStatement();
  Object loopStatement();
  Object repeatStatement();
  Object whileStatement();
  Object iterateStatement();
  Object returnStatement();
  Object cursorStatement();
};

class BlockStatementContextProxy : public ContextProxy {
public:
  BlockStatementContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uid();
  Object uidAt(size_t i);
  Object declareVariable();
  Object declareVariableAt(size_t i);
  Object declareCondition();
  Object declareConditionAt(size_t i);
  Object declareCursor();
  Object declareCursorAt(size_t i);
  Object declareHandler();
  Object declareHandlerAt(size_t i);
  Object procedureSqlStatement();
  Object procedureSqlStatementAt(size_t i);
};

class CaseStatementContextProxy : public ContextProxy {
public:
  CaseStatementContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uid();
  Object expression();
  Object caseAlternative();
  Object caseAlternativeAt(size_t i);
  Object procedureSqlStatement();
  Object procedureSqlStatementAt(size_t i);
};

class IfStatementContextProxy : public ContextProxy {
public:
  IfStatementContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object expression();
  Object elifAlternative();
  Object elifAlternativeAt(size_t i);
  Object procedureSqlStatement();
  Object procedureSqlStatementAt(size_t i);
};

class LeaveStatementContextProxy : public ContextProxy {
public:
  LeaveStatementContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uid();
};

class LoopStatementContextProxy : public ContextProxy {
public:
  LoopStatementContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uid();
  Object uidAt(size_t i);
  Object procedureSqlStatement();
  Object procedureSqlStatementAt(size_t i);
};

class RepeatStatementContextProxy : public ContextProxy {
public:
  RepeatStatementContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object expression();
  Object uid();
  Object uidAt(size_t i);
  Object procedureSqlStatement();
  Object procedureSqlStatementAt(size_t i);
};

class WhileStatementContextProxy : public ContextProxy {
public:
  WhileStatementContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object expression();
  Object uid();
  Object uidAt(size_t i);
  Object procedureSqlStatement();
  Object procedureSqlStatementAt(size_t i);
};

class IterateStatementContextProxy : public ContextProxy {
public:
  IterateStatementContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uid();
};

class ReturnStatementContextProxy : public ContextProxy {
public:
  ReturnStatementContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object expression();
};

class CursorStatementContextProxy : public ContextProxy {
public:
  CursorStatementContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class AlterUserContextProxy : public ContextProxy {
public:
  AlterUserContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class CreateUserContextProxy : public ContextProxy {
public:
  CreateUserContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class DropUserContextProxy : public ContextProxy {
public:
  DropUserContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object userName();
  Object userNameAt(size_t i);
  Object ifExists();
};

class GrantStatementContextProxy : public ContextProxy {
public:
  GrantStatementContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object privelegeClause();
  Object privelegeClauseAt(size_t i);
  Object privilegeLevel();
  Object userAuthOption();
  Object userAuthOptionAt(size_t i);
  Object tlsOption();
  Object tlsOptionAt(size_t i);
  Object userResourceOption();
  Object userResourceOptionAt(size_t i);
};

class GrantProxyContextProxy : public ContextProxy {
public:
  GrantProxyContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object userName();
  Object userNameAt(size_t i);
};

class RenameUserContextProxy : public ContextProxy {
public:
  RenameUserContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object renameUserClause();
  Object renameUserClauseAt(size_t i);
};

class RevokeStatementContextProxy : public ContextProxy {
public:
  RevokeStatementContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class RevokeProxyContextProxy : public ContextProxy {
public:
  RevokeProxyContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object userName();
  Object userNameAt(size_t i);
};

class AnalyzeTableContextProxy : public ContextProxy {
public:
  AnalyzeTableContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object tables();
};

class CheckTableContextProxy : public ContextProxy {
public:
  CheckTableContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object tables();
  Object checkTableOption();
  Object checkTableOptionAt(size_t i);
};

class ChecksumTableContextProxy : public ContextProxy {
public:
  ChecksumTableContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object tables();
};

class OptimizeTableContextProxy : public ContextProxy {
public:
  OptimizeTableContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object tables();
};

class RepairTableContextProxy : public ContextProxy {
public:
  RepairTableContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object tables();
};

class CreateUdfunctionContextProxy : public ContextProxy {
public:
  CreateUdfunctionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uid();
};

class InstallPluginContextProxy : public ContextProxy {
public:
  InstallPluginContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uid();
};

class UninstallPluginContextProxy : public ContextProxy {
public:
  UninstallPluginContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uid();
};

class SetStatementContextProxy : public ContextProxy {
public:
  SetStatementContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class ShowStatementContextProxy : public ContextProxy {
public:
  ShowStatementContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class BinlogStatementContextProxy : public ContextProxy {
public:
  BinlogStatementContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class CacheIndexStatementContextProxy : public ContextProxy {
public:
  CacheIndexStatementContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object tableIndexes();
  Object tableIndexesAt(size_t i);
  Object uid();
  Object uidList();
};

class FlushStatementContextProxy : public ContextProxy {
public:
  FlushStatementContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object flushOption();
  Object flushOptionAt(size_t i);
};

class KillStatementContextProxy : public ContextProxy {
public:
  KillStatementContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object decimalLiteral();
  Object decimalLiteralAt(size_t i);
};

class LoadIndexIntoCacheContextProxy : public ContextProxy {
public:
  LoadIndexIntoCacheContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object loadedTableIndexes();
  Object loadedTableIndexesAt(size_t i);
};

class ResetStatementContextProxy : public ContextProxy {
public:
  ResetStatementContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class ShutdownStatementContextProxy : public ContextProxy {
public:
  ShutdownStatementContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class SimpleDescribeStatementContextProxy : public ContextProxy {
public:
  SimpleDescribeStatementContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object tableName();
  Object uid();
};

class FullDescribeStatementContextProxy : public ContextProxy {
public:
  FullDescribeStatementContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object describeObjectClause();
};

class HelpStatementContextProxy : public ContextProxy {
public:
  HelpStatementContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class UseStatementContextProxy : public ContextProxy {
public:
  UseStatementContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uid();
};

class SignalStatementContextProxy : public ContextProxy {
public:
  SignalStatementContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object signalConditionInformation();
  Object signalConditionInformationAt(size_t i);
  Object stringLiteral();
};

class ResignalStatementContextProxy : public ContextProxy {
public:
  ResignalStatementContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object signalConditionInformation();
  Object signalConditionInformationAt(size_t i);
  Object stringLiteral();
};

class DiagnosticsStatementContextProxy : public ContextProxy {
public:
  DiagnosticsStatementContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object variableClause();
  Object variableClauseAt(size_t i);
  Object diagnosticsConditionInformationName();
  Object diagnosticsConditionInformationNameAt(size_t i);
  Object decimalLiteral();
};

class UidContextProxy : public ContextProxy {
public:
  UidContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object simpleId();
};

class IfNotExistsContextProxy : public ContextProxy {
public:
  IfNotExistsContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class CreateDatabaseOptionContextProxy : public ContextProxy {
public:
  CreateDatabaseOptionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object charsetName();
  Object collationName();
};

class FullIdContextProxy : public ContextProxy {
public:
  FullIdContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uid();
  Object uidAt(size_t i);
};

class ScheduleExpressionContextProxy : public ContextProxy {
public:
  ScheduleExpressionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class RoutineBodyContextProxy : public ContextProxy {
public:
  RoutineBodyContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object blockStatement();
  Object sqlStatement();
};

class OwnerStatementContextProxy : public ContextProxy {
public:
  OwnerStatementContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object userName();
};

class EnableTypeContextProxy : public ContextProxy {
public:
  EnableTypeContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class TableNameContextProxy : public ContextProxy {
public:
  TableNameContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object fullId();
};

class IndexColumnNamesContextProxy : public ContextProxy {
public:
  IndexColumnNamesContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object indexColumnName();
  Object indexColumnNameAt(size_t i);
};

class IndexTypeContextProxy : public ContextProxy {
public:
  IndexTypeContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class IndexOptionContextProxy : public ContextProxy {
public:
  IndexOptionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object fileSizeLiteral();
  Object indexType();
  Object uid();
};

class EngineNameContextProxy : public ContextProxy {
public:
  EngineNameContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class FileSizeLiteralContextProxy : public ContextProxy {
public:
  FileSizeLiteralContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object decimalLiteral();
};

class ProcedureParameterContextProxy : public ContextProxy {
public:
  ProcedureParameterContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uid();
  Object dataType();
};

class RoutineOptionContextProxy : public ContextProxy {
public:
  RoutineOptionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class DataTypeContextProxy : public ContextProxy {
public:
  DataTypeContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class FunctionParameterContextProxy : public ContextProxy {
public:
  FunctionParameterContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uid();
  Object dataType();
};

class ServerOptionContextProxy : public ContextProxy {
public:
  ServerOptionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object decimalLiteral();
};

class CopyCreateTableContextProxy : public ContextProxy {
public:
  CopyCreateTableContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object tableName();
  Object tableNameAt(size_t i);
  Object ifNotExists();
};

class ColumnCreateTableContextProxy : public ContextProxy {
public:
  ColumnCreateTableContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object tableName();
  Object createDefinitions();
  Object ifNotExists();
  Object tableOption();
  Object tableOptionAt(size_t i);
  Object partitionDefinitions();
};

class CreateDefinitionsContextProxy : public ContextProxy {
public:
  CreateDefinitionsContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object createDefinition();
  Object createDefinitionAt(size_t i);
};

class TableOptionContextProxy : public ContextProxy {
public:
  TableOptionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class PartitionDefinitionsContextProxy : public ContextProxy {
public:
  PartitionDefinitionsContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object partitionFunctionDefinition();
  Object subpartitionFunctionDefinition();
  Object partitionDefinition();
  Object partitionDefinitionAt(size_t i);
  Object decimalLiteral();
  Object decimalLiteralAt(size_t i);
};

class QueryCreateTableContextProxy : public ContextProxy {
public:
  QueryCreateTableContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object tableName();
  Object selectStatement();
  Object ifNotExists();
  Object createDefinitions();
  Object tableOption();
  Object tableOptionAt(size_t i);
  Object partitionDefinitions();
};

class UidListContextProxy : public ContextProxy {
public:
  UidListContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uid();
  Object uidAt(size_t i);
};

class CharsetNameContextProxy : public ContextProxy {
public:
  CharsetNameContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object charsetNameBase();
};

class CollationNameContextProxy : public ContextProxy {
public:
  CollationNameContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uid();
};

class UserNameContextProxy : public ContextProxy {
public:
  UserNameContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class PreciseScheduleContextProxy : public ContextProxy {
public:
  PreciseScheduleContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object timestampValue();
  Object intervalExpr();
  Object intervalExprAt(size_t i);
};

class TimestampValueContextProxy : public ContextProxy {
public:
  TimestampValueContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object stringLiteral();
  Object decimalLiteral();
  Object expression();
};

class IntervalExprContextProxy : public ContextProxy {
public:
  IntervalExprContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object intervalType();
  Object decimalLiteral();
  Object expression();
};

class IntervalScheduleContextProxy : public ContextProxy {
public:
  IntervalScheduleContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object intervalType();
  Object decimalLiteral();
  Object expression();
  Object timestampValue();
  Object timestampValueAt(size_t i);
  Object intervalExpr();
  Object intervalExprAt(size_t i);
};

class IntervalTypeContextProxy : public ContextProxy {
public:
  IntervalTypeContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object intervalTypeBase();
};

class DecimalLiteralContextProxy : public ContextProxy {
public:
  DecimalLiteralContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class ExpressionContextProxy : public ContextProxy {
public:
  ExpressionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class StringLiteralContextProxy : public ContextProxy {
public:
  StringLiteralContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object collationName();
};

class IntervalTypeBaseContextProxy : public ContextProxy {
public:
  IntervalTypeBaseContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class RoutineBehaviorContextProxy : public ContextProxy {
public:
  RoutineBehaviorContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class RoutineLanguageContextProxy : public ContextProxy {
public:
  RoutineLanguageContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class RoutineCommentContextProxy : public ContextProxy {
public:
  RoutineCommentContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class RoutineSecurityContextProxy : public ContextProxy {
public:
  RoutineSecurityContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class RoutineDataContextProxy : public ContextProxy {
public:
  RoutineDataContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class CreateDefinitionContextProxy : public ContextProxy {
public:
  CreateDefinitionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class ColumnDeclarationContextProxy : public ContextProxy {
public:
  ColumnDeclarationContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uid();
  Object columnDefinition();
};

class ColumnDefinitionContextProxy : public ContextProxy {
public:
  ColumnDefinitionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object dataType();
  Object columnConstraint();
  Object columnConstraintAt(size_t i);
};

class TableConstraintContextProxy : public ContextProxy {
public:
  TableConstraintContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class ConstraintDeclarationContextProxy : public ContextProxy {
public:
  ConstraintDeclarationContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object tableConstraint();
};

class IndexColumnDefinitionContextProxy : public ContextProxy {
public:
  IndexColumnDefinitionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class IndexDeclarationContextProxy : public ContextProxy {
public:
  IndexDeclarationContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object indexColumnDefinition();
};

class ColumnConstraintContextProxy : public ContextProxy {
public:
  ColumnConstraintContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class StorageColumnConstraintContextProxy : public ContextProxy {
public:
  StorageColumnConstraintContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class FormatColumnConstraintContextProxy : public ContextProxy {
public:
  FormatColumnConstraintContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class CollateColumnConstraintContextProxy : public ContextProxy {
public:
  CollateColumnConstraintContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object collationName();
};

class AutoIncrementColumnConstraintContextProxy : public ContextProxy {
public:
  AutoIncrementColumnConstraintContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object currentTimestamp();
};

class CurrentTimestampContextProxy : public ContextProxy {
public:
  CurrentTimestampContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object decimalLiteral();
};

class CommentColumnConstraintContextProxy : public ContextProxy {
public:
  CommentColumnConstraintContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class PrimaryKeyColumnConstraintContextProxy : public ContextProxy {
public:
  PrimaryKeyColumnConstraintContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class UniqueKeyColumnConstraintContextProxy : public ContextProxy {
public:
  UniqueKeyColumnConstraintContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class SerialDefaultColumnConstraintContextProxy : public ContextProxy {
public:
  SerialDefaultColumnConstraintContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class NullNotnullContextProxy : public ContextProxy {
public:
  NullNotnullContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class NullColumnConstraintContextProxy : public ContextProxy {
public:
  NullColumnConstraintContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object nullNotnull();
};

class DefaultColumnConstraintContextProxy : public ContextProxy {
public:
  DefaultColumnConstraintContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object defaultValue();
};

class DefaultValueContextProxy : public ContextProxy {
public:
  DefaultValueContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object constant();
  Object unaryOperator();
  Object currentTimestamp();
  Object currentTimestampAt(size_t i);
};

class ReferenceDefinitionContextProxy : public ContextProxy {
public:
  ReferenceDefinitionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object tableName();
  Object indexColumnNames();
  Object referenceAction();
};

class ReferenceColumnConstraintContextProxy : public ContextProxy {
public:
  ReferenceColumnConstraintContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object referenceDefinition();
};

class GeneratedColumnConstraintContextProxy : public ContextProxy {
public:
  GeneratedColumnConstraintContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object expression();
};

class UniqueKeyTableConstraintContextProxy : public ContextProxy {
public:
  UniqueKeyTableConstraintContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object indexColumnNames();
  Object indexType();
  Object indexOption();
  Object indexOptionAt(size_t i);
  Object uid();
  Object uidAt(size_t i);
};

class CheckTableConstraintContextProxy : public ContextProxy {
public:
  CheckTableConstraintContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object expression();
  Object uid();
};

class PrimaryKeyTableConstraintContextProxy : public ContextProxy {
public:
  PrimaryKeyTableConstraintContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object indexColumnNames();
  Object indexType();
  Object indexOption();
  Object indexOptionAt(size_t i);
  Object uid();
  Object uidAt(size_t i);
};

class ForeignKeyTableConstraintContextProxy : public ContextProxy {
public:
  ForeignKeyTableConstraintContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object indexColumnNames();
  Object referenceDefinition();
  Object uid();
  Object uidAt(size_t i);
};

class ReferenceActionContextProxy : public ContextProxy {
public:
  ReferenceActionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object referenceControlType();
  Object referenceControlTypeAt(size_t i);
};

class ReferenceControlTypeContextProxy : public ContextProxy {
public:
  ReferenceControlTypeContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class SpecialIndexDeclarationContextProxy : public ContextProxy {
public:
  SpecialIndexDeclarationContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object indexColumnNames();
  Object uid();
  Object indexOption();
  Object indexOptionAt(size_t i);
};

class SimpleIndexDeclarationContextProxy : public ContextProxy {
public:
  SimpleIndexDeclarationContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object indexColumnNames();
  Object uid();
  Object indexType();
  Object indexOption();
  Object indexOptionAt(size_t i);
};

class TableOptionEngineContextProxy : public ContextProxy {
public:
  TableOptionEngineContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object engineName();
};

class TableOptionMaxRowsContextProxy : public ContextProxy {
public:
  TableOptionMaxRowsContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object decimalLiteral();
};

class TableOptionCollateContextProxy : public ContextProxy {
public:
  TableOptionCollateContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object collationName();
};

class TableOptionPersistentContextProxy : public ContextProxy {
public:
  TableOptionPersistentContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class TableOptionTablespaceContextProxy : public ContextProxy {
public:
  TableOptionTablespaceContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uid();
  Object tablespaceStorage();
};

class TablespaceStorageContextProxy : public ContextProxy {
public:
  TablespaceStorageContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class TableOptionPackKeysContextProxy : public ContextProxy {
public:
  TableOptionPackKeysContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class TableOptionPasswordContextProxy : public ContextProxy {
public:
  TableOptionPasswordContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class TableOptionUnionContextProxy : public ContextProxy {
public:
  TableOptionUnionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object tables();
};

class TablesContextProxy : public ContextProxy {
public:
  TablesContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object tableName();
  Object tableNameAt(size_t i);
};

class TableOptionSamplePageContextProxy : public ContextProxy {
public:
  TableOptionSamplePageContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object decimalLiteral();
};

class TableOptionCharsetContextProxy : public ContextProxy {
public:
  TableOptionCharsetContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object charsetName();
};

class TableOptionIndexDirectoryContextProxy : public ContextProxy {
public:
  TableOptionIndexDirectoryContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class TableOptionKeyBlockSizeContextProxy : public ContextProxy {
public:
  TableOptionKeyBlockSizeContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object fileSizeLiteral();
};

class TableOptionEncryptionContextProxy : public ContextProxy {
public:
  TableOptionEncryptionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class TableOptionDataDirectoryContextProxy : public ContextProxy {
public:
  TableOptionDataDirectoryContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class TableOptionRecalculationContextProxy : public ContextProxy {
public:
  TableOptionRecalculationContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class TableOptionAutoIncrementContextProxy : public ContextProxy {
public:
  TableOptionAutoIncrementContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object decimalLiteral();
};

class TableOptionChecksumContextProxy : public ContextProxy {
public:
  TableOptionChecksumContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class TableOptionDelayContextProxy : public ContextProxy {
public:
  TableOptionDelayContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class TableOptionConnectionContextProxy : public ContextProxy {
public:
  TableOptionConnectionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class TableOptionCommentContextProxy : public ContextProxy {
public:
  TableOptionCommentContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class TableOptionAverageContextProxy : public ContextProxy {
public:
  TableOptionAverageContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object decimalLiteral();
};

class TableOptionRowFormatContextProxy : public ContextProxy {
public:
  TableOptionRowFormatContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class TableOptionCompressionContextProxy : public ContextProxy {
public:
  TableOptionCompressionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class TableOptionInsertMethodContextProxy : public ContextProxy {
public:
  TableOptionInsertMethodContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class TableOptionMinRowsContextProxy : public ContextProxy {
public:
  TableOptionMinRowsContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object decimalLiteral();
};

class PartitionFunctionDefinitionContextProxy : public ContextProxy {
public:
  PartitionFunctionDefinitionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class SubpartitionFunctionDefinitionContextProxy : public ContextProxy {
public:
  SubpartitionFunctionDefinitionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class PartitionDefinitionContextProxy : public ContextProxy {
public:
  PartitionDefinitionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class PartitionFunctionKeyContextProxy : public ContextProxy {
public:
  PartitionFunctionKeyContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uidList();
};

class PartitionFunctionHashContextProxy : public ContextProxy {
public:
  PartitionFunctionHashContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object expression();
};

class PartitionFunctionListContextProxy : public ContextProxy {
public:
  PartitionFunctionListContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object expression();
  Object uidList();
};

class PartitionFunctionRangeContextProxy : public ContextProxy {
public:
  PartitionFunctionRangeContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object expression();
  Object uidList();
};

class SubPartitionFunctionHashContextProxy : public ContextProxy {
public:
  SubPartitionFunctionHashContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object expression();
};

class SubPartitionFunctionKeyContextProxy : public ContextProxy {
public:
  SubPartitionFunctionKeyContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uidList();
};

class PartitionComparisionContextProxy : public ContextProxy {
public:
  PartitionComparisionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uid();
  Object partitionDefinerAtom();
  Object partitionDefinerAtomAt(size_t i);
  Object partitionOption();
  Object partitionOptionAt(size_t i);
  Object subpartitionDefinition();
  Object subpartitionDefinitionAt(size_t i);
};

class PartitionDefinerAtomContextProxy : public ContextProxy {
public:
  PartitionDefinerAtomContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object constant();
  Object expression();
};

class PartitionOptionContextProxy : public ContextProxy {
public:
  PartitionOptionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class SubpartitionDefinitionContextProxy : public ContextProxy {
public:
  SubpartitionDefinitionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uid();
  Object partitionOption();
  Object partitionOptionAt(size_t i);
};

class PartitionListAtomContextProxy : public ContextProxy {
public:
  PartitionListAtomContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uid();
  Object partitionDefinerAtom();
  Object partitionDefinerAtomAt(size_t i);
  Object partitionOption();
  Object partitionOptionAt(size_t i);
  Object subpartitionDefinition();
  Object subpartitionDefinitionAt(size_t i);
};

class PartitionListVectorContextProxy : public ContextProxy {
public:
  PartitionListVectorContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uid();
  Object partitionDefinerVector();
  Object partitionDefinerVectorAt(size_t i);
  Object partitionOption();
  Object partitionOptionAt(size_t i);
  Object subpartitionDefinition();
  Object subpartitionDefinitionAt(size_t i);
};

class PartitionDefinerVectorContextProxy : public ContextProxy {
public:
  PartitionDefinerVectorContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object partitionDefinerAtom();
  Object partitionDefinerAtomAt(size_t i);
};

class PartitionSimpleContextProxy : public ContextProxy {
public:
  PartitionSimpleContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uid();
  Object partitionOption();
  Object partitionOptionAt(size_t i);
  Object subpartitionDefinition();
  Object subpartitionDefinitionAt(size_t i);
};

class ConstantContextProxy : public ContextProxy {
public:
  ConstantContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object stringLiteral();
  Object decimalLiteral();
  Object hexadecimalLiteral();
  Object booleanLiteral();
};

class PartitionOptionCommentContextProxy : public ContextProxy {
public:
  PartitionOptionCommentContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class PartitionOptionNodeGroupContextProxy : public ContextProxy {
public:
  PartitionOptionNodeGroupContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uid();
};

class PartitionOptionIndexDirectoryContextProxy : public ContextProxy {
public:
  PartitionOptionIndexDirectoryContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class PartitionOptionMaxRowsContextProxy : public ContextProxy {
public:
  PartitionOptionMaxRowsContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object decimalLiteral();
};

class PartitionOptionTablespaceContextProxy : public ContextProxy {
public:
  PartitionOptionTablespaceContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uid();
};

class PartitionOptionEngineContextProxy : public ContextProxy {
public:
  PartitionOptionEngineContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object engineName();
};

class PartitionOptionMinRowsContextProxy : public ContextProxy {
public:
  PartitionOptionMinRowsContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object decimalLiteral();
};

class PartitionOptionDataDirectoryContextProxy : public ContextProxy {
public:
  PartitionOptionDataDirectoryContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class AlterUpgradeNameContextProxy : public ContextProxy {
public:
  AlterUpgradeNameContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uid();
};

class AlterSimpleDatabaseContextProxy : public ContextProxy {
public:
  AlterSimpleDatabaseContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uid();
  Object createDatabaseOption();
  Object createDatabaseOptionAt(size_t i);
};

class AlterSpecificationContextProxy : public ContextProxy {
public:
  AlterSpecificationContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class AlterByDisableKeysContextProxy : public ContextProxy {
public:
  AlterByDisableKeysContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class AlterByDefaultCharsetContextProxy : public ContextProxy {
public:
  AlterByDefaultCharsetContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object charsetName();
  Object collationName();
};

class AlterByRenameColumnContextProxy : public ContextProxy {
public:
  AlterByRenameColumnContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uid();
  Object uidAt(size_t i);
};

class AlterByConvertCharsetContextProxy : public ContextProxy {
public:
  AlterByConvertCharsetContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object charsetName();
  Object collationName();
};

class AlterByAddPartitionContextProxy : public ContextProxy {
public:
  AlterByAddPartitionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object partitionDefinition();
  Object partitionDefinitionAt(size_t i);
};

class AlterByAddForeignKeyContextProxy : public ContextProxy {
public:
  AlterByAddForeignKeyContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object indexColumnNames();
  Object referenceDefinition();
  Object uid();
  Object uidAt(size_t i);
};

class AlterByRenameIndexContextProxy : public ContextProxy {
public:
  AlterByRenameIndexContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uid();
  Object uidAt(size_t i);
};

class AlterByRemovePartitioningContextProxy : public ContextProxy {
public:
  AlterByRemovePartitioningContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class AlterByRenameContextProxy : public ContextProxy {
public:
  AlterByRenameContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uid();
  Object fullId();
};

class AlterByOptimizePartitionContextProxy : public ContextProxy {
public:
  AlterByOptimizePartitionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uidList();
};

class AlterByImportTablespaceContextProxy : public ContextProxy {
public:
  AlterByImportTablespaceContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class AlterByCoalescePartitionContextProxy : public ContextProxy {
public:
  AlterByCoalescePartitionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object decimalLiteral();
};

class AlterByAddColumnsContextProxy : public ContextProxy {
public:
  AlterByAddColumnsContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uid();
  Object uidAt(size_t i);
  Object columnDefinition();
  Object columnDefinitionAt(size_t i);
};

class AlterByDropForeignKeyContextProxy : public ContextProxy {
public:
  AlterByDropForeignKeyContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uid();
};

class AlterByAddCheckTableConstraintContextProxy : public ContextProxy {
public:
  AlterByAddCheckTableConstraintContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object expression();
  Object uid();
};

class AlterByRebuildPartitionContextProxy : public ContextProxy {
public:
  AlterByRebuildPartitionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uidList();
};

class AlterByUpgradePartitioningContextProxy : public ContextProxy {
public:
  AlterByUpgradePartitioningContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class AlterByRepairPartitionContextProxy : public ContextProxy {
public:
  AlterByRepairPartitionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uidList();
};

class AlterByExchangePartitionContextProxy : public ContextProxy {
public:
  AlterByExchangePartitionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uid();
  Object tableName();
};

class AlterByAddIndexContextProxy : public ContextProxy {
public:
  AlterByAddIndexContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object indexColumnNames();
  Object uid();
  Object indexType();
  Object indexOption();
  Object indexOptionAt(size_t i);
};

class AlterByDropColumnContextProxy : public ContextProxy {
public:
  AlterByDropColumnContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uid();
};

class AlterByImportPartitionContextProxy : public ContextProxy {
public:
  AlterByImportPartitionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uidList();
};

class AlterByChangeDefaultContextProxy : public ContextProxy {
public:
  AlterByChangeDefaultContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uid();
  Object defaultValue();
};

class AlterByForceContextProxy : public ContextProxy {
public:
  AlterByForceContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class AlterByDropPartitionContextProxy : public ContextProxy {
public:
  AlterByDropPartitionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uidList();
};

class AlterByAddSpecialIndexContextProxy : public ContextProxy {
public:
  AlterByAddSpecialIndexContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object indexColumnNames();
  Object uid();
  Object indexOption();
  Object indexOptionAt(size_t i);
};

class AlterByModifyColumnContextProxy : public ContextProxy {
public:
  AlterByModifyColumnContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uid();
  Object uidAt(size_t i);
  Object columnDefinition();
};

class AlterByTableOptionContextProxy : public ContextProxy {
public:
  AlterByTableOptionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object tableOption();
  Object tableOptionAt(size_t i);
};

class AlterByDropPrimaryKeyContextProxy : public ContextProxy {
public:
  AlterByDropPrimaryKeyContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class AlterByLockContextProxy : public ContextProxy {
public:
  AlterByLockContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class AlterByDiscardPartitionContextProxy : public ContextProxy {
public:
  AlterByDiscardPartitionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uidList();
};

class AlterByDiscardTablespaceContextProxy : public ContextProxy {
public:
  AlterByDiscardTablespaceContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class AlterByValidateContextProxy : public ContextProxy {
public:
  AlterByValidateContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class AlterByAddPrimaryKeyContextProxy : public ContextProxy {
public:
  AlterByAddPrimaryKeyContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object indexColumnNames();
  Object indexType();
  Object indexOption();
  Object indexOptionAt(size_t i);
  Object uid();
};

class AlterByCheckPartitionContextProxy : public ContextProxy {
public:
  AlterByCheckPartitionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uidList();
};

class AlterByEnableKeysContextProxy : public ContextProxy {
public:
  AlterByEnableKeysContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class AlterByReorganizePartitionContextProxy : public ContextProxy {
public:
  AlterByReorganizePartitionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uidList();
  Object partitionDefinition();
  Object partitionDefinitionAt(size_t i);
};

class AlterBySetAlgorithmContextProxy : public ContextProxy {
public:
  AlterBySetAlgorithmContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class AlterByAnalyzePartitionContextProxy : public ContextProxy {
public:
  AlterByAnalyzePartitionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uidList();
};

class AlterByChangeColumnContextProxy : public ContextProxy {
public:
  AlterByChangeColumnContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object columnDefinition();
  Object uid();
  Object uidAt(size_t i);
};

class AlterByAddUniqueKeyContextProxy : public ContextProxy {
public:
  AlterByAddUniqueKeyContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object indexColumnNames();
  Object indexType();
  Object indexOption();
  Object indexOptionAt(size_t i);
  Object uid();
  Object uidAt(size_t i);
};

class AlterByTruncatePartitionContextProxy : public ContextProxy {
public:
  AlterByTruncatePartitionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uidList();
};

class AlterByDropIndexContextProxy : public ContextProxy {
public:
  AlterByDropIndexContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uid();
};

class AlterByAddColumnContextProxy : public ContextProxy {
public:
  AlterByAddColumnContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uid();
  Object uidAt(size_t i);
  Object columnDefinition();
};

class AlterByOrderContextProxy : public ContextProxy {
public:
  AlterByOrderContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uidList();
};

class IfExistsContextProxy : public ContextProxy {
public:
  IfExistsContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class RenameTableClauseContextProxy : public ContextProxy {
public:
  RenameTableClauseContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object tableName();
  Object tableNameAt(size_t i);
};

class ConstantsContextProxy : public ContextProxy {
public:
  ConstantsContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object constant();
  Object constantAt(size_t i);
};

class ExpressionsContextProxy : public ContextProxy {
public:
  ExpressionsContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object expression();
  Object expressionAt(size_t i);
};

class SingleDeleteStatementContextProxy : public ContextProxy {
public:
  SingleDeleteStatementContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object tableName();
  Object uidList();
  Object expression();
  Object orderByClause();
  Object decimalLiteral();
};

class MultipleDeleteStatementContextProxy : public ContextProxy {
public:
  MultipleDeleteStatementContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object tableName();
  Object tableNameAt(size_t i);
  Object tableSources();
  Object expression();
};

class HandlerOpenStatementContextProxy : public ContextProxy {
public:
  HandlerOpenStatementContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object tableName();
  Object uid();
};

class HandlerReadIndexStatementContextProxy : public ContextProxy {
public:
  HandlerReadIndexStatementContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object tableName();
  Object uid();
  Object comparisonOperator();
  Object constants();
  Object expression();
  Object decimalLiteral();
};

class HandlerReadStatementContextProxy : public ContextProxy {
public:
  HandlerReadStatementContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object tableName();
  Object expression();
  Object decimalLiteral();
};

class HandlerCloseStatementContextProxy : public ContextProxy {
public:
  HandlerCloseStatementContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object tableName();
};

class InsertStatementValueContextProxy : public ContextProxy {
public:
  InsertStatementValueContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object selectStatement();
  Object expressionsWithDefaults();
  Object expressionsWithDefaultsAt(size_t i);
};

class UpdatedElementContextProxy : public ContextProxy {
public:
  UpdatedElementContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object fullColumnName();
  Object expression();
};

class AssignmentFieldContextProxy : public ContextProxy {
public:
  AssignmentFieldContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uid();
};

class SelectFieldsIntoContextProxy : public ContextProxy {
public:
  SelectFieldsIntoContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class SelectLinesIntoContextProxy : public ContextProxy {
public:
  SelectLinesIntoContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class QuerySpecificationNointoContextProxy : public ContextProxy {
public:
  QuerySpecificationNointoContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object selectElements();
  Object selectSpec();
  Object selectSpecAt(size_t i);
  Object fromClause();
  Object orderByClause();
  Object limitClause();
};

class UnionSelectContextProxy : public ContextProxy {
public:
  UnionSelectContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object querySpecificationNointo();
  Object unionStatement();
  Object unionStatementAt(size_t i);
  Object orderByClause();
  Object limitClause();
  Object lockClause();
  Object querySpecification();
  Object queryExpression();
};

class UnionStatementContextProxy : public ContextProxy {
public:
  UnionStatementContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object querySpecificationNointo();
  Object queryExpressionNointo();
};

class OrderByClauseContextProxy : public ContextProxy {
public:
  OrderByClauseContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object orderByExpression();
  Object orderByExpressionAt(size_t i);
};

class LimitClauseContextProxy : public ContextProxy {
public:
  LimitClauseContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object limitClauseAtom();
  Object limitClauseAtomAt(size_t i);
};

class LockClauseContextProxy : public ContextProxy {
public:
  LockClauseContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class QuerySpecificationContextProxy : public ContextProxy {
public:
  QuerySpecificationContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object selectElements();
  Object selectSpec();
  Object selectSpecAt(size_t i);
  Object selectIntoExpression();
  Object fromClause();
  Object orderByClause();
  Object limitClause();
};

class QueryExpressionContextProxy : public ContextProxy {
public:
  QueryExpressionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object querySpecification();
  Object queryExpression();
};

class QueryExpressionNointoContextProxy : public ContextProxy {
public:
  QueryExpressionNointoContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object querySpecificationNointo();
  Object queryExpressionNointo();
};

class UnionParenthesisSelectContextProxy : public ContextProxy {
public:
  UnionParenthesisSelectContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object queryExpressionNointo();
  Object unionParenthesis();
  Object unionParenthesisAt(size_t i);
  Object queryExpression();
  Object orderByClause();
  Object limitClause();
  Object lockClause();
};

class UnionParenthesisContextProxy : public ContextProxy {
public:
  UnionParenthesisContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object queryExpressionNointo();
};

class SimpleSelectContextProxy : public ContextProxy {
public:
  SimpleSelectContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object querySpecification();
  Object lockClause();
};

class ParenthesisSelectContextProxy : public ContextProxy {
public:
  ParenthesisSelectContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object queryExpression();
  Object lockClause();
};

class SingleUpdateStatementContextProxy : public ContextProxy {
public:
  SingleUpdateStatementContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object tableName();
  Object updatedElement();
  Object updatedElementAt(size_t i);
  Object uid();
  Object expression();
  Object orderByClause();
  Object limitClause();
};

class MultipleUpdateStatementContextProxy : public ContextProxy {
public:
  MultipleUpdateStatementContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object tableSources();
  Object updatedElement();
  Object updatedElementAt(size_t i);
  Object expression();
};

class ExpressionsWithDefaultsContextProxy : public ContextProxy {
public:
  ExpressionsWithDefaultsContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object expressionOrDefault();
  Object expressionOrDefaultAt(size_t i);
};

class FullColumnNameContextProxy : public ContextProxy {
public:
  FullColumnNameContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uid();
  Object dottedId();
  Object dottedIdAt(size_t i);
};

class TableSourcesContextProxy : public ContextProxy {
public:
  TableSourcesContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object tableSource();
  Object tableSourceAt(size_t i);
};

class ComparisonOperatorContextProxy : public ContextProxy {
public:
  ComparisonOperatorContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class OrderByExpressionContextProxy : public ContextProxy {
public:
  OrderByExpressionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object expression();
};

class TableSourceContextProxy : public ContextProxy {
public:
  TableSourceContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class TableSourceNestedContextProxy : public ContextProxy {
public:
  TableSourceNestedContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object tableSourceItem();
  Object joinPart();
  Object joinPartAt(size_t i);
};

class TableSourceItemContextProxy : public ContextProxy {
public:
  TableSourceItemContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class JoinPartContextProxy : public ContextProxy {
public:
  JoinPartContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class TableSourceBaseContextProxy : public ContextProxy {
public:
  TableSourceBaseContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object tableSourceItem();
  Object joinPart();
  Object joinPartAt(size_t i);
};

class SubqueryTableItemContextProxy : public ContextProxy {
public:
  SubqueryTableItemContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uid();
  Object selectStatement();
};

class AtomTableItemContextProxy : public ContextProxy {
public:
  AtomTableItemContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object tableName();
  Object uidList();
  Object indexHint();
  Object indexHintAt(size_t i);
  Object uid();
};

class IndexHintContextProxy : public ContextProxy {
public:
  IndexHintContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uidList();
  Object indexHintType();
};

class TableSourcesItemContextProxy : public ContextProxy {
public:
  TableSourcesItemContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object tableSources();
};

class IndexHintTypeContextProxy : public ContextProxy {
public:
  IndexHintTypeContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class InnerJoinContextProxy : public ContextProxy {
public:
  InnerJoinContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object tableSourceItem();
  Object expression();
  Object uidList();
};

class NaturalJoinContextProxy : public ContextProxy {
public:
  NaturalJoinContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object tableSourceItem();
};

class OuterJoinContextProxy : public ContextProxy {
public:
  OuterJoinContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object tableSourceItem();
  Object expression();
  Object uidList();
};

class StraightJoinContextProxy : public ContextProxy {
public:
  StraightJoinContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object tableSourceItem();
  Object expression();
};

class SelectElementsContextProxy : public ContextProxy {
public:
  SelectElementsContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object selectElement();
  Object selectElementAt(size_t i);
};

class SelectSpecContextProxy : public ContextProxy {
public:
  SelectSpecContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class SelectIntoExpressionContextProxy : public ContextProxy {
public:
  SelectIntoExpressionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class FromClauseContextProxy : public ContextProxy {
public:
  FromClauseContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object tableSources();
  Object groupByItem();
  Object groupByItemAt(size_t i);
  Object expression();
  Object expressionAt(size_t i);
};

class SelectElementContextProxy : public ContextProxy {
public:
  SelectElementContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class SelectExpressionElementContextProxy : public ContextProxy {
public:
  SelectExpressionElementContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object expression();
  Object uid();
};

class FunctionCallContextProxy : public ContextProxy {
public:
  FunctionCallContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class SelectFunctionElementContextProxy : public ContextProxy {
public:
  SelectFunctionElementContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object functionCall();
  Object uid();
};

class SelectStarElementContextProxy : public ContextProxy {
public:
  SelectStarElementContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object fullId();
};

class SelectColumnElementContextProxy : public ContextProxy {
public:
  SelectColumnElementContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object fullColumnName();
  Object uid();
};

class SelectIntoVariablesContextProxy : public ContextProxy {
public:
  SelectIntoVariablesContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object assignmentField();
  Object assignmentFieldAt(size_t i);
};

class SelectIntoTextFileContextProxy : public ContextProxy {
public:
  SelectIntoTextFileContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object charsetName();
  Object selectFieldsInto();
  Object selectFieldsIntoAt(size_t i);
  Object selectLinesInto();
  Object selectLinesIntoAt(size_t i);
};

class SelectIntoDumpFileContextProxy : public ContextProxy {
public:
  SelectIntoDumpFileContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class GroupByItemContextProxy : public ContextProxy {
public:
  GroupByItemContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object expression();
};

class LimitClauseAtomContextProxy : public ContextProxy {
public:
  LimitClauseAtomContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object decimalLiteral();
  Object mysqlVariable();
};

class MysqlVariableContextProxy : public ContextProxy {
public:
  MysqlVariableContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class TransactionModeContextProxy : public ContextProxy {
public:
  TransactionModeContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class LockTableElementContextProxy : public ContextProxy {
public:
  LockTableElementContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object tableName();
  Object lockAction();
  Object uid();
};

class SetAutocommitStatementContextProxy : public ContextProxy {
public:
  SetAutocommitStatementContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class SetTransactionStatementContextProxy : public ContextProxy {
public:
  SetTransactionStatementContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object transactionOption();
  Object transactionOptionAt(size_t i);
};

class TransactionOptionContextProxy : public ContextProxy {
public:
  TransactionOptionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object transactionLevel();
};

class LockActionContextProxy : public ContextProxy {
public:
  LockActionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class TransactionLevelContextProxy : public ContextProxy {
public:
  TransactionLevelContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class MasterOptionContextProxy : public ContextProxy {
public:
  MasterOptionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class ChannelOptionContextProxy : public ContextProxy {
public:
  ChannelOptionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class ReplicationFilterContextProxy : public ContextProxy {
public:
  ReplicationFilterContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class ThreadTypeContextProxy : public ContextProxy {
public:
  ThreadTypeContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class UntilOptionContextProxy : public ContextProxy {
public:
  UntilOptionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class ConnectionOptionContextProxy : public ContextProxy {
public:
  ConnectionOptionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class StringMasterOptionContextProxy : public ContextProxy {
public:
  StringMasterOptionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class MasterStringOptionContextProxy : public ContextProxy {
public:
  MasterStringOptionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object stringMasterOption();
};

class MasterRealOptionContextProxy : public ContextProxy {
public:
  MasterRealOptionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class BoolMasterOptionContextProxy : public ContextProxy {
public:
  BoolMasterOptionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class MasterBoolOptionContextProxy : public ContextProxy {
public:
  MasterBoolOptionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object boolMasterOption();
};

class MasterUidListOptionContextProxy : public ContextProxy {
public:
  MasterUidListOptionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uid();
  Object uidAt(size_t i);
};

class DecimalMasterOptionContextProxy : public ContextProxy {
public:
  DecimalMasterOptionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class MasterDecimalOptionContextProxy : public ContextProxy {
public:
  MasterDecimalOptionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object decimalMasterOption();
  Object decimalLiteral();
};

class WildIgnoreTableReplicationContextProxy : public ContextProxy {
public:
  WildIgnoreTableReplicationContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object simpleStrings();
};

class SimpleStringsContextProxy : public ContextProxy {
public:
  SimpleStringsContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class DoTableReplicationContextProxy : public ContextProxy {
public:
  DoTableReplicationContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object tables();
};

class IgnoreTableReplicationContextProxy : public ContextProxy {
public:
  IgnoreTableReplicationContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object tables();
};

class RewriteDbReplicationContextProxy : public ContextProxy {
public:
  RewriteDbReplicationContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object tablePair();
  Object tablePairAt(size_t i);
};

class TablePairContextProxy : public ContextProxy {
public:
  TablePairContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object tableName();
  Object tableNameAt(size_t i);
};

class DoDbReplicationContextProxy : public ContextProxy {
public:
  DoDbReplicationContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uidList();
};

class IgnoreDbReplicationContextProxy : public ContextProxy {
public:
  IgnoreDbReplicationContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uidList();
};

class WildDoTableReplicationContextProxy : public ContextProxy {
public:
  WildDoTableReplicationContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object simpleStrings();
};

class GtidsUntilOptionContextProxy : public ContextProxy {
public:
  GtidsUntilOptionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object gtuidSet();
};

class GtuidSetContextProxy : public ContextProxy {
public:
  GtuidSetContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uuidSet();
  Object uuidSetAt(size_t i);
};

class SqlGapsUntilOptionContextProxy : public ContextProxy {
public:
  SqlGapsUntilOptionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class MasterLogUntilOptionContextProxy : public ContextProxy {
public:
  MasterLogUntilOptionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object decimalLiteral();
};

class RelayLogUntilOptionContextProxy : public ContextProxy {
public:
  RelayLogUntilOptionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object decimalLiteral();
};

class PluginDirConnectionOptionContextProxy : public ContextProxy {
public:
  PluginDirConnectionOptionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class UserConnectionOptionContextProxy : public ContextProxy {
public:
  UserConnectionOptionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class DefaultAuthConnectionOptionContextProxy : public ContextProxy {
public:
  DefaultAuthConnectionOptionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class PasswordConnectionOptionContextProxy : public ContextProxy {
public:
  PasswordConnectionOptionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class UuidSetContextProxy : public ContextProxy {
public:
  UuidSetContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object decimalLiteral();
  Object decimalLiteralAt(size_t i);
};

class XidContextProxy : public ContextProxy {
public:
  XidContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object xuidStringId();
  Object xuidStringIdAt(size_t i);
  Object decimalLiteral();
};

class UserVariablesContextProxy : public ContextProxy {
public:
  UserVariablesContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class DeclareVariableContextProxy : public ContextProxy {
public:
  DeclareVariableContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uidList();
  Object dataType();
  Object defaultValue();
};

class DeclareConditionContextProxy : public ContextProxy {
public:
  DeclareConditionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uid();
  Object decimalLiteral();
};

class DeclareCursorContextProxy : public ContextProxy {
public:
  DeclareCursorContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uid();
  Object selectStatement();
};

class DeclareHandlerContextProxy : public ContextProxy {
public:
  DeclareHandlerContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object handlerConditionValue();
  Object handlerConditionValueAt(size_t i);
  Object routineBody();
};

class ProcedureSqlStatementContextProxy : public ContextProxy {
public:
  ProcedureSqlStatementContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object compoundStatement();
  Object sqlStatement();
};

class CaseAlternativeContextProxy : public ContextProxy {
public:
  CaseAlternativeContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object constant();
  Object expression();
  Object procedureSqlStatement();
  Object procedureSqlStatementAt(size_t i);
};

class ElifAlternativeContextProxy : public ContextProxy {
public:
  ElifAlternativeContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object expression();
  Object procedureSqlStatement();
  Object procedureSqlStatementAt(size_t i);
};

class CloseCursorContextProxy : public ContextProxy {
public:
  CloseCursorContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uid();
};

class OpenCursorContextProxy : public ContextProxy {
public:
  OpenCursorContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uid();
};

class FetchCursorContextProxy : public ContextProxy {
public:
  FetchCursorContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uid();
  Object uidList();
};

class HandlerConditionValueContextProxy : public ContextProxy {
public:
  HandlerConditionValueContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class HandlerConditionWarningContextProxy : public ContextProxy {
public:
  HandlerConditionWarningContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class HandlerConditionCodeContextProxy : public ContextProxy {
public:
  HandlerConditionCodeContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object decimalLiteral();
};

class HandlerConditionNotfoundContextProxy : public ContextProxy {
public:
  HandlerConditionNotfoundContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class HandlerConditionStateContextProxy : public ContextProxy {
public:
  HandlerConditionStateContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class HandlerConditionExceptionContextProxy : public ContextProxy {
public:
  HandlerConditionExceptionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class HandlerConditionNameContextProxy : public ContextProxy {
public:
  HandlerConditionNameContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uid();
};

class AlterUserMysqlV56ContextProxy : public ContextProxy {
public:
  AlterUserMysqlV56ContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object userSpecification();
  Object userSpecificationAt(size_t i);
};

class UserSpecificationContextProxy : public ContextProxy {
public:
  UserSpecificationContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object userName();
  Object userPasswordOption();
};

class AlterUserMysqlV57ContextProxy : public ContextProxy {
public:
  AlterUserMysqlV57ContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object userAuthOption();
  Object userAuthOptionAt(size_t i);
  Object ifExists();
  Object userPasswordOption();
  Object userPasswordOptionAt(size_t i);
  Object userLockOption();
  Object userLockOptionAt(size_t i);
  Object tlsOption();
  Object tlsOptionAt(size_t i);
  Object userResourceOption();
  Object userResourceOptionAt(size_t i);
};

class UserAuthOptionContextProxy : public ContextProxy {
public:
  UserAuthOptionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class UserPasswordOptionContextProxy : public ContextProxy {
public:
  UserPasswordOptionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object decimalLiteral();
};

class UserLockOptionContextProxy : public ContextProxy {
public:
  UserLockOptionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class TlsOptionContextProxy : public ContextProxy {
public:
  TlsOptionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class UserResourceOptionContextProxy : public ContextProxy {
public:
  UserResourceOptionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object decimalLiteral();
};

class CreateUserMysqlV57ContextProxy : public ContextProxy {
public:
  CreateUserMysqlV57ContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object userAuthOption();
  Object userAuthOptionAt(size_t i);
  Object ifNotExists();
  Object userPasswordOption();
  Object userPasswordOptionAt(size_t i);
  Object userLockOption();
  Object userLockOptionAt(size_t i);
  Object tlsOption();
  Object tlsOptionAt(size_t i);
  Object userResourceOption();
  Object userResourceOptionAt(size_t i);
};

class CreateUserMysqlV56ContextProxy : public ContextProxy {
public:
  CreateUserMysqlV56ContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object userAuthOption();
  Object userAuthOptionAt(size_t i);
};

class PrivelegeClauseContextProxy : public ContextProxy {
public:
  PrivelegeClauseContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object privilege();
  Object uidList();
};

class PrivilegeLevelContextProxy : public ContextProxy {
public:
  PrivilegeLevelContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class RenameUserClauseContextProxy : public ContextProxy {
public:
  RenameUserClauseContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object userName();
  Object userNameAt(size_t i);
};

class DetailRevokeContextProxy : public ContextProxy {
public:
  DetailRevokeContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object privelegeClause();
  Object privelegeClauseAt(size_t i);
  Object privilegeLevel();
  Object userName();
  Object userNameAt(size_t i);
};

class ShortRevokeContextProxy : public ContextProxy {
public:
  ShortRevokeContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object userName();
  Object userNameAt(size_t i);
};

class SetPasswordStatementContextProxy : public ContextProxy {
public:
  SetPasswordStatementContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object passwordFunctionClause();
  Object userName();
};

class PasswordFunctionClauseContextProxy : public ContextProxy {
public:
  PasswordFunctionClauseContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object functionArg();
};

class SimpleAuthOptionContextProxy : public ContextProxy {
public:
  SimpleAuthOptionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object userName();
};

class PasswordAuthOptionContextProxy : public ContextProxy {
public:
  PasswordAuthOptionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object userName();
};

class StringAuthOptionContextProxy : public ContextProxy {
public:
  StringAuthOptionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object userName();
  Object authPlugin();
};

class AuthPluginContextProxy : public ContextProxy {
public:
  AuthPluginContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uid();
};

class HashAuthOptionContextProxy : public ContextProxy {
public:
  HashAuthOptionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object userName();
  Object authPlugin();
};

class PrivilegeContextProxy : public ContextProxy {
public:
  PrivilegeContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class DefiniteSchemaPrivLevelContextProxy : public ContextProxy {
public:
  DefiniteSchemaPrivLevelContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uid();
};

class DefiniteFullTablePrivLevel2ContextProxy : public ContextProxy {
public:
  DefiniteFullTablePrivLevel2ContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uid();
  Object dottedId();
};

class DottedIdContextProxy : public ContextProxy {
public:
  DottedIdContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uid();
};

class DefiniteFullTablePrivLevelContextProxy : public ContextProxy {
public:
  DefiniteFullTablePrivLevelContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uid();
  Object uidAt(size_t i);
};

class GlobalPrivLevelContextProxy : public ContextProxy {
public:
  GlobalPrivLevelContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class DefiniteTablePrivLevelContextProxy : public ContextProxy {
public:
  DefiniteTablePrivLevelContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uid();
};

class CurrentSchemaPriviLevelContextProxy : public ContextProxy {
public:
  CurrentSchemaPriviLevelContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class CheckTableOptionContextProxy : public ContextProxy {
public:
  CheckTableOptionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class SetTransactionContextProxy : public ContextProxy {
public:
  SetTransactionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object setTransactionStatement();
};

class SetCharsetContextProxy : public ContextProxy {
public:
  SetCharsetContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object charsetName();
};

class SetNamesContextProxy : public ContextProxy {
public:
  SetNamesContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object charsetName();
  Object collationName();
};

class SetPasswordContextProxy : public ContextProxy {
public:
  SetPasswordContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object setPasswordStatement();
};

class SetAutocommitContextProxy : public ContextProxy {
public:
  SetAutocommitContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object setAutocommitStatement();
};

class SetNewValueInsideTriggerContextProxy : public ContextProxy {
public:
  SetNewValueInsideTriggerContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object fullId();
  Object expression();
};

class SetVariableContextProxy : public ContextProxy {
public:
  SetVariableContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object variableClause();
  Object variableClauseAt(size_t i);
  Object expression();
  Object expressionAt(size_t i);
};

class VariableClauseContextProxy : public ContextProxy {
public:
  VariableClauseContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uid();
};

class ShowOpenTablesContextProxy : public ContextProxy {
public:
  ShowOpenTablesContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uid();
  Object showFilter();
};

class ShowFilterContextProxy : public ContextProxy {
public:
  ShowFilterContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object expression();
};

class ShowGlobalInfoContextProxy : public ContextProxy {
public:
  ShowGlobalInfoContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object showGlobalInfoClause();
};

class ShowGlobalInfoClauseContextProxy : public ContextProxy {
public:
  ShowGlobalInfoClauseContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class ShowCreateFullIdObjectContextProxy : public ContextProxy {
public:
  ShowCreateFullIdObjectContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object fullId();
};

class ShowCreateUserContextProxy : public ContextProxy {
public:
  ShowCreateUserContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object userName();
};

class ShowErrorsContextProxy : public ContextProxy {
public:
  ShowErrorsContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object decimalLiteral();
  Object decimalLiteralAt(size_t i);
};

class ShowCountErrorsContextProxy : public ContextProxy {
public:
  ShowCountErrorsContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class ShowObjectFilterContextProxy : public ContextProxy {
public:
  ShowObjectFilterContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object showCommonEntity();
  Object showFilter();
};

class ShowCommonEntityContextProxy : public ContextProxy {
public:
  ShowCommonEntityContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class ShowCreateDbContextProxy : public ContextProxy {
public:
  ShowCreateDbContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uid();
  Object ifNotExists();
};

class ShowEngineContextProxy : public ContextProxy {
public:
  ShowEngineContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object engineName();
};

class ShowSchemaFilterContextProxy : public ContextProxy {
public:
  ShowSchemaFilterContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object showSchemaEntity();
  Object uid();
  Object showFilter();
};

class ShowSchemaEntityContextProxy : public ContextProxy {
public:
  ShowSchemaEntityContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class ShowIndexesContextProxy : public ContextProxy {
public:
  ShowIndexesContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object tableName();
  Object uid();
  Object expression();
};

class ShowLogEventsContextProxy : public ContextProxy {
public:
  ShowLogEventsContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object decimalLiteral();
  Object decimalLiteralAt(size_t i);
};

class ShowMasterLogsContextProxy : public ContextProxy {
public:
  ShowMasterLogsContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class ShowGrantsContextProxy : public ContextProxy {
public:
  ShowGrantsContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object userName();
};

class ShowSlaveStatusContextProxy : public ContextProxy {
public:
  ShowSlaveStatusContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class ShowRoutineContextProxy : public ContextProxy {
public:
  ShowRoutineContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object fullId();
};

class ShowProfileContextProxy : public ContextProxy {
public:
  ShowProfileContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object showProfileType();
  Object showProfileTypeAt(size_t i);
  Object decimalLiteral();
  Object decimalLiteralAt(size_t i);
};

class ShowProfileTypeContextProxy : public ContextProxy {
public:
  ShowProfileTypeContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class ShowColumnsContextProxy : public ContextProxy {
public:
  ShowColumnsContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object tableName();
  Object uid();
  Object showFilter();
};

class TableIndexesContextProxy : public ContextProxy {
public:
  TableIndexesContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object tableName();
  Object uidList();
};

class FlushOptionContextProxy : public ContextProxy {
public:
  FlushOptionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class LoadedTableIndexesContextProxy : public ContextProxy {
public:
  LoadedTableIndexesContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object tableName();
  Object uidList();
  Object uidListAt(size_t i);
};

class TableFlushOptionContextProxy : public ContextProxy {
public:
  TableFlushOptionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object tables();
  Object flushTableOption();
};

class FlushTableOptionContextProxy : public ContextProxy {
public:
  FlushTableOptionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class ChannelFlushOptionContextProxy : public ContextProxy {
public:
  ChannelFlushOptionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object channelOption();
};

class SimpleFlushOptionContextProxy : public ContextProxy {
public:
  SimpleFlushOptionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class DescribeObjectClauseContextProxy : public ContextProxy {
public:
  DescribeObjectClauseContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class SignalConditionInformationContextProxy : public ContextProxy {
public:
  SignalConditionInformationContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object stringLiteral();
};

class DiagnosticsConditionInformationNameContextProxy : public ContextProxy {
public:
  DiagnosticsConditionInformationNameContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class DescribeStatementsContextProxy : public ContextProxy {
public:
  DescribeStatementsContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object selectStatement();
  Object deleteStatement();
  Object insertStatement();
  Object replaceStatement();
  Object updateStatement();
};

class DescribeConnectionContextProxy : public ContextProxy {
public:
  DescribeConnectionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uid();
};

class IndexColumnNameContextProxy : public ContextProxy {
public:
  IndexColumnNameContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object uid();
  Object decimalLiteral();
};

class CharsetNameBaseContextProxy : public ContextProxy {
public:
  CharsetNameBaseContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class XuidStringIdContextProxy : public ContextProxy {
public:
  XuidStringIdContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class SimpleIdContextProxy : public ContextProxy {
public:
  SimpleIdContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object charsetNameBase();
  Object transactionLevelBase();
  Object engineName();
  Object privilegesBase();
  Object intervalTypeBase();
  Object dataTypeBase();
  Object keywordsCanBeId();
  Object functionNameBase();
};

class TransactionLevelBaseContextProxy : public ContextProxy {
public:
  TransactionLevelBaseContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class PrivilegesBaseContextProxy : public ContextProxy {
public:
  PrivilegesBaseContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class DataTypeBaseContextProxy : public ContextProxy {
public:
  DataTypeBaseContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class KeywordsCanBeIdContextProxy : public ContextProxy {
public:
  KeywordsCanBeIdContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class FunctionNameBaseContextProxy : public ContextProxy {
public:
  FunctionNameBaseContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class BooleanLiteralContextProxy : public ContextProxy {
public:
  BooleanLiteralContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class HexadecimalLiteralContextProxy : public ContextProxy {
public:
  HexadecimalLiteralContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class SpatialDataTypeContextProxy : public ContextProxy {
public:
  SpatialDataTypeContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class CollectionOptionsContextProxy : public ContextProxy {
public:
  CollectionOptionsContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class CollectionDataTypeContextProxy : public ContextProxy {
public:
  CollectionDataTypeContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object collectionOptions();
  Object charsetName();
};

class NationalVaryingStringDataTypeContextProxy : public ContextProxy {
public:
  NationalVaryingStringDataTypeContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object lengthOneDimension();
};

class LengthOneDimensionContextProxy : public ContextProxy {
public:
  LengthOneDimensionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object decimalLiteral();
};

class DimensionDataTypeContextProxy : public ContextProxy {
public:
  DimensionDataTypeContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object lengthOneDimension();
  Object lengthTwoDimension();
  Object lengthTwoOptionalDimension();
};

class LengthTwoDimensionContextProxy : public ContextProxy {
public:
  LengthTwoDimensionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object decimalLiteral();
  Object decimalLiteralAt(size_t i);
};

class LengthTwoOptionalDimensionContextProxy : public ContextProxy {
public:
  LengthTwoOptionalDimensionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object decimalLiteral();
  Object decimalLiteralAt(size_t i);
};

class StringDataTypeContextProxy : public ContextProxy {
public:
  StringDataTypeContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object lengthOneDimension();
  Object charsetName();
  Object collationName();
};

class NationalStringDataTypeContextProxy : public ContextProxy {
public:
  NationalStringDataTypeContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object lengthOneDimension();
};

class SimpleDataTypeContextProxy : public ContextProxy {
public:
  SimpleDataTypeContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class ConvertedDataTypeContextProxy : public ContextProxy {
public:
  ConvertedDataTypeContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object lengthOneDimension();
  Object charsetName();
  Object lengthTwoDimension();
};

class ExpressionOrDefaultContextProxy : public ContextProxy {
public:
  ExpressionOrDefaultContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object expression();
};

class UnaryOperatorContextProxy : public ContextProxy {
public:
  UnaryOperatorContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class SpecificFunctionContextProxy : public ContextProxy {
public:
  SpecificFunctionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class SpecificFunctionCallContextProxy : public ContextProxy {
public:
  SpecificFunctionCallContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object specificFunction();
};

class PasswordFunctionCallContextProxy : public ContextProxy {
public:
  PasswordFunctionCallContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object passwordFunctionClause();
};

class UdfFunctionCallContextProxy : public ContextProxy {
public:
  UdfFunctionCallContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object fullId();
  Object functionArgs();
};

class FunctionArgsContextProxy : public ContextProxy {
public:
  FunctionArgsContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object constant();
  Object constantAt(size_t i);
  Object fullColumnName();
  Object fullColumnNameAt(size_t i);
  Object functionCall();
  Object functionCallAt(size_t i);
  Object expression();
  Object expressionAt(size_t i);
};

class AggregateWindowedFunctionContextProxy : public ContextProxy {
public:
  AggregateWindowedFunctionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object functionArg();
  Object functionArgs();
  Object orderByExpression();
  Object orderByExpressionAt(size_t i);
};

class AggregateFunctionCallContextProxy : public ContextProxy {
public:
  AggregateFunctionCallContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object aggregateWindowedFunction();
};

class ScalarFunctionNameContextProxy : public ContextProxy {
public:
  ScalarFunctionNameContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object functionNameBase();
};

class ScalarFunctionCallContextProxy : public ContextProxy {
public:
  ScalarFunctionCallContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object scalarFunctionName();
  Object functionArgs();
};

class PositionFunctionCallContextProxy : public ContextProxy {
public:
  PositionFunctionCallContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object stringLiteral();
  Object stringLiteralAt(size_t i);
  Object expression();
  Object expressionAt(size_t i);
};

class TrimFunctionCallContextProxy : public ContextProxy {
public:
  TrimFunctionCallContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object stringLiteral();
  Object stringLiteralAt(size_t i);
  Object expression();
  Object expressionAt(size_t i);
};

class SimpleFunctionCallContextProxy : public ContextProxy {
public:
  SimpleFunctionCallContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class CharFunctionCallContextProxy : public ContextProxy {
public:
  CharFunctionCallContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object functionArgs();
  Object charsetName();
};

class WeightFunctionCallContextProxy : public ContextProxy {
public:
  WeightFunctionCallContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object stringLiteral();
  Object expression();
  Object decimalLiteral();
  Object levelsInWeightString();
};

class LevelsInWeightStringContextProxy : public ContextProxy {
public:
  LevelsInWeightStringContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class GetFormatFunctionCallContextProxy : public ContextProxy {
public:
  GetFormatFunctionCallContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object stringLiteral();
};

class CaseFunctionCallContextProxy : public ContextProxy {
public:
  CaseFunctionCallContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object expression();
  Object caseFuncAlternative();
  Object caseFuncAlternativeAt(size_t i);
  Object functionArg();
};

class CaseFuncAlternativeContextProxy : public ContextProxy {
public:
  CaseFuncAlternativeContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object functionArg();
  Object functionArgAt(size_t i);
};

class FunctionArgContextProxy : public ContextProxy {
public:
  FunctionArgContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object constant();
  Object fullColumnName();
  Object functionCall();
  Object expression();
};

class ExtractFunctionCallContextProxy : public ContextProxy {
public:
  ExtractFunctionCallContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object intervalType();
  Object stringLiteral();
  Object expression();
};

class DataTypeFunctionCallContextProxy : public ContextProxy {
public:
  DataTypeFunctionCallContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object expression();
  Object convertedDataType();
  Object charsetName();
};

class ValuesFunctionCallContextProxy : public ContextProxy {
public:
  ValuesFunctionCallContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object fullColumnName();
};

class SubstrFunctionCallContextProxy : public ContextProxy {
public:
  SubstrFunctionCallContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object stringLiteral();
  Object expression();
  Object expressionAt(size_t i);
  Object decimalLiteral();
  Object decimalLiteralAt(size_t i);
};

class LevelWeightRangeContextProxy : public ContextProxy {
public:
  LevelWeightRangeContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object decimalLiteral();
  Object decimalLiteralAt(size_t i);
};

class LevelWeightListContextProxy : public ContextProxy {
public:
  LevelWeightListContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object levelInWeightListElement();
  Object levelInWeightListElementAt(size_t i);
};

class LevelInWeightListElementContextProxy : public ContextProxy {
public:
  LevelInWeightListElementContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object decimalLiteral();
};

class PredicateContextProxy : public ContextProxy {
public:
  PredicateContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class IsExpressionContextProxy : public ContextProxy {
public:
  IsExpressionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object predicate();
};

class NotExpressionContextProxy : public ContextProxy {
public:
  NotExpressionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object expression();
};

class LogicalExpressionContextProxy : public ContextProxy {
public:
  LogicalExpressionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object expression();
  Object expressionAt(size_t i);
  Object logicalOperator();
};

class LogicalOperatorContextProxy : public ContextProxy {
public:
  LogicalOperatorContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class PredicateExpressionContextProxy : public ContextProxy {
public:
  PredicateExpressionContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object predicate();
};

class SoundsLikePredicateContextProxy : public ContextProxy {
public:
  SoundsLikePredicateContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object predicate();
  Object predicateAt(size_t i);
};

class ExpressionAtomContextProxy : public ContextProxy {
public:
  ExpressionAtomContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class ExpressionAtomPredicateContextProxy : public ContextProxy {
public:
  ExpressionAtomPredicateContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object expressionAtom();
};

class InPredicateContextProxy : public ContextProxy {
public:
  InPredicateContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object predicate();
  Object selectStatement();
  Object expressions();
};

class SubqueryComparasionPredicateContextProxy : public ContextProxy {
public:
  SubqueryComparasionPredicateContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object predicate();
  Object comparisonOperator();
  Object selectStatement();
};

class BetweenPredicateContextProxy : public ContextProxy {
public:
  BetweenPredicateContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object predicate();
  Object predicateAt(size_t i);
};

class BinaryComparasionPredicateContextProxy : public ContextProxy {
public:
  BinaryComparasionPredicateContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object comparisonOperator();
  Object predicate();
  Object predicateAt(size_t i);
};

class IsNullPredicateContextProxy : public ContextProxy {
public:
  IsNullPredicateContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object predicate();
  Object nullNotnull();
};

class LikePredicateContextProxy : public ContextProxy {
public:
  LikePredicateContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object predicate();
  Object predicateAt(size_t i);
};

class RegexpPredicateContextProxy : public ContextProxy {
public:
  RegexpPredicateContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object predicate();
  Object predicateAt(size_t i);
};

class UnaryExpressionAtomContextProxy : public ContextProxy {
public:
  UnaryExpressionAtomContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object unaryOperator();
  Object expressionAtom();
};

class CollateExpressionAtomContextProxy : public ContextProxy {
public:
  CollateExpressionAtomContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object expressionAtom();
  Object collationName();
};

class SubqueryExpessionAtomContextProxy : public ContextProxy {
public:
  SubqueryExpessionAtomContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object selectStatement();
};

class MysqlVariableExpressionAtomContextProxy : public ContextProxy {
public:
  MysqlVariableExpressionAtomContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object mysqlVariable();
};

class NestedExpressionAtomContextProxy : public ContextProxy {
public:
  NestedExpressionAtomContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object expression();
  Object expressionAt(size_t i);
};

class NestedRowExpressionAtomContextProxy : public ContextProxy {
public:
  NestedRowExpressionAtomContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object expression();
  Object expressionAt(size_t i);
};

class MathOperatorContextProxy : public ContextProxy {
public:
  MathOperatorContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class MathExpressionAtomContextProxy : public ContextProxy {
public:
  MathExpressionAtomContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object mathOperator();
  Object expressionAtom();
  Object expressionAtomAt(size_t i);
};

class IntervalExpressionAtomContextProxy : public ContextProxy {
public:
  IntervalExpressionAtomContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object expression();
  Object intervalType();
};

class ExistsExpessionAtomContextProxy : public ContextProxy {
public:
  ExistsExpessionAtomContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object selectStatement();
};

class ConstantExpressionAtomContextProxy : public ContextProxy {
public:
  ConstantExpressionAtomContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object constant();
};

class FunctionCallExpressionAtomContextProxy : public ContextProxy {
public:
  FunctionCallExpressionAtomContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object functionCall();
};

class BinaryExpressionAtomContextProxy : public ContextProxy {
public:
  BinaryExpressionAtomContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object expressionAtom();
};

class FullColumnNameExpressionAtomContextProxy : public ContextProxy {
public:
  FullColumnNameExpressionAtomContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object fullColumnName();
};

class BitOperatorContextProxy : public ContextProxy {
public:
  BitOperatorContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};

};

class BitExpressionAtomContextProxy : public ContextProxy {
public:
  BitExpressionAtomContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object bitOperator();
  Object expressionAtom();
  Object expressionAtomAt(size_t i);
};


Class rb_cRootContext;
Class rb_cSqlStatementsContext;
Class rb_cSqlStatementContext;
Class rb_cEmptyStatementContext;
Class rb_cDdlStatementContext;
Class rb_cDmlStatementContext;
Class rb_cTransactionStatementContext;
Class rb_cReplicationStatementContext;
Class rb_cPreparedStatementContext;
Class rb_cAdministrationStatementContext;
Class rb_cUtilityStatementContext;
Class rb_cCreateDatabaseContext;
Class rb_cCreateEventContext;
Class rb_cCreateIndexContext;
Class rb_cCreateLogfileGroupContext;
Class rb_cCreateProcedureContext;
Class rb_cCreateFunctionContext;
Class rb_cCreateServerContext;
Class rb_cCreateTableContext;
Class rb_cCreateTablespaceInnodbContext;
Class rb_cCreateTablespaceNdbContext;
Class rb_cCreateTriggerContext;
Class rb_cCreateViewContext;
Class rb_cAlterDatabaseContext;
Class rb_cAlterEventContext;
Class rb_cAlterFunctionContext;
Class rb_cAlterInstanceContext;
Class rb_cAlterLogfileGroupContext;
Class rb_cAlterProcedureContext;
Class rb_cAlterServerContext;
Class rb_cAlterTableContext;
Class rb_cAlterTablespaceContext;
Class rb_cAlterViewContext;
Class rb_cDropDatabaseContext;
Class rb_cDropEventContext;
Class rb_cDropIndexContext;
Class rb_cDropLogfileGroupContext;
Class rb_cDropProcedureContext;
Class rb_cDropFunctionContext;
Class rb_cDropServerContext;
Class rb_cDropTableContext;
Class rb_cDropTablespaceContext;
Class rb_cDropTriggerContext;
Class rb_cDropViewContext;
Class rb_cRenameTableContext;
Class rb_cTruncateTableContext;
Class rb_cSelectStatementContext;
Class rb_cInsertStatementContext;
Class rb_cUpdateStatementContext;
Class rb_cDeleteStatementContext;
Class rb_cReplaceStatementContext;
Class rb_cCallStatementContext;
Class rb_cLoadDataStatementContext;
Class rb_cLoadXmlStatementContext;
Class rb_cDoStatementContext;
Class rb_cHandlerStatementContext;
Class rb_cStartTransactionContext;
Class rb_cBeginWorkContext;
Class rb_cCommitWorkContext;
Class rb_cRollbackWorkContext;
Class rb_cSavepointStatementContext;
Class rb_cRollbackStatementContext;
Class rb_cReleaseStatementContext;
Class rb_cLockTablesContext;
Class rb_cUnlockTablesContext;
Class rb_cChangeMasterContext;
Class rb_cChangeReplicationFilterContext;
Class rb_cPurgeBinaryLogsContext;
Class rb_cResetMasterContext;
Class rb_cResetSlaveContext;
Class rb_cStartSlaveContext;
Class rb_cStopSlaveContext;
Class rb_cStartGroupReplicationContext;
Class rb_cStopGroupReplicationContext;
Class rb_cXaStartTransactionContext;
Class rb_cXaEndTransactionContext;
Class rb_cXaPrepareStatementContext;
Class rb_cXaCommitWorkContext;
Class rb_cXaRollbackWorkContext;
Class rb_cXaRecoverWorkContext;
Class rb_cPrepareStatementContext;
Class rb_cExecuteStatementContext;
Class rb_cDeallocatePrepareContext;
Class rb_cCompoundStatementContext;
Class rb_cBlockStatementContext;
Class rb_cCaseStatementContext;
Class rb_cIfStatementContext;
Class rb_cLeaveStatementContext;
Class rb_cLoopStatementContext;
Class rb_cRepeatStatementContext;
Class rb_cWhileStatementContext;
Class rb_cIterateStatementContext;
Class rb_cReturnStatementContext;
Class rb_cCursorStatementContext;
Class rb_cAlterUserContext;
Class rb_cCreateUserContext;
Class rb_cDropUserContext;
Class rb_cGrantStatementContext;
Class rb_cGrantProxyContext;
Class rb_cRenameUserContext;
Class rb_cRevokeStatementContext;
Class rb_cRevokeProxyContext;
Class rb_cAnalyzeTableContext;
Class rb_cCheckTableContext;
Class rb_cChecksumTableContext;
Class rb_cOptimizeTableContext;
Class rb_cRepairTableContext;
Class rb_cCreateUdfunctionContext;
Class rb_cInstallPluginContext;
Class rb_cUninstallPluginContext;
Class rb_cSetStatementContext;
Class rb_cShowStatementContext;
Class rb_cBinlogStatementContext;
Class rb_cCacheIndexStatementContext;
Class rb_cFlushStatementContext;
Class rb_cKillStatementContext;
Class rb_cLoadIndexIntoCacheContext;
Class rb_cResetStatementContext;
Class rb_cShutdownStatementContext;
Class rb_cSimpleDescribeStatementContext;
Class rb_cFullDescribeStatementContext;
Class rb_cHelpStatementContext;
Class rb_cUseStatementContext;
Class rb_cSignalStatementContext;
Class rb_cResignalStatementContext;
Class rb_cDiagnosticsStatementContext;
Class rb_cUidContext;
Class rb_cIfNotExistsContext;
Class rb_cCreateDatabaseOptionContext;
Class rb_cFullIdContext;
Class rb_cScheduleExpressionContext;
Class rb_cRoutineBodyContext;
Class rb_cOwnerStatementContext;
Class rb_cEnableTypeContext;
Class rb_cTableNameContext;
Class rb_cIndexColumnNamesContext;
Class rb_cIndexTypeContext;
Class rb_cIndexOptionContext;
Class rb_cEngineNameContext;
Class rb_cFileSizeLiteralContext;
Class rb_cProcedureParameterContext;
Class rb_cRoutineOptionContext;
Class rb_cDataTypeContext;
Class rb_cFunctionParameterContext;
Class rb_cServerOptionContext;
Class rb_cCopyCreateTableContext;
Class rb_cColumnCreateTableContext;
Class rb_cCreateDefinitionsContext;
Class rb_cTableOptionContext;
Class rb_cPartitionDefinitionsContext;
Class rb_cQueryCreateTableContext;
Class rb_cUidListContext;
Class rb_cCharsetNameContext;
Class rb_cCollationNameContext;
Class rb_cUserNameContext;
Class rb_cPreciseScheduleContext;
Class rb_cTimestampValueContext;
Class rb_cIntervalExprContext;
Class rb_cIntervalScheduleContext;
Class rb_cIntervalTypeContext;
Class rb_cDecimalLiteralContext;
Class rb_cExpressionContext;
Class rb_cStringLiteralContext;
Class rb_cIntervalTypeBaseContext;
Class rb_cRoutineBehaviorContext;
Class rb_cRoutineLanguageContext;
Class rb_cRoutineCommentContext;
Class rb_cRoutineSecurityContext;
Class rb_cRoutineDataContext;
Class rb_cCreateDefinitionContext;
Class rb_cColumnDeclarationContext;
Class rb_cColumnDefinitionContext;
Class rb_cTableConstraintContext;
Class rb_cConstraintDeclarationContext;
Class rb_cIndexColumnDefinitionContext;
Class rb_cIndexDeclarationContext;
Class rb_cColumnConstraintContext;
Class rb_cStorageColumnConstraintContext;
Class rb_cFormatColumnConstraintContext;
Class rb_cCollateColumnConstraintContext;
Class rb_cAutoIncrementColumnConstraintContext;
Class rb_cCurrentTimestampContext;
Class rb_cCommentColumnConstraintContext;
Class rb_cPrimaryKeyColumnConstraintContext;
Class rb_cUniqueKeyColumnConstraintContext;
Class rb_cSerialDefaultColumnConstraintContext;
Class rb_cNullNotnullContext;
Class rb_cNullColumnConstraintContext;
Class rb_cDefaultColumnConstraintContext;
Class rb_cDefaultValueContext;
Class rb_cReferenceDefinitionContext;
Class rb_cReferenceColumnConstraintContext;
Class rb_cGeneratedColumnConstraintContext;
Class rb_cUniqueKeyTableConstraintContext;
Class rb_cCheckTableConstraintContext;
Class rb_cPrimaryKeyTableConstraintContext;
Class rb_cForeignKeyTableConstraintContext;
Class rb_cReferenceActionContext;
Class rb_cReferenceControlTypeContext;
Class rb_cSpecialIndexDeclarationContext;
Class rb_cSimpleIndexDeclarationContext;
Class rb_cTableOptionEngineContext;
Class rb_cTableOptionMaxRowsContext;
Class rb_cTableOptionCollateContext;
Class rb_cTableOptionPersistentContext;
Class rb_cTableOptionTablespaceContext;
Class rb_cTablespaceStorageContext;
Class rb_cTableOptionPackKeysContext;
Class rb_cTableOptionPasswordContext;
Class rb_cTableOptionUnionContext;
Class rb_cTablesContext;
Class rb_cTableOptionSamplePageContext;
Class rb_cTableOptionCharsetContext;
Class rb_cTableOptionIndexDirectoryContext;
Class rb_cTableOptionKeyBlockSizeContext;
Class rb_cTableOptionEncryptionContext;
Class rb_cTableOptionDataDirectoryContext;
Class rb_cTableOptionRecalculationContext;
Class rb_cTableOptionAutoIncrementContext;
Class rb_cTableOptionChecksumContext;
Class rb_cTableOptionDelayContext;
Class rb_cTableOptionConnectionContext;
Class rb_cTableOptionCommentContext;
Class rb_cTableOptionAverageContext;
Class rb_cTableOptionRowFormatContext;
Class rb_cTableOptionCompressionContext;
Class rb_cTableOptionInsertMethodContext;
Class rb_cTableOptionMinRowsContext;
Class rb_cPartitionFunctionDefinitionContext;
Class rb_cSubpartitionFunctionDefinitionContext;
Class rb_cPartitionDefinitionContext;
Class rb_cPartitionFunctionKeyContext;
Class rb_cPartitionFunctionHashContext;
Class rb_cPartitionFunctionListContext;
Class rb_cPartitionFunctionRangeContext;
Class rb_cSubPartitionFunctionHashContext;
Class rb_cSubPartitionFunctionKeyContext;
Class rb_cPartitionComparisionContext;
Class rb_cPartitionDefinerAtomContext;
Class rb_cPartitionOptionContext;
Class rb_cSubpartitionDefinitionContext;
Class rb_cPartitionListAtomContext;
Class rb_cPartitionListVectorContext;
Class rb_cPartitionDefinerVectorContext;
Class rb_cPartitionSimpleContext;
Class rb_cConstantContext;
Class rb_cPartitionOptionCommentContext;
Class rb_cPartitionOptionNodeGroupContext;
Class rb_cPartitionOptionIndexDirectoryContext;
Class rb_cPartitionOptionMaxRowsContext;
Class rb_cPartitionOptionTablespaceContext;
Class rb_cPartitionOptionEngineContext;
Class rb_cPartitionOptionMinRowsContext;
Class rb_cPartitionOptionDataDirectoryContext;
Class rb_cAlterUpgradeNameContext;
Class rb_cAlterSimpleDatabaseContext;
Class rb_cAlterSpecificationContext;
Class rb_cAlterByDisableKeysContext;
Class rb_cAlterByDefaultCharsetContext;
Class rb_cAlterByRenameColumnContext;
Class rb_cAlterByConvertCharsetContext;
Class rb_cAlterByAddPartitionContext;
Class rb_cAlterByAddForeignKeyContext;
Class rb_cAlterByRenameIndexContext;
Class rb_cAlterByRemovePartitioningContext;
Class rb_cAlterByRenameContext;
Class rb_cAlterByOptimizePartitionContext;
Class rb_cAlterByImportTablespaceContext;
Class rb_cAlterByCoalescePartitionContext;
Class rb_cAlterByAddColumnsContext;
Class rb_cAlterByDropForeignKeyContext;
Class rb_cAlterByAddCheckTableConstraintContext;
Class rb_cAlterByRebuildPartitionContext;
Class rb_cAlterByUpgradePartitioningContext;
Class rb_cAlterByRepairPartitionContext;
Class rb_cAlterByExchangePartitionContext;
Class rb_cAlterByAddIndexContext;
Class rb_cAlterByDropColumnContext;
Class rb_cAlterByImportPartitionContext;
Class rb_cAlterByChangeDefaultContext;
Class rb_cAlterByForceContext;
Class rb_cAlterByDropPartitionContext;
Class rb_cAlterByAddSpecialIndexContext;
Class rb_cAlterByModifyColumnContext;
Class rb_cAlterByTableOptionContext;
Class rb_cAlterByDropPrimaryKeyContext;
Class rb_cAlterByLockContext;
Class rb_cAlterByDiscardPartitionContext;
Class rb_cAlterByDiscardTablespaceContext;
Class rb_cAlterByValidateContext;
Class rb_cAlterByAddPrimaryKeyContext;
Class rb_cAlterByCheckPartitionContext;
Class rb_cAlterByEnableKeysContext;
Class rb_cAlterByReorganizePartitionContext;
Class rb_cAlterBySetAlgorithmContext;
Class rb_cAlterByAnalyzePartitionContext;
Class rb_cAlterByChangeColumnContext;
Class rb_cAlterByAddUniqueKeyContext;
Class rb_cAlterByTruncatePartitionContext;
Class rb_cAlterByDropIndexContext;
Class rb_cAlterByAddColumnContext;
Class rb_cAlterByOrderContext;
Class rb_cIfExistsContext;
Class rb_cRenameTableClauseContext;
Class rb_cConstantsContext;
Class rb_cExpressionsContext;
Class rb_cSingleDeleteStatementContext;
Class rb_cMultipleDeleteStatementContext;
Class rb_cHandlerOpenStatementContext;
Class rb_cHandlerReadIndexStatementContext;
Class rb_cHandlerReadStatementContext;
Class rb_cHandlerCloseStatementContext;
Class rb_cInsertStatementValueContext;
Class rb_cUpdatedElementContext;
Class rb_cAssignmentFieldContext;
Class rb_cSelectFieldsIntoContext;
Class rb_cSelectLinesIntoContext;
Class rb_cQuerySpecificationNointoContext;
Class rb_cUnionSelectContext;
Class rb_cUnionStatementContext;
Class rb_cOrderByClauseContext;
Class rb_cLimitClauseContext;
Class rb_cLockClauseContext;
Class rb_cQuerySpecificationContext;
Class rb_cQueryExpressionContext;
Class rb_cQueryExpressionNointoContext;
Class rb_cUnionParenthesisSelectContext;
Class rb_cUnionParenthesisContext;
Class rb_cSimpleSelectContext;
Class rb_cParenthesisSelectContext;
Class rb_cSingleUpdateStatementContext;
Class rb_cMultipleUpdateStatementContext;
Class rb_cExpressionsWithDefaultsContext;
Class rb_cFullColumnNameContext;
Class rb_cTableSourcesContext;
Class rb_cComparisonOperatorContext;
Class rb_cOrderByExpressionContext;
Class rb_cTableSourceContext;
Class rb_cTableSourceNestedContext;
Class rb_cTableSourceItemContext;
Class rb_cJoinPartContext;
Class rb_cTableSourceBaseContext;
Class rb_cSubqueryTableItemContext;
Class rb_cAtomTableItemContext;
Class rb_cIndexHintContext;
Class rb_cTableSourcesItemContext;
Class rb_cIndexHintTypeContext;
Class rb_cInnerJoinContext;
Class rb_cNaturalJoinContext;
Class rb_cOuterJoinContext;
Class rb_cStraightJoinContext;
Class rb_cSelectElementsContext;
Class rb_cSelectSpecContext;
Class rb_cSelectIntoExpressionContext;
Class rb_cFromClauseContext;
Class rb_cSelectElementContext;
Class rb_cSelectExpressionElementContext;
Class rb_cFunctionCallContext;
Class rb_cSelectFunctionElementContext;
Class rb_cSelectStarElementContext;
Class rb_cSelectColumnElementContext;
Class rb_cSelectIntoVariablesContext;
Class rb_cSelectIntoTextFileContext;
Class rb_cSelectIntoDumpFileContext;
Class rb_cGroupByItemContext;
Class rb_cLimitClauseAtomContext;
Class rb_cMysqlVariableContext;
Class rb_cTransactionModeContext;
Class rb_cLockTableElementContext;
Class rb_cSetAutocommitStatementContext;
Class rb_cSetTransactionStatementContext;
Class rb_cTransactionOptionContext;
Class rb_cLockActionContext;
Class rb_cTransactionLevelContext;
Class rb_cMasterOptionContext;
Class rb_cChannelOptionContext;
Class rb_cReplicationFilterContext;
Class rb_cThreadTypeContext;
Class rb_cUntilOptionContext;
Class rb_cConnectionOptionContext;
Class rb_cStringMasterOptionContext;
Class rb_cMasterStringOptionContext;
Class rb_cMasterRealOptionContext;
Class rb_cBoolMasterOptionContext;
Class rb_cMasterBoolOptionContext;
Class rb_cMasterUidListOptionContext;
Class rb_cDecimalMasterOptionContext;
Class rb_cMasterDecimalOptionContext;
Class rb_cWildIgnoreTableReplicationContext;
Class rb_cSimpleStringsContext;
Class rb_cDoTableReplicationContext;
Class rb_cIgnoreTableReplicationContext;
Class rb_cRewriteDbReplicationContext;
Class rb_cTablePairContext;
Class rb_cDoDbReplicationContext;
Class rb_cIgnoreDbReplicationContext;
Class rb_cWildDoTableReplicationContext;
Class rb_cGtidsUntilOptionContext;
Class rb_cGtuidSetContext;
Class rb_cSqlGapsUntilOptionContext;
Class rb_cMasterLogUntilOptionContext;
Class rb_cRelayLogUntilOptionContext;
Class rb_cPluginDirConnectionOptionContext;
Class rb_cUserConnectionOptionContext;
Class rb_cDefaultAuthConnectionOptionContext;
Class rb_cPasswordConnectionOptionContext;
Class rb_cUuidSetContext;
Class rb_cXidContext;
Class rb_cUserVariablesContext;
Class rb_cDeclareVariableContext;
Class rb_cDeclareConditionContext;
Class rb_cDeclareCursorContext;
Class rb_cDeclareHandlerContext;
Class rb_cProcedureSqlStatementContext;
Class rb_cCaseAlternativeContext;
Class rb_cElifAlternativeContext;
Class rb_cCloseCursorContext;
Class rb_cOpenCursorContext;
Class rb_cFetchCursorContext;
Class rb_cHandlerConditionValueContext;
Class rb_cHandlerConditionWarningContext;
Class rb_cHandlerConditionCodeContext;
Class rb_cHandlerConditionNotfoundContext;
Class rb_cHandlerConditionStateContext;
Class rb_cHandlerConditionExceptionContext;
Class rb_cHandlerConditionNameContext;
Class rb_cAlterUserMysqlV56Context;
Class rb_cUserSpecificationContext;
Class rb_cAlterUserMysqlV57Context;
Class rb_cUserAuthOptionContext;
Class rb_cUserPasswordOptionContext;
Class rb_cUserLockOptionContext;
Class rb_cTlsOptionContext;
Class rb_cUserResourceOptionContext;
Class rb_cCreateUserMysqlV57Context;
Class rb_cCreateUserMysqlV56Context;
Class rb_cPrivelegeClauseContext;
Class rb_cPrivilegeLevelContext;
Class rb_cRenameUserClauseContext;
Class rb_cDetailRevokeContext;
Class rb_cShortRevokeContext;
Class rb_cSetPasswordStatementContext;
Class rb_cPasswordFunctionClauseContext;
Class rb_cSimpleAuthOptionContext;
Class rb_cPasswordAuthOptionContext;
Class rb_cStringAuthOptionContext;
Class rb_cAuthPluginContext;
Class rb_cHashAuthOptionContext;
Class rb_cPrivilegeContext;
Class rb_cDefiniteSchemaPrivLevelContext;
Class rb_cDefiniteFullTablePrivLevel2Context;
Class rb_cDottedIdContext;
Class rb_cDefiniteFullTablePrivLevelContext;
Class rb_cGlobalPrivLevelContext;
Class rb_cDefiniteTablePrivLevelContext;
Class rb_cCurrentSchemaPriviLevelContext;
Class rb_cCheckTableOptionContext;
Class rb_cSetTransactionContext;
Class rb_cSetCharsetContext;
Class rb_cSetNamesContext;
Class rb_cSetPasswordContext;
Class rb_cSetAutocommitContext;
Class rb_cSetNewValueInsideTriggerContext;
Class rb_cSetVariableContext;
Class rb_cVariableClauseContext;
Class rb_cShowOpenTablesContext;
Class rb_cShowFilterContext;
Class rb_cShowGlobalInfoContext;
Class rb_cShowGlobalInfoClauseContext;
Class rb_cShowCreateFullIdObjectContext;
Class rb_cShowCreateUserContext;
Class rb_cShowErrorsContext;
Class rb_cShowCountErrorsContext;
Class rb_cShowObjectFilterContext;
Class rb_cShowCommonEntityContext;
Class rb_cShowCreateDbContext;
Class rb_cShowEngineContext;
Class rb_cShowSchemaFilterContext;
Class rb_cShowSchemaEntityContext;
Class rb_cShowIndexesContext;
Class rb_cShowLogEventsContext;
Class rb_cShowMasterLogsContext;
Class rb_cShowGrantsContext;
Class rb_cShowSlaveStatusContext;
Class rb_cShowRoutineContext;
Class rb_cShowProfileContext;
Class rb_cShowProfileTypeContext;
Class rb_cShowColumnsContext;
Class rb_cTableIndexesContext;
Class rb_cFlushOptionContext;
Class rb_cLoadedTableIndexesContext;
Class rb_cTableFlushOptionContext;
Class rb_cFlushTableOptionContext;
Class rb_cChannelFlushOptionContext;
Class rb_cSimpleFlushOptionContext;
Class rb_cDescribeObjectClauseContext;
Class rb_cSignalConditionInformationContext;
Class rb_cDiagnosticsConditionInformationNameContext;
Class rb_cDescribeStatementsContext;
Class rb_cDescribeConnectionContext;
Class rb_cIndexColumnNameContext;
Class rb_cCharsetNameBaseContext;
Class rb_cXuidStringIdContext;
Class rb_cSimpleIdContext;
Class rb_cTransactionLevelBaseContext;
Class rb_cPrivilegesBaseContext;
Class rb_cDataTypeBaseContext;
Class rb_cKeywordsCanBeIdContext;
Class rb_cFunctionNameBaseContext;
Class rb_cBooleanLiteralContext;
Class rb_cHexadecimalLiteralContext;
Class rb_cSpatialDataTypeContext;
Class rb_cCollectionOptionsContext;
Class rb_cCollectionDataTypeContext;
Class rb_cNationalVaryingStringDataTypeContext;
Class rb_cLengthOneDimensionContext;
Class rb_cDimensionDataTypeContext;
Class rb_cLengthTwoDimensionContext;
Class rb_cLengthTwoOptionalDimensionContext;
Class rb_cStringDataTypeContext;
Class rb_cNationalStringDataTypeContext;
Class rb_cSimpleDataTypeContext;
Class rb_cConvertedDataTypeContext;
Class rb_cExpressionOrDefaultContext;
Class rb_cUnaryOperatorContext;
Class rb_cSpecificFunctionContext;
Class rb_cSpecificFunctionCallContext;
Class rb_cPasswordFunctionCallContext;
Class rb_cUdfFunctionCallContext;
Class rb_cFunctionArgsContext;
Class rb_cAggregateWindowedFunctionContext;
Class rb_cAggregateFunctionCallContext;
Class rb_cScalarFunctionNameContext;
Class rb_cScalarFunctionCallContext;
Class rb_cPositionFunctionCallContext;
Class rb_cTrimFunctionCallContext;
Class rb_cSimpleFunctionCallContext;
Class rb_cCharFunctionCallContext;
Class rb_cWeightFunctionCallContext;
Class rb_cLevelsInWeightStringContext;
Class rb_cGetFormatFunctionCallContext;
Class rb_cCaseFunctionCallContext;
Class rb_cCaseFuncAlternativeContext;
Class rb_cFunctionArgContext;
Class rb_cExtractFunctionCallContext;
Class rb_cDataTypeFunctionCallContext;
Class rb_cValuesFunctionCallContext;
Class rb_cSubstrFunctionCallContext;
Class rb_cLevelWeightRangeContext;
Class rb_cLevelWeightListContext;
Class rb_cLevelInWeightListElementContext;
Class rb_cPredicateContext;
Class rb_cIsExpressionContext;
Class rb_cNotExpressionContext;
Class rb_cLogicalExpressionContext;
Class rb_cLogicalOperatorContext;
Class rb_cPredicateExpressionContext;
Class rb_cSoundsLikePredicateContext;
Class rb_cExpressionAtomContext;
Class rb_cExpressionAtomPredicateContext;
Class rb_cInPredicateContext;
Class rb_cSubqueryComparasionPredicateContext;
Class rb_cBetweenPredicateContext;
Class rb_cBinaryComparasionPredicateContext;
Class rb_cIsNullPredicateContext;
Class rb_cLikePredicateContext;
Class rb_cRegexpPredicateContext;
Class rb_cUnaryExpressionAtomContext;
Class rb_cCollateExpressionAtomContext;
Class rb_cSubqueryExpessionAtomContext;
Class rb_cMysqlVariableExpressionAtomContext;
Class rb_cNestedExpressionAtomContext;
Class rb_cNestedRowExpressionAtomContext;
Class rb_cMathOperatorContext;
Class rb_cMathExpressionAtomContext;
Class rb_cIntervalExpressionAtomContext;
Class rb_cExistsExpessionAtomContext;
Class rb_cConstantExpressionAtomContext;
Class rb_cFunctionCallExpressionAtomContext;
Class rb_cBinaryExpressionAtomContext;
Class rb_cFullColumnNameExpressionAtomContext;
Class rb_cBitOperatorContext;
Class rb_cBitExpressionAtomContext;
Class rb_cParseTree;

template <>
Object to_ruby<tree::ParseTree*>(tree::ParseTree* const &x) {
  if (!x) return Nil;
  return Data_Object<tree::ParseTree>(x, rb_cParseTree, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::RootContext*>(MySqlParser::RootContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::RootContext>(x, rb_cRootContext, nullptr, nullptr);
}

template <>
Object to_ruby<RootContextProxy*>(RootContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<RootContextProxy>(x, rb_cRootContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::SqlStatementsContext*>(MySqlParser::SqlStatementsContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::SqlStatementsContext>(x, rb_cSqlStatementsContext, nullptr, nullptr);
}

template <>
Object to_ruby<SqlStatementsContextProxy*>(SqlStatementsContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<SqlStatementsContextProxy>(x, rb_cSqlStatementsContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::SqlStatementContext*>(MySqlParser::SqlStatementContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::SqlStatementContext>(x, rb_cSqlStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<SqlStatementContextProxy*>(SqlStatementContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<SqlStatementContextProxy>(x, rb_cSqlStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::EmptyStatementContext*>(MySqlParser::EmptyStatementContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::EmptyStatementContext>(x, rb_cEmptyStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<EmptyStatementContextProxy*>(EmptyStatementContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<EmptyStatementContextProxy>(x, rb_cEmptyStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::DdlStatementContext*>(MySqlParser::DdlStatementContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::DdlStatementContext>(x, rb_cDdlStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<DdlStatementContextProxy*>(DdlStatementContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<DdlStatementContextProxy>(x, rb_cDdlStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::DmlStatementContext*>(MySqlParser::DmlStatementContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::DmlStatementContext>(x, rb_cDmlStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<DmlStatementContextProxy*>(DmlStatementContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<DmlStatementContextProxy>(x, rb_cDmlStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::TransactionStatementContext*>(MySqlParser::TransactionStatementContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::TransactionStatementContext>(x, rb_cTransactionStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<TransactionStatementContextProxy*>(TransactionStatementContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<TransactionStatementContextProxy>(x, rb_cTransactionStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::ReplicationStatementContext*>(MySqlParser::ReplicationStatementContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::ReplicationStatementContext>(x, rb_cReplicationStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<ReplicationStatementContextProxy*>(ReplicationStatementContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<ReplicationStatementContextProxy>(x, rb_cReplicationStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::PreparedStatementContext*>(MySqlParser::PreparedStatementContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::PreparedStatementContext>(x, rb_cPreparedStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<PreparedStatementContextProxy*>(PreparedStatementContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<PreparedStatementContextProxy>(x, rb_cPreparedStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::AdministrationStatementContext*>(MySqlParser::AdministrationStatementContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::AdministrationStatementContext>(x, rb_cAdministrationStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<AdministrationStatementContextProxy*>(AdministrationStatementContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<AdministrationStatementContextProxy>(x, rb_cAdministrationStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::UtilityStatementContext*>(MySqlParser::UtilityStatementContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::UtilityStatementContext>(x, rb_cUtilityStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<UtilityStatementContextProxy*>(UtilityStatementContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<UtilityStatementContextProxy>(x, rb_cUtilityStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::CreateDatabaseContext*>(MySqlParser::CreateDatabaseContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::CreateDatabaseContext>(x, rb_cCreateDatabaseContext, nullptr, nullptr);
}

template <>
Object to_ruby<CreateDatabaseContextProxy*>(CreateDatabaseContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<CreateDatabaseContextProxy>(x, rb_cCreateDatabaseContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::CreateEventContext*>(MySqlParser::CreateEventContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::CreateEventContext>(x, rb_cCreateEventContext, nullptr, nullptr);
}

template <>
Object to_ruby<CreateEventContextProxy*>(CreateEventContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<CreateEventContextProxy>(x, rb_cCreateEventContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::CreateIndexContext*>(MySqlParser::CreateIndexContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::CreateIndexContext>(x, rb_cCreateIndexContext, nullptr, nullptr);
}

template <>
Object to_ruby<CreateIndexContextProxy*>(CreateIndexContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<CreateIndexContextProxy>(x, rb_cCreateIndexContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::CreateLogfileGroupContext*>(MySqlParser::CreateLogfileGroupContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::CreateLogfileGroupContext>(x, rb_cCreateLogfileGroupContext, nullptr, nullptr);
}

template <>
Object to_ruby<CreateLogfileGroupContextProxy*>(CreateLogfileGroupContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<CreateLogfileGroupContextProxy>(x, rb_cCreateLogfileGroupContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::CreateProcedureContext*>(MySqlParser::CreateProcedureContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::CreateProcedureContext>(x, rb_cCreateProcedureContext, nullptr, nullptr);
}

template <>
Object to_ruby<CreateProcedureContextProxy*>(CreateProcedureContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<CreateProcedureContextProxy>(x, rb_cCreateProcedureContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::CreateFunctionContext*>(MySqlParser::CreateFunctionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::CreateFunctionContext>(x, rb_cCreateFunctionContext, nullptr, nullptr);
}

template <>
Object to_ruby<CreateFunctionContextProxy*>(CreateFunctionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<CreateFunctionContextProxy>(x, rb_cCreateFunctionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::CreateServerContext*>(MySqlParser::CreateServerContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::CreateServerContext>(x, rb_cCreateServerContext, nullptr, nullptr);
}

template <>
Object to_ruby<CreateServerContextProxy*>(CreateServerContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<CreateServerContextProxy>(x, rb_cCreateServerContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::CreateTableContext*>(MySqlParser::CreateTableContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::CreateTableContext>(x, rb_cCreateTableContext, nullptr, nullptr);
}

template <>
Object to_ruby<CreateTableContextProxy*>(CreateTableContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<CreateTableContextProxy>(x, rb_cCreateTableContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::CreateTablespaceInnodbContext*>(MySqlParser::CreateTablespaceInnodbContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::CreateTablespaceInnodbContext>(x, rb_cCreateTablespaceInnodbContext, nullptr, nullptr);
}

template <>
Object to_ruby<CreateTablespaceInnodbContextProxy*>(CreateTablespaceInnodbContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<CreateTablespaceInnodbContextProxy>(x, rb_cCreateTablespaceInnodbContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::CreateTablespaceNdbContext*>(MySqlParser::CreateTablespaceNdbContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::CreateTablespaceNdbContext>(x, rb_cCreateTablespaceNdbContext, nullptr, nullptr);
}

template <>
Object to_ruby<CreateTablespaceNdbContextProxy*>(CreateTablespaceNdbContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<CreateTablespaceNdbContextProxy>(x, rb_cCreateTablespaceNdbContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::CreateTriggerContext*>(MySqlParser::CreateTriggerContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::CreateTriggerContext>(x, rb_cCreateTriggerContext, nullptr, nullptr);
}

template <>
Object to_ruby<CreateTriggerContextProxy*>(CreateTriggerContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<CreateTriggerContextProxy>(x, rb_cCreateTriggerContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::CreateViewContext*>(MySqlParser::CreateViewContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::CreateViewContext>(x, rb_cCreateViewContext, nullptr, nullptr);
}

template <>
Object to_ruby<CreateViewContextProxy*>(CreateViewContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<CreateViewContextProxy>(x, rb_cCreateViewContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::AlterDatabaseContext*>(MySqlParser::AlterDatabaseContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::AlterDatabaseContext>(x, rb_cAlterDatabaseContext, nullptr, nullptr);
}

template <>
Object to_ruby<AlterDatabaseContextProxy*>(AlterDatabaseContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<AlterDatabaseContextProxy>(x, rb_cAlterDatabaseContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::AlterEventContext*>(MySqlParser::AlterEventContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::AlterEventContext>(x, rb_cAlterEventContext, nullptr, nullptr);
}

template <>
Object to_ruby<AlterEventContextProxy*>(AlterEventContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<AlterEventContextProxy>(x, rb_cAlterEventContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::AlterFunctionContext*>(MySqlParser::AlterFunctionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::AlterFunctionContext>(x, rb_cAlterFunctionContext, nullptr, nullptr);
}

template <>
Object to_ruby<AlterFunctionContextProxy*>(AlterFunctionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<AlterFunctionContextProxy>(x, rb_cAlterFunctionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::AlterInstanceContext*>(MySqlParser::AlterInstanceContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::AlterInstanceContext>(x, rb_cAlterInstanceContext, nullptr, nullptr);
}

template <>
Object to_ruby<AlterInstanceContextProxy*>(AlterInstanceContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<AlterInstanceContextProxy>(x, rb_cAlterInstanceContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::AlterLogfileGroupContext*>(MySqlParser::AlterLogfileGroupContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::AlterLogfileGroupContext>(x, rb_cAlterLogfileGroupContext, nullptr, nullptr);
}

template <>
Object to_ruby<AlterLogfileGroupContextProxy*>(AlterLogfileGroupContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<AlterLogfileGroupContextProxy>(x, rb_cAlterLogfileGroupContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::AlterProcedureContext*>(MySqlParser::AlterProcedureContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::AlterProcedureContext>(x, rb_cAlterProcedureContext, nullptr, nullptr);
}

template <>
Object to_ruby<AlterProcedureContextProxy*>(AlterProcedureContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<AlterProcedureContextProxy>(x, rb_cAlterProcedureContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::AlterServerContext*>(MySqlParser::AlterServerContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::AlterServerContext>(x, rb_cAlterServerContext, nullptr, nullptr);
}

template <>
Object to_ruby<AlterServerContextProxy*>(AlterServerContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<AlterServerContextProxy>(x, rb_cAlterServerContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::AlterTableContext*>(MySqlParser::AlterTableContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::AlterTableContext>(x, rb_cAlterTableContext, nullptr, nullptr);
}

template <>
Object to_ruby<AlterTableContextProxy*>(AlterTableContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<AlterTableContextProxy>(x, rb_cAlterTableContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::AlterTablespaceContext*>(MySqlParser::AlterTablespaceContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::AlterTablespaceContext>(x, rb_cAlterTablespaceContext, nullptr, nullptr);
}

template <>
Object to_ruby<AlterTablespaceContextProxy*>(AlterTablespaceContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<AlterTablespaceContextProxy>(x, rb_cAlterTablespaceContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::AlterViewContext*>(MySqlParser::AlterViewContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::AlterViewContext>(x, rb_cAlterViewContext, nullptr, nullptr);
}

template <>
Object to_ruby<AlterViewContextProxy*>(AlterViewContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<AlterViewContextProxy>(x, rb_cAlterViewContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::DropDatabaseContext*>(MySqlParser::DropDatabaseContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::DropDatabaseContext>(x, rb_cDropDatabaseContext, nullptr, nullptr);
}

template <>
Object to_ruby<DropDatabaseContextProxy*>(DropDatabaseContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<DropDatabaseContextProxy>(x, rb_cDropDatabaseContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::DropEventContext*>(MySqlParser::DropEventContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::DropEventContext>(x, rb_cDropEventContext, nullptr, nullptr);
}

template <>
Object to_ruby<DropEventContextProxy*>(DropEventContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<DropEventContextProxy>(x, rb_cDropEventContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::DropIndexContext*>(MySqlParser::DropIndexContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::DropIndexContext>(x, rb_cDropIndexContext, nullptr, nullptr);
}

template <>
Object to_ruby<DropIndexContextProxy*>(DropIndexContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<DropIndexContextProxy>(x, rb_cDropIndexContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::DropLogfileGroupContext*>(MySqlParser::DropLogfileGroupContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::DropLogfileGroupContext>(x, rb_cDropLogfileGroupContext, nullptr, nullptr);
}

template <>
Object to_ruby<DropLogfileGroupContextProxy*>(DropLogfileGroupContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<DropLogfileGroupContextProxy>(x, rb_cDropLogfileGroupContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::DropProcedureContext*>(MySqlParser::DropProcedureContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::DropProcedureContext>(x, rb_cDropProcedureContext, nullptr, nullptr);
}

template <>
Object to_ruby<DropProcedureContextProxy*>(DropProcedureContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<DropProcedureContextProxy>(x, rb_cDropProcedureContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::DropFunctionContext*>(MySqlParser::DropFunctionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::DropFunctionContext>(x, rb_cDropFunctionContext, nullptr, nullptr);
}

template <>
Object to_ruby<DropFunctionContextProxy*>(DropFunctionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<DropFunctionContextProxy>(x, rb_cDropFunctionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::DropServerContext*>(MySqlParser::DropServerContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::DropServerContext>(x, rb_cDropServerContext, nullptr, nullptr);
}

template <>
Object to_ruby<DropServerContextProxy*>(DropServerContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<DropServerContextProxy>(x, rb_cDropServerContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::DropTableContext*>(MySqlParser::DropTableContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::DropTableContext>(x, rb_cDropTableContext, nullptr, nullptr);
}

template <>
Object to_ruby<DropTableContextProxy*>(DropTableContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<DropTableContextProxy>(x, rb_cDropTableContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::DropTablespaceContext*>(MySqlParser::DropTablespaceContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::DropTablespaceContext>(x, rb_cDropTablespaceContext, nullptr, nullptr);
}

template <>
Object to_ruby<DropTablespaceContextProxy*>(DropTablespaceContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<DropTablespaceContextProxy>(x, rb_cDropTablespaceContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::DropTriggerContext*>(MySqlParser::DropTriggerContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::DropTriggerContext>(x, rb_cDropTriggerContext, nullptr, nullptr);
}

template <>
Object to_ruby<DropTriggerContextProxy*>(DropTriggerContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<DropTriggerContextProxy>(x, rb_cDropTriggerContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::DropViewContext*>(MySqlParser::DropViewContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::DropViewContext>(x, rb_cDropViewContext, nullptr, nullptr);
}

template <>
Object to_ruby<DropViewContextProxy*>(DropViewContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<DropViewContextProxy>(x, rb_cDropViewContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::RenameTableContext*>(MySqlParser::RenameTableContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::RenameTableContext>(x, rb_cRenameTableContext, nullptr, nullptr);
}

template <>
Object to_ruby<RenameTableContextProxy*>(RenameTableContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<RenameTableContextProxy>(x, rb_cRenameTableContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::TruncateTableContext*>(MySqlParser::TruncateTableContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::TruncateTableContext>(x, rb_cTruncateTableContext, nullptr, nullptr);
}

template <>
Object to_ruby<TruncateTableContextProxy*>(TruncateTableContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<TruncateTableContextProxy>(x, rb_cTruncateTableContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::SelectStatementContext*>(MySqlParser::SelectStatementContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::SelectStatementContext>(x, rb_cSelectStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<SelectStatementContextProxy*>(SelectStatementContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<SelectStatementContextProxy>(x, rb_cSelectStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::InsertStatementContext*>(MySqlParser::InsertStatementContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::InsertStatementContext>(x, rb_cInsertStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<InsertStatementContextProxy*>(InsertStatementContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<InsertStatementContextProxy>(x, rb_cInsertStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::UpdateStatementContext*>(MySqlParser::UpdateStatementContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::UpdateStatementContext>(x, rb_cUpdateStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<UpdateStatementContextProxy*>(UpdateStatementContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<UpdateStatementContextProxy>(x, rb_cUpdateStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::DeleteStatementContext*>(MySqlParser::DeleteStatementContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::DeleteStatementContext>(x, rb_cDeleteStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<DeleteStatementContextProxy*>(DeleteStatementContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<DeleteStatementContextProxy>(x, rb_cDeleteStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::ReplaceStatementContext*>(MySqlParser::ReplaceStatementContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::ReplaceStatementContext>(x, rb_cReplaceStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<ReplaceStatementContextProxy*>(ReplaceStatementContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<ReplaceStatementContextProxy>(x, rb_cReplaceStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::CallStatementContext*>(MySqlParser::CallStatementContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::CallStatementContext>(x, rb_cCallStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<CallStatementContextProxy*>(CallStatementContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<CallStatementContextProxy>(x, rb_cCallStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::LoadDataStatementContext*>(MySqlParser::LoadDataStatementContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::LoadDataStatementContext>(x, rb_cLoadDataStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<LoadDataStatementContextProxy*>(LoadDataStatementContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<LoadDataStatementContextProxy>(x, rb_cLoadDataStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::LoadXmlStatementContext*>(MySqlParser::LoadXmlStatementContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::LoadXmlStatementContext>(x, rb_cLoadXmlStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<LoadXmlStatementContextProxy*>(LoadXmlStatementContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<LoadXmlStatementContextProxy>(x, rb_cLoadXmlStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::DoStatementContext*>(MySqlParser::DoStatementContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::DoStatementContext>(x, rb_cDoStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<DoStatementContextProxy*>(DoStatementContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<DoStatementContextProxy>(x, rb_cDoStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::HandlerStatementContext*>(MySqlParser::HandlerStatementContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::HandlerStatementContext>(x, rb_cHandlerStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<HandlerStatementContextProxy*>(HandlerStatementContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<HandlerStatementContextProxy>(x, rb_cHandlerStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::StartTransactionContext*>(MySqlParser::StartTransactionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::StartTransactionContext>(x, rb_cStartTransactionContext, nullptr, nullptr);
}

template <>
Object to_ruby<StartTransactionContextProxy*>(StartTransactionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<StartTransactionContextProxy>(x, rb_cStartTransactionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::BeginWorkContext*>(MySqlParser::BeginWorkContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::BeginWorkContext>(x, rb_cBeginWorkContext, nullptr, nullptr);
}

template <>
Object to_ruby<BeginWorkContextProxy*>(BeginWorkContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<BeginWorkContextProxy>(x, rb_cBeginWorkContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::CommitWorkContext*>(MySqlParser::CommitWorkContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::CommitWorkContext>(x, rb_cCommitWorkContext, nullptr, nullptr);
}

template <>
Object to_ruby<CommitWorkContextProxy*>(CommitWorkContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<CommitWorkContextProxy>(x, rb_cCommitWorkContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::RollbackWorkContext*>(MySqlParser::RollbackWorkContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::RollbackWorkContext>(x, rb_cRollbackWorkContext, nullptr, nullptr);
}

template <>
Object to_ruby<RollbackWorkContextProxy*>(RollbackWorkContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<RollbackWorkContextProxy>(x, rb_cRollbackWorkContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::SavepointStatementContext*>(MySqlParser::SavepointStatementContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::SavepointStatementContext>(x, rb_cSavepointStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<SavepointStatementContextProxy*>(SavepointStatementContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<SavepointStatementContextProxy>(x, rb_cSavepointStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::RollbackStatementContext*>(MySqlParser::RollbackStatementContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::RollbackStatementContext>(x, rb_cRollbackStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<RollbackStatementContextProxy*>(RollbackStatementContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<RollbackStatementContextProxy>(x, rb_cRollbackStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::ReleaseStatementContext*>(MySqlParser::ReleaseStatementContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::ReleaseStatementContext>(x, rb_cReleaseStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<ReleaseStatementContextProxy*>(ReleaseStatementContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<ReleaseStatementContextProxy>(x, rb_cReleaseStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::LockTablesContext*>(MySqlParser::LockTablesContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::LockTablesContext>(x, rb_cLockTablesContext, nullptr, nullptr);
}

template <>
Object to_ruby<LockTablesContextProxy*>(LockTablesContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<LockTablesContextProxy>(x, rb_cLockTablesContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::UnlockTablesContext*>(MySqlParser::UnlockTablesContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::UnlockTablesContext>(x, rb_cUnlockTablesContext, nullptr, nullptr);
}

template <>
Object to_ruby<UnlockTablesContextProxy*>(UnlockTablesContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<UnlockTablesContextProxy>(x, rb_cUnlockTablesContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::ChangeMasterContext*>(MySqlParser::ChangeMasterContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::ChangeMasterContext>(x, rb_cChangeMasterContext, nullptr, nullptr);
}

template <>
Object to_ruby<ChangeMasterContextProxy*>(ChangeMasterContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<ChangeMasterContextProxy>(x, rb_cChangeMasterContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::ChangeReplicationFilterContext*>(MySqlParser::ChangeReplicationFilterContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::ChangeReplicationFilterContext>(x, rb_cChangeReplicationFilterContext, nullptr, nullptr);
}

template <>
Object to_ruby<ChangeReplicationFilterContextProxy*>(ChangeReplicationFilterContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<ChangeReplicationFilterContextProxy>(x, rb_cChangeReplicationFilterContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::PurgeBinaryLogsContext*>(MySqlParser::PurgeBinaryLogsContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::PurgeBinaryLogsContext>(x, rb_cPurgeBinaryLogsContext, nullptr, nullptr);
}

template <>
Object to_ruby<PurgeBinaryLogsContextProxy*>(PurgeBinaryLogsContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<PurgeBinaryLogsContextProxy>(x, rb_cPurgeBinaryLogsContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::ResetMasterContext*>(MySqlParser::ResetMasterContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::ResetMasterContext>(x, rb_cResetMasterContext, nullptr, nullptr);
}

template <>
Object to_ruby<ResetMasterContextProxy*>(ResetMasterContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<ResetMasterContextProxy>(x, rb_cResetMasterContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::ResetSlaveContext*>(MySqlParser::ResetSlaveContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::ResetSlaveContext>(x, rb_cResetSlaveContext, nullptr, nullptr);
}

template <>
Object to_ruby<ResetSlaveContextProxy*>(ResetSlaveContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<ResetSlaveContextProxy>(x, rb_cResetSlaveContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::StartSlaveContext*>(MySqlParser::StartSlaveContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::StartSlaveContext>(x, rb_cStartSlaveContext, nullptr, nullptr);
}

template <>
Object to_ruby<StartSlaveContextProxy*>(StartSlaveContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<StartSlaveContextProxy>(x, rb_cStartSlaveContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::StopSlaveContext*>(MySqlParser::StopSlaveContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::StopSlaveContext>(x, rb_cStopSlaveContext, nullptr, nullptr);
}

template <>
Object to_ruby<StopSlaveContextProxy*>(StopSlaveContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<StopSlaveContextProxy>(x, rb_cStopSlaveContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::StartGroupReplicationContext*>(MySqlParser::StartGroupReplicationContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::StartGroupReplicationContext>(x, rb_cStartGroupReplicationContext, nullptr, nullptr);
}

template <>
Object to_ruby<StartGroupReplicationContextProxy*>(StartGroupReplicationContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<StartGroupReplicationContextProxy>(x, rb_cStartGroupReplicationContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::StopGroupReplicationContext*>(MySqlParser::StopGroupReplicationContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::StopGroupReplicationContext>(x, rb_cStopGroupReplicationContext, nullptr, nullptr);
}

template <>
Object to_ruby<StopGroupReplicationContextProxy*>(StopGroupReplicationContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<StopGroupReplicationContextProxy>(x, rb_cStopGroupReplicationContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::XaStartTransactionContext*>(MySqlParser::XaStartTransactionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::XaStartTransactionContext>(x, rb_cXaStartTransactionContext, nullptr, nullptr);
}

template <>
Object to_ruby<XaStartTransactionContextProxy*>(XaStartTransactionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<XaStartTransactionContextProxy>(x, rb_cXaStartTransactionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::XaEndTransactionContext*>(MySqlParser::XaEndTransactionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::XaEndTransactionContext>(x, rb_cXaEndTransactionContext, nullptr, nullptr);
}

template <>
Object to_ruby<XaEndTransactionContextProxy*>(XaEndTransactionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<XaEndTransactionContextProxy>(x, rb_cXaEndTransactionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::XaPrepareStatementContext*>(MySqlParser::XaPrepareStatementContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::XaPrepareStatementContext>(x, rb_cXaPrepareStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<XaPrepareStatementContextProxy*>(XaPrepareStatementContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<XaPrepareStatementContextProxy>(x, rb_cXaPrepareStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::XaCommitWorkContext*>(MySqlParser::XaCommitWorkContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::XaCommitWorkContext>(x, rb_cXaCommitWorkContext, nullptr, nullptr);
}

template <>
Object to_ruby<XaCommitWorkContextProxy*>(XaCommitWorkContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<XaCommitWorkContextProxy>(x, rb_cXaCommitWorkContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::XaRollbackWorkContext*>(MySqlParser::XaRollbackWorkContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::XaRollbackWorkContext>(x, rb_cXaRollbackWorkContext, nullptr, nullptr);
}

template <>
Object to_ruby<XaRollbackWorkContextProxy*>(XaRollbackWorkContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<XaRollbackWorkContextProxy>(x, rb_cXaRollbackWorkContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::XaRecoverWorkContext*>(MySqlParser::XaRecoverWorkContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::XaRecoverWorkContext>(x, rb_cXaRecoverWorkContext, nullptr, nullptr);
}

template <>
Object to_ruby<XaRecoverWorkContextProxy*>(XaRecoverWorkContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<XaRecoverWorkContextProxy>(x, rb_cXaRecoverWorkContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::PrepareStatementContext*>(MySqlParser::PrepareStatementContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::PrepareStatementContext>(x, rb_cPrepareStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<PrepareStatementContextProxy*>(PrepareStatementContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<PrepareStatementContextProxy>(x, rb_cPrepareStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::ExecuteStatementContext*>(MySqlParser::ExecuteStatementContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::ExecuteStatementContext>(x, rb_cExecuteStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<ExecuteStatementContextProxy*>(ExecuteStatementContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<ExecuteStatementContextProxy>(x, rb_cExecuteStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::DeallocatePrepareContext*>(MySqlParser::DeallocatePrepareContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::DeallocatePrepareContext>(x, rb_cDeallocatePrepareContext, nullptr, nullptr);
}

template <>
Object to_ruby<DeallocatePrepareContextProxy*>(DeallocatePrepareContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<DeallocatePrepareContextProxy>(x, rb_cDeallocatePrepareContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::CompoundStatementContext*>(MySqlParser::CompoundStatementContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::CompoundStatementContext>(x, rb_cCompoundStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<CompoundStatementContextProxy*>(CompoundStatementContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<CompoundStatementContextProxy>(x, rb_cCompoundStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::BlockStatementContext*>(MySqlParser::BlockStatementContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::BlockStatementContext>(x, rb_cBlockStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<BlockStatementContextProxy*>(BlockStatementContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<BlockStatementContextProxy>(x, rb_cBlockStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::CaseStatementContext*>(MySqlParser::CaseStatementContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::CaseStatementContext>(x, rb_cCaseStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<CaseStatementContextProxy*>(CaseStatementContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<CaseStatementContextProxy>(x, rb_cCaseStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::IfStatementContext*>(MySqlParser::IfStatementContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::IfStatementContext>(x, rb_cIfStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<IfStatementContextProxy*>(IfStatementContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<IfStatementContextProxy>(x, rb_cIfStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::LeaveStatementContext*>(MySqlParser::LeaveStatementContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::LeaveStatementContext>(x, rb_cLeaveStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<LeaveStatementContextProxy*>(LeaveStatementContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<LeaveStatementContextProxy>(x, rb_cLeaveStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::LoopStatementContext*>(MySqlParser::LoopStatementContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::LoopStatementContext>(x, rb_cLoopStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<LoopStatementContextProxy*>(LoopStatementContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<LoopStatementContextProxy>(x, rb_cLoopStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::RepeatStatementContext*>(MySqlParser::RepeatStatementContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::RepeatStatementContext>(x, rb_cRepeatStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<RepeatStatementContextProxy*>(RepeatStatementContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<RepeatStatementContextProxy>(x, rb_cRepeatStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::WhileStatementContext*>(MySqlParser::WhileStatementContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::WhileStatementContext>(x, rb_cWhileStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<WhileStatementContextProxy*>(WhileStatementContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<WhileStatementContextProxy>(x, rb_cWhileStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::IterateStatementContext*>(MySqlParser::IterateStatementContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::IterateStatementContext>(x, rb_cIterateStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<IterateStatementContextProxy*>(IterateStatementContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<IterateStatementContextProxy>(x, rb_cIterateStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::ReturnStatementContext*>(MySqlParser::ReturnStatementContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::ReturnStatementContext>(x, rb_cReturnStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<ReturnStatementContextProxy*>(ReturnStatementContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<ReturnStatementContextProxy>(x, rb_cReturnStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::CursorStatementContext*>(MySqlParser::CursorStatementContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::CursorStatementContext>(x, rb_cCursorStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<CursorStatementContextProxy*>(CursorStatementContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<CursorStatementContextProxy>(x, rb_cCursorStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::AlterUserContext*>(MySqlParser::AlterUserContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::AlterUserContext>(x, rb_cAlterUserContext, nullptr, nullptr);
}

template <>
Object to_ruby<AlterUserContextProxy*>(AlterUserContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<AlterUserContextProxy>(x, rb_cAlterUserContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::CreateUserContext*>(MySqlParser::CreateUserContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::CreateUserContext>(x, rb_cCreateUserContext, nullptr, nullptr);
}

template <>
Object to_ruby<CreateUserContextProxy*>(CreateUserContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<CreateUserContextProxy>(x, rb_cCreateUserContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::DropUserContext*>(MySqlParser::DropUserContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::DropUserContext>(x, rb_cDropUserContext, nullptr, nullptr);
}

template <>
Object to_ruby<DropUserContextProxy*>(DropUserContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<DropUserContextProxy>(x, rb_cDropUserContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::GrantStatementContext*>(MySqlParser::GrantStatementContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::GrantStatementContext>(x, rb_cGrantStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<GrantStatementContextProxy*>(GrantStatementContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<GrantStatementContextProxy>(x, rb_cGrantStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::GrantProxyContext*>(MySqlParser::GrantProxyContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::GrantProxyContext>(x, rb_cGrantProxyContext, nullptr, nullptr);
}

template <>
Object to_ruby<GrantProxyContextProxy*>(GrantProxyContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<GrantProxyContextProxy>(x, rb_cGrantProxyContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::RenameUserContext*>(MySqlParser::RenameUserContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::RenameUserContext>(x, rb_cRenameUserContext, nullptr, nullptr);
}

template <>
Object to_ruby<RenameUserContextProxy*>(RenameUserContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<RenameUserContextProxy>(x, rb_cRenameUserContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::RevokeStatementContext*>(MySqlParser::RevokeStatementContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::RevokeStatementContext>(x, rb_cRevokeStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<RevokeStatementContextProxy*>(RevokeStatementContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<RevokeStatementContextProxy>(x, rb_cRevokeStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::RevokeProxyContext*>(MySqlParser::RevokeProxyContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::RevokeProxyContext>(x, rb_cRevokeProxyContext, nullptr, nullptr);
}

template <>
Object to_ruby<RevokeProxyContextProxy*>(RevokeProxyContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<RevokeProxyContextProxy>(x, rb_cRevokeProxyContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::AnalyzeTableContext*>(MySqlParser::AnalyzeTableContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::AnalyzeTableContext>(x, rb_cAnalyzeTableContext, nullptr, nullptr);
}

template <>
Object to_ruby<AnalyzeTableContextProxy*>(AnalyzeTableContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<AnalyzeTableContextProxy>(x, rb_cAnalyzeTableContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::CheckTableContext*>(MySqlParser::CheckTableContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::CheckTableContext>(x, rb_cCheckTableContext, nullptr, nullptr);
}

template <>
Object to_ruby<CheckTableContextProxy*>(CheckTableContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<CheckTableContextProxy>(x, rb_cCheckTableContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::ChecksumTableContext*>(MySqlParser::ChecksumTableContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::ChecksumTableContext>(x, rb_cChecksumTableContext, nullptr, nullptr);
}

template <>
Object to_ruby<ChecksumTableContextProxy*>(ChecksumTableContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<ChecksumTableContextProxy>(x, rb_cChecksumTableContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::OptimizeTableContext*>(MySqlParser::OptimizeTableContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::OptimizeTableContext>(x, rb_cOptimizeTableContext, nullptr, nullptr);
}

template <>
Object to_ruby<OptimizeTableContextProxy*>(OptimizeTableContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<OptimizeTableContextProxy>(x, rb_cOptimizeTableContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::RepairTableContext*>(MySqlParser::RepairTableContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::RepairTableContext>(x, rb_cRepairTableContext, nullptr, nullptr);
}

template <>
Object to_ruby<RepairTableContextProxy*>(RepairTableContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<RepairTableContextProxy>(x, rb_cRepairTableContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::CreateUdfunctionContext*>(MySqlParser::CreateUdfunctionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::CreateUdfunctionContext>(x, rb_cCreateUdfunctionContext, nullptr, nullptr);
}

template <>
Object to_ruby<CreateUdfunctionContextProxy*>(CreateUdfunctionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<CreateUdfunctionContextProxy>(x, rb_cCreateUdfunctionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::InstallPluginContext*>(MySqlParser::InstallPluginContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::InstallPluginContext>(x, rb_cInstallPluginContext, nullptr, nullptr);
}

template <>
Object to_ruby<InstallPluginContextProxy*>(InstallPluginContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<InstallPluginContextProxy>(x, rb_cInstallPluginContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::UninstallPluginContext*>(MySqlParser::UninstallPluginContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::UninstallPluginContext>(x, rb_cUninstallPluginContext, nullptr, nullptr);
}

template <>
Object to_ruby<UninstallPluginContextProxy*>(UninstallPluginContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<UninstallPluginContextProxy>(x, rb_cUninstallPluginContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::SetStatementContext*>(MySqlParser::SetStatementContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::SetStatementContext>(x, rb_cSetStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<SetStatementContextProxy*>(SetStatementContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<SetStatementContextProxy>(x, rb_cSetStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::ShowStatementContext*>(MySqlParser::ShowStatementContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::ShowStatementContext>(x, rb_cShowStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<ShowStatementContextProxy*>(ShowStatementContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<ShowStatementContextProxy>(x, rb_cShowStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::BinlogStatementContext*>(MySqlParser::BinlogStatementContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::BinlogStatementContext>(x, rb_cBinlogStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<BinlogStatementContextProxy*>(BinlogStatementContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<BinlogStatementContextProxy>(x, rb_cBinlogStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::CacheIndexStatementContext*>(MySqlParser::CacheIndexStatementContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::CacheIndexStatementContext>(x, rb_cCacheIndexStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<CacheIndexStatementContextProxy*>(CacheIndexStatementContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<CacheIndexStatementContextProxy>(x, rb_cCacheIndexStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::FlushStatementContext*>(MySqlParser::FlushStatementContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::FlushStatementContext>(x, rb_cFlushStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<FlushStatementContextProxy*>(FlushStatementContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<FlushStatementContextProxy>(x, rb_cFlushStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::KillStatementContext*>(MySqlParser::KillStatementContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::KillStatementContext>(x, rb_cKillStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<KillStatementContextProxy*>(KillStatementContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<KillStatementContextProxy>(x, rb_cKillStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::LoadIndexIntoCacheContext*>(MySqlParser::LoadIndexIntoCacheContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::LoadIndexIntoCacheContext>(x, rb_cLoadIndexIntoCacheContext, nullptr, nullptr);
}

template <>
Object to_ruby<LoadIndexIntoCacheContextProxy*>(LoadIndexIntoCacheContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<LoadIndexIntoCacheContextProxy>(x, rb_cLoadIndexIntoCacheContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::ResetStatementContext*>(MySqlParser::ResetStatementContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::ResetStatementContext>(x, rb_cResetStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<ResetStatementContextProxy*>(ResetStatementContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<ResetStatementContextProxy>(x, rb_cResetStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::ShutdownStatementContext*>(MySqlParser::ShutdownStatementContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::ShutdownStatementContext>(x, rb_cShutdownStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<ShutdownStatementContextProxy*>(ShutdownStatementContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<ShutdownStatementContextProxy>(x, rb_cShutdownStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::SimpleDescribeStatementContext*>(MySqlParser::SimpleDescribeStatementContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::SimpleDescribeStatementContext>(x, rb_cSimpleDescribeStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<SimpleDescribeStatementContextProxy*>(SimpleDescribeStatementContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<SimpleDescribeStatementContextProxy>(x, rb_cSimpleDescribeStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::FullDescribeStatementContext*>(MySqlParser::FullDescribeStatementContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::FullDescribeStatementContext>(x, rb_cFullDescribeStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<FullDescribeStatementContextProxy*>(FullDescribeStatementContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<FullDescribeStatementContextProxy>(x, rb_cFullDescribeStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::HelpStatementContext*>(MySqlParser::HelpStatementContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::HelpStatementContext>(x, rb_cHelpStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<HelpStatementContextProxy*>(HelpStatementContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<HelpStatementContextProxy>(x, rb_cHelpStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::UseStatementContext*>(MySqlParser::UseStatementContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::UseStatementContext>(x, rb_cUseStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<UseStatementContextProxy*>(UseStatementContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<UseStatementContextProxy>(x, rb_cUseStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::SignalStatementContext*>(MySqlParser::SignalStatementContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::SignalStatementContext>(x, rb_cSignalStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<SignalStatementContextProxy*>(SignalStatementContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<SignalStatementContextProxy>(x, rb_cSignalStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::ResignalStatementContext*>(MySqlParser::ResignalStatementContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::ResignalStatementContext>(x, rb_cResignalStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<ResignalStatementContextProxy*>(ResignalStatementContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<ResignalStatementContextProxy>(x, rb_cResignalStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::DiagnosticsStatementContext*>(MySqlParser::DiagnosticsStatementContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::DiagnosticsStatementContext>(x, rb_cDiagnosticsStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<DiagnosticsStatementContextProxy*>(DiagnosticsStatementContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<DiagnosticsStatementContextProxy>(x, rb_cDiagnosticsStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::UidContext*>(MySqlParser::UidContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::UidContext>(x, rb_cUidContext, nullptr, nullptr);
}

template <>
Object to_ruby<UidContextProxy*>(UidContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<UidContextProxy>(x, rb_cUidContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::IfNotExistsContext*>(MySqlParser::IfNotExistsContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::IfNotExistsContext>(x, rb_cIfNotExistsContext, nullptr, nullptr);
}

template <>
Object to_ruby<IfNotExistsContextProxy*>(IfNotExistsContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<IfNotExistsContextProxy>(x, rb_cIfNotExistsContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::CreateDatabaseOptionContext*>(MySqlParser::CreateDatabaseOptionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::CreateDatabaseOptionContext>(x, rb_cCreateDatabaseOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<CreateDatabaseOptionContextProxy*>(CreateDatabaseOptionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<CreateDatabaseOptionContextProxy>(x, rb_cCreateDatabaseOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::FullIdContext*>(MySqlParser::FullIdContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::FullIdContext>(x, rb_cFullIdContext, nullptr, nullptr);
}

template <>
Object to_ruby<FullIdContextProxy*>(FullIdContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<FullIdContextProxy>(x, rb_cFullIdContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::ScheduleExpressionContext*>(MySqlParser::ScheduleExpressionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::ScheduleExpressionContext>(x, rb_cScheduleExpressionContext, nullptr, nullptr);
}

template <>
Object to_ruby<ScheduleExpressionContextProxy*>(ScheduleExpressionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<ScheduleExpressionContextProxy>(x, rb_cScheduleExpressionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::RoutineBodyContext*>(MySqlParser::RoutineBodyContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::RoutineBodyContext>(x, rb_cRoutineBodyContext, nullptr, nullptr);
}

template <>
Object to_ruby<RoutineBodyContextProxy*>(RoutineBodyContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<RoutineBodyContextProxy>(x, rb_cRoutineBodyContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::OwnerStatementContext*>(MySqlParser::OwnerStatementContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::OwnerStatementContext>(x, rb_cOwnerStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<OwnerStatementContextProxy*>(OwnerStatementContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<OwnerStatementContextProxy>(x, rb_cOwnerStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::EnableTypeContext*>(MySqlParser::EnableTypeContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::EnableTypeContext>(x, rb_cEnableTypeContext, nullptr, nullptr);
}

template <>
Object to_ruby<EnableTypeContextProxy*>(EnableTypeContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<EnableTypeContextProxy>(x, rb_cEnableTypeContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::TableNameContext*>(MySqlParser::TableNameContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::TableNameContext>(x, rb_cTableNameContext, nullptr, nullptr);
}

template <>
Object to_ruby<TableNameContextProxy*>(TableNameContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<TableNameContextProxy>(x, rb_cTableNameContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::IndexColumnNamesContext*>(MySqlParser::IndexColumnNamesContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::IndexColumnNamesContext>(x, rb_cIndexColumnNamesContext, nullptr, nullptr);
}

template <>
Object to_ruby<IndexColumnNamesContextProxy*>(IndexColumnNamesContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<IndexColumnNamesContextProxy>(x, rb_cIndexColumnNamesContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::IndexTypeContext*>(MySqlParser::IndexTypeContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::IndexTypeContext>(x, rb_cIndexTypeContext, nullptr, nullptr);
}

template <>
Object to_ruby<IndexTypeContextProxy*>(IndexTypeContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<IndexTypeContextProxy>(x, rb_cIndexTypeContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::IndexOptionContext*>(MySqlParser::IndexOptionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::IndexOptionContext>(x, rb_cIndexOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<IndexOptionContextProxy*>(IndexOptionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<IndexOptionContextProxy>(x, rb_cIndexOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::EngineNameContext*>(MySqlParser::EngineNameContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::EngineNameContext>(x, rb_cEngineNameContext, nullptr, nullptr);
}

template <>
Object to_ruby<EngineNameContextProxy*>(EngineNameContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<EngineNameContextProxy>(x, rb_cEngineNameContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::FileSizeLiteralContext*>(MySqlParser::FileSizeLiteralContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::FileSizeLiteralContext>(x, rb_cFileSizeLiteralContext, nullptr, nullptr);
}

template <>
Object to_ruby<FileSizeLiteralContextProxy*>(FileSizeLiteralContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<FileSizeLiteralContextProxy>(x, rb_cFileSizeLiteralContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::ProcedureParameterContext*>(MySqlParser::ProcedureParameterContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::ProcedureParameterContext>(x, rb_cProcedureParameterContext, nullptr, nullptr);
}

template <>
Object to_ruby<ProcedureParameterContextProxy*>(ProcedureParameterContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<ProcedureParameterContextProxy>(x, rb_cProcedureParameterContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::RoutineOptionContext*>(MySqlParser::RoutineOptionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::RoutineOptionContext>(x, rb_cRoutineOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<RoutineOptionContextProxy*>(RoutineOptionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<RoutineOptionContextProxy>(x, rb_cRoutineOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::DataTypeContext*>(MySqlParser::DataTypeContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::DataTypeContext>(x, rb_cDataTypeContext, nullptr, nullptr);
}

template <>
Object to_ruby<DataTypeContextProxy*>(DataTypeContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<DataTypeContextProxy>(x, rb_cDataTypeContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::FunctionParameterContext*>(MySqlParser::FunctionParameterContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::FunctionParameterContext>(x, rb_cFunctionParameterContext, nullptr, nullptr);
}

template <>
Object to_ruby<FunctionParameterContextProxy*>(FunctionParameterContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<FunctionParameterContextProxy>(x, rb_cFunctionParameterContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::ServerOptionContext*>(MySqlParser::ServerOptionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::ServerOptionContext>(x, rb_cServerOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<ServerOptionContextProxy*>(ServerOptionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<ServerOptionContextProxy>(x, rb_cServerOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::CopyCreateTableContext*>(MySqlParser::CopyCreateTableContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::CopyCreateTableContext>(x, rb_cCopyCreateTableContext, nullptr, nullptr);
}

template <>
Object to_ruby<CopyCreateTableContextProxy*>(CopyCreateTableContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<CopyCreateTableContextProxy>(x, rb_cCopyCreateTableContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::ColumnCreateTableContext*>(MySqlParser::ColumnCreateTableContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::ColumnCreateTableContext>(x, rb_cColumnCreateTableContext, nullptr, nullptr);
}

template <>
Object to_ruby<ColumnCreateTableContextProxy*>(ColumnCreateTableContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<ColumnCreateTableContextProxy>(x, rb_cColumnCreateTableContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::CreateDefinitionsContext*>(MySqlParser::CreateDefinitionsContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::CreateDefinitionsContext>(x, rb_cCreateDefinitionsContext, nullptr, nullptr);
}

template <>
Object to_ruby<CreateDefinitionsContextProxy*>(CreateDefinitionsContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<CreateDefinitionsContextProxy>(x, rb_cCreateDefinitionsContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::TableOptionContext*>(MySqlParser::TableOptionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::TableOptionContext>(x, rb_cTableOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<TableOptionContextProxy*>(TableOptionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<TableOptionContextProxy>(x, rb_cTableOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::PartitionDefinitionsContext*>(MySqlParser::PartitionDefinitionsContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::PartitionDefinitionsContext>(x, rb_cPartitionDefinitionsContext, nullptr, nullptr);
}

template <>
Object to_ruby<PartitionDefinitionsContextProxy*>(PartitionDefinitionsContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<PartitionDefinitionsContextProxy>(x, rb_cPartitionDefinitionsContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::QueryCreateTableContext*>(MySqlParser::QueryCreateTableContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::QueryCreateTableContext>(x, rb_cQueryCreateTableContext, nullptr, nullptr);
}

template <>
Object to_ruby<QueryCreateTableContextProxy*>(QueryCreateTableContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<QueryCreateTableContextProxy>(x, rb_cQueryCreateTableContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::UidListContext*>(MySqlParser::UidListContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::UidListContext>(x, rb_cUidListContext, nullptr, nullptr);
}

template <>
Object to_ruby<UidListContextProxy*>(UidListContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<UidListContextProxy>(x, rb_cUidListContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::CharsetNameContext*>(MySqlParser::CharsetNameContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::CharsetNameContext>(x, rb_cCharsetNameContext, nullptr, nullptr);
}

template <>
Object to_ruby<CharsetNameContextProxy*>(CharsetNameContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<CharsetNameContextProxy>(x, rb_cCharsetNameContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::CollationNameContext*>(MySqlParser::CollationNameContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::CollationNameContext>(x, rb_cCollationNameContext, nullptr, nullptr);
}

template <>
Object to_ruby<CollationNameContextProxy*>(CollationNameContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<CollationNameContextProxy>(x, rb_cCollationNameContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::UserNameContext*>(MySqlParser::UserNameContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::UserNameContext>(x, rb_cUserNameContext, nullptr, nullptr);
}

template <>
Object to_ruby<UserNameContextProxy*>(UserNameContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<UserNameContextProxy>(x, rb_cUserNameContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::PreciseScheduleContext*>(MySqlParser::PreciseScheduleContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::PreciseScheduleContext>(x, rb_cPreciseScheduleContext, nullptr, nullptr);
}

template <>
Object to_ruby<PreciseScheduleContextProxy*>(PreciseScheduleContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<PreciseScheduleContextProxy>(x, rb_cPreciseScheduleContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::TimestampValueContext*>(MySqlParser::TimestampValueContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::TimestampValueContext>(x, rb_cTimestampValueContext, nullptr, nullptr);
}

template <>
Object to_ruby<TimestampValueContextProxy*>(TimestampValueContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<TimestampValueContextProxy>(x, rb_cTimestampValueContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::IntervalExprContext*>(MySqlParser::IntervalExprContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::IntervalExprContext>(x, rb_cIntervalExprContext, nullptr, nullptr);
}

template <>
Object to_ruby<IntervalExprContextProxy*>(IntervalExprContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<IntervalExprContextProxy>(x, rb_cIntervalExprContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::IntervalScheduleContext*>(MySqlParser::IntervalScheduleContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::IntervalScheduleContext>(x, rb_cIntervalScheduleContext, nullptr, nullptr);
}

template <>
Object to_ruby<IntervalScheduleContextProxy*>(IntervalScheduleContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<IntervalScheduleContextProxy>(x, rb_cIntervalScheduleContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::IntervalTypeContext*>(MySqlParser::IntervalTypeContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::IntervalTypeContext>(x, rb_cIntervalTypeContext, nullptr, nullptr);
}

template <>
Object to_ruby<IntervalTypeContextProxy*>(IntervalTypeContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<IntervalTypeContextProxy>(x, rb_cIntervalTypeContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::DecimalLiteralContext*>(MySqlParser::DecimalLiteralContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::DecimalLiteralContext>(x, rb_cDecimalLiteralContext, nullptr, nullptr);
}

template <>
Object to_ruby<DecimalLiteralContextProxy*>(DecimalLiteralContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<DecimalLiteralContextProxy>(x, rb_cDecimalLiteralContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::ExpressionContext*>(MySqlParser::ExpressionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::ExpressionContext>(x, rb_cExpressionContext, nullptr, nullptr);
}

template <>
Object to_ruby<ExpressionContextProxy*>(ExpressionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<ExpressionContextProxy>(x, rb_cExpressionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::StringLiteralContext*>(MySqlParser::StringLiteralContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::StringLiteralContext>(x, rb_cStringLiteralContext, nullptr, nullptr);
}

template <>
Object to_ruby<StringLiteralContextProxy*>(StringLiteralContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<StringLiteralContextProxy>(x, rb_cStringLiteralContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::IntervalTypeBaseContext*>(MySqlParser::IntervalTypeBaseContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::IntervalTypeBaseContext>(x, rb_cIntervalTypeBaseContext, nullptr, nullptr);
}

template <>
Object to_ruby<IntervalTypeBaseContextProxy*>(IntervalTypeBaseContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<IntervalTypeBaseContextProxy>(x, rb_cIntervalTypeBaseContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::RoutineBehaviorContext*>(MySqlParser::RoutineBehaviorContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::RoutineBehaviorContext>(x, rb_cRoutineBehaviorContext, nullptr, nullptr);
}

template <>
Object to_ruby<RoutineBehaviorContextProxy*>(RoutineBehaviorContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<RoutineBehaviorContextProxy>(x, rb_cRoutineBehaviorContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::RoutineLanguageContext*>(MySqlParser::RoutineLanguageContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::RoutineLanguageContext>(x, rb_cRoutineLanguageContext, nullptr, nullptr);
}

template <>
Object to_ruby<RoutineLanguageContextProxy*>(RoutineLanguageContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<RoutineLanguageContextProxy>(x, rb_cRoutineLanguageContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::RoutineCommentContext*>(MySqlParser::RoutineCommentContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::RoutineCommentContext>(x, rb_cRoutineCommentContext, nullptr, nullptr);
}

template <>
Object to_ruby<RoutineCommentContextProxy*>(RoutineCommentContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<RoutineCommentContextProxy>(x, rb_cRoutineCommentContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::RoutineSecurityContext*>(MySqlParser::RoutineSecurityContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::RoutineSecurityContext>(x, rb_cRoutineSecurityContext, nullptr, nullptr);
}

template <>
Object to_ruby<RoutineSecurityContextProxy*>(RoutineSecurityContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<RoutineSecurityContextProxy>(x, rb_cRoutineSecurityContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::RoutineDataContext*>(MySqlParser::RoutineDataContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::RoutineDataContext>(x, rb_cRoutineDataContext, nullptr, nullptr);
}

template <>
Object to_ruby<RoutineDataContextProxy*>(RoutineDataContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<RoutineDataContextProxy>(x, rb_cRoutineDataContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::CreateDefinitionContext*>(MySqlParser::CreateDefinitionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::CreateDefinitionContext>(x, rb_cCreateDefinitionContext, nullptr, nullptr);
}

template <>
Object to_ruby<CreateDefinitionContextProxy*>(CreateDefinitionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<CreateDefinitionContextProxy>(x, rb_cCreateDefinitionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::ColumnDeclarationContext*>(MySqlParser::ColumnDeclarationContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::ColumnDeclarationContext>(x, rb_cColumnDeclarationContext, nullptr, nullptr);
}

template <>
Object to_ruby<ColumnDeclarationContextProxy*>(ColumnDeclarationContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<ColumnDeclarationContextProxy>(x, rb_cColumnDeclarationContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::ColumnDefinitionContext*>(MySqlParser::ColumnDefinitionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::ColumnDefinitionContext>(x, rb_cColumnDefinitionContext, nullptr, nullptr);
}

template <>
Object to_ruby<ColumnDefinitionContextProxy*>(ColumnDefinitionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<ColumnDefinitionContextProxy>(x, rb_cColumnDefinitionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::TableConstraintContext*>(MySqlParser::TableConstraintContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::TableConstraintContext>(x, rb_cTableConstraintContext, nullptr, nullptr);
}

template <>
Object to_ruby<TableConstraintContextProxy*>(TableConstraintContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<TableConstraintContextProxy>(x, rb_cTableConstraintContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::ConstraintDeclarationContext*>(MySqlParser::ConstraintDeclarationContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::ConstraintDeclarationContext>(x, rb_cConstraintDeclarationContext, nullptr, nullptr);
}

template <>
Object to_ruby<ConstraintDeclarationContextProxy*>(ConstraintDeclarationContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<ConstraintDeclarationContextProxy>(x, rb_cConstraintDeclarationContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::IndexColumnDefinitionContext*>(MySqlParser::IndexColumnDefinitionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::IndexColumnDefinitionContext>(x, rb_cIndexColumnDefinitionContext, nullptr, nullptr);
}

template <>
Object to_ruby<IndexColumnDefinitionContextProxy*>(IndexColumnDefinitionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<IndexColumnDefinitionContextProxy>(x, rb_cIndexColumnDefinitionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::IndexDeclarationContext*>(MySqlParser::IndexDeclarationContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::IndexDeclarationContext>(x, rb_cIndexDeclarationContext, nullptr, nullptr);
}

template <>
Object to_ruby<IndexDeclarationContextProxy*>(IndexDeclarationContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<IndexDeclarationContextProxy>(x, rb_cIndexDeclarationContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::ColumnConstraintContext*>(MySqlParser::ColumnConstraintContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::ColumnConstraintContext>(x, rb_cColumnConstraintContext, nullptr, nullptr);
}

template <>
Object to_ruby<ColumnConstraintContextProxy*>(ColumnConstraintContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<ColumnConstraintContextProxy>(x, rb_cColumnConstraintContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::StorageColumnConstraintContext*>(MySqlParser::StorageColumnConstraintContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::StorageColumnConstraintContext>(x, rb_cStorageColumnConstraintContext, nullptr, nullptr);
}

template <>
Object to_ruby<StorageColumnConstraintContextProxy*>(StorageColumnConstraintContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<StorageColumnConstraintContextProxy>(x, rb_cStorageColumnConstraintContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::FormatColumnConstraintContext*>(MySqlParser::FormatColumnConstraintContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::FormatColumnConstraintContext>(x, rb_cFormatColumnConstraintContext, nullptr, nullptr);
}

template <>
Object to_ruby<FormatColumnConstraintContextProxy*>(FormatColumnConstraintContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<FormatColumnConstraintContextProxy>(x, rb_cFormatColumnConstraintContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::CollateColumnConstraintContext*>(MySqlParser::CollateColumnConstraintContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::CollateColumnConstraintContext>(x, rb_cCollateColumnConstraintContext, nullptr, nullptr);
}

template <>
Object to_ruby<CollateColumnConstraintContextProxy*>(CollateColumnConstraintContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<CollateColumnConstraintContextProxy>(x, rb_cCollateColumnConstraintContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::AutoIncrementColumnConstraintContext*>(MySqlParser::AutoIncrementColumnConstraintContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::AutoIncrementColumnConstraintContext>(x, rb_cAutoIncrementColumnConstraintContext, nullptr, nullptr);
}

template <>
Object to_ruby<AutoIncrementColumnConstraintContextProxy*>(AutoIncrementColumnConstraintContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<AutoIncrementColumnConstraintContextProxy>(x, rb_cAutoIncrementColumnConstraintContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::CurrentTimestampContext*>(MySqlParser::CurrentTimestampContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::CurrentTimestampContext>(x, rb_cCurrentTimestampContext, nullptr, nullptr);
}

template <>
Object to_ruby<CurrentTimestampContextProxy*>(CurrentTimestampContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<CurrentTimestampContextProxy>(x, rb_cCurrentTimestampContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::CommentColumnConstraintContext*>(MySqlParser::CommentColumnConstraintContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::CommentColumnConstraintContext>(x, rb_cCommentColumnConstraintContext, nullptr, nullptr);
}

template <>
Object to_ruby<CommentColumnConstraintContextProxy*>(CommentColumnConstraintContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<CommentColumnConstraintContextProxy>(x, rb_cCommentColumnConstraintContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::PrimaryKeyColumnConstraintContext*>(MySqlParser::PrimaryKeyColumnConstraintContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::PrimaryKeyColumnConstraintContext>(x, rb_cPrimaryKeyColumnConstraintContext, nullptr, nullptr);
}

template <>
Object to_ruby<PrimaryKeyColumnConstraintContextProxy*>(PrimaryKeyColumnConstraintContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<PrimaryKeyColumnConstraintContextProxy>(x, rb_cPrimaryKeyColumnConstraintContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::UniqueKeyColumnConstraintContext*>(MySqlParser::UniqueKeyColumnConstraintContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::UniqueKeyColumnConstraintContext>(x, rb_cUniqueKeyColumnConstraintContext, nullptr, nullptr);
}

template <>
Object to_ruby<UniqueKeyColumnConstraintContextProxy*>(UniqueKeyColumnConstraintContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<UniqueKeyColumnConstraintContextProxy>(x, rb_cUniqueKeyColumnConstraintContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::SerialDefaultColumnConstraintContext*>(MySqlParser::SerialDefaultColumnConstraintContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::SerialDefaultColumnConstraintContext>(x, rb_cSerialDefaultColumnConstraintContext, nullptr, nullptr);
}

template <>
Object to_ruby<SerialDefaultColumnConstraintContextProxy*>(SerialDefaultColumnConstraintContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<SerialDefaultColumnConstraintContextProxy>(x, rb_cSerialDefaultColumnConstraintContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::NullNotnullContext*>(MySqlParser::NullNotnullContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::NullNotnullContext>(x, rb_cNullNotnullContext, nullptr, nullptr);
}

template <>
Object to_ruby<NullNotnullContextProxy*>(NullNotnullContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<NullNotnullContextProxy>(x, rb_cNullNotnullContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::NullColumnConstraintContext*>(MySqlParser::NullColumnConstraintContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::NullColumnConstraintContext>(x, rb_cNullColumnConstraintContext, nullptr, nullptr);
}

template <>
Object to_ruby<NullColumnConstraintContextProxy*>(NullColumnConstraintContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<NullColumnConstraintContextProxy>(x, rb_cNullColumnConstraintContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::DefaultColumnConstraintContext*>(MySqlParser::DefaultColumnConstraintContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::DefaultColumnConstraintContext>(x, rb_cDefaultColumnConstraintContext, nullptr, nullptr);
}

template <>
Object to_ruby<DefaultColumnConstraintContextProxy*>(DefaultColumnConstraintContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<DefaultColumnConstraintContextProxy>(x, rb_cDefaultColumnConstraintContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::DefaultValueContext*>(MySqlParser::DefaultValueContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::DefaultValueContext>(x, rb_cDefaultValueContext, nullptr, nullptr);
}

template <>
Object to_ruby<DefaultValueContextProxy*>(DefaultValueContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<DefaultValueContextProxy>(x, rb_cDefaultValueContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::ReferenceDefinitionContext*>(MySqlParser::ReferenceDefinitionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::ReferenceDefinitionContext>(x, rb_cReferenceDefinitionContext, nullptr, nullptr);
}

template <>
Object to_ruby<ReferenceDefinitionContextProxy*>(ReferenceDefinitionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<ReferenceDefinitionContextProxy>(x, rb_cReferenceDefinitionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::ReferenceColumnConstraintContext*>(MySqlParser::ReferenceColumnConstraintContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::ReferenceColumnConstraintContext>(x, rb_cReferenceColumnConstraintContext, nullptr, nullptr);
}

template <>
Object to_ruby<ReferenceColumnConstraintContextProxy*>(ReferenceColumnConstraintContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<ReferenceColumnConstraintContextProxy>(x, rb_cReferenceColumnConstraintContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::GeneratedColumnConstraintContext*>(MySqlParser::GeneratedColumnConstraintContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::GeneratedColumnConstraintContext>(x, rb_cGeneratedColumnConstraintContext, nullptr, nullptr);
}

template <>
Object to_ruby<GeneratedColumnConstraintContextProxy*>(GeneratedColumnConstraintContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<GeneratedColumnConstraintContextProxy>(x, rb_cGeneratedColumnConstraintContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::UniqueKeyTableConstraintContext*>(MySqlParser::UniqueKeyTableConstraintContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::UniqueKeyTableConstraintContext>(x, rb_cUniqueKeyTableConstraintContext, nullptr, nullptr);
}

template <>
Object to_ruby<UniqueKeyTableConstraintContextProxy*>(UniqueKeyTableConstraintContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<UniqueKeyTableConstraintContextProxy>(x, rb_cUniqueKeyTableConstraintContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::CheckTableConstraintContext*>(MySqlParser::CheckTableConstraintContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::CheckTableConstraintContext>(x, rb_cCheckTableConstraintContext, nullptr, nullptr);
}

template <>
Object to_ruby<CheckTableConstraintContextProxy*>(CheckTableConstraintContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<CheckTableConstraintContextProxy>(x, rb_cCheckTableConstraintContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::PrimaryKeyTableConstraintContext*>(MySqlParser::PrimaryKeyTableConstraintContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::PrimaryKeyTableConstraintContext>(x, rb_cPrimaryKeyTableConstraintContext, nullptr, nullptr);
}

template <>
Object to_ruby<PrimaryKeyTableConstraintContextProxy*>(PrimaryKeyTableConstraintContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<PrimaryKeyTableConstraintContextProxy>(x, rb_cPrimaryKeyTableConstraintContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::ForeignKeyTableConstraintContext*>(MySqlParser::ForeignKeyTableConstraintContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::ForeignKeyTableConstraintContext>(x, rb_cForeignKeyTableConstraintContext, nullptr, nullptr);
}

template <>
Object to_ruby<ForeignKeyTableConstraintContextProxy*>(ForeignKeyTableConstraintContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<ForeignKeyTableConstraintContextProxy>(x, rb_cForeignKeyTableConstraintContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::ReferenceActionContext*>(MySqlParser::ReferenceActionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::ReferenceActionContext>(x, rb_cReferenceActionContext, nullptr, nullptr);
}

template <>
Object to_ruby<ReferenceActionContextProxy*>(ReferenceActionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<ReferenceActionContextProxy>(x, rb_cReferenceActionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::ReferenceControlTypeContext*>(MySqlParser::ReferenceControlTypeContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::ReferenceControlTypeContext>(x, rb_cReferenceControlTypeContext, nullptr, nullptr);
}

template <>
Object to_ruby<ReferenceControlTypeContextProxy*>(ReferenceControlTypeContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<ReferenceControlTypeContextProxy>(x, rb_cReferenceControlTypeContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::SpecialIndexDeclarationContext*>(MySqlParser::SpecialIndexDeclarationContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::SpecialIndexDeclarationContext>(x, rb_cSpecialIndexDeclarationContext, nullptr, nullptr);
}

template <>
Object to_ruby<SpecialIndexDeclarationContextProxy*>(SpecialIndexDeclarationContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<SpecialIndexDeclarationContextProxy>(x, rb_cSpecialIndexDeclarationContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::SimpleIndexDeclarationContext*>(MySqlParser::SimpleIndexDeclarationContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::SimpleIndexDeclarationContext>(x, rb_cSimpleIndexDeclarationContext, nullptr, nullptr);
}

template <>
Object to_ruby<SimpleIndexDeclarationContextProxy*>(SimpleIndexDeclarationContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<SimpleIndexDeclarationContextProxy>(x, rb_cSimpleIndexDeclarationContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::TableOptionEngineContext*>(MySqlParser::TableOptionEngineContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::TableOptionEngineContext>(x, rb_cTableOptionEngineContext, nullptr, nullptr);
}

template <>
Object to_ruby<TableOptionEngineContextProxy*>(TableOptionEngineContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<TableOptionEngineContextProxy>(x, rb_cTableOptionEngineContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::TableOptionMaxRowsContext*>(MySqlParser::TableOptionMaxRowsContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::TableOptionMaxRowsContext>(x, rb_cTableOptionMaxRowsContext, nullptr, nullptr);
}

template <>
Object to_ruby<TableOptionMaxRowsContextProxy*>(TableOptionMaxRowsContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<TableOptionMaxRowsContextProxy>(x, rb_cTableOptionMaxRowsContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::TableOptionCollateContext*>(MySqlParser::TableOptionCollateContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::TableOptionCollateContext>(x, rb_cTableOptionCollateContext, nullptr, nullptr);
}

template <>
Object to_ruby<TableOptionCollateContextProxy*>(TableOptionCollateContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<TableOptionCollateContextProxy>(x, rb_cTableOptionCollateContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::TableOptionPersistentContext*>(MySqlParser::TableOptionPersistentContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::TableOptionPersistentContext>(x, rb_cTableOptionPersistentContext, nullptr, nullptr);
}

template <>
Object to_ruby<TableOptionPersistentContextProxy*>(TableOptionPersistentContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<TableOptionPersistentContextProxy>(x, rb_cTableOptionPersistentContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::TableOptionTablespaceContext*>(MySqlParser::TableOptionTablespaceContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::TableOptionTablespaceContext>(x, rb_cTableOptionTablespaceContext, nullptr, nullptr);
}

template <>
Object to_ruby<TableOptionTablespaceContextProxy*>(TableOptionTablespaceContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<TableOptionTablespaceContextProxy>(x, rb_cTableOptionTablespaceContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::TablespaceStorageContext*>(MySqlParser::TablespaceStorageContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::TablespaceStorageContext>(x, rb_cTablespaceStorageContext, nullptr, nullptr);
}

template <>
Object to_ruby<TablespaceStorageContextProxy*>(TablespaceStorageContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<TablespaceStorageContextProxy>(x, rb_cTablespaceStorageContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::TableOptionPackKeysContext*>(MySqlParser::TableOptionPackKeysContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::TableOptionPackKeysContext>(x, rb_cTableOptionPackKeysContext, nullptr, nullptr);
}

template <>
Object to_ruby<TableOptionPackKeysContextProxy*>(TableOptionPackKeysContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<TableOptionPackKeysContextProxy>(x, rb_cTableOptionPackKeysContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::TableOptionPasswordContext*>(MySqlParser::TableOptionPasswordContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::TableOptionPasswordContext>(x, rb_cTableOptionPasswordContext, nullptr, nullptr);
}

template <>
Object to_ruby<TableOptionPasswordContextProxy*>(TableOptionPasswordContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<TableOptionPasswordContextProxy>(x, rb_cTableOptionPasswordContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::TableOptionUnionContext*>(MySqlParser::TableOptionUnionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::TableOptionUnionContext>(x, rb_cTableOptionUnionContext, nullptr, nullptr);
}

template <>
Object to_ruby<TableOptionUnionContextProxy*>(TableOptionUnionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<TableOptionUnionContextProxy>(x, rb_cTableOptionUnionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::TablesContext*>(MySqlParser::TablesContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::TablesContext>(x, rb_cTablesContext, nullptr, nullptr);
}

template <>
Object to_ruby<TablesContextProxy*>(TablesContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<TablesContextProxy>(x, rb_cTablesContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::TableOptionSamplePageContext*>(MySqlParser::TableOptionSamplePageContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::TableOptionSamplePageContext>(x, rb_cTableOptionSamplePageContext, nullptr, nullptr);
}

template <>
Object to_ruby<TableOptionSamplePageContextProxy*>(TableOptionSamplePageContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<TableOptionSamplePageContextProxy>(x, rb_cTableOptionSamplePageContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::TableOptionCharsetContext*>(MySqlParser::TableOptionCharsetContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::TableOptionCharsetContext>(x, rb_cTableOptionCharsetContext, nullptr, nullptr);
}

template <>
Object to_ruby<TableOptionCharsetContextProxy*>(TableOptionCharsetContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<TableOptionCharsetContextProxy>(x, rb_cTableOptionCharsetContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::TableOptionIndexDirectoryContext*>(MySqlParser::TableOptionIndexDirectoryContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::TableOptionIndexDirectoryContext>(x, rb_cTableOptionIndexDirectoryContext, nullptr, nullptr);
}

template <>
Object to_ruby<TableOptionIndexDirectoryContextProxy*>(TableOptionIndexDirectoryContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<TableOptionIndexDirectoryContextProxy>(x, rb_cTableOptionIndexDirectoryContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::TableOptionKeyBlockSizeContext*>(MySqlParser::TableOptionKeyBlockSizeContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::TableOptionKeyBlockSizeContext>(x, rb_cTableOptionKeyBlockSizeContext, nullptr, nullptr);
}

template <>
Object to_ruby<TableOptionKeyBlockSizeContextProxy*>(TableOptionKeyBlockSizeContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<TableOptionKeyBlockSizeContextProxy>(x, rb_cTableOptionKeyBlockSizeContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::TableOptionEncryptionContext*>(MySqlParser::TableOptionEncryptionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::TableOptionEncryptionContext>(x, rb_cTableOptionEncryptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<TableOptionEncryptionContextProxy*>(TableOptionEncryptionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<TableOptionEncryptionContextProxy>(x, rb_cTableOptionEncryptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::TableOptionDataDirectoryContext*>(MySqlParser::TableOptionDataDirectoryContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::TableOptionDataDirectoryContext>(x, rb_cTableOptionDataDirectoryContext, nullptr, nullptr);
}

template <>
Object to_ruby<TableOptionDataDirectoryContextProxy*>(TableOptionDataDirectoryContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<TableOptionDataDirectoryContextProxy>(x, rb_cTableOptionDataDirectoryContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::TableOptionRecalculationContext*>(MySqlParser::TableOptionRecalculationContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::TableOptionRecalculationContext>(x, rb_cTableOptionRecalculationContext, nullptr, nullptr);
}

template <>
Object to_ruby<TableOptionRecalculationContextProxy*>(TableOptionRecalculationContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<TableOptionRecalculationContextProxy>(x, rb_cTableOptionRecalculationContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::TableOptionAutoIncrementContext*>(MySqlParser::TableOptionAutoIncrementContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::TableOptionAutoIncrementContext>(x, rb_cTableOptionAutoIncrementContext, nullptr, nullptr);
}

template <>
Object to_ruby<TableOptionAutoIncrementContextProxy*>(TableOptionAutoIncrementContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<TableOptionAutoIncrementContextProxy>(x, rb_cTableOptionAutoIncrementContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::TableOptionChecksumContext*>(MySqlParser::TableOptionChecksumContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::TableOptionChecksumContext>(x, rb_cTableOptionChecksumContext, nullptr, nullptr);
}

template <>
Object to_ruby<TableOptionChecksumContextProxy*>(TableOptionChecksumContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<TableOptionChecksumContextProxy>(x, rb_cTableOptionChecksumContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::TableOptionDelayContext*>(MySqlParser::TableOptionDelayContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::TableOptionDelayContext>(x, rb_cTableOptionDelayContext, nullptr, nullptr);
}

template <>
Object to_ruby<TableOptionDelayContextProxy*>(TableOptionDelayContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<TableOptionDelayContextProxy>(x, rb_cTableOptionDelayContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::TableOptionConnectionContext*>(MySqlParser::TableOptionConnectionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::TableOptionConnectionContext>(x, rb_cTableOptionConnectionContext, nullptr, nullptr);
}

template <>
Object to_ruby<TableOptionConnectionContextProxy*>(TableOptionConnectionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<TableOptionConnectionContextProxy>(x, rb_cTableOptionConnectionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::TableOptionCommentContext*>(MySqlParser::TableOptionCommentContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::TableOptionCommentContext>(x, rb_cTableOptionCommentContext, nullptr, nullptr);
}

template <>
Object to_ruby<TableOptionCommentContextProxy*>(TableOptionCommentContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<TableOptionCommentContextProxy>(x, rb_cTableOptionCommentContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::TableOptionAverageContext*>(MySqlParser::TableOptionAverageContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::TableOptionAverageContext>(x, rb_cTableOptionAverageContext, nullptr, nullptr);
}

template <>
Object to_ruby<TableOptionAverageContextProxy*>(TableOptionAverageContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<TableOptionAverageContextProxy>(x, rb_cTableOptionAverageContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::TableOptionRowFormatContext*>(MySqlParser::TableOptionRowFormatContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::TableOptionRowFormatContext>(x, rb_cTableOptionRowFormatContext, nullptr, nullptr);
}

template <>
Object to_ruby<TableOptionRowFormatContextProxy*>(TableOptionRowFormatContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<TableOptionRowFormatContextProxy>(x, rb_cTableOptionRowFormatContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::TableOptionCompressionContext*>(MySqlParser::TableOptionCompressionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::TableOptionCompressionContext>(x, rb_cTableOptionCompressionContext, nullptr, nullptr);
}

template <>
Object to_ruby<TableOptionCompressionContextProxy*>(TableOptionCompressionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<TableOptionCompressionContextProxy>(x, rb_cTableOptionCompressionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::TableOptionInsertMethodContext*>(MySqlParser::TableOptionInsertMethodContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::TableOptionInsertMethodContext>(x, rb_cTableOptionInsertMethodContext, nullptr, nullptr);
}

template <>
Object to_ruby<TableOptionInsertMethodContextProxy*>(TableOptionInsertMethodContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<TableOptionInsertMethodContextProxy>(x, rb_cTableOptionInsertMethodContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::TableOptionMinRowsContext*>(MySqlParser::TableOptionMinRowsContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::TableOptionMinRowsContext>(x, rb_cTableOptionMinRowsContext, nullptr, nullptr);
}

template <>
Object to_ruby<TableOptionMinRowsContextProxy*>(TableOptionMinRowsContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<TableOptionMinRowsContextProxy>(x, rb_cTableOptionMinRowsContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::PartitionFunctionDefinitionContext*>(MySqlParser::PartitionFunctionDefinitionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::PartitionFunctionDefinitionContext>(x, rb_cPartitionFunctionDefinitionContext, nullptr, nullptr);
}

template <>
Object to_ruby<PartitionFunctionDefinitionContextProxy*>(PartitionFunctionDefinitionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<PartitionFunctionDefinitionContextProxy>(x, rb_cPartitionFunctionDefinitionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::SubpartitionFunctionDefinitionContext*>(MySqlParser::SubpartitionFunctionDefinitionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::SubpartitionFunctionDefinitionContext>(x, rb_cSubpartitionFunctionDefinitionContext, nullptr, nullptr);
}

template <>
Object to_ruby<SubpartitionFunctionDefinitionContextProxy*>(SubpartitionFunctionDefinitionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<SubpartitionFunctionDefinitionContextProxy>(x, rb_cSubpartitionFunctionDefinitionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::PartitionDefinitionContext*>(MySqlParser::PartitionDefinitionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::PartitionDefinitionContext>(x, rb_cPartitionDefinitionContext, nullptr, nullptr);
}

template <>
Object to_ruby<PartitionDefinitionContextProxy*>(PartitionDefinitionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<PartitionDefinitionContextProxy>(x, rb_cPartitionDefinitionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::PartitionFunctionKeyContext*>(MySqlParser::PartitionFunctionKeyContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::PartitionFunctionKeyContext>(x, rb_cPartitionFunctionKeyContext, nullptr, nullptr);
}

template <>
Object to_ruby<PartitionFunctionKeyContextProxy*>(PartitionFunctionKeyContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<PartitionFunctionKeyContextProxy>(x, rb_cPartitionFunctionKeyContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::PartitionFunctionHashContext*>(MySqlParser::PartitionFunctionHashContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::PartitionFunctionHashContext>(x, rb_cPartitionFunctionHashContext, nullptr, nullptr);
}

template <>
Object to_ruby<PartitionFunctionHashContextProxy*>(PartitionFunctionHashContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<PartitionFunctionHashContextProxy>(x, rb_cPartitionFunctionHashContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::PartitionFunctionListContext*>(MySqlParser::PartitionFunctionListContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::PartitionFunctionListContext>(x, rb_cPartitionFunctionListContext, nullptr, nullptr);
}

template <>
Object to_ruby<PartitionFunctionListContextProxy*>(PartitionFunctionListContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<PartitionFunctionListContextProxy>(x, rb_cPartitionFunctionListContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::PartitionFunctionRangeContext*>(MySqlParser::PartitionFunctionRangeContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::PartitionFunctionRangeContext>(x, rb_cPartitionFunctionRangeContext, nullptr, nullptr);
}

template <>
Object to_ruby<PartitionFunctionRangeContextProxy*>(PartitionFunctionRangeContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<PartitionFunctionRangeContextProxy>(x, rb_cPartitionFunctionRangeContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::SubPartitionFunctionHashContext*>(MySqlParser::SubPartitionFunctionHashContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::SubPartitionFunctionHashContext>(x, rb_cSubPartitionFunctionHashContext, nullptr, nullptr);
}

template <>
Object to_ruby<SubPartitionFunctionHashContextProxy*>(SubPartitionFunctionHashContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<SubPartitionFunctionHashContextProxy>(x, rb_cSubPartitionFunctionHashContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::SubPartitionFunctionKeyContext*>(MySqlParser::SubPartitionFunctionKeyContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::SubPartitionFunctionKeyContext>(x, rb_cSubPartitionFunctionKeyContext, nullptr, nullptr);
}

template <>
Object to_ruby<SubPartitionFunctionKeyContextProxy*>(SubPartitionFunctionKeyContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<SubPartitionFunctionKeyContextProxy>(x, rb_cSubPartitionFunctionKeyContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::PartitionComparisionContext*>(MySqlParser::PartitionComparisionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::PartitionComparisionContext>(x, rb_cPartitionComparisionContext, nullptr, nullptr);
}

template <>
Object to_ruby<PartitionComparisionContextProxy*>(PartitionComparisionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<PartitionComparisionContextProxy>(x, rb_cPartitionComparisionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::PartitionDefinerAtomContext*>(MySqlParser::PartitionDefinerAtomContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::PartitionDefinerAtomContext>(x, rb_cPartitionDefinerAtomContext, nullptr, nullptr);
}

template <>
Object to_ruby<PartitionDefinerAtomContextProxy*>(PartitionDefinerAtomContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<PartitionDefinerAtomContextProxy>(x, rb_cPartitionDefinerAtomContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::PartitionOptionContext*>(MySqlParser::PartitionOptionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::PartitionOptionContext>(x, rb_cPartitionOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<PartitionOptionContextProxy*>(PartitionOptionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<PartitionOptionContextProxy>(x, rb_cPartitionOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::SubpartitionDefinitionContext*>(MySqlParser::SubpartitionDefinitionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::SubpartitionDefinitionContext>(x, rb_cSubpartitionDefinitionContext, nullptr, nullptr);
}

template <>
Object to_ruby<SubpartitionDefinitionContextProxy*>(SubpartitionDefinitionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<SubpartitionDefinitionContextProxy>(x, rb_cSubpartitionDefinitionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::PartitionListAtomContext*>(MySqlParser::PartitionListAtomContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::PartitionListAtomContext>(x, rb_cPartitionListAtomContext, nullptr, nullptr);
}

template <>
Object to_ruby<PartitionListAtomContextProxy*>(PartitionListAtomContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<PartitionListAtomContextProxy>(x, rb_cPartitionListAtomContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::PartitionListVectorContext*>(MySqlParser::PartitionListVectorContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::PartitionListVectorContext>(x, rb_cPartitionListVectorContext, nullptr, nullptr);
}

template <>
Object to_ruby<PartitionListVectorContextProxy*>(PartitionListVectorContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<PartitionListVectorContextProxy>(x, rb_cPartitionListVectorContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::PartitionDefinerVectorContext*>(MySqlParser::PartitionDefinerVectorContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::PartitionDefinerVectorContext>(x, rb_cPartitionDefinerVectorContext, nullptr, nullptr);
}

template <>
Object to_ruby<PartitionDefinerVectorContextProxy*>(PartitionDefinerVectorContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<PartitionDefinerVectorContextProxy>(x, rb_cPartitionDefinerVectorContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::PartitionSimpleContext*>(MySqlParser::PartitionSimpleContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::PartitionSimpleContext>(x, rb_cPartitionSimpleContext, nullptr, nullptr);
}

template <>
Object to_ruby<PartitionSimpleContextProxy*>(PartitionSimpleContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<PartitionSimpleContextProxy>(x, rb_cPartitionSimpleContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::ConstantContext*>(MySqlParser::ConstantContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::ConstantContext>(x, rb_cConstantContext, nullptr, nullptr);
}

template <>
Object to_ruby<ConstantContextProxy*>(ConstantContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<ConstantContextProxy>(x, rb_cConstantContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::PartitionOptionCommentContext*>(MySqlParser::PartitionOptionCommentContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::PartitionOptionCommentContext>(x, rb_cPartitionOptionCommentContext, nullptr, nullptr);
}

template <>
Object to_ruby<PartitionOptionCommentContextProxy*>(PartitionOptionCommentContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<PartitionOptionCommentContextProxy>(x, rb_cPartitionOptionCommentContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::PartitionOptionNodeGroupContext*>(MySqlParser::PartitionOptionNodeGroupContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::PartitionOptionNodeGroupContext>(x, rb_cPartitionOptionNodeGroupContext, nullptr, nullptr);
}

template <>
Object to_ruby<PartitionOptionNodeGroupContextProxy*>(PartitionOptionNodeGroupContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<PartitionOptionNodeGroupContextProxy>(x, rb_cPartitionOptionNodeGroupContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::PartitionOptionIndexDirectoryContext*>(MySqlParser::PartitionOptionIndexDirectoryContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::PartitionOptionIndexDirectoryContext>(x, rb_cPartitionOptionIndexDirectoryContext, nullptr, nullptr);
}

template <>
Object to_ruby<PartitionOptionIndexDirectoryContextProxy*>(PartitionOptionIndexDirectoryContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<PartitionOptionIndexDirectoryContextProxy>(x, rb_cPartitionOptionIndexDirectoryContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::PartitionOptionMaxRowsContext*>(MySqlParser::PartitionOptionMaxRowsContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::PartitionOptionMaxRowsContext>(x, rb_cPartitionOptionMaxRowsContext, nullptr, nullptr);
}

template <>
Object to_ruby<PartitionOptionMaxRowsContextProxy*>(PartitionOptionMaxRowsContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<PartitionOptionMaxRowsContextProxy>(x, rb_cPartitionOptionMaxRowsContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::PartitionOptionTablespaceContext*>(MySqlParser::PartitionOptionTablespaceContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::PartitionOptionTablespaceContext>(x, rb_cPartitionOptionTablespaceContext, nullptr, nullptr);
}

template <>
Object to_ruby<PartitionOptionTablespaceContextProxy*>(PartitionOptionTablespaceContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<PartitionOptionTablespaceContextProxy>(x, rb_cPartitionOptionTablespaceContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::PartitionOptionEngineContext*>(MySqlParser::PartitionOptionEngineContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::PartitionOptionEngineContext>(x, rb_cPartitionOptionEngineContext, nullptr, nullptr);
}

template <>
Object to_ruby<PartitionOptionEngineContextProxy*>(PartitionOptionEngineContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<PartitionOptionEngineContextProxy>(x, rb_cPartitionOptionEngineContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::PartitionOptionMinRowsContext*>(MySqlParser::PartitionOptionMinRowsContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::PartitionOptionMinRowsContext>(x, rb_cPartitionOptionMinRowsContext, nullptr, nullptr);
}

template <>
Object to_ruby<PartitionOptionMinRowsContextProxy*>(PartitionOptionMinRowsContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<PartitionOptionMinRowsContextProxy>(x, rb_cPartitionOptionMinRowsContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::PartitionOptionDataDirectoryContext*>(MySqlParser::PartitionOptionDataDirectoryContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::PartitionOptionDataDirectoryContext>(x, rb_cPartitionOptionDataDirectoryContext, nullptr, nullptr);
}

template <>
Object to_ruby<PartitionOptionDataDirectoryContextProxy*>(PartitionOptionDataDirectoryContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<PartitionOptionDataDirectoryContextProxy>(x, rb_cPartitionOptionDataDirectoryContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::AlterUpgradeNameContext*>(MySqlParser::AlterUpgradeNameContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::AlterUpgradeNameContext>(x, rb_cAlterUpgradeNameContext, nullptr, nullptr);
}

template <>
Object to_ruby<AlterUpgradeNameContextProxy*>(AlterUpgradeNameContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<AlterUpgradeNameContextProxy>(x, rb_cAlterUpgradeNameContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::AlterSimpleDatabaseContext*>(MySqlParser::AlterSimpleDatabaseContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::AlterSimpleDatabaseContext>(x, rb_cAlterSimpleDatabaseContext, nullptr, nullptr);
}

template <>
Object to_ruby<AlterSimpleDatabaseContextProxy*>(AlterSimpleDatabaseContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<AlterSimpleDatabaseContextProxy>(x, rb_cAlterSimpleDatabaseContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::AlterSpecificationContext*>(MySqlParser::AlterSpecificationContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::AlterSpecificationContext>(x, rb_cAlterSpecificationContext, nullptr, nullptr);
}

template <>
Object to_ruby<AlterSpecificationContextProxy*>(AlterSpecificationContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<AlterSpecificationContextProxy>(x, rb_cAlterSpecificationContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::AlterByDisableKeysContext*>(MySqlParser::AlterByDisableKeysContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::AlterByDisableKeysContext>(x, rb_cAlterByDisableKeysContext, nullptr, nullptr);
}

template <>
Object to_ruby<AlterByDisableKeysContextProxy*>(AlterByDisableKeysContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<AlterByDisableKeysContextProxy>(x, rb_cAlterByDisableKeysContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::AlterByDefaultCharsetContext*>(MySqlParser::AlterByDefaultCharsetContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::AlterByDefaultCharsetContext>(x, rb_cAlterByDefaultCharsetContext, nullptr, nullptr);
}

template <>
Object to_ruby<AlterByDefaultCharsetContextProxy*>(AlterByDefaultCharsetContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<AlterByDefaultCharsetContextProxy>(x, rb_cAlterByDefaultCharsetContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::AlterByRenameColumnContext*>(MySqlParser::AlterByRenameColumnContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::AlterByRenameColumnContext>(x, rb_cAlterByRenameColumnContext, nullptr, nullptr);
}

template <>
Object to_ruby<AlterByRenameColumnContextProxy*>(AlterByRenameColumnContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<AlterByRenameColumnContextProxy>(x, rb_cAlterByRenameColumnContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::AlterByConvertCharsetContext*>(MySqlParser::AlterByConvertCharsetContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::AlterByConvertCharsetContext>(x, rb_cAlterByConvertCharsetContext, nullptr, nullptr);
}

template <>
Object to_ruby<AlterByConvertCharsetContextProxy*>(AlterByConvertCharsetContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<AlterByConvertCharsetContextProxy>(x, rb_cAlterByConvertCharsetContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::AlterByAddPartitionContext*>(MySqlParser::AlterByAddPartitionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::AlterByAddPartitionContext>(x, rb_cAlterByAddPartitionContext, nullptr, nullptr);
}

template <>
Object to_ruby<AlterByAddPartitionContextProxy*>(AlterByAddPartitionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<AlterByAddPartitionContextProxy>(x, rb_cAlterByAddPartitionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::AlterByAddForeignKeyContext*>(MySqlParser::AlterByAddForeignKeyContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::AlterByAddForeignKeyContext>(x, rb_cAlterByAddForeignKeyContext, nullptr, nullptr);
}

template <>
Object to_ruby<AlterByAddForeignKeyContextProxy*>(AlterByAddForeignKeyContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<AlterByAddForeignKeyContextProxy>(x, rb_cAlterByAddForeignKeyContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::AlterByRenameIndexContext*>(MySqlParser::AlterByRenameIndexContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::AlterByRenameIndexContext>(x, rb_cAlterByRenameIndexContext, nullptr, nullptr);
}

template <>
Object to_ruby<AlterByRenameIndexContextProxy*>(AlterByRenameIndexContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<AlterByRenameIndexContextProxy>(x, rb_cAlterByRenameIndexContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::AlterByRemovePartitioningContext*>(MySqlParser::AlterByRemovePartitioningContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::AlterByRemovePartitioningContext>(x, rb_cAlterByRemovePartitioningContext, nullptr, nullptr);
}

template <>
Object to_ruby<AlterByRemovePartitioningContextProxy*>(AlterByRemovePartitioningContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<AlterByRemovePartitioningContextProxy>(x, rb_cAlterByRemovePartitioningContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::AlterByRenameContext*>(MySqlParser::AlterByRenameContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::AlterByRenameContext>(x, rb_cAlterByRenameContext, nullptr, nullptr);
}

template <>
Object to_ruby<AlterByRenameContextProxy*>(AlterByRenameContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<AlterByRenameContextProxy>(x, rb_cAlterByRenameContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::AlterByOptimizePartitionContext*>(MySqlParser::AlterByOptimizePartitionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::AlterByOptimizePartitionContext>(x, rb_cAlterByOptimizePartitionContext, nullptr, nullptr);
}

template <>
Object to_ruby<AlterByOptimizePartitionContextProxy*>(AlterByOptimizePartitionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<AlterByOptimizePartitionContextProxy>(x, rb_cAlterByOptimizePartitionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::AlterByImportTablespaceContext*>(MySqlParser::AlterByImportTablespaceContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::AlterByImportTablespaceContext>(x, rb_cAlterByImportTablespaceContext, nullptr, nullptr);
}

template <>
Object to_ruby<AlterByImportTablespaceContextProxy*>(AlterByImportTablespaceContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<AlterByImportTablespaceContextProxy>(x, rb_cAlterByImportTablespaceContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::AlterByCoalescePartitionContext*>(MySqlParser::AlterByCoalescePartitionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::AlterByCoalescePartitionContext>(x, rb_cAlterByCoalescePartitionContext, nullptr, nullptr);
}

template <>
Object to_ruby<AlterByCoalescePartitionContextProxy*>(AlterByCoalescePartitionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<AlterByCoalescePartitionContextProxy>(x, rb_cAlterByCoalescePartitionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::AlterByAddColumnsContext*>(MySqlParser::AlterByAddColumnsContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::AlterByAddColumnsContext>(x, rb_cAlterByAddColumnsContext, nullptr, nullptr);
}

template <>
Object to_ruby<AlterByAddColumnsContextProxy*>(AlterByAddColumnsContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<AlterByAddColumnsContextProxy>(x, rb_cAlterByAddColumnsContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::AlterByDropForeignKeyContext*>(MySqlParser::AlterByDropForeignKeyContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::AlterByDropForeignKeyContext>(x, rb_cAlterByDropForeignKeyContext, nullptr, nullptr);
}

template <>
Object to_ruby<AlterByDropForeignKeyContextProxy*>(AlterByDropForeignKeyContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<AlterByDropForeignKeyContextProxy>(x, rb_cAlterByDropForeignKeyContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::AlterByAddCheckTableConstraintContext*>(MySqlParser::AlterByAddCheckTableConstraintContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::AlterByAddCheckTableConstraintContext>(x, rb_cAlterByAddCheckTableConstraintContext, nullptr, nullptr);
}

template <>
Object to_ruby<AlterByAddCheckTableConstraintContextProxy*>(AlterByAddCheckTableConstraintContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<AlterByAddCheckTableConstraintContextProxy>(x, rb_cAlterByAddCheckTableConstraintContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::AlterByRebuildPartitionContext*>(MySqlParser::AlterByRebuildPartitionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::AlterByRebuildPartitionContext>(x, rb_cAlterByRebuildPartitionContext, nullptr, nullptr);
}

template <>
Object to_ruby<AlterByRebuildPartitionContextProxy*>(AlterByRebuildPartitionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<AlterByRebuildPartitionContextProxy>(x, rb_cAlterByRebuildPartitionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::AlterByUpgradePartitioningContext*>(MySqlParser::AlterByUpgradePartitioningContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::AlterByUpgradePartitioningContext>(x, rb_cAlterByUpgradePartitioningContext, nullptr, nullptr);
}

template <>
Object to_ruby<AlterByUpgradePartitioningContextProxy*>(AlterByUpgradePartitioningContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<AlterByUpgradePartitioningContextProxy>(x, rb_cAlterByUpgradePartitioningContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::AlterByRepairPartitionContext*>(MySqlParser::AlterByRepairPartitionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::AlterByRepairPartitionContext>(x, rb_cAlterByRepairPartitionContext, nullptr, nullptr);
}

template <>
Object to_ruby<AlterByRepairPartitionContextProxy*>(AlterByRepairPartitionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<AlterByRepairPartitionContextProxy>(x, rb_cAlterByRepairPartitionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::AlterByExchangePartitionContext*>(MySqlParser::AlterByExchangePartitionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::AlterByExchangePartitionContext>(x, rb_cAlterByExchangePartitionContext, nullptr, nullptr);
}

template <>
Object to_ruby<AlterByExchangePartitionContextProxy*>(AlterByExchangePartitionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<AlterByExchangePartitionContextProxy>(x, rb_cAlterByExchangePartitionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::AlterByAddIndexContext*>(MySqlParser::AlterByAddIndexContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::AlterByAddIndexContext>(x, rb_cAlterByAddIndexContext, nullptr, nullptr);
}

template <>
Object to_ruby<AlterByAddIndexContextProxy*>(AlterByAddIndexContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<AlterByAddIndexContextProxy>(x, rb_cAlterByAddIndexContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::AlterByDropColumnContext*>(MySqlParser::AlterByDropColumnContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::AlterByDropColumnContext>(x, rb_cAlterByDropColumnContext, nullptr, nullptr);
}

template <>
Object to_ruby<AlterByDropColumnContextProxy*>(AlterByDropColumnContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<AlterByDropColumnContextProxy>(x, rb_cAlterByDropColumnContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::AlterByImportPartitionContext*>(MySqlParser::AlterByImportPartitionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::AlterByImportPartitionContext>(x, rb_cAlterByImportPartitionContext, nullptr, nullptr);
}

template <>
Object to_ruby<AlterByImportPartitionContextProxy*>(AlterByImportPartitionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<AlterByImportPartitionContextProxy>(x, rb_cAlterByImportPartitionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::AlterByChangeDefaultContext*>(MySqlParser::AlterByChangeDefaultContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::AlterByChangeDefaultContext>(x, rb_cAlterByChangeDefaultContext, nullptr, nullptr);
}

template <>
Object to_ruby<AlterByChangeDefaultContextProxy*>(AlterByChangeDefaultContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<AlterByChangeDefaultContextProxy>(x, rb_cAlterByChangeDefaultContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::AlterByForceContext*>(MySqlParser::AlterByForceContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::AlterByForceContext>(x, rb_cAlterByForceContext, nullptr, nullptr);
}

template <>
Object to_ruby<AlterByForceContextProxy*>(AlterByForceContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<AlterByForceContextProxy>(x, rb_cAlterByForceContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::AlterByDropPartitionContext*>(MySqlParser::AlterByDropPartitionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::AlterByDropPartitionContext>(x, rb_cAlterByDropPartitionContext, nullptr, nullptr);
}

template <>
Object to_ruby<AlterByDropPartitionContextProxy*>(AlterByDropPartitionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<AlterByDropPartitionContextProxy>(x, rb_cAlterByDropPartitionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::AlterByAddSpecialIndexContext*>(MySqlParser::AlterByAddSpecialIndexContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::AlterByAddSpecialIndexContext>(x, rb_cAlterByAddSpecialIndexContext, nullptr, nullptr);
}

template <>
Object to_ruby<AlterByAddSpecialIndexContextProxy*>(AlterByAddSpecialIndexContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<AlterByAddSpecialIndexContextProxy>(x, rb_cAlterByAddSpecialIndexContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::AlterByModifyColumnContext*>(MySqlParser::AlterByModifyColumnContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::AlterByModifyColumnContext>(x, rb_cAlterByModifyColumnContext, nullptr, nullptr);
}

template <>
Object to_ruby<AlterByModifyColumnContextProxy*>(AlterByModifyColumnContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<AlterByModifyColumnContextProxy>(x, rb_cAlterByModifyColumnContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::AlterByTableOptionContext*>(MySqlParser::AlterByTableOptionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::AlterByTableOptionContext>(x, rb_cAlterByTableOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<AlterByTableOptionContextProxy*>(AlterByTableOptionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<AlterByTableOptionContextProxy>(x, rb_cAlterByTableOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::AlterByDropPrimaryKeyContext*>(MySqlParser::AlterByDropPrimaryKeyContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::AlterByDropPrimaryKeyContext>(x, rb_cAlterByDropPrimaryKeyContext, nullptr, nullptr);
}

template <>
Object to_ruby<AlterByDropPrimaryKeyContextProxy*>(AlterByDropPrimaryKeyContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<AlterByDropPrimaryKeyContextProxy>(x, rb_cAlterByDropPrimaryKeyContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::AlterByLockContext*>(MySqlParser::AlterByLockContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::AlterByLockContext>(x, rb_cAlterByLockContext, nullptr, nullptr);
}

template <>
Object to_ruby<AlterByLockContextProxy*>(AlterByLockContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<AlterByLockContextProxy>(x, rb_cAlterByLockContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::AlterByDiscardPartitionContext*>(MySqlParser::AlterByDiscardPartitionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::AlterByDiscardPartitionContext>(x, rb_cAlterByDiscardPartitionContext, nullptr, nullptr);
}

template <>
Object to_ruby<AlterByDiscardPartitionContextProxy*>(AlterByDiscardPartitionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<AlterByDiscardPartitionContextProxy>(x, rb_cAlterByDiscardPartitionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::AlterByDiscardTablespaceContext*>(MySqlParser::AlterByDiscardTablespaceContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::AlterByDiscardTablespaceContext>(x, rb_cAlterByDiscardTablespaceContext, nullptr, nullptr);
}

template <>
Object to_ruby<AlterByDiscardTablespaceContextProxy*>(AlterByDiscardTablespaceContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<AlterByDiscardTablespaceContextProxy>(x, rb_cAlterByDiscardTablespaceContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::AlterByValidateContext*>(MySqlParser::AlterByValidateContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::AlterByValidateContext>(x, rb_cAlterByValidateContext, nullptr, nullptr);
}

template <>
Object to_ruby<AlterByValidateContextProxy*>(AlterByValidateContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<AlterByValidateContextProxy>(x, rb_cAlterByValidateContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::AlterByAddPrimaryKeyContext*>(MySqlParser::AlterByAddPrimaryKeyContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::AlterByAddPrimaryKeyContext>(x, rb_cAlterByAddPrimaryKeyContext, nullptr, nullptr);
}

template <>
Object to_ruby<AlterByAddPrimaryKeyContextProxy*>(AlterByAddPrimaryKeyContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<AlterByAddPrimaryKeyContextProxy>(x, rb_cAlterByAddPrimaryKeyContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::AlterByCheckPartitionContext*>(MySqlParser::AlterByCheckPartitionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::AlterByCheckPartitionContext>(x, rb_cAlterByCheckPartitionContext, nullptr, nullptr);
}

template <>
Object to_ruby<AlterByCheckPartitionContextProxy*>(AlterByCheckPartitionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<AlterByCheckPartitionContextProxy>(x, rb_cAlterByCheckPartitionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::AlterByEnableKeysContext*>(MySqlParser::AlterByEnableKeysContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::AlterByEnableKeysContext>(x, rb_cAlterByEnableKeysContext, nullptr, nullptr);
}

template <>
Object to_ruby<AlterByEnableKeysContextProxy*>(AlterByEnableKeysContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<AlterByEnableKeysContextProxy>(x, rb_cAlterByEnableKeysContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::AlterByReorganizePartitionContext*>(MySqlParser::AlterByReorganizePartitionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::AlterByReorganizePartitionContext>(x, rb_cAlterByReorganizePartitionContext, nullptr, nullptr);
}

template <>
Object to_ruby<AlterByReorganizePartitionContextProxy*>(AlterByReorganizePartitionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<AlterByReorganizePartitionContextProxy>(x, rb_cAlterByReorganizePartitionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::AlterBySetAlgorithmContext*>(MySqlParser::AlterBySetAlgorithmContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::AlterBySetAlgorithmContext>(x, rb_cAlterBySetAlgorithmContext, nullptr, nullptr);
}

template <>
Object to_ruby<AlterBySetAlgorithmContextProxy*>(AlterBySetAlgorithmContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<AlterBySetAlgorithmContextProxy>(x, rb_cAlterBySetAlgorithmContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::AlterByAnalyzePartitionContext*>(MySqlParser::AlterByAnalyzePartitionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::AlterByAnalyzePartitionContext>(x, rb_cAlterByAnalyzePartitionContext, nullptr, nullptr);
}

template <>
Object to_ruby<AlterByAnalyzePartitionContextProxy*>(AlterByAnalyzePartitionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<AlterByAnalyzePartitionContextProxy>(x, rb_cAlterByAnalyzePartitionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::AlterByChangeColumnContext*>(MySqlParser::AlterByChangeColumnContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::AlterByChangeColumnContext>(x, rb_cAlterByChangeColumnContext, nullptr, nullptr);
}

template <>
Object to_ruby<AlterByChangeColumnContextProxy*>(AlterByChangeColumnContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<AlterByChangeColumnContextProxy>(x, rb_cAlterByChangeColumnContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::AlterByAddUniqueKeyContext*>(MySqlParser::AlterByAddUniqueKeyContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::AlterByAddUniqueKeyContext>(x, rb_cAlterByAddUniqueKeyContext, nullptr, nullptr);
}

template <>
Object to_ruby<AlterByAddUniqueKeyContextProxy*>(AlterByAddUniqueKeyContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<AlterByAddUniqueKeyContextProxy>(x, rb_cAlterByAddUniqueKeyContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::AlterByTruncatePartitionContext*>(MySqlParser::AlterByTruncatePartitionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::AlterByTruncatePartitionContext>(x, rb_cAlterByTruncatePartitionContext, nullptr, nullptr);
}

template <>
Object to_ruby<AlterByTruncatePartitionContextProxy*>(AlterByTruncatePartitionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<AlterByTruncatePartitionContextProxy>(x, rb_cAlterByTruncatePartitionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::AlterByDropIndexContext*>(MySqlParser::AlterByDropIndexContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::AlterByDropIndexContext>(x, rb_cAlterByDropIndexContext, nullptr, nullptr);
}

template <>
Object to_ruby<AlterByDropIndexContextProxy*>(AlterByDropIndexContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<AlterByDropIndexContextProxy>(x, rb_cAlterByDropIndexContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::AlterByAddColumnContext*>(MySqlParser::AlterByAddColumnContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::AlterByAddColumnContext>(x, rb_cAlterByAddColumnContext, nullptr, nullptr);
}

template <>
Object to_ruby<AlterByAddColumnContextProxy*>(AlterByAddColumnContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<AlterByAddColumnContextProxy>(x, rb_cAlterByAddColumnContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::AlterByOrderContext*>(MySqlParser::AlterByOrderContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::AlterByOrderContext>(x, rb_cAlterByOrderContext, nullptr, nullptr);
}

template <>
Object to_ruby<AlterByOrderContextProxy*>(AlterByOrderContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<AlterByOrderContextProxy>(x, rb_cAlterByOrderContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::IfExistsContext*>(MySqlParser::IfExistsContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::IfExistsContext>(x, rb_cIfExistsContext, nullptr, nullptr);
}

template <>
Object to_ruby<IfExistsContextProxy*>(IfExistsContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<IfExistsContextProxy>(x, rb_cIfExistsContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::RenameTableClauseContext*>(MySqlParser::RenameTableClauseContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::RenameTableClauseContext>(x, rb_cRenameTableClauseContext, nullptr, nullptr);
}

template <>
Object to_ruby<RenameTableClauseContextProxy*>(RenameTableClauseContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<RenameTableClauseContextProxy>(x, rb_cRenameTableClauseContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::ConstantsContext*>(MySqlParser::ConstantsContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::ConstantsContext>(x, rb_cConstantsContext, nullptr, nullptr);
}

template <>
Object to_ruby<ConstantsContextProxy*>(ConstantsContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<ConstantsContextProxy>(x, rb_cConstantsContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::ExpressionsContext*>(MySqlParser::ExpressionsContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::ExpressionsContext>(x, rb_cExpressionsContext, nullptr, nullptr);
}

template <>
Object to_ruby<ExpressionsContextProxy*>(ExpressionsContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<ExpressionsContextProxy>(x, rb_cExpressionsContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::SingleDeleteStatementContext*>(MySqlParser::SingleDeleteStatementContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::SingleDeleteStatementContext>(x, rb_cSingleDeleteStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<SingleDeleteStatementContextProxy*>(SingleDeleteStatementContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<SingleDeleteStatementContextProxy>(x, rb_cSingleDeleteStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::MultipleDeleteStatementContext*>(MySqlParser::MultipleDeleteStatementContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::MultipleDeleteStatementContext>(x, rb_cMultipleDeleteStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<MultipleDeleteStatementContextProxy*>(MultipleDeleteStatementContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<MultipleDeleteStatementContextProxy>(x, rb_cMultipleDeleteStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::HandlerOpenStatementContext*>(MySqlParser::HandlerOpenStatementContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::HandlerOpenStatementContext>(x, rb_cHandlerOpenStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<HandlerOpenStatementContextProxy*>(HandlerOpenStatementContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<HandlerOpenStatementContextProxy>(x, rb_cHandlerOpenStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::HandlerReadIndexStatementContext*>(MySqlParser::HandlerReadIndexStatementContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::HandlerReadIndexStatementContext>(x, rb_cHandlerReadIndexStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<HandlerReadIndexStatementContextProxy*>(HandlerReadIndexStatementContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<HandlerReadIndexStatementContextProxy>(x, rb_cHandlerReadIndexStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::HandlerReadStatementContext*>(MySqlParser::HandlerReadStatementContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::HandlerReadStatementContext>(x, rb_cHandlerReadStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<HandlerReadStatementContextProxy*>(HandlerReadStatementContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<HandlerReadStatementContextProxy>(x, rb_cHandlerReadStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::HandlerCloseStatementContext*>(MySqlParser::HandlerCloseStatementContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::HandlerCloseStatementContext>(x, rb_cHandlerCloseStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<HandlerCloseStatementContextProxy*>(HandlerCloseStatementContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<HandlerCloseStatementContextProxy>(x, rb_cHandlerCloseStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::InsertStatementValueContext*>(MySqlParser::InsertStatementValueContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::InsertStatementValueContext>(x, rb_cInsertStatementValueContext, nullptr, nullptr);
}

template <>
Object to_ruby<InsertStatementValueContextProxy*>(InsertStatementValueContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<InsertStatementValueContextProxy>(x, rb_cInsertStatementValueContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::UpdatedElementContext*>(MySqlParser::UpdatedElementContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::UpdatedElementContext>(x, rb_cUpdatedElementContext, nullptr, nullptr);
}

template <>
Object to_ruby<UpdatedElementContextProxy*>(UpdatedElementContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<UpdatedElementContextProxy>(x, rb_cUpdatedElementContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::AssignmentFieldContext*>(MySqlParser::AssignmentFieldContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::AssignmentFieldContext>(x, rb_cAssignmentFieldContext, nullptr, nullptr);
}

template <>
Object to_ruby<AssignmentFieldContextProxy*>(AssignmentFieldContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<AssignmentFieldContextProxy>(x, rb_cAssignmentFieldContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::SelectFieldsIntoContext*>(MySqlParser::SelectFieldsIntoContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::SelectFieldsIntoContext>(x, rb_cSelectFieldsIntoContext, nullptr, nullptr);
}

template <>
Object to_ruby<SelectFieldsIntoContextProxy*>(SelectFieldsIntoContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<SelectFieldsIntoContextProxy>(x, rb_cSelectFieldsIntoContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::SelectLinesIntoContext*>(MySqlParser::SelectLinesIntoContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::SelectLinesIntoContext>(x, rb_cSelectLinesIntoContext, nullptr, nullptr);
}

template <>
Object to_ruby<SelectLinesIntoContextProxy*>(SelectLinesIntoContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<SelectLinesIntoContextProxy>(x, rb_cSelectLinesIntoContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::QuerySpecificationNointoContext*>(MySqlParser::QuerySpecificationNointoContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::QuerySpecificationNointoContext>(x, rb_cQuerySpecificationNointoContext, nullptr, nullptr);
}

template <>
Object to_ruby<QuerySpecificationNointoContextProxy*>(QuerySpecificationNointoContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<QuerySpecificationNointoContextProxy>(x, rb_cQuerySpecificationNointoContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::UnionSelectContext*>(MySqlParser::UnionSelectContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::UnionSelectContext>(x, rb_cUnionSelectContext, nullptr, nullptr);
}

template <>
Object to_ruby<UnionSelectContextProxy*>(UnionSelectContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<UnionSelectContextProxy>(x, rb_cUnionSelectContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::UnionStatementContext*>(MySqlParser::UnionStatementContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::UnionStatementContext>(x, rb_cUnionStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<UnionStatementContextProxy*>(UnionStatementContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<UnionStatementContextProxy>(x, rb_cUnionStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::OrderByClauseContext*>(MySqlParser::OrderByClauseContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::OrderByClauseContext>(x, rb_cOrderByClauseContext, nullptr, nullptr);
}

template <>
Object to_ruby<OrderByClauseContextProxy*>(OrderByClauseContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<OrderByClauseContextProxy>(x, rb_cOrderByClauseContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::LimitClauseContext*>(MySqlParser::LimitClauseContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::LimitClauseContext>(x, rb_cLimitClauseContext, nullptr, nullptr);
}

template <>
Object to_ruby<LimitClauseContextProxy*>(LimitClauseContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<LimitClauseContextProxy>(x, rb_cLimitClauseContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::LockClauseContext*>(MySqlParser::LockClauseContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::LockClauseContext>(x, rb_cLockClauseContext, nullptr, nullptr);
}

template <>
Object to_ruby<LockClauseContextProxy*>(LockClauseContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<LockClauseContextProxy>(x, rb_cLockClauseContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::QuerySpecificationContext*>(MySqlParser::QuerySpecificationContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::QuerySpecificationContext>(x, rb_cQuerySpecificationContext, nullptr, nullptr);
}

template <>
Object to_ruby<QuerySpecificationContextProxy*>(QuerySpecificationContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<QuerySpecificationContextProxy>(x, rb_cQuerySpecificationContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::QueryExpressionContext*>(MySqlParser::QueryExpressionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::QueryExpressionContext>(x, rb_cQueryExpressionContext, nullptr, nullptr);
}

template <>
Object to_ruby<QueryExpressionContextProxy*>(QueryExpressionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<QueryExpressionContextProxy>(x, rb_cQueryExpressionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::QueryExpressionNointoContext*>(MySqlParser::QueryExpressionNointoContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::QueryExpressionNointoContext>(x, rb_cQueryExpressionNointoContext, nullptr, nullptr);
}

template <>
Object to_ruby<QueryExpressionNointoContextProxy*>(QueryExpressionNointoContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<QueryExpressionNointoContextProxy>(x, rb_cQueryExpressionNointoContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::UnionParenthesisSelectContext*>(MySqlParser::UnionParenthesisSelectContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::UnionParenthesisSelectContext>(x, rb_cUnionParenthesisSelectContext, nullptr, nullptr);
}

template <>
Object to_ruby<UnionParenthesisSelectContextProxy*>(UnionParenthesisSelectContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<UnionParenthesisSelectContextProxy>(x, rb_cUnionParenthesisSelectContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::UnionParenthesisContext*>(MySqlParser::UnionParenthesisContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::UnionParenthesisContext>(x, rb_cUnionParenthesisContext, nullptr, nullptr);
}

template <>
Object to_ruby<UnionParenthesisContextProxy*>(UnionParenthesisContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<UnionParenthesisContextProxy>(x, rb_cUnionParenthesisContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::SimpleSelectContext*>(MySqlParser::SimpleSelectContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::SimpleSelectContext>(x, rb_cSimpleSelectContext, nullptr, nullptr);
}

template <>
Object to_ruby<SimpleSelectContextProxy*>(SimpleSelectContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<SimpleSelectContextProxy>(x, rb_cSimpleSelectContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::ParenthesisSelectContext*>(MySqlParser::ParenthesisSelectContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::ParenthesisSelectContext>(x, rb_cParenthesisSelectContext, nullptr, nullptr);
}

template <>
Object to_ruby<ParenthesisSelectContextProxy*>(ParenthesisSelectContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<ParenthesisSelectContextProxy>(x, rb_cParenthesisSelectContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::SingleUpdateStatementContext*>(MySqlParser::SingleUpdateStatementContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::SingleUpdateStatementContext>(x, rb_cSingleUpdateStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<SingleUpdateStatementContextProxy*>(SingleUpdateStatementContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<SingleUpdateStatementContextProxy>(x, rb_cSingleUpdateStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::MultipleUpdateStatementContext*>(MySqlParser::MultipleUpdateStatementContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::MultipleUpdateStatementContext>(x, rb_cMultipleUpdateStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<MultipleUpdateStatementContextProxy*>(MultipleUpdateStatementContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<MultipleUpdateStatementContextProxy>(x, rb_cMultipleUpdateStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::ExpressionsWithDefaultsContext*>(MySqlParser::ExpressionsWithDefaultsContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::ExpressionsWithDefaultsContext>(x, rb_cExpressionsWithDefaultsContext, nullptr, nullptr);
}

template <>
Object to_ruby<ExpressionsWithDefaultsContextProxy*>(ExpressionsWithDefaultsContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<ExpressionsWithDefaultsContextProxy>(x, rb_cExpressionsWithDefaultsContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::FullColumnNameContext*>(MySqlParser::FullColumnNameContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::FullColumnNameContext>(x, rb_cFullColumnNameContext, nullptr, nullptr);
}

template <>
Object to_ruby<FullColumnNameContextProxy*>(FullColumnNameContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<FullColumnNameContextProxy>(x, rb_cFullColumnNameContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::TableSourcesContext*>(MySqlParser::TableSourcesContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::TableSourcesContext>(x, rb_cTableSourcesContext, nullptr, nullptr);
}

template <>
Object to_ruby<TableSourcesContextProxy*>(TableSourcesContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<TableSourcesContextProxy>(x, rb_cTableSourcesContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::ComparisonOperatorContext*>(MySqlParser::ComparisonOperatorContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::ComparisonOperatorContext>(x, rb_cComparisonOperatorContext, nullptr, nullptr);
}

template <>
Object to_ruby<ComparisonOperatorContextProxy*>(ComparisonOperatorContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<ComparisonOperatorContextProxy>(x, rb_cComparisonOperatorContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::OrderByExpressionContext*>(MySqlParser::OrderByExpressionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::OrderByExpressionContext>(x, rb_cOrderByExpressionContext, nullptr, nullptr);
}

template <>
Object to_ruby<OrderByExpressionContextProxy*>(OrderByExpressionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<OrderByExpressionContextProxy>(x, rb_cOrderByExpressionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::TableSourceContext*>(MySqlParser::TableSourceContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::TableSourceContext>(x, rb_cTableSourceContext, nullptr, nullptr);
}

template <>
Object to_ruby<TableSourceContextProxy*>(TableSourceContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<TableSourceContextProxy>(x, rb_cTableSourceContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::TableSourceNestedContext*>(MySqlParser::TableSourceNestedContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::TableSourceNestedContext>(x, rb_cTableSourceNestedContext, nullptr, nullptr);
}

template <>
Object to_ruby<TableSourceNestedContextProxy*>(TableSourceNestedContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<TableSourceNestedContextProxy>(x, rb_cTableSourceNestedContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::TableSourceItemContext*>(MySqlParser::TableSourceItemContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::TableSourceItemContext>(x, rb_cTableSourceItemContext, nullptr, nullptr);
}

template <>
Object to_ruby<TableSourceItemContextProxy*>(TableSourceItemContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<TableSourceItemContextProxy>(x, rb_cTableSourceItemContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::JoinPartContext*>(MySqlParser::JoinPartContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::JoinPartContext>(x, rb_cJoinPartContext, nullptr, nullptr);
}

template <>
Object to_ruby<JoinPartContextProxy*>(JoinPartContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<JoinPartContextProxy>(x, rb_cJoinPartContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::TableSourceBaseContext*>(MySqlParser::TableSourceBaseContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::TableSourceBaseContext>(x, rb_cTableSourceBaseContext, nullptr, nullptr);
}

template <>
Object to_ruby<TableSourceBaseContextProxy*>(TableSourceBaseContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<TableSourceBaseContextProxy>(x, rb_cTableSourceBaseContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::SubqueryTableItemContext*>(MySqlParser::SubqueryTableItemContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::SubqueryTableItemContext>(x, rb_cSubqueryTableItemContext, nullptr, nullptr);
}

template <>
Object to_ruby<SubqueryTableItemContextProxy*>(SubqueryTableItemContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<SubqueryTableItemContextProxy>(x, rb_cSubqueryTableItemContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::AtomTableItemContext*>(MySqlParser::AtomTableItemContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::AtomTableItemContext>(x, rb_cAtomTableItemContext, nullptr, nullptr);
}

template <>
Object to_ruby<AtomTableItemContextProxy*>(AtomTableItemContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<AtomTableItemContextProxy>(x, rb_cAtomTableItemContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::IndexHintContext*>(MySqlParser::IndexHintContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::IndexHintContext>(x, rb_cIndexHintContext, nullptr, nullptr);
}

template <>
Object to_ruby<IndexHintContextProxy*>(IndexHintContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<IndexHintContextProxy>(x, rb_cIndexHintContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::TableSourcesItemContext*>(MySqlParser::TableSourcesItemContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::TableSourcesItemContext>(x, rb_cTableSourcesItemContext, nullptr, nullptr);
}

template <>
Object to_ruby<TableSourcesItemContextProxy*>(TableSourcesItemContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<TableSourcesItemContextProxy>(x, rb_cTableSourcesItemContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::IndexHintTypeContext*>(MySqlParser::IndexHintTypeContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::IndexHintTypeContext>(x, rb_cIndexHintTypeContext, nullptr, nullptr);
}

template <>
Object to_ruby<IndexHintTypeContextProxy*>(IndexHintTypeContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<IndexHintTypeContextProxy>(x, rb_cIndexHintTypeContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::InnerJoinContext*>(MySqlParser::InnerJoinContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::InnerJoinContext>(x, rb_cInnerJoinContext, nullptr, nullptr);
}

template <>
Object to_ruby<InnerJoinContextProxy*>(InnerJoinContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<InnerJoinContextProxy>(x, rb_cInnerJoinContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::NaturalJoinContext*>(MySqlParser::NaturalJoinContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::NaturalJoinContext>(x, rb_cNaturalJoinContext, nullptr, nullptr);
}

template <>
Object to_ruby<NaturalJoinContextProxy*>(NaturalJoinContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<NaturalJoinContextProxy>(x, rb_cNaturalJoinContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::OuterJoinContext*>(MySqlParser::OuterJoinContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::OuterJoinContext>(x, rb_cOuterJoinContext, nullptr, nullptr);
}

template <>
Object to_ruby<OuterJoinContextProxy*>(OuterJoinContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<OuterJoinContextProxy>(x, rb_cOuterJoinContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::StraightJoinContext*>(MySqlParser::StraightJoinContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::StraightJoinContext>(x, rb_cStraightJoinContext, nullptr, nullptr);
}

template <>
Object to_ruby<StraightJoinContextProxy*>(StraightJoinContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<StraightJoinContextProxy>(x, rb_cStraightJoinContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::SelectElementsContext*>(MySqlParser::SelectElementsContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::SelectElementsContext>(x, rb_cSelectElementsContext, nullptr, nullptr);
}

template <>
Object to_ruby<SelectElementsContextProxy*>(SelectElementsContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<SelectElementsContextProxy>(x, rb_cSelectElementsContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::SelectSpecContext*>(MySqlParser::SelectSpecContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::SelectSpecContext>(x, rb_cSelectSpecContext, nullptr, nullptr);
}

template <>
Object to_ruby<SelectSpecContextProxy*>(SelectSpecContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<SelectSpecContextProxy>(x, rb_cSelectSpecContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::SelectIntoExpressionContext*>(MySqlParser::SelectIntoExpressionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::SelectIntoExpressionContext>(x, rb_cSelectIntoExpressionContext, nullptr, nullptr);
}

template <>
Object to_ruby<SelectIntoExpressionContextProxy*>(SelectIntoExpressionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<SelectIntoExpressionContextProxy>(x, rb_cSelectIntoExpressionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::FromClauseContext*>(MySqlParser::FromClauseContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::FromClauseContext>(x, rb_cFromClauseContext, nullptr, nullptr);
}

template <>
Object to_ruby<FromClauseContextProxy*>(FromClauseContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<FromClauseContextProxy>(x, rb_cFromClauseContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::SelectElementContext*>(MySqlParser::SelectElementContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::SelectElementContext>(x, rb_cSelectElementContext, nullptr, nullptr);
}

template <>
Object to_ruby<SelectElementContextProxy*>(SelectElementContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<SelectElementContextProxy>(x, rb_cSelectElementContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::SelectExpressionElementContext*>(MySqlParser::SelectExpressionElementContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::SelectExpressionElementContext>(x, rb_cSelectExpressionElementContext, nullptr, nullptr);
}

template <>
Object to_ruby<SelectExpressionElementContextProxy*>(SelectExpressionElementContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<SelectExpressionElementContextProxy>(x, rb_cSelectExpressionElementContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::FunctionCallContext*>(MySqlParser::FunctionCallContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::FunctionCallContext>(x, rb_cFunctionCallContext, nullptr, nullptr);
}

template <>
Object to_ruby<FunctionCallContextProxy*>(FunctionCallContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<FunctionCallContextProxy>(x, rb_cFunctionCallContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::SelectFunctionElementContext*>(MySqlParser::SelectFunctionElementContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::SelectFunctionElementContext>(x, rb_cSelectFunctionElementContext, nullptr, nullptr);
}

template <>
Object to_ruby<SelectFunctionElementContextProxy*>(SelectFunctionElementContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<SelectFunctionElementContextProxy>(x, rb_cSelectFunctionElementContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::SelectStarElementContext*>(MySqlParser::SelectStarElementContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::SelectStarElementContext>(x, rb_cSelectStarElementContext, nullptr, nullptr);
}

template <>
Object to_ruby<SelectStarElementContextProxy*>(SelectStarElementContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<SelectStarElementContextProxy>(x, rb_cSelectStarElementContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::SelectColumnElementContext*>(MySqlParser::SelectColumnElementContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::SelectColumnElementContext>(x, rb_cSelectColumnElementContext, nullptr, nullptr);
}

template <>
Object to_ruby<SelectColumnElementContextProxy*>(SelectColumnElementContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<SelectColumnElementContextProxy>(x, rb_cSelectColumnElementContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::SelectIntoVariablesContext*>(MySqlParser::SelectIntoVariablesContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::SelectIntoVariablesContext>(x, rb_cSelectIntoVariablesContext, nullptr, nullptr);
}

template <>
Object to_ruby<SelectIntoVariablesContextProxy*>(SelectIntoVariablesContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<SelectIntoVariablesContextProxy>(x, rb_cSelectIntoVariablesContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::SelectIntoTextFileContext*>(MySqlParser::SelectIntoTextFileContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::SelectIntoTextFileContext>(x, rb_cSelectIntoTextFileContext, nullptr, nullptr);
}

template <>
Object to_ruby<SelectIntoTextFileContextProxy*>(SelectIntoTextFileContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<SelectIntoTextFileContextProxy>(x, rb_cSelectIntoTextFileContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::SelectIntoDumpFileContext*>(MySqlParser::SelectIntoDumpFileContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::SelectIntoDumpFileContext>(x, rb_cSelectIntoDumpFileContext, nullptr, nullptr);
}

template <>
Object to_ruby<SelectIntoDumpFileContextProxy*>(SelectIntoDumpFileContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<SelectIntoDumpFileContextProxy>(x, rb_cSelectIntoDumpFileContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::GroupByItemContext*>(MySqlParser::GroupByItemContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::GroupByItemContext>(x, rb_cGroupByItemContext, nullptr, nullptr);
}

template <>
Object to_ruby<GroupByItemContextProxy*>(GroupByItemContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<GroupByItemContextProxy>(x, rb_cGroupByItemContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::LimitClauseAtomContext*>(MySqlParser::LimitClauseAtomContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::LimitClauseAtomContext>(x, rb_cLimitClauseAtomContext, nullptr, nullptr);
}

template <>
Object to_ruby<LimitClauseAtomContextProxy*>(LimitClauseAtomContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<LimitClauseAtomContextProxy>(x, rb_cLimitClauseAtomContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::MysqlVariableContext*>(MySqlParser::MysqlVariableContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::MysqlVariableContext>(x, rb_cMysqlVariableContext, nullptr, nullptr);
}

template <>
Object to_ruby<MysqlVariableContextProxy*>(MysqlVariableContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<MysqlVariableContextProxy>(x, rb_cMysqlVariableContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::TransactionModeContext*>(MySqlParser::TransactionModeContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::TransactionModeContext>(x, rb_cTransactionModeContext, nullptr, nullptr);
}

template <>
Object to_ruby<TransactionModeContextProxy*>(TransactionModeContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<TransactionModeContextProxy>(x, rb_cTransactionModeContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::LockTableElementContext*>(MySqlParser::LockTableElementContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::LockTableElementContext>(x, rb_cLockTableElementContext, nullptr, nullptr);
}

template <>
Object to_ruby<LockTableElementContextProxy*>(LockTableElementContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<LockTableElementContextProxy>(x, rb_cLockTableElementContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::SetAutocommitStatementContext*>(MySqlParser::SetAutocommitStatementContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::SetAutocommitStatementContext>(x, rb_cSetAutocommitStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<SetAutocommitStatementContextProxy*>(SetAutocommitStatementContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<SetAutocommitStatementContextProxy>(x, rb_cSetAutocommitStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::SetTransactionStatementContext*>(MySqlParser::SetTransactionStatementContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::SetTransactionStatementContext>(x, rb_cSetTransactionStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<SetTransactionStatementContextProxy*>(SetTransactionStatementContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<SetTransactionStatementContextProxy>(x, rb_cSetTransactionStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::TransactionOptionContext*>(MySqlParser::TransactionOptionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::TransactionOptionContext>(x, rb_cTransactionOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<TransactionOptionContextProxy*>(TransactionOptionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<TransactionOptionContextProxy>(x, rb_cTransactionOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::LockActionContext*>(MySqlParser::LockActionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::LockActionContext>(x, rb_cLockActionContext, nullptr, nullptr);
}

template <>
Object to_ruby<LockActionContextProxy*>(LockActionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<LockActionContextProxy>(x, rb_cLockActionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::TransactionLevelContext*>(MySqlParser::TransactionLevelContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::TransactionLevelContext>(x, rb_cTransactionLevelContext, nullptr, nullptr);
}

template <>
Object to_ruby<TransactionLevelContextProxy*>(TransactionLevelContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<TransactionLevelContextProxy>(x, rb_cTransactionLevelContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::MasterOptionContext*>(MySqlParser::MasterOptionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::MasterOptionContext>(x, rb_cMasterOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MasterOptionContextProxy*>(MasterOptionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<MasterOptionContextProxy>(x, rb_cMasterOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::ChannelOptionContext*>(MySqlParser::ChannelOptionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::ChannelOptionContext>(x, rb_cChannelOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<ChannelOptionContextProxy*>(ChannelOptionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<ChannelOptionContextProxy>(x, rb_cChannelOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::ReplicationFilterContext*>(MySqlParser::ReplicationFilterContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::ReplicationFilterContext>(x, rb_cReplicationFilterContext, nullptr, nullptr);
}

template <>
Object to_ruby<ReplicationFilterContextProxy*>(ReplicationFilterContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<ReplicationFilterContextProxy>(x, rb_cReplicationFilterContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::ThreadTypeContext*>(MySqlParser::ThreadTypeContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::ThreadTypeContext>(x, rb_cThreadTypeContext, nullptr, nullptr);
}

template <>
Object to_ruby<ThreadTypeContextProxy*>(ThreadTypeContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<ThreadTypeContextProxy>(x, rb_cThreadTypeContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::UntilOptionContext*>(MySqlParser::UntilOptionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::UntilOptionContext>(x, rb_cUntilOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<UntilOptionContextProxy*>(UntilOptionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<UntilOptionContextProxy>(x, rb_cUntilOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::ConnectionOptionContext*>(MySqlParser::ConnectionOptionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::ConnectionOptionContext>(x, rb_cConnectionOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<ConnectionOptionContextProxy*>(ConnectionOptionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<ConnectionOptionContextProxy>(x, rb_cConnectionOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::StringMasterOptionContext*>(MySqlParser::StringMasterOptionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::StringMasterOptionContext>(x, rb_cStringMasterOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<StringMasterOptionContextProxy*>(StringMasterOptionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<StringMasterOptionContextProxy>(x, rb_cStringMasterOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::MasterStringOptionContext*>(MySqlParser::MasterStringOptionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::MasterStringOptionContext>(x, rb_cMasterStringOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MasterStringOptionContextProxy*>(MasterStringOptionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<MasterStringOptionContextProxy>(x, rb_cMasterStringOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::MasterRealOptionContext*>(MySqlParser::MasterRealOptionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::MasterRealOptionContext>(x, rb_cMasterRealOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MasterRealOptionContextProxy*>(MasterRealOptionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<MasterRealOptionContextProxy>(x, rb_cMasterRealOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::BoolMasterOptionContext*>(MySqlParser::BoolMasterOptionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::BoolMasterOptionContext>(x, rb_cBoolMasterOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<BoolMasterOptionContextProxy*>(BoolMasterOptionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<BoolMasterOptionContextProxy>(x, rb_cBoolMasterOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::MasterBoolOptionContext*>(MySqlParser::MasterBoolOptionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::MasterBoolOptionContext>(x, rb_cMasterBoolOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MasterBoolOptionContextProxy*>(MasterBoolOptionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<MasterBoolOptionContextProxy>(x, rb_cMasterBoolOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::MasterUidListOptionContext*>(MySqlParser::MasterUidListOptionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::MasterUidListOptionContext>(x, rb_cMasterUidListOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MasterUidListOptionContextProxy*>(MasterUidListOptionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<MasterUidListOptionContextProxy>(x, rb_cMasterUidListOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::DecimalMasterOptionContext*>(MySqlParser::DecimalMasterOptionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::DecimalMasterOptionContext>(x, rb_cDecimalMasterOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<DecimalMasterOptionContextProxy*>(DecimalMasterOptionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<DecimalMasterOptionContextProxy>(x, rb_cDecimalMasterOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::MasterDecimalOptionContext*>(MySqlParser::MasterDecimalOptionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::MasterDecimalOptionContext>(x, rb_cMasterDecimalOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MasterDecimalOptionContextProxy*>(MasterDecimalOptionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<MasterDecimalOptionContextProxy>(x, rb_cMasterDecimalOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::WildIgnoreTableReplicationContext*>(MySqlParser::WildIgnoreTableReplicationContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::WildIgnoreTableReplicationContext>(x, rb_cWildIgnoreTableReplicationContext, nullptr, nullptr);
}

template <>
Object to_ruby<WildIgnoreTableReplicationContextProxy*>(WildIgnoreTableReplicationContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<WildIgnoreTableReplicationContextProxy>(x, rb_cWildIgnoreTableReplicationContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::SimpleStringsContext*>(MySqlParser::SimpleStringsContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::SimpleStringsContext>(x, rb_cSimpleStringsContext, nullptr, nullptr);
}

template <>
Object to_ruby<SimpleStringsContextProxy*>(SimpleStringsContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<SimpleStringsContextProxy>(x, rb_cSimpleStringsContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::DoTableReplicationContext*>(MySqlParser::DoTableReplicationContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::DoTableReplicationContext>(x, rb_cDoTableReplicationContext, nullptr, nullptr);
}

template <>
Object to_ruby<DoTableReplicationContextProxy*>(DoTableReplicationContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<DoTableReplicationContextProxy>(x, rb_cDoTableReplicationContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::IgnoreTableReplicationContext*>(MySqlParser::IgnoreTableReplicationContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::IgnoreTableReplicationContext>(x, rb_cIgnoreTableReplicationContext, nullptr, nullptr);
}

template <>
Object to_ruby<IgnoreTableReplicationContextProxy*>(IgnoreTableReplicationContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<IgnoreTableReplicationContextProxy>(x, rb_cIgnoreTableReplicationContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::RewriteDbReplicationContext*>(MySqlParser::RewriteDbReplicationContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::RewriteDbReplicationContext>(x, rb_cRewriteDbReplicationContext, nullptr, nullptr);
}

template <>
Object to_ruby<RewriteDbReplicationContextProxy*>(RewriteDbReplicationContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<RewriteDbReplicationContextProxy>(x, rb_cRewriteDbReplicationContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::TablePairContext*>(MySqlParser::TablePairContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::TablePairContext>(x, rb_cTablePairContext, nullptr, nullptr);
}

template <>
Object to_ruby<TablePairContextProxy*>(TablePairContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<TablePairContextProxy>(x, rb_cTablePairContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::DoDbReplicationContext*>(MySqlParser::DoDbReplicationContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::DoDbReplicationContext>(x, rb_cDoDbReplicationContext, nullptr, nullptr);
}

template <>
Object to_ruby<DoDbReplicationContextProxy*>(DoDbReplicationContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<DoDbReplicationContextProxy>(x, rb_cDoDbReplicationContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::IgnoreDbReplicationContext*>(MySqlParser::IgnoreDbReplicationContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::IgnoreDbReplicationContext>(x, rb_cIgnoreDbReplicationContext, nullptr, nullptr);
}

template <>
Object to_ruby<IgnoreDbReplicationContextProxy*>(IgnoreDbReplicationContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<IgnoreDbReplicationContextProxy>(x, rb_cIgnoreDbReplicationContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::WildDoTableReplicationContext*>(MySqlParser::WildDoTableReplicationContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::WildDoTableReplicationContext>(x, rb_cWildDoTableReplicationContext, nullptr, nullptr);
}

template <>
Object to_ruby<WildDoTableReplicationContextProxy*>(WildDoTableReplicationContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<WildDoTableReplicationContextProxy>(x, rb_cWildDoTableReplicationContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::GtidsUntilOptionContext*>(MySqlParser::GtidsUntilOptionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::GtidsUntilOptionContext>(x, rb_cGtidsUntilOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<GtidsUntilOptionContextProxy*>(GtidsUntilOptionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<GtidsUntilOptionContextProxy>(x, rb_cGtidsUntilOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::GtuidSetContext*>(MySqlParser::GtuidSetContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::GtuidSetContext>(x, rb_cGtuidSetContext, nullptr, nullptr);
}

template <>
Object to_ruby<GtuidSetContextProxy*>(GtuidSetContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<GtuidSetContextProxy>(x, rb_cGtuidSetContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::SqlGapsUntilOptionContext*>(MySqlParser::SqlGapsUntilOptionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::SqlGapsUntilOptionContext>(x, rb_cSqlGapsUntilOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<SqlGapsUntilOptionContextProxy*>(SqlGapsUntilOptionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<SqlGapsUntilOptionContextProxy>(x, rb_cSqlGapsUntilOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::MasterLogUntilOptionContext*>(MySqlParser::MasterLogUntilOptionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::MasterLogUntilOptionContext>(x, rb_cMasterLogUntilOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MasterLogUntilOptionContextProxy*>(MasterLogUntilOptionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<MasterLogUntilOptionContextProxy>(x, rb_cMasterLogUntilOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::RelayLogUntilOptionContext*>(MySqlParser::RelayLogUntilOptionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::RelayLogUntilOptionContext>(x, rb_cRelayLogUntilOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<RelayLogUntilOptionContextProxy*>(RelayLogUntilOptionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<RelayLogUntilOptionContextProxy>(x, rb_cRelayLogUntilOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::PluginDirConnectionOptionContext*>(MySqlParser::PluginDirConnectionOptionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::PluginDirConnectionOptionContext>(x, rb_cPluginDirConnectionOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<PluginDirConnectionOptionContextProxy*>(PluginDirConnectionOptionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<PluginDirConnectionOptionContextProxy>(x, rb_cPluginDirConnectionOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::UserConnectionOptionContext*>(MySqlParser::UserConnectionOptionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::UserConnectionOptionContext>(x, rb_cUserConnectionOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<UserConnectionOptionContextProxy*>(UserConnectionOptionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<UserConnectionOptionContextProxy>(x, rb_cUserConnectionOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::DefaultAuthConnectionOptionContext*>(MySqlParser::DefaultAuthConnectionOptionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::DefaultAuthConnectionOptionContext>(x, rb_cDefaultAuthConnectionOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<DefaultAuthConnectionOptionContextProxy*>(DefaultAuthConnectionOptionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<DefaultAuthConnectionOptionContextProxy>(x, rb_cDefaultAuthConnectionOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::PasswordConnectionOptionContext*>(MySqlParser::PasswordConnectionOptionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::PasswordConnectionOptionContext>(x, rb_cPasswordConnectionOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<PasswordConnectionOptionContextProxy*>(PasswordConnectionOptionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<PasswordConnectionOptionContextProxy>(x, rb_cPasswordConnectionOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::UuidSetContext*>(MySqlParser::UuidSetContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::UuidSetContext>(x, rb_cUuidSetContext, nullptr, nullptr);
}

template <>
Object to_ruby<UuidSetContextProxy*>(UuidSetContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<UuidSetContextProxy>(x, rb_cUuidSetContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::XidContext*>(MySqlParser::XidContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::XidContext>(x, rb_cXidContext, nullptr, nullptr);
}

template <>
Object to_ruby<XidContextProxy*>(XidContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<XidContextProxy>(x, rb_cXidContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::UserVariablesContext*>(MySqlParser::UserVariablesContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::UserVariablesContext>(x, rb_cUserVariablesContext, nullptr, nullptr);
}

template <>
Object to_ruby<UserVariablesContextProxy*>(UserVariablesContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<UserVariablesContextProxy>(x, rb_cUserVariablesContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::DeclareVariableContext*>(MySqlParser::DeclareVariableContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::DeclareVariableContext>(x, rb_cDeclareVariableContext, nullptr, nullptr);
}

template <>
Object to_ruby<DeclareVariableContextProxy*>(DeclareVariableContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<DeclareVariableContextProxy>(x, rb_cDeclareVariableContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::DeclareConditionContext*>(MySqlParser::DeclareConditionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::DeclareConditionContext>(x, rb_cDeclareConditionContext, nullptr, nullptr);
}

template <>
Object to_ruby<DeclareConditionContextProxy*>(DeclareConditionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<DeclareConditionContextProxy>(x, rb_cDeclareConditionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::DeclareCursorContext*>(MySqlParser::DeclareCursorContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::DeclareCursorContext>(x, rb_cDeclareCursorContext, nullptr, nullptr);
}

template <>
Object to_ruby<DeclareCursorContextProxy*>(DeclareCursorContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<DeclareCursorContextProxy>(x, rb_cDeclareCursorContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::DeclareHandlerContext*>(MySqlParser::DeclareHandlerContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::DeclareHandlerContext>(x, rb_cDeclareHandlerContext, nullptr, nullptr);
}

template <>
Object to_ruby<DeclareHandlerContextProxy*>(DeclareHandlerContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<DeclareHandlerContextProxy>(x, rb_cDeclareHandlerContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::ProcedureSqlStatementContext*>(MySqlParser::ProcedureSqlStatementContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::ProcedureSqlStatementContext>(x, rb_cProcedureSqlStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<ProcedureSqlStatementContextProxy*>(ProcedureSqlStatementContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<ProcedureSqlStatementContextProxy>(x, rb_cProcedureSqlStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::CaseAlternativeContext*>(MySqlParser::CaseAlternativeContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::CaseAlternativeContext>(x, rb_cCaseAlternativeContext, nullptr, nullptr);
}

template <>
Object to_ruby<CaseAlternativeContextProxy*>(CaseAlternativeContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<CaseAlternativeContextProxy>(x, rb_cCaseAlternativeContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::ElifAlternativeContext*>(MySqlParser::ElifAlternativeContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::ElifAlternativeContext>(x, rb_cElifAlternativeContext, nullptr, nullptr);
}

template <>
Object to_ruby<ElifAlternativeContextProxy*>(ElifAlternativeContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<ElifAlternativeContextProxy>(x, rb_cElifAlternativeContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::CloseCursorContext*>(MySqlParser::CloseCursorContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::CloseCursorContext>(x, rb_cCloseCursorContext, nullptr, nullptr);
}

template <>
Object to_ruby<CloseCursorContextProxy*>(CloseCursorContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<CloseCursorContextProxy>(x, rb_cCloseCursorContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::OpenCursorContext*>(MySqlParser::OpenCursorContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::OpenCursorContext>(x, rb_cOpenCursorContext, nullptr, nullptr);
}

template <>
Object to_ruby<OpenCursorContextProxy*>(OpenCursorContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<OpenCursorContextProxy>(x, rb_cOpenCursorContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::FetchCursorContext*>(MySqlParser::FetchCursorContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::FetchCursorContext>(x, rb_cFetchCursorContext, nullptr, nullptr);
}

template <>
Object to_ruby<FetchCursorContextProxy*>(FetchCursorContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<FetchCursorContextProxy>(x, rb_cFetchCursorContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::HandlerConditionValueContext*>(MySqlParser::HandlerConditionValueContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::HandlerConditionValueContext>(x, rb_cHandlerConditionValueContext, nullptr, nullptr);
}

template <>
Object to_ruby<HandlerConditionValueContextProxy*>(HandlerConditionValueContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<HandlerConditionValueContextProxy>(x, rb_cHandlerConditionValueContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::HandlerConditionWarningContext*>(MySqlParser::HandlerConditionWarningContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::HandlerConditionWarningContext>(x, rb_cHandlerConditionWarningContext, nullptr, nullptr);
}

template <>
Object to_ruby<HandlerConditionWarningContextProxy*>(HandlerConditionWarningContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<HandlerConditionWarningContextProxy>(x, rb_cHandlerConditionWarningContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::HandlerConditionCodeContext*>(MySqlParser::HandlerConditionCodeContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::HandlerConditionCodeContext>(x, rb_cHandlerConditionCodeContext, nullptr, nullptr);
}

template <>
Object to_ruby<HandlerConditionCodeContextProxy*>(HandlerConditionCodeContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<HandlerConditionCodeContextProxy>(x, rb_cHandlerConditionCodeContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::HandlerConditionNotfoundContext*>(MySqlParser::HandlerConditionNotfoundContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::HandlerConditionNotfoundContext>(x, rb_cHandlerConditionNotfoundContext, nullptr, nullptr);
}

template <>
Object to_ruby<HandlerConditionNotfoundContextProxy*>(HandlerConditionNotfoundContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<HandlerConditionNotfoundContextProxy>(x, rb_cHandlerConditionNotfoundContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::HandlerConditionStateContext*>(MySqlParser::HandlerConditionStateContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::HandlerConditionStateContext>(x, rb_cHandlerConditionStateContext, nullptr, nullptr);
}

template <>
Object to_ruby<HandlerConditionStateContextProxy*>(HandlerConditionStateContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<HandlerConditionStateContextProxy>(x, rb_cHandlerConditionStateContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::HandlerConditionExceptionContext*>(MySqlParser::HandlerConditionExceptionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::HandlerConditionExceptionContext>(x, rb_cHandlerConditionExceptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<HandlerConditionExceptionContextProxy*>(HandlerConditionExceptionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<HandlerConditionExceptionContextProxy>(x, rb_cHandlerConditionExceptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::HandlerConditionNameContext*>(MySqlParser::HandlerConditionNameContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::HandlerConditionNameContext>(x, rb_cHandlerConditionNameContext, nullptr, nullptr);
}

template <>
Object to_ruby<HandlerConditionNameContextProxy*>(HandlerConditionNameContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<HandlerConditionNameContextProxy>(x, rb_cHandlerConditionNameContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::AlterUserMysqlV56Context*>(MySqlParser::AlterUserMysqlV56Context* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::AlterUserMysqlV56Context>(x, rb_cAlterUserMysqlV56Context, nullptr, nullptr);
}

template <>
Object to_ruby<AlterUserMysqlV56ContextProxy*>(AlterUserMysqlV56ContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<AlterUserMysqlV56ContextProxy>(x, rb_cAlterUserMysqlV56Context, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::UserSpecificationContext*>(MySqlParser::UserSpecificationContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::UserSpecificationContext>(x, rb_cUserSpecificationContext, nullptr, nullptr);
}

template <>
Object to_ruby<UserSpecificationContextProxy*>(UserSpecificationContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<UserSpecificationContextProxy>(x, rb_cUserSpecificationContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::AlterUserMysqlV57Context*>(MySqlParser::AlterUserMysqlV57Context* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::AlterUserMysqlV57Context>(x, rb_cAlterUserMysqlV57Context, nullptr, nullptr);
}

template <>
Object to_ruby<AlterUserMysqlV57ContextProxy*>(AlterUserMysqlV57ContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<AlterUserMysqlV57ContextProxy>(x, rb_cAlterUserMysqlV57Context, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::UserAuthOptionContext*>(MySqlParser::UserAuthOptionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::UserAuthOptionContext>(x, rb_cUserAuthOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<UserAuthOptionContextProxy*>(UserAuthOptionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<UserAuthOptionContextProxy>(x, rb_cUserAuthOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::UserPasswordOptionContext*>(MySqlParser::UserPasswordOptionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::UserPasswordOptionContext>(x, rb_cUserPasswordOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<UserPasswordOptionContextProxy*>(UserPasswordOptionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<UserPasswordOptionContextProxy>(x, rb_cUserPasswordOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::UserLockOptionContext*>(MySqlParser::UserLockOptionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::UserLockOptionContext>(x, rb_cUserLockOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<UserLockOptionContextProxy*>(UserLockOptionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<UserLockOptionContextProxy>(x, rb_cUserLockOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::TlsOptionContext*>(MySqlParser::TlsOptionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::TlsOptionContext>(x, rb_cTlsOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<TlsOptionContextProxy*>(TlsOptionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<TlsOptionContextProxy>(x, rb_cTlsOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::UserResourceOptionContext*>(MySqlParser::UserResourceOptionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::UserResourceOptionContext>(x, rb_cUserResourceOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<UserResourceOptionContextProxy*>(UserResourceOptionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<UserResourceOptionContextProxy>(x, rb_cUserResourceOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::CreateUserMysqlV57Context*>(MySqlParser::CreateUserMysqlV57Context* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::CreateUserMysqlV57Context>(x, rb_cCreateUserMysqlV57Context, nullptr, nullptr);
}

template <>
Object to_ruby<CreateUserMysqlV57ContextProxy*>(CreateUserMysqlV57ContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<CreateUserMysqlV57ContextProxy>(x, rb_cCreateUserMysqlV57Context, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::CreateUserMysqlV56Context*>(MySqlParser::CreateUserMysqlV56Context* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::CreateUserMysqlV56Context>(x, rb_cCreateUserMysqlV56Context, nullptr, nullptr);
}

template <>
Object to_ruby<CreateUserMysqlV56ContextProxy*>(CreateUserMysqlV56ContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<CreateUserMysqlV56ContextProxy>(x, rb_cCreateUserMysqlV56Context, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::PrivelegeClauseContext*>(MySqlParser::PrivelegeClauseContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::PrivelegeClauseContext>(x, rb_cPrivelegeClauseContext, nullptr, nullptr);
}

template <>
Object to_ruby<PrivelegeClauseContextProxy*>(PrivelegeClauseContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<PrivelegeClauseContextProxy>(x, rb_cPrivelegeClauseContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::PrivilegeLevelContext*>(MySqlParser::PrivilegeLevelContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::PrivilegeLevelContext>(x, rb_cPrivilegeLevelContext, nullptr, nullptr);
}

template <>
Object to_ruby<PrivilegeLevelContextProxy*>(PrivilegeLevelContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<PrivilegeLevelContextProxy>(x, rb_cPrivilegeLevelContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::RenameUserClauseContext*>(MySqlParser::RenameUserClauseContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::RenameUserClauseContext>(x, rb_cRenameUserClauseContext, nullptr, nullptr);
}

template <>
Object to_ruby<RenameUserClauseContextProxy*>(RenameUserClauseContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<RenameUserClauseContextProxy>(x, rb_cRenameUserClauseContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::DetailRevokeContext*>(MySqlParser::DetailRevokeContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::DetailRevokeContext>(x, rb_cDetailRevokeContext, nullptr, nullptr);
}

template <>
Object to_ruby<DetailRevokeContextProxy*>(DetailRevokeContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<DetailRevokeContextProxy>(x, rb_cDetailRevokeContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::ShortRevokeContext*>(MySqlParser::ShortRevokeContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::ShortRevokeContext>(x, rb_cShortRevokeContext, nullptr, nullptr);
}

template <>
Object to_ruby<ShortRevokeContextProxy*>(ShortRevokeContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<ShortRevokeContextProxy>(x, rb_cShortRevokeContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::SetPasswordStatementContext*>(MySqlParser::SetPasswordStatementContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::SetPasswordStatementContext>(x, rb_cSetPasswordStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<SetPasswordStatementContextProxy*>(SetPasswordStatementContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<SetPasswordStatementContextProxy>(x, rb_cSetPasswordStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::PasswordFunctionClauseContext*>(MySqlParser::PasswordFunctionClauseContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::PasswordFunctionClauseContext>(x, rb_cPasswordFunctionClauseContext, nullptr, nullptr);
}

template <>
Object to_ruby<PasswordFunctionClauseContextProxy*>(PasswordFunctionClauseContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<PasswordFunctionClauseContextProxy>(x, rb_cPasswordFunctionClauseContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::SimpleAuthOptionContext*>(MySqlParser::SimpleAuthOptionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::SimpleAuthOptionContext>(x, rb_cSimpleAuthOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<SimpleAuthOptionContextProxy*>(SimpleAuthOptionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<SimpleAuthOptionContextProxy>(x, rb_cSimpleAuthOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::PasswordAuthOptionContext*>(MySqlParser::PasswordAuthOptionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::PasswordAuthOptionContext>(x, rb_cPasswordAuthOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<PasswordAuthOptionContextProxy*>(PasswordAuthOptionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<PasswordAuthOptionContextProxy>(x, rb_cPasswordAuthOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::StringAuthOptionContext*>(MySqlParser::StringAuthOptionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::StringAuthOptionContext>(x, rb_cStringAuthOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<StringAuthOptionContextProxy*>(StringAuthOptionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<StringAuthOptionContextProxy>(x, rb_cStringAuthOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::AuthPluginContext*>(MySqlParser::AuthPluginContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::AuthPluginContext>(x, rb_cAuthPluginContext, nullptr, nullptr);
}

template <>
Object to_ruby<AuthPluginContextProxy*>(AuthPluginContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<AuthPluginContextProxy>(x, rb_cAuthPluginContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::HashAuthOptionContext*>(MySqlParser::HashAuthOptionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::HashAuthOptionContext>(x, rb_cHashAuthOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<HashAuthOptionContextProxy*>(HashAuthOptionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<HashAuthOptionContextProxy>(x, rb_cHashAuthOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::PrivilegeContext*>(MySqlParser::PrivilegeContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::PrivilegeContext>(x, rb_cPrivilegeContext, nullptr, nullptr);
}

template <>
Object to_ruby<PrivilegeContextProxy*>(PrivilegeContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<PrivilegeContextProxy>(x, rb_cPrivilegeContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::DefiniteSchemaPrivLevelContext*>(MySqlParser::DefiniteSchemaPrivLevelContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::DefiniteSchemaPrivLevelContext>(x, rb_cDefiniteSchemaPrivLevelContext, nullptr, nullptr);
}

template <>
Object to_ruby<DefiniteSchemaPrivLevelContextProxy*>(DefiniteSchemaPrivLevelContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<DefiniteSchemaPrivLevelContextProxy>(x, rb_cDefiniteSchemaPrivLevelContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::DefiniteFullTablePrivLevel2Context*>(MySqlParser::DefiniteFullTablePrivLevel2Context* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::DefiniteFullTablePrivLevel2Context>(x, rb_cDefiniteFullTablePrivLevel2Context, nullptr, nullptr);
}

template <>
Object to_ruby<DefiniteFullTablePrivLevel2ContextProxy*>(DefiniteFullTablePrivLevel2ContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<DefiniteFullTablePrivLevel2ContextProxy>(x, rb_cDefiniteFullTablePrivLevel2Context, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::DottedIdContext*>(MySqlParser::DottedIdContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::DottedIdContext>(x, rb_cDottedIdContext, nullptr, nullptr);
}

template <>
Object to_ruby<DottedIdContextProxy*>(DottedIdContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<DottedIdContextProxy>(x, rb_cDottedIdContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::DefiniteFullTablePrivLevelContext*>(MySqlParser::DefiniteFullTablePrivLevelContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::DefiniteFullTablePrivLevelContext>(x, rb_cDefiniteFullTablePrivLevelContext, nullptr, nullptr);
}

template <>
Object to_ruby<DefiniteFullTablePrivLevelContextProxy*>(DefiniteFullTablePrivLevelContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<DefiniteFullTablePrivLevelContextProxy>(x, rb_cDefiniteFullTablePrivLevelContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::GlobalPrivLevelContext*>(MySqlParser::GlobalPrivLevelContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::GlobalPrivLevelContext>(x, rb_cGlobalPrivLevelContext, nullptr, nullptr);
}

template <>
Object to_ruby<GlobalPrivLevelContextProxy*>(GlobalPrivLevelContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<GlobalPrivLevelContextProxy>(x, rb_cGlobalPrivLevelContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::DefiniteTablePrivLevelContext*>(MySqlParser::DefiniteTablePrivLevelContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::DefiniteTablePrivLevelContext>(x, rb_cDefiniteTablePrivLevelContext, nullptr, nullptr);
}

template <>
Object to_ruby<DefiniteTablePrivLevelContextProxy*>(DefiniteTablePrivLevelContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<DefiniteTablePrivLevelContextProxy>(x, rb_cDefiniteTablePrivLevelContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::CurrentSchemaPriviLevelContext*>(MySqlParser::CurrentSchemaPriviLevelContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::CurrentSchemaPriviLevelContext>(x, rb_cCurrentSchemaPriviLevelContext, nullptr, nullptr);
}

template <>
Object to_ruby<CurrentSchemaPriviLevelContextProxy*>(CurrentSchemaPriviLevelContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<CurrentSchemaPriviLevelContextProxy>(x, rb_cCurrentSchemaPriviLevelContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::CheckTableOptionContext*>(MySqlParser::CheckTableOptionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::CheckTableOptionContext>(x, rb_cCheckTableOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<CheckTableOptionContextProxy*>(CheckTableOptionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<CheckTableOptionContextProxy>(x, rb_cCheckTableOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::SetTransactionContext*>(MySqlParser::SetTransactionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::SetTransactionContext>(x, rb_cSetTransactionContext, nullptr, nullptr);
}

template <>
Object to_ruby<SetTransactionContextProxy*>(SetTransactionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<SetTransactionContextProxy>(x, rb_cSetTransactionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::SetCharsetContext*>(MySqlParser::SetCharsetContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::SetCharsetContext>(x, rb_cSetCharsetContext, nullptr, nullptr);
}

template <>
Object to_ruby<SetCharsetContextProxy*>(SetCharsetContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<SetCharsetContextProxy>(x, rb_cSetCharsetContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::SetNamesContext*>(MySqlParser::SetNamesContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::SetNamesContext>(x, rb_cSetNamesContext, nullptr, nullptr);
}

template <>
Object to_ruby<SetNamesContextProxy*>(SetNamesContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<SetNamesContextProxy>(x, rb_cSetNamesContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::SetPasswordContext*>(MySqlParser::SetPasswordContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::SetPasswordContext>(x, rb_cSetPasswordContext, nullptr, nullptr);
}

template <>
Object to_ruby<SetPasswordContextProxy*>(SetPasswordContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<SetPasswordContextProxy>(x, rb_cSetPasswordContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::SetAutocommitContext*>(MySqlParser::SetAutocommitContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::SetAutocommitContext>(x, rb_cSetAutocommitContext, nullptr, nullptr);
}

template <>
Object to_ruby<SetAutocommitContextProxy*>(SetAutocommitContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<SetAutocommitContextProxy>(x, rb_cSetAutocommitContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::SetNewValueInsideTriggerContext*>(MySqlParser::SetNewValueInsideTriggerContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::SetNewValueInsideTriggerContext>(x, rb_cSetNewValueInsideTriggerContext, nullptr, nullptr);
}

template <>
Object to_ruby<SetNewValueInsideTriggerContextProxy*>(SetNewValueInsideTriggerContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<SetNewValueInsideTriggerContextProxy>(x, rb_cSetNewValueInsideTriggerContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::SetVariableContext*>(MySqlParser::SetVariableContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::SetVariableContext>(x, rb_cSetVariableContext, nullptr, nullptr);
}

template <>
Object to_ruby<SetVariableContextProxy*>(SetVariableContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<SetVariableContextProxy>(x, rb_cSetVariableContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::VariableClauseContext*>(MySqlParser::VariableClauseContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::VariableClauseContext>(x, rb_cVariableClauseContext, nullptr, nullptr);
}

template <>
Object to_ruby<VariableClauseContextProxy*>(VariableClauseContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<VariableClauseContextProxy>(x, rb_cVariableClauseContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::ShowOpenTablesContext*>(MySqlParser::ShowOpenTablesContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::ShowOpenTablesContext>(x, rb_cShowOpenTablesContext, nullptr, nullptr);
}

template <>
Object to_ruby<ShowOpenTablesContextProxy*>(ShowOpenTablesContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<ShowOpenTablesContextProxy>(x, rb_cShowOpenTablesContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::ShowFilterContext*>(MySqlParser::ShowFilterContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::ShowFilterContext>(x, rb_cShowFilterContext, nullptr, nullptr);
}

template <>
Object to_ruby<ShowFilterContextProxy*>(ShowFilterContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<ShowFilterContextProxy>(x, rb_cShowFilterContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::ShowGlobalInfoContext*>(MySqlParser::ShowGlobalInfoContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::ShowGlobalInfoContext>(x, rb_cShowGlobalInfoContext, nullptr, nullptr);
}

template <>
Object to_ruby<ShowGlobalInfoContextProxy*>(ShowGlobalInfoContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<ShowGlobalInfoContextProxy>(x, rb_cShowGlobalInfoContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::ShowGlobalInfoClauseContext*>(MySqlParser::ShowGlobalInfoClauseContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::ShowGlobalInfoClauseContext>(x, rb_cShowGlobalInfoClauseContext, nullptr, nullptr);
}

template <>
Object to_ruby<ShowGlobalInfoClauseContextProxy*>(ShowGlobalInfoClauseContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<ShowGlobalInfoClauseContextProxy>(x, rb_cShowGlobalInfoClauseContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::ShowCreateFullIdObjectContext*>(MySqlParser::ShowCreateFullIdObjectContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::ShowCreateFullIdObjectContext>(x, rb_cShowCreateFullIdObjectContext, nullptr, nullptr);
}

template <>
Object to_ruby<ShowCreateFullIdObjectContextProxy*>(ShowCreateFullIdObjectContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<ShowCreateFullIdObjectContextProxy>(x, rb_cShowCreateFullIdObjectContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::ShowCreateUserContext*>(MySqlParser::ShowCreateUserContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::ShowCreateUserContext>(x, rb_cShowCreateUserContext, nullptr, nullptr);
}

template <>
Object to_ruby<ShowCreateUserContextProxy*>(ShowCreateUserContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<ShowCreateUserContextProxy>(x, rb_cShowCreateUserContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::ShowErrorsContext*>(MySqlParser::ShowErrorsContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::ShowErrorsContext>(x, rb_cShowErrorsContext, nullptr, nullptr);
}

template <>
Object to_ruby<ShowErrorsContextProxy*>(ShowErrorsContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<ShowErrorsContextProxy>(x, rb_cShowErrorsContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::ShowCountErrorsContext*>(MySqlParser::ShowCountErrorsContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::ShowCountErrorsContext>(x, rb_cShowCountErrorsContext, nullptr, nullptr);
}

template <>
Object to_ruby<ShowCountErrorsContextProxy*>(ShowCountErrorsContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<ShowCountErrorsContextProxy>(x, rb_cShowCountErrorsContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::ShowObjectFilterContext*>(MySqlParser::ShowObjectFilterContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::ShowObjectFilterContext>(x, rb_cShowObjectFilterContext, nullptr, nullptr);
}

template <>
Object to_ruby<ShowObjectFilterContextProxy*>(ShowObjectFilterContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<ShowObjectFilterContextProxy>(x, rb_cShowObjectFilterContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::ShowCommonEntityContext*>(MySqlParser::ShowCommonEntityContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::ShowCommonEntityContext>(x, rb_cShowCommonEntityContext, nullptr, nullptr);
}

template <>
Object to_ruby<ShowCommonEntityContextProxy*>(ShowCommonEntityContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<ShowCommonEntityContextProxy>(x, rb_cShowCommonEntityContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::ShowCreateDbContext*>(MySqlParser::ShowCreateDbContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::ShowCreateDbContext>(x, rb_cShowCreateDbContext, nullptr, nullptr);
}

template <>
Object to_ruby<ShowCreateDbContextProxy*>(ShowCreateDbContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<ShowCreateDbContextProxy>(x, rb_cShowCreateDbContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::ShowEngineContext*>(MySqlParser::ShowEngineContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::ShowEngineContext>(x, rb_cShowEngineContext, nullptr, nullptr);
}

template <>
Object to_ruby<ShowEngineContextProxy*>(ShowEngineContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<ShowEngineContextProxy>(x, rb_cShowEngineContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::ShowSchemaFilterContext*>(MySqlParser::ShowSchemaFilterContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::ShowSchemaFilterContext>(x, rb_cShowSchemaFilterContext, nullptr, nullptr);
}

template <>
Object to_ruby<ShowSchemaFilterContextProxy*>(ShowSchemaFilterContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<ShowSchemaFilterContextProxy>(x, rb_cShowSchemaFilterContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::ShowSchemaEntityContext*>(MySqlParser::ShowSchemaEntityContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::ShowSchemaEntityContext>(x, rb_cShowSchemaEntityContext, nullptr, nullptr);
}

template <>
Object to_ruby<ShowSchemaEntityContextProxy*>(ShowSchemaEntityContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<ShowSchemaEntityContextProxy>(x, rb_cShowSchemaEntityContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::ShowIndexesContext*>(MySqlParser::ShowIndexesContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::ShowIndexesContext>(x, rb_cShowIndexesContext, nullptr, nullptr);
}

template <>
Object to_ruby<ShowIndexesContextProxy*>(ShowIndexesContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<ShowIndexesContextProxy>(x, rb_cShowIndexesContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::ShowLogEventsContext*>(MySqlParser::ShowLogEventsContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::ShowLogEventsContext>(x, rb_cShowLogEventsContext, nullptr, nullptr);
}

template <>
Object to_ruby<ShowLogEventsContextProxy*>(ShowLogEventsContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<ShowLogEventsContextProxy>(x, rb_cShowLogEventsContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::ShowMasterLogsContext*>(MySqlParser::ShowMasterLogsContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::ShowMasterLogsContext>(x, rb_cShowMasterLogsContext, nullptr, nullptr);
}

template <>
Object to_ruby<ShowMasterLogsContextProxy*>(ShowMasterLogsContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<ShowMasterLogsContextProxy>(x, rb_cShowMasterLogsContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::ShowGrantsContext*>(MySqlParser::ShowGrantsContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::ShowGrantsContext>(x, rb_cShowGrantsContext, nullptr, nullptr);
}

template <>
Object to_ruby<ShowGrantsContextProxy*>(ShowGrantsContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<ShowGrantsContextProxy>(x, rb_cShowGrantsContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::ShowSlaveStatusContext*>(MySqlParser::ShowSlaveStatusContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::ShowSlaveStatusContext>(x, rb_cShowSlaveStatusContext, nullptr, nullptr);
}

template <>
Object to_ruby<ShowSlaveStatusContextProxy*>(ShowSlaveStatusContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<ShowSlaveStatusContextProxy>(x, rb_cShowSlaveStatusContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::ShowRoutineContext*>(MySqlParser::ShowRoutineContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::ShowRoutineContext>(x, rb_cShowRoutineContext, nullptr, nullptr);
}

template <>
Object to_ruby<ShowRoutineContextProxy*>(ShowRoutineContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<ShowRoutineContextProxy>(x, rb_cShowRoutineContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::ShowProfileContext*>(MySqlParser::ShowProfileContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::ShowProfileContext>(x, rb_cShowProfileContext, nullptr, nullptr);
}

template <>
Object to_ruby<ShowProfileContextProxy*>(ShowProfileContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<ShowProfileContextProxy>(x, rb_cShowProfileContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::ShowProfileTypeContext*>(MySqlParser::ShowProfileTypeContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::ShowProfileTypeContext>(x, rb_cShowProfileTypeContext, nullptr, nullptr);
}

template <>
Object to_ruby<ShowProfileTypeContextProxy*>(ShowProfileTypeContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<ShowProfileTypeContextProxy>(x, rb_cShowProfileTypeContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::ShowColumnsContext*>(MySqlParser::ShowColumnsContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::ShowColumnsContext>(x, rb_cShowColumnsContext, nullptr, nullptr);
}

template <>
Object to_ruby<ShowColumnsContextProxy*>(ShowColumnsContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<ShowColumnsContextProxy>(x, rb_cShowColumnsContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::TableIndexesContext*>(MySqlParser::TableIndexesContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::TableIndexesContext>(x, rb_cTableIndexesContext, nullptr, nullptr);
}

template <>
Object to_ruby<TableIndexesContextProxy*>(TableIndexesContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<TableIndexesContextProxy>(x, rb_cTableIndexesContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::FlushOptionContext*>(MySqlParser::FlushOptionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::FlushOptionContext>(x, rb_cFlushOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<FlushOptionContextProxy*>(FlushOptionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<FlushOptionContextProxy>(x, rb_cFlushOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::LoadedTableIndexesContext*>(MySqlParser::LoadedTableIndexesContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::LoadedTableIndexesContext>(x, rb_cLoadedTableIndexesContext, nullptr, nullptr);
}

template <>
Object to_ruby<LoadedTableIndexesContextProxy*>(LoadedTableIndexesContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<LoadedTableIndexesContextProxy>(x, rb_cLoadedTableIndexesContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::TableFlushOptionContext*>(MySqlParser::TableFlushOptionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::TableFlushOptionContext>(x, rb_cTableFlushOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<TableFlushOptionContextProxy*>(TableFlushOptionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<TableFlushOptionContextProxy>(x, rb_cTableFlushOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::FlushTableOptionContext*>(MySqlParser::FlushTableOptionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::FlushTableOptionContext>(x, rb_cFlushTableOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<FlushTableOptionContextProxy*>(FlushTableOptionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<FlushTableOptionContextProxy>(x, rb_cFlushTableOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::ChannelFlushOptionContext*>(MySqlParser::ChannelFlushOptionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::ChannelFlushOptionContext>(x, rb_cChannelFlushOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<ChannelFlushOptionContextProxy*>(ChannelFlushOptionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<ChannelFlushOptionContextProxy>(x, rb_cChannelFlushOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::SimpleFlushOptionContext*>(MySqlParser::SimpleFlushOptionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::SimpleFlushOptionContext>(x, rb_cSimpleFlushOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<SimpleFlushOptionContextProxy*>(SimpleFlushOptionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<SimpleFlushOptionContextProxy>(x, rb_cSimpleFlushOptionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::DescribeObjectClauseContext*>(MySqlParser::DescribeObjectClauseContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::DescribeObjectClauseContext>(x, rb_cDescribeObjectClauseContext, nullptr, nullptr);
}

template <>
Object to_ruby<DescribeObjectClauseContextProxy*>(DescribeObjectClauseContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<DescribeObjectClauseContextProxy>(x, rb_cDescribeObjectClauseContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::SignalConditionInformationContext*>(MySqlParser::SignalConditionInformationContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::SignalConditionInformationContext>(x, rb_cSignalConditionInformationContext, nullptr, nullptr);
}

template <>
Object to_ruby<SignalConditionInformationContextProxy*>(SignalConditionInformationContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<SignalConditionInformationContextProxy>(x, rb_cSignalConditionInformationContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::DiagnosticsConditionInformationNameContext*>(MySqlParser::DiagnosticsConditionInformationNameContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::DiagnosticsConditionInformationNameContext>(x, rb_cDiagnosticsConditionInformationNameContext, nullptr, nullptr);
}

template <>
Object to_ruby<DiagnosticsConditionInformationNameContextProxy*>(DiagnosticsConditionInformationNameContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<DiagnosticsConditionInformationNameContextProxy>(x, rb_cDiagnosticsConditionInformationNameContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::DescribeStatementsContext*>(MySqlParser::DescribeStatementsContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::DescribeStatementsContext>(x, rb_cDescribeStatementsContext, nullptr, nullptr);
}

template <>
Object to_ruby<DescribeStatementsContextProxy*>(DescribeStatementsContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<DescribeStatementsContextProxy>(x, rb_cDescribeStatementsContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::DescribeConnectionContext*>(MySqlParser::DescribeConnectionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::DescribeConnectionContext>(x, rb_cDescribeConnectionContext, nullptr, nullptr);
}

template <>
Object to_ruby<DescribeConnectionContextProxy*>(DescribeConnectionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<DescribeConnectionContextProxy>(x, rb_cDescribeConnectionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::IndexColumnNameContext*>(MySqlParser::IndexColumnNameContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::IndexColumnNameContext>(x, rb_cIndexColumnNameContext, nullptr, nullptr);
}

template <>
Object to_ruby<IndexColumnNameContextProxy*>(IndexColumnNameContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<IndexColumnNameContextProxy>(x, rb_cIndexColumnNameContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::CharsetNameBaseContext*>(MySqlParser::CharsetNameBaseContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::CharsetNameBaseContext>(x, rb_cCharsetNameBaseContext, nullptr, nullptr);
}

template <>
Object to_ruby<CharsetNameBaseContextProxy*>(CharsetNameBaseContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<CharsetNameBaseContextProxy>(x, rb_cCharsetNameBaseContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::XuidStringIdContext*>(MySqlParser::XuidStringIdContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::XuidStringIdContext>(x, rb_cXuidStringIdContext, nullptr, nullptr);
}

template <>
Object to_ruby<XuidStringIdContextProxy*>(XuidStringIdContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<XuidStringIdContextProxy>(x, rb_cXuidStringIdContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::SimpleIdContext*>(MySqlParser::SimpleIdContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::SimpleIdContext>(x, rb_cSimpleIdContext, nullptr, nullptr);
}

template <>
Object to_ruby<SimpleIdContextProxy*>(SimpleIdContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<SimpleIdContextProxy>(x, rb_cSimpleIdContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::TransactionLevelBaseContext*>(MySqlParser::TransactionLevelBaseContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::TransactionLevelBaseContext>(x, rb_cTransactionLevelBaseContext, nullptr, nullptr);
}

template <>
Object to_ruby<TransactionLevelBaseContextProxy*>(TransactionLevelBaseContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<TransactionLevelBaseContextProxy>(x, rb_cTransactionLevelBaseContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::PrivilegesBaseContext*>(MySqlParser::PrivilegesBaseContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::PrivilegesBaseContext>(x, rb_cPrivilegesBaseContext, nullptr, nullptr);
}

template <>
Object to_ruby<PrivilegesBaseContextProxy*>(PrivilegesBaseContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<PrivilegesBaseContextProxy>(x, rb_cPrivilegesBaseContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::DataTypeBaseContext*>(MySqlParser::DataTypeBaseContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::DataTypeBaseContext>(x, rb_cDataTypeBaseContext, nullptr, nullptr);
}

template <>
Object to_ruby<DataTypeBaseContextProxy*>(DataTypeBaseContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<DataTypeBaseContextProxy>(x, rb_cDataTypeBaseContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::KeywordsCanBeIdContext*>(MySqlParser::KeywordsCanBeIdContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::KeywordsCanBeIdContext>(x, rb_cKeywordsCanBeIdContext, nullptr, nullptr);
}

template <>
Object to_ruby<KeywordsCanBeIdContextProxy*>(KeywordsCanBeIdContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<KeywordsCanBeIdContextProxy>(x, rb_cKeywordsCanBeIdContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::FunctionNameBaseContext*>(MySqlParser::FunctionNameBaseContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::FunctionNameBaseContext>(x, rb_cFunctionNameBaseContext, nullptr, nullptr);
}

template <>
Object to_ruby<FunctionNameBaseContextProxy*>(FunctionNameBaseContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<FunctionNameBaseContextProxy>(x, rb_cFunctionNameBaseContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::BooleanLiteralContext*>(MySqlParser::BooleanLiteralContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::BooleanLiteralContext>(x, rb_cBooleanLiteralContext, nullptr, nullptr);
}

template <>
Object to_ruby<BooleanLiteralContextProxy*>(BooleanLiteralContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<BooleanLiteralContextProxy>(x, rb_cBooleanLiteralContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::HexadecimalLiteralContext*>(MySqlParser::HexadecimalLiteralContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::HexadecimalLiteralContext>(x, rb_cHexadecimalLiteralContext, nullptr, nullptr);
}

template <>
Object to_ruby<HexadecimalLiteralContextProxy*>(HexadecimalLiteralContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<HexadecimalLiteralContextProxy>(x, rb_cHexadecimalLiteralContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::SpatialDataTypeContext*>(MySqlParser::SpatialDataTypeContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::SpatialDataTypeContext>(x, rb_cSpatialDataTypeContext, nullptr, nullptr);
}

template <>
Object to_ruby<SpatialDataTypeContextProxy*>(SpatialDataTypeContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<SpatialDataTypeContextProxy>(x, rb_cSpatialDataTypeContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::CollectionOptionsContext*>(MySqlParser::CollectionOptionsContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::CollectionOptionsContext>(x, rb_cCollectionOptionsContext, nullptr, nullptr);
}

template <>
Object to_ruby<CollectionOptionsContextProxy*>(CollectionOptionsContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<CollectionOptionsContextProxy>(x, rb_cCollectionOptionsContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::CollectionDataTypeContext*>(MySqlParser::CollectionDataTypeContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::CollectionDataTypeContext>(x, rb_cCollectionDataTypeContext, nullptr, nullptr);
}

template <>
Object to_ruby<CollectionDataTypeContextProxy*>(CollectionDataTypeContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<CollectionDataTypeContextProxy>(x, rb_cCollectionDataTypeContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::NationalVaryingStringDataTypeContext*>(MySqlParser::NationalVaryingStringDataTypeContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::NationalVaryingStringDataTypeContext>(x, rb_cNationalVaryingStringDataTypeContext, nullptr, nullptr);
}

template <>
Object to_ruby<NationalVaryingStringDataTypeContextProxy*>(NationalVaryingStringDataTypeContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<NationalVaryingStringDataTypeContextProxy>(x, rb_cNationalVaryingStringDataTypeContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::LengthOneDimensionContext*>(MySqlParser::LengthOneDimensionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::LengthOneDimensionContext>(x, rb_cLengthOneDimensionContext, nullptr, nullptr);
}

template <>
Object to_ruby<LengthOneDimensionContextProxy*>(LengthOneDimensionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<LengthOneDimensionContextProxy>(x, rb_cLengthOneDimensionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::DimensionDataTypeContext*>(MySqlParser::DimensionDataTypeContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::DimensionDataTypeContext>(x, rb_cDimensionDataTypeContext, nullptr, nullptr);
}

template <>
Object to_ruby<DimensionDataTypeContextProxy*>(DimensionDataTypeContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<DimensionDataTypeContextProxy>(x, rb_cDimensionDataTypeContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::LengthTwoDimensionContext*>(MySqlParser::LengthTwoDimensionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::LengthTwoDimensionContext>(x, rb_cLengthTwoDimensionContext, nullptr, nullptr);
}

template <>
Object to_ruby<LengthTwoDimensionContextProxy*>(LengthTwoDimensionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<LengthTwoDimensionContextProxy>(x, rb_cLengthTwoDimensionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::LengthTwoOptionalDimensionContext*>(MySqlParser::LengthTwoOptionalDimensionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::LengthTwoOptionalDimensionContext>(x, rb_cLengthTwoOptionalDimensionContext, nullptr, nullptr);
}

template <>
Object to_ruby<LengthTwoOptionalDimensionContextProxy*>(LengthTwoOptionalDimensionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<LengthTwoOptionalDimensionContextProxy>(x, rb_cLengthTwoOptionalDimensionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::StringDataTypeContext*>(MySqlParser::StringDataTypeContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::StringDataTypeContext>(x, rb_cStringDataTypeContext, nullptr, nullptr);
}

template <>
Object to_ruby<StringDataTypeContextProxy*>(StringDataTypeContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<StringDataTypeContextProxy>(x, rb_cStringDataTypeContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::NationalStringDataTypeContext*>(MySqlParser::NationalStringDataTypeContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::NationalStringDataTypeContext>(x, rb_cNationalStringDataTypeContext, nullptr, nullptr);
}

template <>
Object to_ruby<NationalStringDataTypeContextProxy*>(NationalStringDataTypeContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<NationalStringDataTypeContextProxy>(x, rb_cNationalStringDataTypeContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::SimpleDataTypeContext*>(MySqlParser::SimpleDataTypeContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::SimpleDataTypeContext>(x, rb_cSimpleDataTypeContext, nullptr, nullptr);
}

template <>
Object to_ruby<SimpleDataTypeContextProxy*>(SimpleDataTypeContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<SimpleDataTypeContextProxy>(x, rb_cSimpleDataTypeContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::ConvertedDataTypeContext*>(MySqlParser::ConvertedDataTypeContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::ConvertedDataTypeContext>(x, rb_cConvertedDataTypeContext, nullptr, nullptr);
}

template <>
Object to_ruby<ConvertedDataTypeContextProxy*>(ConvertedDataTypeContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<ConvertedDataTypeContextProxy>(x, rb_cConvertedDataTypeContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::ExpressionOrDefaultContext*>(MySqlParser::ExpressionOrDefaultContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::ExpressionOrDefaultContext>(x, rb_cExpressionOrDefaultContext, nullptr, nullptr);
}

template <>
Object to_ruby<ExpressionOrDefaultContextProxy*>(ExpressionOrDefaultContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<ExpressionOrDefaultContextProxy>(x, rb_cExpressionOrDefaultContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::UnaryOperatorContext*>(MySqlParser::UnaryOperatorContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::UnaryOperatorContext>(x, rb_cUnaryOperatorContext, nullptr, nullptr);
}

template <>
Object to_ruby<UnaryOperatorContextProxy*>(UnaryOperatorContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<UnaryOperatorContextProxy>(x, rb_cUnaryOperatorContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::SpecificFunctionContext*>(MySqlParser::SpecificFunctionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::SpecificFunctionContext>(x, rb_cSpecificFunctionContext, nullptr, nullptr);
}

template <>
Object to_ruby<SpecificFunctionContextProxy*>(SpecificFunctionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<SpecificFunctionContextProxy>(x, rb_cSpecificFunctionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::SpecificFunctionCallContext*>(MySqlParser::SpecificFunctionCallContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::SpecificFunctionCallContext>(x, rb_cSpecificFunctionCallContext, nullptr, nullptr);
}

template <>
Object to_ruby<SpecificFunctionCallContextProxy*>(SpecificFunctionCallContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<SpecificFunctionCallContextProxy>(x, rb_cSpecificFunctionCallContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::PasswordFunctionCallContext*>(MySqlParser::PasswordFunctionCallContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::PasswordFunctionCallContext>(x, rb_cPasswordFunctionCallContext, nullptr, nullptr);
}

template <>
Object to_ruby<PasswordFunctionCallContextProxy*>(PasswordFunctionCallContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<PasswordFunctionCallContextProxy>(x, rb_cPasswordFunctionCallContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::UdfFunctionCallContext*>(MySqlParser::UdfFunctionCallContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::UdfFunctionCallContext>(x, rb_cUdfFunctionCallContext, nullptr, nullptr);
}

template <>
Object to_ruby<UdfFunctionCallContextProxy*>(UdfFunctionCallContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<UdfFunctionCallContextProxy>(x, rb_cUdfFunctionCallContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::FunctionArgsContext*>(MySqlParser::FunctionArgsContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::FunctionArgsContext>(x, rb_cFunctionArgsContext, nullptr, nullptr);
}

template <>
Object to_ruby<FunctionArgsContextProxy*>(FunctionArgsContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<FunctionArgsContextProxy>(x, rb_cFunctionArgsContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::AggregateWindowedFunctionContext*>(MySqlParser::AggregateWindowedFunctionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::AggregateWindowedFunctionContext>(x, rb_cAggregateWindowedFunctionContext, nullptr, nullptr);
}

template <>
Object to_ruby<AggregateWindowedFunctionContextProxy*>(AggregateWindowedFunctionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<AggregateWindowedFunctionContextProxy>(x, rb_cAggregateWindowedFunctionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::AggregateFunctionCallContext*>(MySqlParser::AggregateFunctionCallContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::AggregateFunctionCallContext>(x, rb_cAggregateFunctionCallContext, nullptr, nullptr);
}

template <>
Object to_ruby<AggregateFunctionCallContextProxy*>(AggregateFunctionCallContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<AggregateFunctionCallContextProxy>(x, rb_cAggregateFunctionCallContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::ScalarFunctionNameContext*>(MySqlParser::ScalarFunctionNameContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::ScalarFunctionNameContext>(x, rb_cScalarFunctionNameContext, nullptr, nullptr);
}

template <>
Object to_ruby<ScalarFunctionNameContextProxy*>(ScalarFunctionNameContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<ScalarFunctionNameContextProxy>(x, rb_cScalarFunctionNameContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::ScalarFunctionCallContext*>(MySqlParser::ScalarFunctionCallContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::ScalarFunctionCallContext>(x, rb_cScalarFunctionCallContext, nullptr, nullptr);
}

template <>
Object to_ruby<ScalarFunctionCallContextProxy*>(ScalarFunctionCallContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<ScalarFunctionCallContextProxy>(x, rb_cScalarFunctionCallContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::PositionFunctionCallContext*>(MySqlParser::PositionFunctionCallContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::PositionFunctionCallContext>(x, rb_cPositionFunctionCallContext, nullptr, nullptr);
}

template <>
Object to_ruby<PositionFunctionCallContextProxy*>(PositionFunctionCallContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<PositionFunctionCallContextProxy>(x, rb_cPositionFunctionCallContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::TrimFunctionCallContext*>(MySqlParser::TrimFunctionCallContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::TrimFunctionCallContext>(x, rb_cTrimFunctionCallContext, nullptr, nullptr);
}

template <>
Object to_ruby<TrimFunctionCallContextProxy*>(TrimFunctionCallContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<TrimFunctionCallContextProxy>(x, rb_cTrimFunctionCallContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::SimpleFunctionCallContext*>(MySqlParser::SimpleFunctionCallContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::SimpleFunctionCallContext>(x, rb_cSimpleFunctionCallContext, nullptr, nullptr);
}

template <>
Object to_ruby<SimpleFunctionCallContextProxy*>(SimpleFunctionCallContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<SimpleFunctionCallContextProxy>(x, rb_cSimpleFunctionCallContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::CharFunctionCallContext*>(MySqlParser::CharFunctionCallContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::CharFunctionCallContext>(x, rb_cCharFunctionCallContext, nullptr, nullptr);
}

template <>
Object to_ruby<CharFunctionCallContextProxy*>(CharFunctionCallContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<CharFunctionCallContextProxy>(x, rb_cCharFunctionCallContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::WeightFunctionCallContext*>(MySqlParser::WeightFunctionCallContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::WeightFunctionCallContext>(x, rb_cWeightFunctionCallContext, nullptr, nullptr);
}

template <>
Object to_ruby<WeightFunctionCallContextProxy*>(WeightFunctionCallContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<WeightFunctionCallContextProxy>(x, rb_cWeightFunctionCallContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::LevelsInWeightStringContext*>(MySqlParser::LevelsInWeightStringContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::LevelsInWeightStringContext>(x, rb_cLevelsInWeightStringContext, nullptr, nullptr);
}

template <>
Object to_ruby<LevelsInWeightStringContextProxy*>(LevelsInWeightStringContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<LevelsInWeightStringContextProxy>(x, rb_cLevelsInWeightStringContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::GetFormatFunctionCallContext*>(MySqlParser::GetFormatFunctionCallContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::GetFormatFunctionCallContext>(x, rb_cGetFormatFunctionCallContext, nullptr, nullptr);
}

template <>
Object to_ruby<GetFormatFunctionCallContextProxy*>(GetFormatFunctionCallContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<GetFormatFunctionCallContextProxy>(x, rb_cGetFormatFunctionCallContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::CaseFunctionCallContext*>(MySqlParser::CaseFunctionCallContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::CaseFunctionCallContext>(x, rb_cCaseFunctionCallContext, nullptr, nullptr);
}

template <>
Object to_ruby<CaseFunctionCallContextProxy*>(CaseFunctionCallContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<CaseFunctionCallContextProxy>(x, rb_cCaseFunctionCallContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::CaseFuncAlternativeContext*>(MySqlParser::CaseFuncAlternativeContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::CaseFuncAlternativeContext>(x, rb_cCaseFuncAlternativeContext, nullptr, nullptr);
}

template <>
Object to_ruby<CaseFuncAlternativeContextProxy*>(CaseFuncAlternativeContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<CaseFuncAlternativeContextProxy>(x, rb_cCaseFuncAlternativeContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::FunctionArgContext*>(MySqlParser::FunctionArgContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::FunctionArgContext>(x, rb_cFunctionArgContext, nullptr, nullptr);
}

template <>
Object to_ruby<FunctionArgContextProxy*>(FunctionArgContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<FunctionArgContextProxy>(x, rb_cFunctionArgContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::ExtractFunctionCallContext*>(MySqlParser::ExtractFunctionCallContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::ExtractFunctionCallContext>(x, rb_cExtractFunctionCallContext, nullptr, nullptr);
}

template <>
Object to_ruby<ExtractFunctionCallContextProxy*>(ExtractFunctionCallContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<ExtractFunctionCallContextProxy>(x, rb_cExtractFunctionCallContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::DataTypeFunctionCallContext*>(MySqlParser::DataTypeFunctionCallContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::DataTypeFunctionCallContext>(x, rb_cDataTypeFunctionCallContext, nullptr, nullptr);
}

template <>
Object to_ruby<DataTypeFunctionCallContextProxy*>(DataTypeFunctionCallContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<DataTypeFunctionCallContextProxy>(x, rb_cDataTypeFunctionCallContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::ValuesFunctionCallContext*>(MySqlParser::ValuesFunctionCallContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::ValuesFunctionCallContext>(x, rb_cValuesFunctionCallContext, nullptr, nullptr);
}

template <>
Object to_ruby<ValuesFunctionCallContextProxy*>(ValuesFunctionCallContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<ValuesFunctionCallContextProxy>(x, rb_cValuesFunctionCallContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::SubstrFunctionCallContext*>(MySqlParser::SubstrFunctionCallContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::SubstrFunctionCallContext>(x, rb_cSubstrFunctionCallContext, nullptr, nullptr);
}

template <>
Object to_ruby<SubstrFunctionCallContextProxy*>(SubstrFunctionCallContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<SubstrFunctionCallContextProxy>(x, rb_cSubstrFunctionCallContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::LevelWeightRangeContext*>(MySqlParser::LevelWeightRangeContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::LevelWeightRangeContext>(x, rb_cLevelWeightRangeContext, nullptr, nullptr);
}

template <>
Object to_ruby<LevelWeightRangeContextProxy*>(LevelWeightRangeContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<LevelWeightRangeContextProxy>(x, rb_cLevelWeightRangeContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::LevelWeightListContext*>(MySqlParser::LevelWeightListContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::LevelWeightListContext>(x, rb_cLevelWeightListContext, nullptr, nullptr);
}

template <>
Object to_ruby<LevelWeightListContextProxy*>(LevelWeightListContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<LevelWeightListContextProxy>(x, rb_cLevelWeightListContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::LevelInWeightListElementContext*>(MySqlParser::LevelInWeightListElementContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::LevelInWeightListElementContext>(x, rb_cLevelInWeightListElementContext, nullptr, nullptr);
}

template <>
Object to_ruby<LevelInWeightListElementContextProxy*>(LevelInWeightListElementContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<LevelInWeightListElementContextProxy>(x, rb_cLevelInWeightListElementContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::PredicateContext*>(MySqlParser::PredicateContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::PredicateContext>(x, rb_cPredicateContext, nullptr, nullptr);
}

template <>
Object to_ruby<PredicateContextProxy*>(PredicateContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<PredicateContextProxy>(x, rb_cPredicateContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::IsExpressionContext*>(MySqlParser::IsExpressionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::IsExpressionContext>(x, rb_cIsExpressionContext, nullptr, nullptr);
}

template <>
Object to_ruby<IsExpressionContextProxy*>(IsExpressionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<IsExpressionContextProxy>(x, rb_cIsExpressionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::NotExpressionContext*>(MySqlParser::NotExpressionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::NotExpressionContext>(x, rb_cNotExpressionContext, nullptr, nullptr);
}

template <>
Object to_ruby<NotExpressionContextProxy*>(NotExpressionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<NotExpressionContextProxy>(x, rb_cNotExpressionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::LogicalExpressionContext*>(MySqlParser::LogicalExpressionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::LogicalExpressionContext>(x, rb_cLogicalExpressionContext, nullptr, nullptr);
}

template <>
Object to_ruby<LogicalExpressionContextProxy*>(LogicalExpressionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<LogicalExpressionContextProxy>(x, rb_cLogicalExpressionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::LogicalOperatorContext*>(MySqlParser::LogicalOperatorContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::LogicalOperatorContext>(x, rb_cLogicalOperatorContext, nullptr, nullptr);
}

template <>
Object to_ruby<LogicalOperatorContextProxy*>(LogicalOperatorContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<LogicalOperatorContextProxy>(x, rb_cLogicalOperatorContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::PredicateExpressionContext*>(MySqlParser::PredicateExpressionContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::PredicateExpressionContext>(x, rb_cPredicateExpressionContext, nullptr, nullptr);
}

template <>
Object to_ruby<PredicateExpressionContextProxy*>(PredicateExpressionContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<PredicateExpressionContextProxy>(x, rb_cPredicateExpressionContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::SoundsLikePredicateContext*>(MySqlParser::SoundsLikePredicateContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::SoundsLikePredicateContext>(x, rb_cSoundsLikePredicateContext, nullptr, nullptr);
}

template <>
Object to_ruby<SoundsLikePredicateContextProxy*>(SoundsLikePredicateContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<SoundsLikePredicateContextProxy>(x, rb_cSoundsLikePredicateContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::ExpressionAtomContext*>(MySqlParser::ExpressionAtomContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::ExpressionAtomContext>(x, rb_cExpressionAtomContext, nullptr, nullptr);
}

template <>
Object to_ruby<ExpressionAtomContextProxy*>(ExpressionAtomContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<ExpressionAtomContextProxy>(x, rb_cExpressionAtomContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::ExpressionAtomPredicateContext*>(MySqlParser::ExpressionAtomPredicateContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::ExpressionAtomPredicateContext>(x, rb_cExpressionAtomPredicateContext, nullptr, nullptr);
}

template <>
Object to_ruby<ExpressionAtomPredicateContextProxy*>(ExpressionAtomPredicateContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<ExpressionAtomPredicateContextProxy>(x, rb_cExpressionAtomPredicateContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::InPredicateContext*>(MySqlParser::InPredicateContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::InPredicateContext>(x, rb_cInPredicateContext, nullptr, nullptr);
}

template <>
Object to_ruby<InPredicateContextProxy*>(InPredicateContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<InPredicateContextProxy>(x, rb_cInPredicateContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::SubqueryComparasionPredicateContext*>(MySqlParser::SubqueryComparasionPredicateContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::SubqueryComparasionPredicateContext>(x, rb_cSubqueryComparasionPredicateContext, nullptr, nullptr);
}

template <>
Object to_ruby<SubqueryComparasionPredicateContextProxy*>(SubqueryComparasionPredicateContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<SubqueryComparasionPredicateContextProxy>(x, rb_cSubqueryComparasionPredicateContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::BetweenPredicateContext*>(MySqlParser::BetweenPredicateContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::BetweenPredicateContext>(x, rb_cBetweenPredicateContext, nullptr, nullptr);
}

template <>
Object to_ruby<BetweenPredicateContextProxy*>(BetweenPredicateContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<BetweenPredicateContextProxy>(x, rb_cBetweenPredicateContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::BinaryComparasionPredicateContext*>(MySqlParser::BinaryComparasionPredicateContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::BinaryComparasionPredicateContext>(x, rb_cBinaryComparasionPredicateContext, nullptr, nullptr);
}

template <>
Object to_ruby<BinaryComparasionPredicateContextProxy*>(BinaryComparasionPredicateContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<BinaryComparasionPredicateContextProxy>(x, rb_cBinaryComparasionPredicateContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::IsNullPredicateContext*>(MySqlParser::IsNullPredicateContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::IsNullPredicateContext>(x, rb_cIsNullPredicateContext, nullptr, nullptr);
}

template <>
Object to_ruby<IsNullPredicateContextProxy*>(IsNullPredicateContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<IsNullPredicateContextProxy>(x, rb_cIsNullPredicateContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::LikePredicateContext*>(MySqlParser::LikePredicateContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::LikePredicateContext>(x, rb_cLikePredicateContext, nullptr, nullptr);
}

template <>
Object to_ruby<LikePredicateContextProxy*>(LikePredicateContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<LikePredicateContextProxy>(x, rb_cLikePredicateContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::RegexpPredicateContext*>(MySqlParser::RegexpPredicateContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::RegexpPredicateContext>(x, rb_cRegexpPredicateContext, nullptr, nullptr);
}

template <>
Object to_ruby<RegexpPredicateContextProxy*>(RegexpPredicateContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<RegexpPredicateContextProxy>(x, rb_cRegexpPredicateContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::UnaryExpressionAtomContext*>(MySqlParser::UnaryExpressionAtomContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::UnaryExpressionAtomContext>(x, rb_cUnaryExpressionAtomContext, nullptr, nullptr);
}

template <>
Object to_ruby<UnaryExpressionAtomContextProxy*>(UnaryExpressionAtomContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<UnaryExpressionAtomContextProxy>(x, rb_cUnaryExpressionAtomContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::CollateExpressionAtomContext*>(MySqlParser::CollateExpressionAtomContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::CollateExpressionAtomContext>(x, rb_cCollateExpressionAtomContext, nullptr, nullptr);
}

template <>
Object to_ruby<CollateExpressionAtomContextProxy*>(CollateExpressionAtomContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<CollateExpressionAtomContextProxy>(x, rb_cCollateExpressionAtomContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::SubqueryExpessionAtomContext*>(MySqlParser::SubqueryExpessionAtomContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::SubqueryExpessionAtomContext>(x, rb_cSubqueryExpessionAtomContext, nullptr, nullptr);
}

template <>
Object to_ruby<SubqueryExpessionAtomContextProxy*>(SubqueryExpessionAtomContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<SubqueryExpessionAtomContextProxy>(x, rb_cSubqueryExpessionAtomContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::MysqlVariableExpressionAtomContext*>(MySqlParser::MysqlVariableExpressionAtomContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::MysqlVariableExpressionAtomContext>(x, rb_cMysqlVariableExpressionAtomContext, nullptr, nullptr);
}

template <>
Object to_ruby<MysqlVariableExpressionAtomContextProxy*>(MysqlVariableExpressionAtomContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<MysqlVariableExpressionAtomContextProxy>(x, rb_cMysqlVariableExpressionAtomContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::NestedExpressionAtomContext*>(MySqlParser::NestedExpressionAtomContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::NestedExpressionAtomContext>(x, rb_cNestedExpressionAtomContext, nullptr, nullptr);
}

template <>
Object to_ruby<NestedExpressionAtomContextProxy*>(NestedExpressionAtomContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<NestedExpressionAtomContextProxy>(x, rb_cNestedExpressionAtomContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::NestedRowExpressionAtomContext*>(MySqlParser::NestedRowExpressionAtomContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::NestedRowExpressionAtomContext>(x, rb_cNestedRowExpressionAtomContext, nullptr, nullptr);
}

template <>
Object to_ruby<NestedRowExpressionAtomContextProxy*>(NestedRowExpressionAtomContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<NestedRowExpressionAtomContextProxy>(x, rb_cNestedRowExpressionAtomContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::MathOperatorContext*>(MySqlParser::MathOperatorContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::MathOperatorContext>(x, rb_cMathOperatorContext, nullptr, nullptr);
}

template <>
Object to_ruby<MathOperatorContextProxy*>(MathOperatorContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<MathOperatorContextProxy>(x, rb_cMathOperatorContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::MathExpressionAtomContext*>(MySqlParser::MathExpressionAtomContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::MathExpressionAtomContext>(x, rb_cMathExpressionAtomContext, nullptr, nullptr);
}

template <>
Object to_ruby<MathExpressionAtomContextProxy*>(MathExpressionAtomContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<MathExpressionAtomContextProxy>(x, rb_cMathExpressionAtomContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::IntervalExpressionAtomContext*>(MySqlParser::IntervalExpressionAtomContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::IntervalExpressionAtomContext>(x, rb_cIntervalExpressionAtomContext, nullptr, nullptr);
}

template <>
Object to_ruby<IntervalExpressionAtomContextProxy*>(IntervalExpressionAtomContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<IntervalExpressionAtomContextProxy>(x, rb_cIntervalExpressionAtomContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::ExistsExpessionAtomContext*>(MySqlParser::ExistsExpessionAtomContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::ExistsExpessionAtomContext>(x, rb_cExistsExpessionAtomContext, nullptr, nullptr);
}

template <>
Object to_ruby<ExistsExpessionAtomContextProxy*>(ExistsExpessionAtomContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<ExistsExpessionAtomContextProxy>(x, rb_cExistsExpessionAtomContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::ConstantExpressionAtomContext*>(MySqlParser::ConstantExpressionAtomContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::ConstantExpressionAtomContext>(x, rb_cConstantExpressionAtomContext, nullptr, nullptr);
}

template <>
Object to_ruby<ConstantExpressionAtomContextProxy*>(ConstantExpressionAtomContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<ConstantExpressionAtomContextProxy>(x, rb_cConstantExpressionAtomContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::FunctionCallExpressionAtomContext*>(MySqlParser::FunctionCallExpressionAtomContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::FunctionCallExpressionAtomContext>(x, rb_cFunctionCallExpressionAtomContext, nullptr, nullptr);
}

template <>
Object to_ruby<FunctionCallExpressionAtomContextProxy*>(FunctionCallExpressionAtomContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<FunctionCallExpressionAtomContextProxy>(x, rb_cFunctionCallExpressionAtomContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::BinaryExpressionAtomContext*>(MySqlParser::BinaryExpressionAtomContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::BinaryExpressionAtomContext>(x, rb_cBinaryExpressionAtomContext, nullptr, nullptr);
}

template <>
Object to_ruby<BinaryExpressionAtomContextProxy*>(BinaryExpressionAtomContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<BinaryExpressionAtomContextProxy>(x, rb_cBinaryExpressionAtomContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::FullColumnNameExpressionAtomContext*>(MySqlParser::FullColumnNameExpressionAtomContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::FullColumnNameExpressionAtomContext>(x, rb_cFullColumnNameExpressionAtomContext, nullptr, nullptr);
}

template <>
Object to_ruby<FullColumnNameExpressionAtomContextProxy*>(FullColumnNameExpressionAtomContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<FullColumnNameExpressionAtomContextProxy>(x, rb_cFullColumnNameExpressionAtomContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::BitOperatorContext*>(MySqlParser::BitOperatorContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::BitOperatorContext>(x, rb_cBitOperatorContext, nullptr, nullptr);
}

template <>
Object to_ruby<BitOperatorContextProxy*>(BitOperatorContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<BitOperatorContextProxy>(x, rb_cBitOperatorContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::BitExpressionAtomContext*>(MySqlParser::BitExpressionAtomContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::BitExpressionAtomContext>(x, rb_cBitExpressionAtomContext, nullptr, nullptr);
}

template <>
Object to_ruby<BitExpressionAtomContextProxy*>(BitExpressionAtomContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<BitExpressionAtomContextProxy>(x, rb_cBitExpressionAtomContext, nullptr, nullptr);
}



Object RootContextProxy::sqlStatements() {
  SqlStatementsContextProxy proxy(((MySqlParser::RootContext*)orig) -> sqlStatements());
  return to_ruby(proxy);
}

Object SqlStatementsContextProxy::sqlStatement() {
  std::vector<MySqlParser::SqlStatementContext *> vec = ((MySqlParser::SqlStatementsContext*)orig) -> sqlStatement();
  return Array(vec.begin(), vec.end());
}

Object SqlStatementsContextProxy::sqlStatementAt(size_t i) {
  SqlStatementContextProxy proxy(((MySqlParser::SqlStatementsContext*)orig) -> sqlStatement(i));
  return to_ruby(proxy);
}

Object SqlStatementsContextProxy::emptyStatement() {
  std::vector<MySqlParser::EmptyStatementContext *> vec = ((MySqlParser::SqlStatementsContext*)orig) -> emptyStatement();
  return Array(vec.begin(), vec.end());
}

Object SqlStatementsContextProxy::emptyStatementAt(size_t i) {
  EmptyStatementContextProxy proxy(((MySqlParser::SqlStatementsContext*)orig) -> emptyStatement(i));
  return to_ruby(proxy);
}

Object SqlStatementContextProxy::ddlStatement() {
  DdlStatementContextProxy proxy(((MySqlParser::SqlStatementContext*)orig) -> ddlStatement());
  return to_ruby(proxy);
}

Object SqlStatementContextProxy::dmlStatement() {
  DmlStatementContextProxy proxy(((MySqlParser::SqlStatementContext*)orig) -> dmlStatement());
  return to_ruby(proxy);
}

Object SqlStatementContextProxy::transactionStatement() {
  TransactionStatementContextProxy proxy(((MySqlParser::SqlStatementContext*)orig) -> transactionStatement());
  return to_ruby(proxy);
}

Object SqlStatementContextProxy::replicationStatement() {
  ReplicationStatementContextProxy proxy(((MySqlParser::SqlStatementContext*)orig) -> replicationStatement());
  return to_ruby(proxy);
}

Object SqlStatementContextProxy::preparedStatement() {
  PreparedStatementContextProxy proxy(((MySqlParser::SqlStatementContext*)orig) -> preparedStatement());
  return to_ruby(proxy);
}

Object SqlStatementContextProxy::administrationStatement() {
  AdministrationStatementContextProxy proxy(((MySqlParser::SqlStatementContext*)orig) -> administrationStatement());
  return to_ruby(proxy);
}

Object SqlStatementContextProxy::utilityStatement() {
  UtilityStatementContextProxy proxy(((MySqlParser::SqlStatementContext*)orig) -> utilityStatement());
  return to_ruby(proxy);
}

Object DdlStatementContextProxy::createDatabase() {
  CreateDatabaseContextProxy proxy(((MySqlParser::DdlStatementContext*)orig) -> createDatabase());
  return to_ruby(proxy);
}

Object DdlStatementContextProxy::createEvent() {
  CreateEventContextProxy proxy(((MySqlParser::DdlStatementContext*)orig) -> createEvent());
  return to_ruby(proxy);
}

Object DdlStatementContextProxy::createIndex() {
  CreateIndexContextProxy proxy(((MySqlParser::DdlStatementContext*)orig) -> createIndex());
  return to_ruby(proxy);
}

Object DdlStatementContextProxy::createLogfileGroup() {
  CreateLogfileGroupContextProxy proxy(((MySqlParser::DdlStatementContext*)orig) -> createLogfileGroup());
  return to_ruby(proxy);
}

Object DdlStatementContextProxy::createProcedure() {
  CreateProcedureContextProxy proxy(((MySqlParser::DdlStatementContext*)orig) -> createProcedure());
  return to_ruby(proxy);
}

Object DdlStatementContextProxy::createFunction() {
  CreateFunctionContextProxy proxy(((MySqlParser::DdlStatementContext*)orig) -> createFunction());
  return to_ruby(proxy);
}

Object DdlStatementContextProxy::createServer() {
  CreateServerContextProxy proxy(((MySqlParser::DdlStatementContext*)orig) -> createServer());
  return to_ruby(proxy);
}

Object DdlStatementContextProxy::createTable() {
  CreateTableContextProxy proxy(((MySqlParser::DdlStatementContext*)orig) -> createTable());
  return to_ruby(proxy);
}

Object DdlStatementContextProxy::createTablespaceInnodb() {
  CreateTablespaceInnodbContextProxy proxy(((MySqlParser::DdlStatementContext*)orig) -> createTablespaceInnodb());
  return to_ruby(proxy);
}

Object DdlStatementContextProxy::createTablespaceNdb() {
  CreateTablespaceNdbContextProxy proxy(((MySqlParser::DdlStatementContext*)orig) -> createTablespaceNdb());
  return to_ruby(proxy);
}

Object DdlStatementContextProxy::createTrigger() {
  CreateTriggerContextProxy proxy(((MySqlParser::DdlStatementContext*)orig) -> createTrigger());
  return to_ruby(proxy);
}

Object DdlStatementContextProxy::createView() {
  CreateViewContextProxy proxy(((MySqlParser::DdlStatementContext*)orig) -> createView());
  return to_ruby(proxy);
}

Object DdlStatementContextProxy::alterDatabase() {
  AlterDatabaseContextProxy proxy(((MySqlParser::DdlStatementContext*)orig) -> alterDatabase());
  return to_ruby(proxy);
}

Object DdlStatementContextProxy::alterEvent() {
  AlterEventContextProxy proxy(((MySqlParser::DdlStatementContext*)orig) -> alterEvent());
  return to_ruby(proxy);
}

Object DdlStatementContextProxy::alterFunction() {
  AlterFunctionContextProxy proxy(((MySqlParser::DdlStatementContext*)orig) -> alterFunction());
  return to_ruby(proxy);
}

Object DdlStatementContextProxy::alterInstance() {
  AlterInstanceContextProxy proxy(((MySqlParser::DdlStatementContext*)orig) -> alterInstance());
  return to_ruby(proxy);
}

Object DdlStatementContextProxy::alterLogfileGroup() {
  AlterLogfileGroupContextProxy proxy(((MySqlParser::DdlStatementContext*)orig) -> alterLogfileGroup());
  return to_ruby(proxy);
}

Object DdlStatementContextProxy::alterProcedure() {
  AlterProcedureContextProxy proxy(((MySqlParser::DdlStatementContext*)orig) -> alterProcedure());
  return to_ruby(proxy);
}

Object DdlStatementContextProxy::alterServer() {
  AlterServerContextProxy proxy(((MySqlParser::DdlStatementContext*)orig) -> alterServer());
  return to_ruby(proxy);
}

Object DdlStatementContextProxy::alterTable() {
  AlterTableContextProxy proxy(((MySqlParser::DdlStatementContext*)orig) -> alterTable());
  return to_ruby(proxy);
}

Object DdlStatementContextProxy::alterTablespace() {
  AlterTablespaceContextProxy proxy(((MySqlParser::DdlStatementContext*)orig) -> alterTablespace());
  return to_ruby(proxy);
}

Object DdlStatementContextProxy::alterView() {
  AlterViewContextProxy proxy(((MySqlParser::DdlStatementContext*)orig) -> alterView());
  return to_ruby(proxy);
}

Object DdlStatementContextProxy::dropDatabase() {
  DropDatabaseContextProxy proxy(((MySqlParser::DdlStatementContext*)orig) -> dropDatabase());
  return to_ruby(proxy);
}

Object DdlStatementContextProxy::dropEvent() {
  DropEventContextProxy proxy(((MySqlParser::DdlStatementContext*)orig) -> dropEvent());
  return to_ruby(proxy);
}

Object DdlStatementContextProxy::dropIndex() {
  DropIndexContextProxy proxy(((MySqlParser::DdlStatementContext*)orig) -> dropIndex());
  return to_ruby(proxy);
}

Object DdlStatementContextProxy::dropLogfileGroup() {
  DropLogfileGroupContextProxy proxy(((MySqlParser::DdlStatementContext*)orig) -> dropLogfileGroup());
  return to_ruby(proxy);
}

Object DdlStatementContextProxy::dropProcedure() {
  DropProcedureContextProxy proxy(((MySqlParser::DdlStatementContext*)orig) -> dropProcedure());
  return to_ruby(proxy);
}

Object DdlStatementContextProxy::dropFunction() {
  DropFunctionContextProxy proxy(((MySqlParser::DdlStatementContext*)orig) -> dropFunction());
  return to_ruby(proxy);
}

Object DdlStatementContextProxy::dropServer() {
  DropServerContextProxy proxy(((MySqlParser::DdlStatementContext*)orig) -> dropServer());
  return to_ruby(proxy);
}

Object DdlStatementContextProxy::dropTable() {
  DropTableContextProxy proxy(((MySqlParser::DdlStatementContext*)orig) -> dropTable());
  return to_ruby(proxy);
}

Object DdlStatementContextProxy::dropTablespace() {
  DropTablespaceContextProxy proxy(((MySqlParser::DdlStatementContext*)orig) -> dropTablespace());
  return to_ruby(proxy);
}

Object DdlStatementContextProxy::dropTrigger() {
  DropTriggerContextProxy proxy(((MySqlParser::DdlStatementContext*)orig) -> dropTrigger());
  return to_ruby(proxy);
}

Object DdlStatementContextProxy::dropView() {
  DropViewContextProxy proxy(((MySqlParser::DdlStatementContext*)orig) -> dropView());
  return to_ruby(proxy);
}

Object DdlStatementContextProxy::renameTable() {
  RenameTableContextProxy proxy(((MySqlParser::DdlStatementContext*)orig) -> renameTable());
  return to_ruby(proxy);
}

Object DdlStatementContextProxy::truncateTable() {
  TruncateTableContextProxy proxy(((MySqlParser::DdlStatementContext*)orig) -> truncateTable());
  return to_ruby(proxy);
}

Object DmlStatementContextProxy::selectStatement() {
  SelectStatementContextProxy proxy(((MySqlParser::DmlStatementContext*)orig) -> selectStatement());
  return to_ruby(proxy);
}

Object DmlStatementContextProxy::insertStatement() {
  InsertStatementContextProxy proxy(((MySqlParser::DmlStatementContext*)orig) -> insertStatement());
  return to_ruby(proxy);
}

Object DmlStatementContextProxy::updateStatement() {
  UpdateStatementContextProxy proxy(((MySqlParser::DmlStatementContext*)orig) -> updateStatement());
  return to_ruby(proxy);
}

Object DmlStatementContextProxy::deleteStatement() {
  DeleteStatementContextProxy proxy(((MySqlParser::DmlStatementContext*)orig) -> deleteStatement());
  return to_ruby(proxy);
}

Object DmlStatementContextProxy::replaceStatement() {
  ReplaceStatementContextProxy proxy(((MySqlParser::DmlStatementContext*)orig) -> replaceStatement());
  return to_ruby(proxy);
}

Object DmlStatementContextProxy::callStatement() {
  CallStatementContextProxy proxy(((MySqlParser::DmlStatementContext*)orig) -> callStatement());
  return to_ruby(proxy);
}

Object DmlStatementContextProxy::loadDataStatement() {
  LoadDataStatementContextProxy proxy(((MySqlParser::DmlStatementContext*)orig) -> loadDataStatement());
  return to_ruby(proxy);
}

Object DmlStatementContextProxy::loadXmlStatement() {
  LoadXmlStatementContextProxy proxy(((MySqlParser::DmlStatementContext*)orig) -> loadXmlStatement());
  return to_ruby(proxy);
}

Object DmlStatementContextProxy::doStatement() {
  DoStatementContextProxy proxy(((MySqlParser::DmlStatementContext*)orig) -> doStatement());
  return to_ruby(proxy);
}

Object DmlStatementContextProxy::handlerStatement() {
  HandlerStatementContextProxy proxy(((MySqlParser::DmlStatementContext*)orig) -> handlerStatement());
  return to_ruby(proxy);
}

Object TransactionStatementContextProxy::startTransaction() {
  StartTransactionContextProxy proxy(((MySqlParser::TransactionStatementContext*)orig) -> startTransaction());
  return to_ruby(proxy);
}

Object TransactionStatementContextProxy::beginWork() {
  BeginWorkContextProxy proxy(((MySqlParser::TransactionStatementContext*)orig) -> beginWork());
  return to_ruby(proxy);
}

Object TransactionStatementContextProxy::commitWork() {
  CommitWorkContextProxy proxy(((MySqlParser::TransactionStatementContext*)orig) -> commitWork());
  return to_ruby(proxy);
}

Object TransactionStatementContextProxy::rollbackWork() {
  RollbackWorkContextProxy proxy(((MySqlParser::TransactionStatementContext*)orig) -> rollbackWork());
  return to_ruby(proxy);
}

Object TransactionStatementContextProxy::savepointStatement() {
  SavepointStatementContextProxy proxy(((MySqlParser::TransactionStatementContext*)orig) -> savepointStatement());
  return to_ruby(proxy);
}

Object TransactionStatementContextProxy::rollbackStatement() {
  RollbackStatementContextProxy proxy(((MySqlParser::TransactionStatementContext*)orig) -> rollbackStatement());
  return to_ruby(proxy);
}

Object TransactionStatementContextProxy::releaseStatement() {
  ReleaseStatementContextProxy proxy(((MySqlParser::TransactionStatementContext*)orig) -> releaseStatement());
  return to_ruby(proxy);
}

Object TransactionStatementContextProxy::lockTables() {
  LockTablesContextProxy proxy(((MySqlParser::TransactionStatementContext*)orig) -> lockTables());
  return to_ruby(proxy);
}

Object TransactionStatementContextProxy::unlockTables() {
  UnlockTablesContextProxy proxy(((MySqlParser::TransactionStatementContext*)orig) -> unlockTables());
  return to_ruby(proxy);
}

Object ReplicationStatementContextProxy::changeMaster() {
  ChangeMasterContextProxy proxy(((MySqlParser::ReplicationStatementContext*)orig) -> changeMaster());
  return to_ruby(proxy);
}

Object ReplicationStatementContextProxy::changeReplicationFilter() {
  ChangeReplicationFilterContextProxy proxy(((MySqlParser::ReplicationStatementContext*)orig) -> changeReplicationFilter());
  return to_ruby(proxy);
}

Object ReplicationStatementContextProxy::purgeBinaryLogs() {
  PurgeBinaryLogsContextProxy proxy(((MySqlParser::ReplicationStatementContext*)orig) -> purgeBinaryLogs());
  return to_ruby(proxy);
}

Object ReplicationStatementContextProxy::resetMaster() {
  ResetMasterContextProxy proxy(((MySqlParser::ReplicationStatementContext*)orig) -> resetMaster());
  return to_ruby(proxy);
}

Object ReplicationStatementContextProxy::resetSlave() {
  ResetSlaveContextProxy proxy(((MySqlParser::ReplicationStatementContext*)orig) -> resetSlave());
  return to_ruby(proxy);
}

Object ReplicationStatementContextProxy::startSlave() {
  StartSlaveContextProxy proxy(((MySqlParser::ReplicationStatementContext*)orig) -> startSlave());
  return to_ruby(proxy);
}

Object ReplicationStatementContextProxy::stopSlave() {
  StopSlaveContextProxy proxy(((MySqlParser::ReplicationStatementContext*)orig) -> stopSlave());
  return to_ruby(proxy);
}

Object ReplicationStatementContextProxy::startGroupReplication() {
  StartGroupReplicationContextProxy proxy(((MySqlParser::ReplicationStatementContext*)orig) -> startGroupReplication());
  return to_ruby(proxy);
}

Object ReplicationStatementContextProxy::stopGroupReplication() {
  StopGroupReplicationContextProxy proxy(((MySqlParser::ReplicationStatementContext*)orig) -> stopGroupReplication());
  return to_ruby(proxy);
}

Object ReplicationStatementContextProxy::xaStartTransaction() {
  XaStartTransactionContextProxy proxy(((MySqlParser::ReplicationStatementContext*)orig) -> xaStartTransaction());
  return to_ruby(proxy);
}

Object ReplicationStatementContextProxy::xaEndTransaction() {
  XaEndTransactionContextProxy proxy(((MySqlParser::ReplicationStatementContext*)orig) -> xaEndTransaction());
  return to_ruby(proxy);
}

Object ReplicationStatementContextProxy::xaPrepareStatement() {
  XaPrepareStatementContextProxy proxy(((MySqlParser::ReplicationStatementContext*)orig) -> xaPrepareStatement());
  return to_ruby(proxy);
}

Object ReplicationStatementContextProxy::xaCommitWork() {
  XaCommitWorkContextProxy proxy(((MySqlParser::ReplicationStatementContext*)orig) -> xaCommitWork());
  return to_ruby(proxy);
}

Object ReplicationStatementContextProxy::xaRollbackWork() {
  XaRollbackWorkContextProxy proxy(((MySqlParser::ReplicationStatementContext*)orig) -> xaRollbackWork());
  return to_ruby(proxy);
}

Object ReplicationStatementContextProxy::xaRecoverWork() {
  XaRecoverWorkContextProxy proxy(((MySqlParser::ReplicationStatementContext*)orig) -> xaRecoverWork());
  return to_ruby(proxy);
}

Object PreparedStatementContextProxy::prepareStatement() {
  PrepareStatementContextProxy proxy(((MySqlParser::PreparedStatementContext*)orig) -> prepareStatement());
  return to_ruby(proxy);
}

Object PreparedStatementContextProxy::executeStatement() {
  ExecuteStatementContextProxy proxy(((MySqlParser::PreparedStatementContext*)orig) -> executeStatement());
  return to_ruby(proxy);
}

Object PreparedStatementContextProxy::deallocatePrepare() {
  DeallocatePrepareContextProxy proxy(((MySqlParser::PreparedStatementContext*)orig) -> deallocatePrepare());
  return to_ruby(proxy);
}

Object AdministrationStatementContextProxy::alterUser() {
  AlterUserContextProxy proxy(((MySqlParser::AdministrationStatementContext*)orig) -> alterUser());
  return to_ruby(proxy);
}

Object AdministrationStatementContextProxy::createUser() {
  CreateUserContextProxy proxy(((MySqlParser::AdministrationStatementContext*)orig) -> createUser());
  return to_ruby(proxy);
}

Object AdministrationStatementContextProxy::dropUser() {
  DropUserContextProxy proxy(((MySqlParser::AdministrationStatementContext*)orig) -> dropUser());
  return to_ruby(proxy);
}

Object AdministrationStatementContextProxy::grantStatement() {
  GrantStatementContextProxy proxy(((MySqlParser::AdministrationStatementContext*)orig) -> grantStatement());
  return to_ruby(proxy);
}

Object AdministrationStatementContextProxy::grantProxy() {
  GrantProxyContextProxy proxy(((MySqlParser::AdministrationStatementContext*)orig) -> grantProxy());
  return to_ruby(proxy);
}

Object AdministrationStatementContextProxy::renameUser() {
  RenameUserContextProxy proxy(((MySqlParser::AdministrationStatementContext*)orig) -> renameUser());
  return to_ruby(proxy);
}

Object AdministrationStatementContextProxy::revokeStatement() {
  RevokeStatementContextProxy proxy(((MySqlParser::AdministrationStatementContext*)orig) -> revokeStatement());
  return to_ruby(proxy);
}

Object AdministrationStatementContextProxy::revokeProxy() {
  RevokeProxyContextProxy proxy(((MySqlParser::AdministrationStatementContext*)orig) -> revokeProxy());
  return to_ruby(proxy);
}

Object AdministrationStatementContextProxy::analyzeTable() {
  AnalyzeTableContextProxy proxy(((MySqlParser::AdministrationStatementContext*)orig) -> analyzeTable());
  return to_ruby(proxy);
}

Object AdministrationStatementContextProxy::checkTable() {
  CheckTableContextProxy proxy(((MySqlParser::AdministrationStatementContext*)orig) -> checkTable());
  return to_ruby(proxy);
}

Object AdministrationStatementContextProxy::checksumTable() {
  ChecksumTableContextProxy proxy(((MySqlParser::AdministrationStatementContext*)orig) -> checksumTable());
  return to_ruby(proxy);
}

Object AdministrationStatementContextProxy::optimizeTable() {
  OptimizeTableContextProxy proxy(((MySqlParser::AdministrationStatementContext*)orig) -> optimizeTable());
  return to_ruby(proxy);
}

Object AdministrationStatementContextProxy::repairTable() {
  RepairTableContextProxy proxy(((MySqlParser::AdministrationStatementContext*)orig) -> repairTable());
  return to_ruby(proxy);
}

Object AdministrationStatementContextProxy::createUdfunction() {
  CreateUdfunctionContextProxy proxy(((MySqlParser::AdministrationStatementContext*)orig) -> createUdfunction());
  return to_ruby(proxy);
}

Object AdministrationStatementContextProxy::installPlugin() {
  InstallPluginContextProxy proxy(((MySqlParser::AdministrationStatementContext*)orig) -> installPlugin());
  return to_ruby(proxy);
}

Object AdministrationStatementContextProxy::uninstallPlugin() {
  UninstallPluginContextProxy proxy(((MySqlParser::AdministrationStatementContext*)orig) -> uninstallPlugin());
  return to_ruby(proxy);
}

Object AdministrationStatementContextProxy::setStatement() {
  SetStatementContextProxy proxy(((MySqlParser::AdministrationStatementContext*)orig) -> setStatement());
  return to_ruby(proxy);
}

Object AdministrationStatementContextProxy::showStatement() {
  ShowStatementContextProxy proxy(((MySqlParser::AdministrationStatementContext*)orig) -> showStatement());
  return to_ruby(proxy);
}

Object AdministrationStatementContextProxy::binlogStatement() {
  BinlogStatementContextProxy proxy(((MySqlParser::AdministrationStatementContext*)orig) -> binlogStatement());
  return to_ruby(proxy);
}

Object AdministrationStatementContextProxy::cacheIndexStatement() {
  CacheIndexStatementContextProxy proxy(((MySqlParser::AdministrationStatementContext*)orig) -> cacheIndexStatement());
  return to_ruby(proxy);
}

Object AdministrationStatementContextProxy::flushStatement() {
  FlushStatementContextProxy proxy(((MySqlParser::AdministrationStatementContext*)orig) -> flushStatement());
  return to_ruby(proxy);
}

Object AdministrationStatementContextProxy::killStatement() {
  KillStatementContextProxy proxy(((MySqlParser::AdministrationStatementContext*)orig) -> killStatement());
  return to_ruby(proxy);
}

Object AdministrationStatementContextProxy::loadIndexIntoCache() {
  LoadIndexIntoCacheContextProxy proxy(((MySqlParser::AdministrationStatementContext*)orig) -> loadIndexIntoCache());
  return to_ruby(proxy);
}

Object AdministrationStatementContextProxy::resetStatement() {
  ResetStatementContextProxy proxy(((MySqlParser::AdministrationStatementContext*)orig) -> resetStatement());
  return to_ruby(proxy);
}

Object AdministrationStatementContextProxy::shutdownStatement() {
  ShutdownStatementContextProxy proxy(((MySqlParser::AdministrationStatementContext*)orig) -> shutdownStatement());
  return to_ruby(proxy);
}

Object UtilityStatementContextProxy::simpleDescribeStatement() {
  SimpleDescribeStatementContextProxy proxy(((MySqlParser::UtilityStatementContext*)orig) -> simpleDescribeStatement());
  return to_ruby(proxy);
}

Object UtilityStatementContextProxy::fullDescribeStatement() {
  FullDescribeStatementContextProxy proxy(((MySqlParser::UtilityStatementContext*)orig) -> fullDescribeStatement());
  return to_ruby(proxy);
}

Object UtilityStatementContextProxy::helpStatement() {
  HelpStatementContextProxy proxy(((MySqlParser::UtilityStatementContext*)orig) -> helpStatement());
  return to_ruby(proxy);
}

Object UtilityStatementContextProxy::useStatement() {
  UseStatementContextProxy proxy(((MySqlParser::UtilityStatementContext*)orig) -> useStatement());
  return to_ruby(proxy);
}

Object UtilityStatementContextProxy::signalStatement() {
  SignalStatementContextProxy proxy(((MySqlParser::UtilityStatementContext*)orig) -> signalStatement());
  return to_ruby(proxy);
}

Object UtilityStatementContextProxy::resignalStatement() {
  ResignalStatementContextProxy proxy(((MySqlParser::UtilityStatementContext*)orig) -> resignalStatement());
  return to_ruby(proxy);
}

Object UtilityStatementContextProxy::diagnosticsStatement() {
  DiagnosticsStatementContextProxy proxy(((MySqlParser::UtilityStatementContext*)orig) -> diagnosticsStatement());
  return to_ruby(proxy);
}

Object CreateDatabaseContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::CreateDatabaseContext*)orig) -> uid());
  return to_ruby(proxy);
}

Object CreateDatabaseContextProxy::ifNotExists() {
  IfNotExistsContextProxy proxy(((MySqlParser::CreateDatabaseContext*)orig) -> ifNotExists());
  return to_ruby(proxy);
}

Object CreateDatabaseContextProxy::createDatabaseOption() {
  std::vector<MySqlParser::CreateDatabaseOptionContext *> vec = ((MySqlParser::CreateDatabaseContext*)orig) -> createDatabaseOption();
  return Array(vec.begin(), vec.end());
}

Object CreateDatabaseContextProxy::createDatabaseOptionAt(size_t i) {
  CreateDatabaseOptionContextProxy proxy(((MySqlParser::CreateDatabaseContext*)orig) -> createDatabaseOption(i));
  return to_ruby(proxy);
}

Object CreateEventContextProxy::fullId() {
  FullIdContextProxy proxy(((MySqlParser::CreateEventContext*)orig) -> fullId());
  return to_ruby(proxy);
}

Object CreateEventContextProxy::scheduleExpression() {
  ScheduleExpressionContextProxy proxy(((MySqlParser::CreateEventContext*)orig) -> scheduleExpression());
  return to_ruby(proxy);
}

Object CreateEventContextProxy::routineBody() {
  RoutineBodyContextProxy proxy(((MySqlParser::CreateEventContext*)orig) -> routineBody());
  return to_ruby(proxy);
}

Object CreateEventContextProxy::ownerStatement() {
  OwnerStatementContextProxy proxy(((MySqlParser::CreateEventContext*)orig) -> ownerStatement());
  return to_ruby(proxy);
}

Object CreateEventContextProxy::ifNotExists() {
  IfNotExistsContextProxy proxy(((MySqlParser::CreateEventContext*)orig) -> ifNotExists());
  return to_ruby(proxy);
}

Object CreateEventContextProxy::enableType() {
  EnableTypeContextProxy proxy(((MySqlParser::CreateEventContext*)orig) -> enableType());
  return to_ruby(proxy);
}

Object CreateIndexContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::CreateIndexContext*)orig) -> uid());
  return to_ruby(proxy);
}

Object CreateIndexContextProxy::tableName() {
  TableNameContextProxy proxy(((MySqlParser::CreateIndexContext*)orig) -> tableName());
  return to_ruby(proxy);
}

Object CreateIndexContextProxy::indexColumnNames() {
  IndexColumnNamesContextProxy proxy(((MySqlParser::CreateIndexContext*)orig) -> indexColumnNames());
  return to_ruby(proxy);
}

Object CreateIndexContextProxy::indexType() {
  IndexTypeContextProxy proxy(((MySqlParser::CreateIndexContext*)orig) -> indexType());
  return to_ruby(proxy);
}

Object CreateIndexContextProxy::indexOption() {
  std::vector<MySqlParser::IndexOptionContext *> vec = ((MySqlParser::CreateIndexContext*)orig) -> indexOption();
  return Array(vec.begin(), vec.end());
}

Object CreateIndexContextProxy::indexOptionAt(size_t i) {
  IndexOptionContextProxy proxy(((MySqlParser::CreateIndexContext*)orig) -> indexOption(i));
  return to_ruby(proxy);
}

Object CreateLogfileGroupContextProxy::uid() {
  std::vector<MySqlParser::UidContext *> vec = ((MySqlParser::CreateLogfileGroupContext*)orig) -> uid();
  return Array(vec.begin(), vec.end());
}

Object CreateLogfileGroupContextProxy::uidAt(size_t i) {
  UidContextProxy proxy(((MySqlParser::CreateLogfileGroupContext*)orig) -> uid(i));
  return to_ruby(proxy);
}

Object CreateLogfileGroupContextProxy::engineName() {
  EngineNameContextProxy proxy(((MySqlParser::CreateLogfileGroupContext*)orig) -> engineName());
  return to_ruby(proxy);
}

Object CreateLogfileGroupContextProxy::fileSizeLiteral() {
  std::vector<MySqlParser::FileSizeLiteralContext *> vec = ((MySqlParser::CreateLogfileGroupContext*)orig) -> fileSizeLiteral();
  return Array(vec.begin(), vec.end());
}

Object CreateLogfileGroupContextProxy::fileSizeLiteralAt(size_t i) {
  FileSizeLiteralContextProxy proxy(((MySqlParser::CreateLogfileGroupContext*)orig) -> fileSizeLiteral(i));
  return to_ruby(proxy);
}

Object CreateProcedureContextProxy::fullId() {
  FullIdContextProxy proxy(((MySqlParser::CreateProcedureContext*)orig) -> fullId());
  return to_ruby(proxy);
}

Object CreateProcedureContextProxy::routineBody() {
  RoutineBodyContextProxy proxy(((MySqlParser::CreateProcedureContext*)orig) -> routineBody());
  return to_ruby(proxy);
}

Object CreateProcedureContextProxy::ownerStatement() {
  OwnerStatementContextProxy proxy(((MySqlParser::CreateProcedureContext*)orig) -> ownerStatement());
  return to_ruby(proxy);
}

Object CreateProcedureContextProxy::procedureParameter() {
  std::vector<MySqlParser::ProcedureParameterContext *> vec = ((MySqlParser::CreateProcedureContext*)orig) -> procedureParameter();
  return Array(vec.begin(), vec.end());
}

Object CreateProcedureContextProxy::procedureParameterAt(size_t i) {
  ProcedureParameterContextProxy proxy(((MySqlParser::CreateProcedureContext*)orig) -> procedureParameter(i));
  return to_ruby(proxy);
}

Object CreateProcedureContextProxy::routineOption() {
  std::vector<MySqlParser::RoutineOptionContext *> vec = ((MySqlParser::CreateProcedureContext*)orig) -> routineOption();
  return Array(vec.begin(), vec.end());
}

Object CreateProcedureContextProxy::routineOptionAt(size_t i) {
  RoutineOptionContextProxy proxy(((MySqlParser::CreateProcedureContext*)orig) -> routineOption(i));
  return to_ruby(proxy);
}

Object CreateFunctionContextProxy::fullId() {
  FullIdContextProxy proxy(((MySqlParser::CreateFunctionContext*)orig) -> fullId());
  return to_ruby(proxy);
}

Object CreateFunctionContextProxy::dataType() {
  DataTypeContextProxy proxy(((MySqlParser::CreateFunctionContext*)orig) -> dataType());
  return to_ruby(proxy);
}

Object CreateFunctionContextProxy::routineBody() {
  RoutineBodyContextProxy proxy(((MySqlParser::CreateFunctionContext*)orig) -> routineBody());
  return to_ruby(proxy);
}

Object CreateFunctionContextProxy::returnStatement() {
  ReturnStatementContextProxy proxy(((MySqlParser::CreateFunctionContext*)orig) -> returnStatement());
  return to_ruby(proxy);
}

Object CreateFunctionContextProxy::ownerStatement() {
  OwnerStatementContextProxy proxy(((MySqlParser::CreateFunctionContext*)orig) -> ownerStatement());
  return to_ruby(proxy);
}

Object CreateFunctionContextProxy::functionParameter() {
  std::vector<MySqlParser::FunctionParameterContext *> vec = ((MySqlParser::CreateFunctionContext*)orig) -> functionParameter();
  return Array(vec.begin(), vec.end());
}

Object CreateFunctionContextProxy::functionParameterAt(size_t i) {
  FunctionParameterContextProxy proxy(((MySqlParser::CreateFunctionContext*)orig) -> functionParameter(i));
  return to_ruby(proxy);
}

Object CreateFunctionContextProxy::routineOption() {
  std::vector<MySqlParser::RoutineOptionContext *> vec = ((MySqlParser::CreateFunctionContext*)orig) -> routineOption();
  return Array(vec.begin(), vec.end());
}

Object CreateFunctionContextProxy::routineOptionAt(size_t i) {
  RoutineOptionContextProxy proxy(((MySqlParser::CreateFunctionContext*)orig) -> routineOption(i));
  return to_ruby(proxy);
}

Object CreateServerContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::CreateServerContext*)orig) -> uid());
  return to_ruby(proxy);
}

Object CreateServerContextProxy::serverOption() {
  std::vector<MySqlParser::ServerOptionContext *> vec = ((MySqlParser::CreateServerContext*)orig) -> serverOption();
  return Array(vec.begin(), vec.end());
}

Object CreateServerContextProxy::serverOptionAt(size_t i) {
  ServerOptionContextProxy proxy(((MySqlParser::CreateServerContext*)orig) -> serverOption(i));
  return to_ruby(proxy);
}

Object CreateTablespaceInnodbContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::CreateTablespaceInnodbContext*)orig) -> uid());
  return to_ruby(proxy);
}

Object CreateTablespaceInnodbContextProxy::engineName() {
  EngineNameContextProxy proxy(((MySqlParser::CreateTablespaceInnodbContext*)orig) -> engineName());
  return to_ruby(proxy);
}

Object CreateTablespaceInnodbContextProxy::fileSizeLiteral() {
  FileSizeLiteralContextProxy proxy(((MySqlParser::CreateTablespaceInnodbContext*)orig) -> fileSizeLiteral());
  return to_ruby(proxy);
}

Object CreateTablespaceNdbContextProxy::uid() {
  std::vector<MySqlParser::UidContext *> vec = ((MySqlParser::CreateTablespaceNdbContext*)orig) -> uid();
  return Array(vec.begin(), vec.end());
}

Object CreateTablespaceNdbContextProxy::uidAt(size_t i) {
  UidContextProxy proxy(((MySqlParser::CreateTablespaceNdbContext*)orig) -> uid(i));
  return to_ruby(proxy);
}

Object CreateTablespaceNdbContextProxy::engineName() {
  EngineNameContextProxy proxy(((MySqlParser::CreateTablespaceNdbContext*)orig) -> engineName());
  return to_ruby(proxy);
}

Object CreateTablespaceNdbContextProxy::fileSizeLiteral() {
  std::vector<MySqlParser::FileSizeLiteralContext *> vec = ((MySqlParser::CreateTablespaceNdbContext*)orig) -> fileSizeLiteral();
  return Array(vec.begin(), vec.end());
}

Object CreateTablespaceNdbContextProxy::fileSizeLiteralAt(size_t i) {
  FileSizeLiteralContextProxy proxy(((MySqlParser::CreateTablespaceNdbContext*)orig) -> fileSizeLiteral(i));
  return to_ruby(proxy);
}

Object CreateTriggerContextProxy::tableName() {
  TableNameContextProxy proxy(((MySqlParser::CreateTriggerContext*)orig) -> tableName());
  return to_ruby(proxy);
}

Object CreateTriggerContextProxy::routineBody() {
  RoutineBodyContextProxy proxy(((MySqlParser::CreateTriggerContext*)orig) -> routineBody());
  return to_ruby(proxy);
}

Object CreateTriggerContextProxy::fullId() {
  std::vector<MySqlParser::FullIdContext *> vec = ((MySqlParser::CreateTriggerContext*)orig) -> fullId();
  return Array(vec.begin(), vec.end());
}

Object CreateTriggerContextProxy::fullIdAt(size_t i) {
  FullIdContextProxy proxy(((MySqlParser::CreateTriggerContext*)orig) -> fullId(i));
  return to_ruby(proxy);
}

Object CreateTriggerContextProxy::ownerStatement() {
  OwnerStatementContextProxy proxy(((MySqlParser::CreateTriggerContext*)orig) -> ownerStatement());
  return to_ruby(proxy);
}

Object CreateViewContextProxy::fullId() {
  FullIdContextProxy proxy(((MySqlParser::CreateViewContext*)orig) -> fullId());
  return to_ruby(proxy);
}

Object CreateViewContextProxy::selectStatement() {
  SelectStatementContextProxy proxy(((MySqlParser::CreateViewContext*)orig) -> selectStatement());
  return to_ruby(proxy);
}

Object CreateViewContextProxy::ownerStatement() {
  OwnerStatementContextProxy proxy(((MySqlParser::CreateViewContext*)orig) -> ownerStatement());
  return to_ruby(proxy);
}

Object CreateViewContextProxy::uidList() {
  UidListContextProxy proxy(((MySqlParser::CreateViewContext*)orig) -> uidList());
  return to_ruby(proxy);
}

Object AlterEventContextProxy::fullId() {
  std::vector<MySqlParser::FullIdContext *> vec = ((MySqlParser::AlterEventContext*)orig) -> fullId();
  return Array(vec.begin(), vec.end());
}

Object AlterEventContextProxy::fullIdAt(size_t i) {
  FullIdContextProxy proxy(((MySqlParser::AlterEventContext*)orig) -> fullId(i));
  return to_ruby(proxy);
}

Object AlterEventContextProxy::ownerStatement() {
  OwnerStatementContextProxy proxy(((MySqlParser::AlterEventContext*)orig) -> ownerStatement());
  return to_ruby(proxy);
}

Object AlterEventContextProxy::scheduleExpression() {
  ScheduleExpressionContextProxy proxy(((MySqlParser::AlterEventContext*)orig) -> scheduleExpression());
  return to_ruby(proxy);
}

Object AlterEventContextProxy::enableType() {
  EnableTypeContextProxy proxy(((MySqlParser::AlterEventContext*)orig) -> enableType());
  return to_ruby(proxy);
}

Object AlterEventContextProxy::routineBody() {
  RoutineBodyContextProxy proxy(((MySqlParser::AlterEventContext*)orig) -> routineBody());
  return to_ruby(proxy);
}

Object AlterFunctionContextProxy::fullId() {
  FullIdContextProxy proxy(((MySqlParser::AlterFunctionContext*)orig) -> fullId());
  return to_ruby(proxy);
}

Object AlterFunctionContextProxy::routineOption() {
  std::vector<MySqlParser::RoutineOptionContext *> vec = ((MySqlParser::AlterFunctionContext*)orig) -> routineOption();
  return Array(vec.begin(), vec.end());
}

Object AlterFunctionContextProxy::routineOptionAt(size_t i) {
  RoutineOptionContextProxy proxy(((MySqlParser::AlterFunctionContext*)orig) -> routineOption(i));
  return to_ruby(proxy);
}

Object AlterLogfileGroupContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::AlterLogfileGroupContext*)orig) -> uid());
  return to_ruby(proxy);
}

Object AlterLogfileGroupContextProxy::engineName() {
  EngineNameContextProxy proxy(((MySqlParser::AlterLogfileGroupContext*)orig) -> engineName());
  return to_ruby(proxy);
}

Object AlterLogfileGroupContextProxy::fileSizeLiteral() {
  FileSizeLiteralContextProxy proxy(((MySqlParser::AlterLogfileGroupContext*)orig) -> fileSizeLiteral());
  return to_ruby(proxy);
}

Object AlterProcedureContextProxy::fullId() {
  FullIdContextProxy proxy(((MySqlParser::AlterProcedureContext*)orig) -> fullId());
  return to_ruby(proxy);
}

Object AlterProcedureContextProxy::routineOption() {
  std::vector<MySqlParser::RoutineOptionContext *> vec = ((MySqlParser::AlterProcedureContext*)orig) -> routineOption();
  return Array(vec.begin(), vec.end());
}

Object AlterProcedureContextProxy::routineOptionAt(size_t i) {
  RoutineOptionContextProxy proxy(((MySqlParser::AlterProcedureContext*)orig) -> routineOption(i));
  return to_ruby(proxy);
}

Object AlterServerContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::AlterServerContext*)orig) -> uid());
  return to_ruby(proxy);
}

Object AlterServerContextProxy::serverOption() {
  std::vector<MySqlParser::ServerOptionContext *> vec = ((MySqlParser::AlterServerContext*)orig) -> serverOption();
  return Array(vec.begin(), vec.end());
}

Object AlterServerContextProxy::serverOptionAt(size_t i) {
  ServerOptionContextProxy proxy(((MySqlParser::AlterServerContext*)orig) -> serverOption(i));
  return to_ruby(proxy);
}

Object AlterTableContextProxy::tableName() {
  TableNameContextProxy proxy(((MySqlParser::AlterTableContext*)orig) -> tableName());
  return to_ruby(proxy);
}

Object AlterTableContextProxy::alterSpecification() {
  std::vector<MySqlParser::AlterSpecificationContext *> vec = ((MySqlParser::AlterTableContext*)orig) -> alterSpecification();
  return Array(vec.begin(), vec.end());
}

Object AlterTableContextProxy::alterSpecificationAt(size_t i) {
  AlterSpecificationContextProxy proxy(((MySqlParser::AlterTableContext*)orig) -> alterSpecification(i));
  return to_ruby(proxy);
}

Object AlterTableContextProxy::partitionDefinitions() {
  PartitionDefinitionsContextProxy proxy(((MySqlParser::AlterTableContext*)orig) -> partitionDefinitions());
  return to_ruby(proxy);
}

Object AlterTablespaceContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::AlterTablespaceContext*)orig) -> uid());
  return to_ruby(proxy);
}

Object AlterTablespaceContextProxy::engineName() {
  EngineNameContextProxy proxy(((MySqlParser::AlterTablespaceContext*)orig) -> engineName());
  return to_ruby(proxy);
}

Object AlterTablespaceContextProxy::fileSizeLiteral() {
  FileSizeLiteralContextProxy proxy(((MySqlParser::AlterTablespaceContext*)orig) -> fileSizeLiteral());
  return to_ruby(proxy);
}

Object AlterViewContextProxy::fullId() {
  FullIdContextProxy proxy(((MySqlParser::AlterViewContext*)orig) -> fullId());
  return to_ruby(proxy);
}

Object AlterViewContextProxy::selectStatement() {
  SelectStatementContextProxy proxy(((MySqlParser::AlterViewContext*)orig) -> selectStatement());
  return to_ruby(proxy);
}

Object AlterViewContextProxy::ownerStatement() {
  OwnerStatementContextProxy proxy(((MySqlParser::AlterViewContext*)orig) -> ownerStatement());
  return to_ruby(proxy);
}

Object AlterViewContextProxy::uidList() {
  UidListContextProxy proxy(((MySqlParser::AlterViewContext*)orig) -> uidList());
  return to_ruby(proxy);
}

Object DropDatabaseContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::DropDatabaseContext*)orig) -> uid());
  return to_ruby(proxy);
}

Object DropDatabaseContextProxy::ifExists() {
  IfExistsContextProxy proxy(((MySqlParser::DropDatabaseContext*)orig) -> ifExists());
  return to_ruby(proxy);
}

Object DropEventContextProxy::fullId() {
  FullIdContextProxy proxy(((MySqlParser::DropEventContext*)orig) -> fullId());
  return to_ruby(proxy);
}

Object DropEventContextProxy::ifExists() {
  IfExistsContextProxy proxy(((MySqlParser::DropEventContext*)orig) -> ifExists());
  return to_ruby(proxy);
}

Object DropIndexContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::DropIndexContext*)orig) -> uid());
  return to_ruby(proxy);
}

Object DropIndexContextProxy::tableName() {
  TableNameContextProxy proxy(((MySqlParser::DropIndexContext*)orig) -> tableName());
  return to_ruby(proxy);
}

Object DropLogfileGroupContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::DropLogfileGroupContext*)orig) -> uid());
  return to_ruby(proxy);
}

Object DropLogfileGroupContextProxy::engineName() {
  EngineNameContextProxy proxy(((MySqlParser::DropLogfileGroupContext*)orig) -> engineName());
  return to_ruby(proxy);
}

Object DropProcedureContextProxy::fullId() {
  FullIdContextProxy proxy(((MySqlParser::DropProcedureContext*)orig) -> fullId());
  return to_ruby(proxy);
}

Object DropProcedureContextProxy::ifExists() {
  IfExistsContextProxy proxy(((MySqlParser::DropProcedureContext*)orig) -> ifExists());
  return to_ruby(proxy);
}

Object DropFunctionContextProxy::fullId() {
  FullIdContextProxy proxy(((MySqlParser::DropFunctionContext*)orig) -> fullId());
  return to_ruby(proxy);
}

Object DropFunctionContextProxy::ifExists() {
  IfExistsContextProxy proxy(((MySqlParser::DropFunctionContext*)orig) -> ifExists());
  return to_ruby(proxy);
}

Object DropServerContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::DropServerContext*)orig) -> uid());
  return to_ruby(proxy);
}

Object DropServerContextProxy::ifExists() {
  IfExistsContextProxy proxy(((MySqlParser::DropServerContext*)orig) -> ifExists());
  return to_ruby(proxy);
}

Object DropTableContextProxy::tables() {
  TablesContextProxy proxy(((MySqlParser::DropTableContext*)orig) -> tables());
  return to_ruby(proxy);
}

Object DropTableContextProxy::ifExists() {
  IfExistsContextProxy proxy(((MySqlParser::DropTableContext*)orig) -> ifExists());
  return to_ruby(proxy);
}

Object DropTablespaceContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::DropTablespaceContext*)orig) -> uid());
  return to_ruby(proxy);
}

Object DropTablespaceContextProxy::engineName() {
  EngineNameContextProxy proxy(((MySqlParser::DropTablespaceContext*)orig) -> engineName());
  return to_ruby(proxy);
}

Object DropTriggerContextProxy::fullId() {
  FullIdContextProxy proxy(((MySqlParser::DropTriggerContext*)orig) -> fullId());
  return to_ruby(proxy);
}

Object DropTriggerContextProxy::ifExists() {
  IfExistsContextProxy proxy(((MySqlParser::DropTriggerContext*)orig) -> ifExists());
  return to_ruby(proxy);
}

Object DropViewContextProxy::fullId() {
  std::vector<MySqlParser::FullIdContext *> vec = ((MySqlParser::DropViewContext*)orig) -> fullId();
  return Array(vec.begin(), vec.end());
}

Object DropViewContextProxy::fullIdAt(size_t i) {
  FullIdContextProxy proxy(((MySqlParser::DropViewContext*)orig) -> fullId(i));
  return to_ruby(proxy);
}

Object DropViewContextProxy::ifExists() {
  IfExistsContextProxy proxy(((MySqlParser::DropViewContext*)orig) -> ifExists());
  return to_ruby(proxy);
}

Object RenameTableContextProxy::renameTableClause() {
  std::vector<MySqlParser::RenameTableClauseContext *> vec = ((MySqlParser::RenameTableContext*)orig) -> renameTableClause();
  return Array(vec.begin(), vec.end());
}

Object RenameTableContextProxy::renameTableClauseAt(size_t i) {
  RenameTableClauseContextProxy proxy(((MySqlParser::RenameTableContext*)orig) -> renameTableClause(i));
  return to_ruby(proxy);
}

Object TruncateTableContextProxy::tableName() {
  TableNameContextProxy proxy(((MySqlParser::TruncateTableContext*)orig) -> tableName());
  return to_ruby(proxy);
}

Object InsertStatementContextProxy::tableName() {
  TableNameContextProxy proxy(((MySqlParser::InsertStatementContext*)orig) -> tableName());
  return to_ruby(proxy);
}

Object InsertStatementContextProxy::insertStatementValue() {
  InsertStatementValueContextProxy proxy(((MySqlParser::InsertStatementContext*)orig) -> insertStatementValue());
  return to_ruby(proxy);
}

Object InsertStatementContextProxy::updatedElement() {
  std::vector<MySqlParser::UpdatedElementContext *> vec = ((MySqlParser::InsertStatementContext*)orig) -> updatedElement();
  return Array(vec.begin(), vec.end());
}

Object InsertStatementContextProxy::updatedElementAt(size_t i) {
  UpdatedElementContextProxy proxy(((MySqlParser::InsertStatementContext*)orig) -> updatedElement(i));
  return to_ruby(proxy);
}

Object InsertStatementContextProxy::uidList() {
  std::vector<MySqlParser::UidListContext *> vec = ((MySqlParser::InsertStatementContext*)orig) -> uidList();
  return Array(vec.begin(), vec.end());
}

Object InsertStatementContextProxy::uidListAt(size_t i) {
  UidListContextProxy proxy(((MySqlParser::InsertStatementContext*)orig) -> uidList(i));
  return to_ruby(proxy);
}

Object UpdateStatementContextProxy::singleUpdateStatement() {
  SingleUpdateStatementContextProxy proxy(((MySqlParser::UpdateStatementContext*)orig) -> singleUpdateStatement());
  return to_ruby(proxy);
}

Object UpdateStatementContextProxy::multipleUpdateStatement() {
  MultipleUpdateStatementContextProxy proxy(((MySqlParser::UpdateStatementContext*)orig) -> multipleUpdateStatement());
  return to_ruby(proxy);
}

Object DeleteStatementContextProxy::singleDeleteStatement() {
  SingleDeleteStatementContextProxy proxy(((MySqlParser::DeleteStatementContext*)orig) -> singleDeleteStatement());
  return to_ruby(proxy);
}

Object DeleteStatementContextProxy::multipleDeleteStatement() {
  MultipleDeleteStatementContextProxy proxy(((MySqlParser::DeleteStatementContext*)orig) -> multipleDeleteStatement());
  return to_ruby(proxy);
}

Object ReplaceStatementContextProxy::tableName() {
  TableNameContextProxy proxy(((MySqlParser::ReplaceStatementContext*)orig) -> tableName());
  return to_ruby(proxy);
}

Object ReplaceStatementContextProxy::insertStatementValue() {
  InsertStatementValueContextProxy proxy(((MySqlParser::ReplaceStatementContext*)orig) -> insertStatementValue());
  return to_ruby(proxy);
}

Object ReplaceStatementContextProxy::updatedElement() {
  std::vector<MySqlParser::UpdatedElementContext *> vec = ((MySqlParser::ReplaceStatementContext*)orig) -> updatedElement();
  return Array(vec.begin(), vec.end());
}

Object ReplaceStatementContextProxy::updatedElementAt(size_t i) {
  UpdatedElementContextProxy proxy(((MySqlParser::ReplaceStatementContext*)orig) -> updatedElement(i));
  return to_ruby(proxy);
}

Object ReplaceStatementContextProxy::uidList() {
  std::vector<MySqlParser::UidListContext *> vec = ((MySqlParser::ReplaceStatementContext*)orig) -> uidList();
  return Array(vec.begin(), vec.end());
}

Object ReplaceStatementContextProxy::uidListAt(size_t i) {
  UidListContextProxy proxy(((MySqlParser::ReplaceStatementContext*)orig) -> uidList(i));
  return to_ruby(proxy);
}

Object CallStatementContextProxy::fullId() {
  FullIdContextProxy proxy(((MySqlParser::CallStatementContext*)orig) -> fullId());
  return to_ruby(proxy);
}

Object CallStatementContextProxy::constants() {
  ConstantsContextProxy proxy(((MySqlParser::CallStatementContext*)orig) -> constants());
  return to_ruby(proxy);
}

Object CallStatementContextProxy::expressions() {
  ExpressionsContextProxy proxy(((MySqlParser::CallStatementContext*)orig) -> expressions());
  return to_ruby(proxy);
}

Object LoadDataStatementContextProxy::tableName() {
  TableNameContextProxy proxy(((MySqlParser::LoadDataStatementContext*)orig) -> tableName());
  return to_ruby(proxy);
}

Object LoadDataStatementContextProxy::uidList() {
  UidListContextProxy proxy(((MySqlParser::LoadDataStatementContext*)orig) -> uidList());
  return to_ruby(proxy);
}

Object LoadDataStatementContextProxy::decimalLiteral() {
  DecimalLiteralContextProxy proxy(((MySqlParser::LoadDataStatementContext*)orig) -> decimalLiteral());
  return to_ruby(proxy);
}

Object LoadDataStatementContextProxy::assignmentField() {
  std::vector<MySqlParser::AssignmentFieldContext *> vec = ((MySqlParser::LoadDataStatementContext*)orig) -> assignmentField();
  return Array(vec.begin(), vec.end());
}

Object LoadDataStatementContextProxy::assignmentFieldAt(size_t i) {
  AssignmentFieldContextProxy proxy(((MySqlParser::LoadDataStatementContext*)orig) -> assignmentField(i));
  return to_ruby(proxy);
}

Object LoadDataStatementContextProxy::updatedElement() {
  std::vector<MySqlParser::UpdatedElementContext *> vec = ((MySqlParser::LoadDataStatementContext*)orig) -> updatedElement();
  return Array(vec.begin(), vec.end());
}

Object LoadDataStatementContextProxy::updatedElementAt(size_t i) {
  UpdatedElementContextProxy proxy(((MySqlParser::LoadDataStatementContext*)orig) -> updatedElement(i));
  return to_ruby(proxy);
}

Object LoadDataStatementContextProxy::charsetName() {
  CharsetNameContextProxy proxy(((MySqlParser::LoadDataStatementContext*)orig) -> charsetName());
  return to_ruby(proxy);
}

Object LoadDataStatementContextProxy::selectFieldsInto() {
  std::vector<MySqlParser::SelectFieldsIntoContext *> vec = ((MySqlParser::LoadDataStatementContext*)orig) -> selectFieldsInto();
  return Array(vec.begin(), vec.end());
}

Object LoadDataStatementContextProxy::selectFieldsIntoAt(size_t i) {
  SelectFieldsIntoContextProxy proxy(((MySqlParser::LoadDataStatementContext*)orig) -> selectFieldsInto(i));
  return to_ruby(proxy);
}

Object LoadDataStatementContextProxy::selectLinesInto() {
  std::vector<MySqlParser::SelectLinesIntoContext *> vec = ((MySqlParser::LoadDataStatementContext*)orig) -> selectLinesInto();
  return Array(vec.begin(), vec.end());
}

Object LoadDataStatementContextProxy::selectLinesIntoAt(size_t i) {
  SelectLinesIntoContextProxy proxy(((MySqlParser::LoadDataStatementContext*)orig) -> selectLinesInto(i));
  return to_ruby(proxy);
}

Object LoadXmlStatementContextProxy::tableName() {
  TableNameContextProxy proxy(((MySqlParser::LoadXmlStatementContext*)orig) -> tableName());
  return to_ruby(proxy);
}

Object LoadXmlStatementContextProxy::decimalLiteral() {
  DecimalLiteralContextProxy proxy(((MySqlParser::LoadXmlStatementContext*)orig) -> decimalLiteral());
  return to_ruby(proxy);
}

Object LoadXmlStatementContextProxy::assignmentField() {
  std::vector<MySqlParser::AssignmentFieldContext *> vec = ((MySqlParser::LoadXmlStatementContext*)orig) -> assignmentField();
  return Array(vec.begin(), vec.end());
}

Object LoadXmlStatementContextProxy::assignmentFieldAt(size_t i) {
  AssignmentFieldContextProxy proxy(((MySqlParser::LoadXmlStatementContext*)orig) -> assignmentField(i));
  return to_ruby(proxy);
}

Object LoadXmlStatementContextProxy::updatedElement() {
  std::vector<MySqlParser::UpdatedElementContext *> vec = ((MySqlParser::LoadXmlStatementContext*)orig) -> updatedElement();
  return Array(vec.begin(), vec.end());
}

Object LoadXmlStatementContextProxy::updatedElementAt(size_t i) {
  UpdatedElementContextProxy proxy(((MySqlParser::LoadXmlStatementContext*)orig) -> updatedElement(i));
  return to_ruby(proxy);
}

Object LoadXmlStatementContextProxy::charsetName() {
  CharsetNameContextProxy proxy(((MySqlParser::LoadXmlStatementContext*)orig) -> charsetName());
  return to_ruby(proxy);
}

Object DoStatementContextProxy::expressions() {
  ExpressionsContextProxy proxy(((MySqlParser::DoStatementContext*)orig) -> expressions());
  return to_ruby(proxy);
}

Object HandlerStatementContextProxy::handlerOpenStatement() {
  HandlerOpenStatementContextProxy proxy(((MySqlParser::HandlerStatementContext*)orig) -> handlerOpenStatement());
  return to_ruby(proxy);
}

Object HandlerStatementContextProxy::handlerReadIndexStatement() {
  HandlerReadIndexStatementContextProxy proxy(((MySqlParser::HandlerStatementContext*)orig) -> handlerReadIndexStatement());
  return to_ruby(proxy);
}

Object HandlerStatementContextProxy::handlerReadStatement() {
  HandlerReadStatementContextProxy proxy(((MySqlParser::HandlerStatementContext*)orig) -> handlerReadStatement());
  return to_ruby(proxy);
}

Object HandlerStatementContextProxy::handlerCloseStatement() {
  HandlerCloseStatementContextProxy proxy(((MySqlParser::HandlerStatementContext*)orig) -> handlerCloseStatement());
  return to_ruby(proxy);
}

Object StartTransactionContextProxy::transactionMode() {
  std::vector<MySqlParser::TransactionModeContext *> vec = ((MySqlParser::StartTransactionContext*)orig) -> transactionMode();
  return Array(vec.begin(), vec.end());
}

Object StartTransactionContextProxy::transactionModeAt(size_t i) {
  TransactionModeContextProxy proxy(((MySqlParser::StartTransactionContext*)orig) -> transactionMode(i));
  return to_ruby(proxy);
}

Object SavepointStatementContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::SavepointStatementContext*)orig) -> uid());
  return to_ruby(proxy);
}

Object RollbackStatementContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::RollbackStatementContext*)orig) -> uid());
  return to_ruby(proxy);
}

Object ReleaseStatementContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::ReleaseStatementContext*)orig) -> uid());
  return to_ruby(proxy);
}

Object LockTablesContextProxy::lockTableElement() {
  std::vector<MySqlParser::LockTableElementContext *> vec = ((MySqlParser::LockTablesContext*)orig) -> lockTableElement();
  return Array(vec.begin(), vec.end());
}

Object LockTablesContextProxy::lockTableElementAt(size_t i) {
  LockTableElementContextProxy proxy(((MySqlParser::LockTablesContext*)orig) -> lockTableElement(i));
  return to_ruby(proxy);
}

Object ChangeMasterContextProxy::masterOption() {
  std::vector<MySqlParser::MasterOptionContext *> vec = ((MySqlParser::ChangeMasterContext*)orig) -> masterOption();
  return Array(vec.begin(), vec.end());
}

Object ChangeMasterContextProxy::masterOptionAt(size_t i) {
  MasterOptionContextProxy proxy(((MySqlParser::ChangeMasterContext*)orig) -> masterOption(i));
  return to_ruby(proxy);
}

Object ChangeMasterContextProxy::channelOption() {
  ChannelOptionContextProxy proxy(((MySqlParser::ChangeMasterContext*)orig) -> channelOption());
  return to_ruby(proxy);
}

Object ChangeReplicationFilterContextProxy::replicationFilter() {
  std::vector<MySqlParser::ReplicationFilterContext *> vec = ((MySqlParser::ChangeReplicationFilterContext*)orig) -> replicationFilter();
  return Array(vec.begin(), vec.end());
}

Object ChangeReplicationFilterContextProxy::replicationFilterAt(size_t i) {
  ReplicationFilterContextProxy proxy(((MySqlParser::ChangeReplicationFilterContext*)orig) -> replicationFilter(i));
  return to_ruby(proxy);
}

Object ResetSlaveContextProxy::channelOption() {
  ChannelOptionContextProxy proxy(((MySqlParser::ResetSlaveContext*)orig) -> channelOption());
  return to_ruby(proxy);
}

Object StartSlaveContextProxy::threadType() {
  std::vector<MySqlParser::ThreadTypeContext *> vec = ((MySqlParser::StartSlaveContext*)orig) -> threadType();
  return Array(vec.begin(), vec.end());
}

Object StartSlaveContextProxy::threadTypeAt(size_t i) {
  ThreadTypeContextProxy proxy(((MySqlParser::StartSlaveContext*)orig) -> threadType(i));
  return to_ruby(proxy);
}

Object StartSlaveContextProxy::untilOption() {
  UntilOptionContextProxy proxy(((MySqlParser::StartSlaveContext*)orig) -> untilOption());
  return to_ruby(proxy);
}

Object StartSlaveContextProxy::connectionOption() {
  std::vector<MySqlParser::ConnectionOptionContext *> vec = ((MySqlParser::StartSlaveContext*)orig) -> connectionOption();
  return Array(vec.begin(), vec.end());
}

Object StartSlaveContextProxy::connectionOptionAt(size_t i) {
  ConnectionOptionContextProxy proxy(((MySqlParser::StartSlaveContext*)orig) -> connectionOption(i));
  return to_ruby(proxy);
}

Object StartSlaveContextProxy::channelOption() {
  ChannelOptionContextProxy proxy(((MySqlParser::StartSlaveContext*)orig) -> channelOption());
  return to_ruby(proxy);
}

Object StopSlaveContextProxy::threadType() {
  std::vector<MySqlParser::ThreadTypeContext *> vec = ((MySqlParser::StopSlaveContext*)orig) -> threadType();
  return Array(vec.begin(), vec.end());
}

Object StopSlaveContextProxy::threadTypeAt(size_t i) {
  ThreadTypeContextProxy proxy(((MySqlParser::StopSlaveContext*)orig) -> threadType(i));
  return to_ruby(proxy);
}

Object XaStartTransactionContextProxy::xid() {
  XidContextProxy proxy(((MySqlParser::XaStartTransactionContext*)orig) -> xid());
  return to_ruby(proxy);
}

Object XaEndTransactionContextProxy::xid() {
  XidContextProxy proxy(((MySqlParser::XaEndTransactionContext*)orig) -> xid());
  return to_ruby(proxy);
}

Object XaPrepareStatementContextProxy::xid() {
  XidContextProxy proxy(((MySqlParser::XaPrepareStatementContext*)orig) -> xid());
  return to_ruby(proxy);
}

Object XaCommitWorkContextProxy::xid() {
  XidContextProxy proxy(((MySqlParser::XaCommitWorkContext*)orig) -> xid());
  return to_ruby(proxy);
}

Object XaRollbackWorkContextProxy::xid() {
  XidContextProxy proxy(((MySqlParser::XaRollbackWorkContext*)orig) -> xid());
  return to_ruby(proxy);
}

Object XaRecoverWorkContextProxy::xid() {
  XidContextProxy proxy(((MySqlParser::XaRecoverWorkContext*)orig) -> xid());
  return to_ruby(proxy);
}

Object PrepareStatementContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::PrepareStatementContext*)orig) -> uid());
  return to_ruby(proxy);
}

Object ExecuteStatementContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::ExecuteStatementContext*)orig) -> uid());
  return to_ruby(proxy);
}

Object ExecuteStatementContextProxy::userVariables() {
  UserVariablesContextProxy proxy(((MySqlParser::ExecuteStatementContext*)orig) -> userVariables());
  return to_ruby(proxy);
}

Object DeallocatePrepareContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::DeallocatePrepareContext*)orig) -> uid());
  return to_ruby(proxy);
}

Object CompoundStatementContextProxy::blockStatement() {
  BlockStatementContextProxy proxy(((MySqlParser::CompoundStatementContext*)orig) -> blockStatement());
  return to_ruby(proxy);
}

Object CompoundStatementContextProxy::caseStatement() {
  CaseStatementContextProxy proxy(((MySqlParser::CompoundStatementContext*)orig) -> caseStatement());
  return to_ruby(proxy);
}

Object CompoundStatementContextProxy::ifStatement() {
  IfStatementContextProxy proxy(((MySqlParser::CompoundStatementContext*)orig) -> ifStatement());
  return to_ruby(proxy);
}

Object CompoundStatementContextProxy::leaveStatement() {
  LeaveStatementContextProxy proxy(((MySqlParser::CompoundStatementContext*)orig) -> leaveStatement());
  return to_ruby(proxy);
}

Object CompoundStatementContextProxy::loopStatement() {
  LoopStatementContextProxy proxy(((MySqlParser::CompoundStatementContext*)orig) -> loopStatement());
  return to_ruby(proxy);
}

Object CompoundStatementContextProxy::repeatStatement() {
  RepeatStatementContextProxy proxy(((MySqlParser::CompoundStatementContext*)orig) -> repeatStatement());
  return to_ruby(proxy);
}

Object CompoundStatementContextProxy::whileStatement() {
  WhileStatementContextProxy proxy(((MySqlParser::CompoundStatementContext*)orig) -> whileStatement());
  return to_ruby(proxy);
}

Object CompoundStatementContextProxy::iterateStatement() {
  IterateStatementContextProxy proxy(((MySqlParser::CompoundStatementContext*)orig) -> iterateStatement());
  return to_ruby(proxy);
}

Object CompoundStatementContextProxy::returnStatement() {
  ReturnStatementContextProxy proxy(((MySqlParser::CompoundStatementContext*)orig) -> returnStatement());
  return to_ruby(proxy);
}

Object CompoundStatementContextProxy::cursorStatement() {
  CursorStatementContextProxy proxy(((MySqlParser::CompoundStatementContext*)orig) -> cursorStatement());
  return to_ruby(proxy);
}

Object BlockStatementContextProxy::uid() {
  std::vector<MySqlParser::UidContext *> vec = ((MySqlParser::BlockStatementContext*)orig) -> uid();
  return Array(vec.begin(), vec.end());
}

Object BlockStatementContextProxy::uidAt(size_t i) {
  UidContextProxy proxy(((MySqlParser::BlockStatementContext*)orig) -> uid(i));
  return to_ruby(proxy);
}

Object BlockStatementContextProxy::declareVariable() {
  std::vector<MySqlParser::DeclareVariableContext *> vec = ((MySqlParser::BlockStatementContext*)orig) -> declareVariable();
  return Array(vec.begin(), vec.end());
}

Object BlockStatementContextProxy::declareVariableAt(size_t i) {
  DeclareVariableContextProxy proxy(((MySqlParser::BlockStatementContext*)orig) -> declareVariable(i));
  return to_ruby(proxy);
}

Object BlockStatementContextProxy::declareCondition() {
  std::vector<MySqlParser::DeclareConditionContext *> vec = ((MySqlParser::BlockStatementContext*)orig) -> declareCondition();
  return Array(vec.begin(), vec.end());
}

Object BlockStatementContextProxy::declareConditionAt(size_t i) {
  DeclareConditionContextProxy proxy(((MySqlParser::BlockStatementContext*)orig) -> declareCondition(i));
  return to_ruby(proxy);
}

Object BlockStatementContextProxy::declareCursor() {
  std::vector<MySqlParser::DeclareCursorContext *> vec = ((MySqlParser::BlockStatementContext*)orig) -> declareCursor();
  return Array(vec.begin(), vec.end());
}

Object BlockStatementContextProxy::declareCursorAt(size_t i) {
  DeclareCursorContextProxy proxy(((MySqlParser::BlockStatementContext*)orig) -> declareCursor(i));
  return to_ruby(proxy);
}

Object BlockStatementContextProxy::declareHandler() {
  std::vector<MySqlParser::DeclareHandlerContext *> vec = ((MySqlParser::BlockStatementContext*)orig) -> declareHandler();
  return Array(vec.begin(), vec.end());
}

Object BlockStatementContextProxy::declareHandlerAt(size_t i) {
  DeclareHandlerContextProxy proxy(((MySqlParser::BlockStatementContext*)orig) -> declareHandler(i));
  return to_ruby(proxy);
}

Object BlockStatementContextProxy::procedureSqlStatement() {
  std::vector<MySqlParser::ProcedureSqlStatementContext *> vec = ((MySqlParser::BlockStatementContext*)orig) -> procedureSqlStatement();
  return Array(vec.begin(), vec.end());
}

Object BlockStatementContextProxy::procedureSqlStatementAt(size_t i) {
  ProcedureSqlStatementContextProxy proxy(((MySqlParser::BlockStatementContext*)orig) -> procedureSqlStatement(i));
  return to_ruby(proxy);
}

Object CaseStatementContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::CaseStatementContext*)orig) -> uid());
  return to_ruby(proxy);
}

Object CaseStatementContextProxy::expression() {
  ExpressionContextProxy proxy(((MySqlParser::CaseStatementContext*)orig) -> expression());
  return to_ruby(proxy);
}

Object CaseStatementContextProxy::caseAlternative() {
  std::vector<MySqlParser::CaseAlternativeContext *> vec = ((MySqlParser::CaseStatementContext*)orig) -> caseAlternative();
  return Array(vec.begin(), vec.end());
}

Object CaseStatementContextProxy::caseAlternativeAt(size_t i) {
  CaseAlternativeContextProxy proxy(((MySqlParser::CaseStatementContext*)orig) -> caseAlternative(i));
  return to_ruby(proxy);
}

Object CaseStatementContextProxy::procedureSqlStatement() {
  std::vector<MySqlParser::ProcedureSqlStatementContext *> vec = ((MySqlParser::CaseStatementContext*)orig) -> procedureSqlStatement();
  return Array(vec.begin(), vec.end());
}

Object CaseStatementContextProxy::procedureSqlStatementAt(size_t i) {
  ProcedureSqlStatementContextProxy proxy(((MySqlParser::CaseStatementContext*)orig) -> procedureSqlStatement(i));
  return to_ruby(proxy);
}

Object IfStatementContextProxy::expression() {
  ExpressionContextProxy proxy(((MySqlParser::IfStatementContext*)orig) -> expression());
  return to_ruby(proxy);
}

Object IfStatementContextProxy::elifAlternative() {
  std::vector<MySqlParser::ElifAlternativeContext *> vec = ((MySqlParser::IfStatementContext*)orig) -> elifAlternative();
  return Array(vec.begin(), vec.end());
}

Object IfStatementContextProxy::elifAlternativeAt(size_t i) {
  ElifAlternativeContextProxy proxy(((MySqlParser::IfStatementContext*)orig) -> elifAlternative(i));
  return to_ruby(proxy);
}

Object IfStatementContextProxy::procedureSqlStatement() {
  std::vector<MySqlParser::ProcedureSqlStatementContext *> vec = ((MySqlParser::IfStatementContext*)orig) -> procedureSqlStatement();
  return Array(vec.begin(), vec.end());
}

Object IfStatementContextProxy::procedureSqlStatementAt(size_t i) {
  ProcedureSqlStatementContextProxy proxy(((MySqlParser::IfStatementContext*)orig) -> procedureSqlStatement(i));
  return to_ruby(proxy);
}

Object LeaveStatementContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::LeaveStatementContext*)orig) -> uid());
  return to_ruby(proxy);
}

Object LoopStatementContextProxy::uid() {
  std::vector<MySqlParser::UidContext *> vec = ((MySqlParser::LoopStatementContext*)orig) -> uid();
  return Array(vec.begin(), vec.end());
}

Object LoopStatementContextProxy::uidAt(size_t i) {
  UidContextProxy proxy(((MySqlParser::LoopStatementContext*)orig) -> uid(i));
  return to_ruby(proxy);
}

Object LoopStatementContextProxy::procedureSqlStatement() {
  std::vector<MySqlParser::ProcedureSqlStatementContext *> vec = ((MySqlParser::LoopStatementContext*)orig) -> procedureSqlStatement();
  return Array(vec.begin(), vec.end());
}

Object LoopStatementContextProxy::procedureSqlStatementAt(size_t i) {
  ProcedureSqlStatementContextProxy proxy(((MySqlParser::LoopStatementContext*)orig) -> procedureSqlStatement(i));
  return to_ruby(proxy);
}

Object RepeatStatementContextProxy::expression() {
  ExpressionContextProxy proxy(((MySqlParser::RepeatStatementContext*)orig) -> expression());
  return to_ruby(proxy);
}

Object RepeatStatementContextProxy::uid() {
  std::vector<MySqlParser::UidContext *> vec = ((MySqlParser::RepeatStatementContext*)orig) -> uid();
  return Array(vec.begin(), vec.end());
}

Object RepeatStatementContextProxy::uidAt(size_t i) {
  UidContextProxy proxy(((MySqlParser::RepeatStatementContext*)orig) -> uid(i));
  return to_ruby(proxy);
}

Object RepeatStatementContextProxy::procedureSqlStatement() {
  std::vector<MySqlParser::ProcedureSqlStatementContext *> vec = ((MySqlParser::RepeatStatementContext*)orig) -> procedureSqlStatement();
  return Array(vec.begin(), vec.end());
}

Object RepeatStatementContextProxy::procedureSqlStatementAt(size_t i) {
  ProcedureSqlStatementContextProxy proxy(((MySqlParser::RepeatStatementContext*)orig) -> procedureSqlStatement(i));
  return to_ruby(proxy);
}

Object WhileStatementContextProxy::expression() {
  ExpressionContextProxy proxy(((MySqlParser::WhileStatementContext*)orig) -> expression());
  return to_ruby(proxy);
}

Object WhileStatementContextProxy::uid() {
  std::vector<MySqlParser::UidContext *> vec = ((MySqlParser::WhileStatementContext*)orig) -> uid();
  return Array(vec.begin(), vec.end());
}

Object WhileStatementContextProxy::uidAt(size_t i) {
  UidContextProxy proxy(((MySqlParser::WhileStatementContext*)orig) -> uid(i));
  return to_ruby(proxy);
}

Object WhileStatementContextProxy::procedureSqlStatement() {
  std::vector<MySqlParser::ProcedureSqlStatementContext *> vec = ((MySqlParser::WhileStatementContext*)orig) -> procedureSqlStatement();
  return Array(vec.begin(), vec.end());
}

Object WhileStatementContextProxy::procedureSqlStatementAt(size_t i) {
  ProcedureSqlStatementContextProxy proxy(((MySqlParser::WhileStatementContext*)orig) -> procedureSqlStatement(i));
  return to_ruby(proxy);
}

Object IterateStatementContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::IterateStatementContext*)orig) -> uid());
  return to_ruby(proxy);
}

Object ReturnStatementContextProxy::expression() {
  ExpressionContextProxy proxy(((MySqlParser::ReturnStatementContext*)orig) -> expression());
  return to_ruby(proxy);
}

Object DropUserContextProxy::userName() {
  std::vector<MySqlParser::UserNameContext *> vec = ((MySqlParser::DropUserContext*)orig) -> userName();
  return Array(vec.begin(), vec.end());
}

Object DropUserContextProxy::userNameAt(size_t i) {
  UserNameContextProxy proxy(((MySqlParser::DropUserContext*)orig) -> userName(i));
  return to_ruby(proxy);
}

Object DropUserContextProxy::ifExists() {
  IfExistsContextProxy proxy(((MySqlParser::DropUserContext*)orig) -> ifExists());
  return to_ruby(proxy);
}

Object GrantStatementContextProxy::privelegeClause() {
  std::vector<MySqlParser::PrivelegeClauseContext *> vec = ((MySqlParser::GrantStatementContext*)orig) -> privelegeClause();
  return Array(vec.begin(), vec.end());
}

Object GrantStatementContextProxy::privelegeClauseAt(size_t i) {
  PrivelegeClauseContextProxy proxy(((MySqlParser::GrantStatementContext*)orig) -> privelegeClause(i));
  return to_ruby(proxy);
}

Object GrantStatementContextProxy::privilegeLevel() {
  PrivilegeLevelContextProxy proxy(((MySqlParser::GrantStatementContext*)orig) -> privilegeLevel());
  return to_ruby(proxy);
}

Object GrantStatementContextProxy::userAuthOption() {
  std::vector<MySqlParser::UserAuthOptionContext *> vec = ((MySqlParser::GrantStatementContext*)orig) -> userAuthOption();
  return Array(vec.begin(), vec.end());
}

Object GrantStatementContextProxy::userAuthOptionAt(size_t i) {
  UserAuthOptionContextProxy proxy(((MySqlParser::GrantStatementContext*)orig) -> userAuthOption(i));
  return to_ruby(proxy);
}

Object GrantStatementContextProxy::tlsOption() {
  std::vector<MySqlParser::TlsOptionContext *> vec = ((MySqlParser::GrantStatementContext*)orig) -> tlsOption();
  return Array(vec.begin(), vec.end());
}

Object GrantStatementContextProxy::tlsOptionAt(size_t i) {
  TlsOptionContextProxy proxy(((MySqlParser::GrantStatementContext*)orig) -> tlsOption(i));
  return to_ruby(proxy);
}

Object GrantStatementContextProxy::userResourceOption() {
  std::vector<MySqlParser::UserResourceOptionContext *> vec = ((MySqlParser::GrantStatementContext*)orig) -> userResourceOption();
  return Array(vec.begin(), vec.end());
}

Object GrantStatementContextProxy::userResourceOptionAt(size_t i) {
  UserResourceOptionContextProxy proxy(((MySqlParser::GrantStatementContext*)orig) -> userResourceOption(i));
  return to_ruby(proxy);
}

Object GrantProxyContextProxy::userName() {
  std::vector<MySqlParser::UserNameContext *> vec = ((MySqlParser::GrantProxyContext*)orig) -> userName();
  return Array(vec.begin(), vec.end());
}

Object GrantProxyContextProxy::userNameAt(size_t i) {
  UserNameContextProxy proxy(((MySqlParser::GrantProxyContext*)orig) -> userName(i));
  return to_ruby(proxy);
}

Object RenameUserContextProxy::renameUserClause() {
  std::vector<MySqlParser::RenameUserClauseContext *> vec = ((MySqlParser::RenameUserContext*)orig) -> renameUserClause();
  return Array(vec.begin(), vec.end());
}

Object RenameUserContextProxy::renameUserClauseAt(size_t i) {
  RenameUserClauseContextProxy proxy(((MySqlParser::RenameUserContext*)orig) -> renameUserClause(i));
  return to_ruby(proxy);
}

Object RevokeProxyContextProxy::userName() {
  std::vector<MySqlParser::UserNameContext *> vec = ((MySqlParser::RevokeProxyContext*)orig) -> userName();
  return Array(vec.begin(), vec.end());
}

Object RevokeProxyContextProxy::userNameAt(size_t i) {
  UserNameContextProxy proxy(((MySqlParser::RevokeProxyContext*)orig) -> userName(i));
  return to_ruby(proxy);
}

Object AnalyzeTableContextProxy::tables() {
  TablesContextProxy proxy(((MySqlParser::AnalyzeTableContext*)orig) -> tables());
  return to_ruby(proxy);
}

Object CheckTableContextProxy::tables() {
  TablesContextProxy proxy(((MySqlParser::CheckTableContext*)orig) -> tables());
  return to_ruby(proxy);
}

Object CheckTableContextProxy::checkTableOption() {
  std::vector<MySqlParser::CheckTableOptionContext *> vec = ((MySqlParser::CheckTableContext*)orig) -> checkTableOption();
  return Array(vec.begin(), vec.end());
}

Object CheckTableContextProxy::checkTableOptionAt(size_t i) {
  CheckTableOptionContextProxy proxy(((MySqlParser::CheckTableContext*)orig) -> checkTableOption(i));
  return to_ruby(proxy);
}

Object ChecksumTableContextProxy::tables() {
  TablesContextProxy proxy(((MySqlParser::ChecksumTableContext*)orig) -> tables());
  return to_ruby(proxy);
}

Object OptimizeTableContextProxy::tables() {
  TablesContextProxy proxy(((MySqlParser::OptimizeTableContext*)orig) -> tables());
  return to_ruby(proxy);
}

Object RepairTableContextProxy::tables() {
  TablesContextProxy proxy(((MySqlParser::RepairTableContext*)orig) -> tables());
  return to_ruby(proxy);
}

Object CreateUdfunctionContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::CreateUdfunctionContext*)orig) -> uid());
  return to_ruby(proxy);
}

Object InstallPluginContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::InstallPluginContext*)orig) -> uid());
  return to_ruby(proxy);
}

Object UninstallPluginContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::UninstallPluginContext*)orig) -> uid());
  return to_ruby(proxy);
}

Object CacheIndexStatementContextProxy::tableIndexes() {
  std::vector<MySqlParser::TableIndexesContext *> vec = ((MySqlParser::CacheIndexStatementContext*)orig) -> tableIndexes();
  return Array(vec.begin(), vec.end());
}

Object CacheIndexStatementContextProxy::tableIndexesAt(size_t i) {
  TableIndexesContextProxy proxy(((MySqlParser::CacheIndexStatementContext*)orig) -> tableIndexes(i));
  return to_ruby(proxy);
}

Object CacheIndexStatementContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::CacheIndexStatementContext*)orig) -> uid());
  return to_ruby(proxy);
}

Object CacheIndexStatementContextProxy::uidList() {
  UidListContextProxy proxy(((MySqlParser::CacheIndexStatementContext*)orig) -> uidList());
  return to_ruby(proxy);
}

Object FlushStatementContextProxy::flushOption() {
  std::vector<MySqlParser::FlushOptionContext *> vec = ((MySqlParser::FlushStatementContext*)orig) -> flushOption();
  return Array(vec.begin(), vec.end());
}

Object FlushStatementContextProxy::flushOptionAt(size_t i) {
  FlushOptionContextProxy proxy(((MySqlParser::FlushStatementContext*)orig) -> flushOption(i));
  return to_ruby(proxy);
}

Object KillStatementContextProxy::decimalLiteral() {
  std::vector<MySqlParser::DecimalLiteralContext *> vec = ((MySqlParser::KillStatementContext*)orig) -> decimalLiteral();
  return Array(vec.begin(), vec.end());
}

Object KillStatementContextProxy::decimalLiteralAt(size_t i) {
  DecimalLiteralContextProxy proxy(((MySqlParser::KillStatementContext*)orig) -> decimalLiteral(i));
  return to_ruby(proxy);
}

Object LoadIndexIntoCacheContextProxy::loadedTableIndexes() {
  std::vector<MySqlParser::LoadedTableIndexesContext *> vec = ((MySqlParser::LoadIndexIntoCacheContext*)orig) -> loadedTableIndexes();
  return Array(vec.begin(), vec.end());
}

Object LoadIndexIntoCacheContextProxy::loadedTableIndexesAt(size_t i) {
  LoadedTableIndexesContextProxy proxy(((MySqlParser::LoadIndexIntoCacheContext*)orig) -> loadedTableIndexes(i));
  return to_ruby(proxy);
}

Object SimpleDescribeStatementContextProxy::tableName() {
  TableNameContextProxy proxy(((MySqlParser::SimpleDescribeStatementContext*)orig) -> tableName());
  return to_ruby(proxy);
}

Object SimpleDescribeStatementContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::SimpleDescribeStatementContext*)orig) -> uid());
  return to_ruby(proxy);
}

Object FullDescribeStatementContextProxy::describeObjectClause() {
  DescribeObjectClauseContextProxy proxy(((MySqlParser::FullDescribeStatementContext*)orig) -> describeObjectClause());
  return to_ruby(proxy);
}

Object UseStatementContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::UseStatementContext*)orig) -> uid());
  return to_ruby(proxy);
}

Object SignalStatementContextProxy::signalConditionInformation() {
  std::vector<MySqlParser::SignalConditionInformationContext *> vec = ((MySqlParser::SignalStatementContext*)orig) -> signalConditionInformation();
  return Array(vec.begin(), vec.end());
}

Object SignalStatementContextProxy::signalConditionInformationAt(size_t i) {
  SignalConditionInformationContextProxy proxy(((MySqlParser::SignalStatementContext*)orig) -> signalConditionInformation(i));
  return to_ruby(proxy);
}

Object SignalStatementContextProxy::stringLiteral() {
  StringLiteralContextProxy proxy(((MySqlParser::SignalStatementContext*)orig) -> stringLiteral());
  return to_ruby(proxy);
}

Object ResignalStatementContextProxy::signalConditionInformation() {
  std::vector<MySqlParser::SignalConditionInformationContext *> vec = ((MySqlParser::ResignalStatementContext*)orig) -> signalConditionInformation();
  return Array(vec.begin(), vec.end());
}

Object ResignalStatementContextProxy::signalConditionInformationAt(size_t i) {
  SignalConditionInformationContextProxy proxy(((MySqlParser::ResignalStatementContext*)orig) -> signalConditionInformation(i));
  return to_ruby(proxy);
}

Object ResignalStatementContextProxy::stringLiteral() {
  StringLiteralContextProxy proxy(((MySqlParser::ResignalStatementContext*)orig) -> stringLiteral());
  return to_ruby(proxy);
}

Object DiagnosticsStatementContextProxy::variableClause() {
  std::vector<MySqlParser::VariableClauseContext *> vec = ((MySqlParser::DiagnosticsStatementContext*)orig) -> variableClause();
  return Array(vec.begin(), vec.end());
}

Object DiagnosticsStatementContextProxy::variableClauseAt(size_t i) {
  VariableClauseContextProxy proxy(((MySqlParser::DiagnosticsStatementContext*)orig) -> variableClause(i));
  return to_ruby(proxy);
}

Object DiagnosticsStatementContextProxy::diagnosticsConditionInformationName() {
  std::vector<MySqlParser::DiagnosticsConditionInformationNameContext *> vec = ((MySqlParser::DiagnosticsStatementContext*)orig) -> diagnosticsConditionInformationName();
  return Array(vec.begin(), vec.end());
}

Object DiagnosticsStatementContextProxy::diagnosticsConditionInformationNameAt(size_t i) {
  DiagnosticsConditionInformationNameContextProxy proxy(((MySqlParser::DiagnosticsStatementContext*)orig) -> diagnosticsConditionInformationName(i));
  return to_ruby(proxy);
}

Object DiagnosticsStatementContextProxy::decimalLiteral() {
  DecimalLiteralContextProxy proxy(((MySqlParser::DiagnosticsStatementContext*)orig) -> decimalLiteral());
  return to_ruby(proxy);
}

Object UidContextProxy::simpleId() {
  SimpleIdContextProxy proxy(((MySqlParser::UidContext*)orig) -> simpleId());
  return to_ruby(proxy);
}

Object CreateDatabaseOptionContextProxy::charsetName() {
  CharsetNameContextProxy proxy(((MySqlParser::CreateDatabaseOptionContext*)orig) -> charsetName());
  return to_ruby(proxy);
}

Object CreateDatabaseOptionContextProxy::collationName() {
  CollationNameContextProxy proxy(((MySqlParser::CreateDatabaseOptionContext*)orig) -> collationName());
  return to_ruby(proxy);
}

Object FullIdContextProxy::uid() {
  std::vector<MySqlParser::UidContext *> vec = ((MySqlParser::FullIdContext*)orig) -> uid();
  return Array(vec.begin(), vec.end());
}

Object FullIdContextProxy::uidAt(size_t i) {
  UidContextProxy proxy(((MySqlParser::FullIdContext*)orig) -> uid(i));
  return to_ruby(proxy);
}

Object RoutineBodyContextProxy::blockStatement() {
  BlockStatementContextProxy proxy(((MySqlParser::RoutineBodyContext*)orig) -> blockStatement());
  return to_ruby(proxy);
}

Object RoutineBodyContextProxy::sqlStatement() {
  SqlStatementContextProxy proxy(((MySqlParser::RoutineBodyContext*)orig) -> sqlStatement());
  return to_ruby(proxy);
}

Object OwnerStatementContextProxy::userName() {
  UserNameContextProxy proxy(((MySqlParser::OwnerStatementContext*)orig) -> userName());
  return to_ruby(proxy);
}

Object TableNameContextProxy::fullId() {
  FullIdContextProxy proxy(((MySqlParser::TableNameContext*)orig) -> fullId());
  return to_ruby(proxy);
}

Object IndexColumnNamesContextProxy::indexColumnName() {
  std::vector<MySqlParser::IndexColumnNameContext *> vec = ((MySqlParser::IndexColumnNamesContext*)orig) -> indexColumnName();
  return Array(vec.begin(), vec.end());
}

Object IndexColumnNamesContextProxy::indexColumnNameAt(size_t i) {
  IndexColumnNameContextProxy proxy(((MySqlParser::IndexColumnNamesContext*)orig) -> indexColumnName(i));
  return to_ruby(proxy);
}

Object IndexOptionContextProxy::fileSizeLiteral() {
  FileSizeLiteralContextProxy proxy(((MySqlParser::IndexOptionContext*)orig) -> fileSizeLiteral());
  return to_ruby(proxy);
}

Object IndexOptionContextProxy::indexType() {
  IndexTypeContextProxy proxy(((MySqlParser::IndexOptionContext*)orig) -> indexType());
  return to_ruby(proxy);
}

Object IndexOptionContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::IndexOptionContext*)orig) -> uid());
  return to_ruby(proxy);
}

Object FileSizeLiteralContextProxy::decimalLiteral() {
  DecimalLiteralContextProxy proxy(((MySqlParser::FileSizeLiteralContext*)orig) -> decimalLiteral());
  return to_ruby(proxy);
}

Object ProcedureParameterContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::ProcedureParameterContext*)orig) -> uid());
  return to_ruby(proxy);
}

Object ProcedureParameterContextProxy::dataType() {
  DataTypeContextProxy proxy(((MySqlParser::ProcedureParameterContext*)orig) -> dataType());
  return to_ruby(proxy);
}

Object FunctionParameterContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::FunctionParameterContext*)orig) -> uid());
  return to_ruby(proxy);
}

Object FunctionParameterContextProxy::dataType() {
  DataTypeContextProxy proxy(((MySqlParser::FunctionParameterContext*)orig) -> dataType());
  return to_ruby(proxy);
}

Object ServerOptionContextProxy::decimalLiteral() {
  DecimalLiteralContextProxy proxy(((MySqlParser::ServerOptionContext*)orig) -> decimalLiteral());
  return to_ruby(proxy);
}

Object CopyCreateTableContextProxy::tableName() {
  std::vector<MySqlParser::TableNameContext *> vec = ((MySqlParser::CopyCreateTableContext*)orig) -> tableName();
  return Array(vec.begin(), vec.end());
}

Object CopyCreateTableContextProxy::tableNameAt(size_t i) {
  TableNameContextProxy proxy(((MySqlParser::CopyCreateTableContext*)orig) -> tableName(i));
  return to_ruby(proxy);
}

Object CopyCreateTableContextProxy::ifNotExists() {
  IfNotExistsContextProxy proxy(((MySqlParser::CopyCreateTableContext*)orig) -> ifNotExists());
  return to_ruby(proxy);
}

Object ColumnCreateTableContextProxy::tableName() {
  TableNameContextProxy proxy(((MySqlParser::ColumnCreateTableContext*)orig) -> tableName());
  return to_ruby(proxy);
}

Object ColumnCreateTableContextProxy::createDefinitions() {
  CreateDefinitionsContextProxy proxy(((MySqlParser::ColumnCreateTableContext*)orig) -> createDefinitions());
  return to_ruby(proxy);
}

Object ColumnCreateTableContextProxy::ifNotExists() {
  IfNotExistsContextProxy proxy(((MySqlParser::ColumnCreateTableContext*)orig) -> ifNotExists());
  return to_ruby(proxy);
}

Object ColumnCreateTableContextProxy::tableOption() {
  std::vector<MySqlParser::TableOptionContext *> vec = ((MySqlParser::ColumnCreateTableContext*)orig) -> tableOption();
  return Array(vec.begin(), vec.end());
}

Object ColumnCreateTableContextProxy::tableOptionAt(size_t i) {
  TableOptionContextProxy proxy(((MySqlParser::ColumnCreateTableContext*)orig) -> tableOption(i));
  return to_ruby(proxy);
}

Object ColumnCreateTableContextProxy::partitionDefinitions() {
  PartitionDefinitionsContextProxy proxy(((MySqlParser::ColumnCreateTableContext*)orig) -> partitionDefinitions());
  return to_ruby(proxy);
}

Object CreateDefinitionsContextProxy::createDefinition() {
  std::vector<MySqlParser::CreateDefinitionContext *> vec = ((MySqlParser::CreateDefinitionsContext*)orig) -> createDefinition();
  return Array(vec.begin(), vec.end());
}

Object CreateDefinitionsContextProxy::createDefinitionAt(size_t i) {
  CreateDefinitionContextProxy proxy(((MySqlParser::CreateDefinitionsContext*)orig) -> createDefinition(i));
  return to_ruby(proxy);
}

Object PartitionDefinitionsContextProxy::partitionFunctionDefinition() {
  PartitionFunctionDefinitionContextProxy proxy(((MySqlParser::PartitionDefinitionsContext*)orig) -> partitionFunctionDefinition());
  return to_ruby(proxy);
}

Object PartitionDefinitionsContextProxy::subpartitionFunctionDefinition() {
  SubpartitionFunctionDefinitionContextProxy proxy(((MySqlParser::PartitionDefinitionsContext*)orig) -> subpartitionFunctionDefinition());
  return to_ruby(proxy);
}

Object PartitionDefinitionsContextProxy::partitionDefinition() {
  std::vector<MySqlParser::PartitionDefinitionContext *> vec = ((MySqlParser::PartitionDefinitionsContext*)orig) -> partitionDefinition();
  return Array(vec.begin(), vec.end());
}

Object PartitionDefinitionsContextProxy::partitionDefinitionAt(size_t i) {
  PartitionDefinitionContextProxy proxy(((MySqlParser::PartitionDefinitionsContext*)orig) -> partitionDefinition(i));
  return to_ruby(proxy);
}

Object PartitionDefinitionsContextProxy::decimalLiteral() {
  std::vector<MySqlParser::DecimalLiteralContext *> vec = ((MySqlParser::PartitionDefinitionsContext*)orig) -> decimalLiteral();
  return Array(vec.begin(), vec.end());
}

Object PartitionDefinitionsContextProxy::decimalLiteralAt(size_t i) {
  DecimalLiteralContextProxy proxy(((MySqlParser::PartitionDefinitionsContext*)orig) -> decimalLiteral(i));
  return to_ruby(proxy);
}

Object QueryCreateTableContextProxy::tableName() {
  TableNameContextProxy proxy(((MySqlParser::QueryCreateTableContext*)orig) -> tableName());
  return to_ruby(proxy);
}

Object QueryCreateTableContextProxy::selectStatement() {
  SelectStatementContextProxy proxy(((MySqlParser::QueryCreateTableContext*)orig) -> selectStatement());
  return to_ruby(proxy);
}

Object QueryCreateTableContextProxy::ifNotExists() {
  IfNotExistsContextProxy proxy(((MySqlParser::QueryCreateTableContext*)orig) -> ifNotExists());
  return to_ruby(proxy);
}

Object QueryCreateTableContextProxy::createDefinitions() {
  CreateDefinitionsContextProxy proxy(((MySqlParser::QueryCreateTableContext*)orig) -> createDefinitions());
  return to_ruby(proxy);
}

Object QueryCreateTableContextProxy::tableOption() {
  std::vector<MySqlParser::TableOptionContext *> vec = ((MySqlParser::QueryCreateTableContext*)orig) -> tableOption();
  return Array(vec.begin(), vec.end());
}

Object QueryCreateTableContextProxy::tableOptionAt(size_t i) {
  TableOptionContextProxy proxy(((MySqlParser::QueryCreateTableContext*)orig) -> tableOption(i));
  return to_ruby(proxy);
}

Object QueryCreateTableContextProxy::partitionDefinitions() {
  PartitionDefinitionsContextProxy proxy(((MySqlParser::QueryCreateTableContext*)orig) -> partitionDefinitions());
  return to_ruby(proxy);
}

Object UidListContextProxy::uid() {
  std::vector<MySqlParser::UidContext *> vec = ((MySqlParser::UidListContext*)orig) -> uid();
  return Array(vec.begin(), vec.end());
}

Object UidListContextProxy::uidAt(size_t i) {
  UidContextProxy proxy(((MySqlParser::UidListContext*)orig) -> uid(i));
  return to_ruby(proxy);
}

Object CharsetNameContextProxy::charsetNameBase() {
  CharsetNameBaseContextProxy proxy(((MySqlParser::CharsetNameContext*)orig) -> charsetNameBase());
  return to_ruby(proxy);
}

Object CollationNameContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::CollationNameContext*)orig) -> uid());
  return to_ruby(proxy);
}

Object PreciseScheduleContextProxy::timestampValue() {
  TimestampValueContextProxy proxy(((MySqlParser::PreciseScheduleContext*)orig) -> timestampValue());
  return to_ruby(proxy);
}

Object PreciseScheduleContextProxy::intervalExpr() {
  std::vector<MySqlParser::IntervalExprContext *> vec = ((MySqlParser::PreciseScheduleContext*)orig) -> intervalExpr();
  return Array(vec.begin(), vec.end());
}

Object PreciseScheduleContextProxy::intervalExprAt(size_t i) {
  IntervalExprContextProxy proxy(((MySqlParser::PreciseScheduleContext*)orig) -> intervalExpr(i));
  return to_ruby(proxy);
}

Object TimestampValueContextProxy::stringLiteral() {
  StringLiteralContextProxy proxy(((MySqlParser::TimestampValueContext*)orig) -> stringLiteral());
  return to_ruby(proxy);
}

Object TimestampValueContextProxy::decimalLiteral() {
  DecimalLiteralContextProxy proxy(((MySqlParser::TimestampValueContext*)orig) -> decimalLiteral());
  return to_ruby(proxy);
}

Object TimestampValueContextProxy::expression() {
  ExpressionContextProxy proxy(((MySqlParser::TimestampValueContext*)orig) -> expression());
  return to_ruby(proxy);
}

Object IntervalExprContextProxy::intervalType() {
  IntervalTypeContextProxy proxy(((MySqlParser::IntervalExprContext*)orig) -> intervalType());
  return to_ruby(proxy);
}

Object IntervalExprContextProxy::decimalLiteral() {
  DecimalLiteralContextProxy proxy(((MySqlParser::IntervalExprContext*)orig) -> decimalLiteral());
  return to_ruby(proxy);
}

Object IntervalExprContextProxy::expression() {
  ExpressionContextProxy proxy(((MySqlParser::IntervalExprContext*)orig) -> expression());
  return to_ruby(proxy);
}

Object IntervalScheduleContextProxy::intervalType() {
  IntervalTypeContextProxy proxy(((MySqlParser::IntervalScheduleContext*)orig) -> intervalType());
  return to_ruby(proxy);
}

Object IntervalScheduleContextProxy::decimalLiteral() {
  DecimalLiteralContextProxy proxy(((MySqlParser::IntervalScheduleContext*)orig) -> decimalLiteral());
  return to_ruby(proxy);
}

Object IntervalScheduleContextProxy::expression() {
  ExpressionContextProxy proxy(((MySqlParser::IntervalScheduleContext*)orig) -> expression());
  return to_ruby(proxy);
}

Object IntervalScheduleContextProxy::timestampValue() {
  std::vector<MySqlParser::TimestampValueContext *> vec = ((MySqlParser::IntervalScheduleContext*)orig) -> timestampValue();
  return Array(vec.begin(), vec.end());
}

Object IntervalScheduleContextProxy::timestampValueAt(size_t i) {
  TimestampValueContextProxy proxy(((MySqlParser::IntervalScheduleContext*)orig) -> timestampValue(i));
  return to_ruby(proxy);
}

Object IntervalScheduleContextProxy::intervalExpr() {
  std::vector<MySqlParser::IntervalExprContext *> vec = ((MySqlParser::IntervalScheduleContext*)orig) -> intervalExpr();
  return Array(vec.begin(), vec.end());
}

Object IntervalScheduleContextProxy::intervalExprAt(size_t i) {
  IntervalExprContextProxy proxy(((MySqlParser::IntervalScheduleContext*)orig) -> intervalExpr(i));
  return to_ruby(proxy);
}

Object IntervalTypeContextProxy::intervalTypeBase() {
  IntervalTypeBaseContextProxy proxy(((MySqlParser::IntervalTypeContext*)orig) -> intervalTypeBase());
  return to_ruby(proxy);
}

Object StringLiteralContextProxy::collationName() {
  CollationNameContextProxy proxy(((MySqlParser::StringLiteralContext*)orig) -> collationName());
  return to_ruby(proxy);
}

Object ColumnDeclarationContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::ColumnDeclarationContext*)orig) -> uid());
  return to_ruby(proxy);
}

Object ColumnDeclarationContextProxy::columnDefinition() {
  ColumnDefinitionContextProxy proxy(((MySqlParser::ColumnDeclarationContext*)orig) -> columnDefinition());
  return to_ruby(proxy);
}

Object ColumnDefinitionContextProxy::dataType() {
  DataTypeContextProxy proxy(((MySqlParser::ColumnDefinitionContext*)orig) -> dataType());
  return to_ruby(proxy);
}

Object ColumnDefinitionContextProxy::columnConstraint() {
  std::vector<MySqlParser::ColumnConstraintContext *> vec = ((MySqlParser::ColumnDefinitionContext*)orig) -> columnConstraint();
  return Array(vec.begin(), vec.end());
}

Object ColumnDefinitionContextProxy::columnConstraintAt(size_t i) {
  ColumnConstraintContextProxy proxy(((MySqlParser::ColumnDefinitionContext*)orig) -> columnConstraint(i));
  return to_ruby(proxy);
}

Object ConstraintDeclarationContextProxy::tableConstraint() {
  TableConstraintContextProxy proxy(((MySqlParser::ConstraintDeclarationContext*)orig) -> tableConstraint());
  return to_ruby(proxy);
}

Object IndexDeclarationContextProxy::indexColumnDefinition() {
  IndexColumnDefinitionContextProxy proxy(((MySqlParser::IndexDeclarationContext*)orig) -> indexColumnDefinition());
  return to_ruby(proxy);
}

Object CollateColumnConstraintContextProxy::collationName() {
  CollationNameContextProxy proxy(((MySqlParser::CollateColumnConstraintContext*)orig) -> collationName());
  return to_ruby(proxy);
}

Object AutoIncrementColumnConstraintContextProxy::currentTimestamp() {
  CurrentTimestampContextProxy proxy(((MySqlParser::AutoIncrementColumnConstraintContext*)orig) -> currentTimestamp());
  return to_ruby(proxy);
}

Object CurrentTimestampContextProxy::decimalLiteral() {
  DecimalLiteralContextProxy proxy(((MySqlParser::CurrentTimestampContext*)orig) -> decimalLiteral());
  return to_ruby(proxy);
}

Object NullColumnConstraintContextProxy::nullNotnull() {
  NullNotnullContextProxy proxy(((MySqlParser::NullColumnConstraintContext*)orig) -> nullNotnull());
  return to_ruby(proxy);
}

Object DefaultColumnConstraintContextProxy::defaultValue() {
  DefaultValueContextProxy proxy(((MySqlParser::DefaultColumnConstraintContext*)orig) -> defaultValue());
  return to_ruby(proxy);
}

Object DefaultValueContextProxy::constant() {
  ConstantContextProxy proxy(((MySqlParser::DefaultValueContext*)orig) -> constant());
  return to_ruby(proxy);
}

Object DefaultValueContextProxy::unaryOperator() {
  UnaryOperatorContextProxy proxy(((MySqlParser::DefaultValueContext*)orig) -> unaryOperator());
  return to_ruby(proxy);
}

Object DefaultValueContextProxy::currentTimestamp() {
  std::vector<MySqlParser::CurrentTimestampContext *> vec = ((MySqlParser::DefaultValueContext*)orig) -> currentTimestamp();
  return Array(vec.begin(), vec.end());
}

Object DefaultValueContextProxy::currentTimestampAt(size_t i) {
  CurrentTimestampContextProxy proxy(((MySqlParser::DefaultValueContext*)orig) -> currentTimestamp(i));
  return to_ruby(proxy);
}

Object ReferenceDefinitionContextProxy::tableName() {
  TableNameContextProxy proxy(((MySqlParser::ReferenceDefinitionContext*)orig) -> tableName());
  return to_ruby(proxy);
}

Object ReferenceDefinitionContextProxy::indexColumnNames() {
  IndexColumnNamesContextProxy proxy(((MySqlParser::ReferenceDefinitionContext*)orig) -> indexColumnNames());
  return to_ruby(proxy);
}

Object ReferenceDefinitionContextProxy::referenceAction() {
  ReferenceActionContextProxy proxy(((MySqlParser::ReferenceDefinitionContext*)orig) -> referenceAction());
  return to_ruby(proxy);
}

Object ReferenceColumnConstraintContextProxy::referenceDefinition() {
  ReferenceDefinitionContextProxy proxy(((MySqlParser::ReferenceColumnConstraintContext*)orig) -> referenceDefinition());
  return to_ruby(proxy);
}

Object GeneratedColumnConstraintContextProxy::expression() {
  ExpressionContextProxy proxy(((MySqlParser::GeneratedColumnConstraintContext*)orig) -> expression());
  return to_ruby(proxy);
}

Object UniqueKeyTableConstraintContextProxy::indexColumnNames() {
  IndexColumnNamesContextProxy proxy(((MySqlParser::UniqueKeyTableConstraintContext*)orig) -> indexColumnNames());
  return to_ruby(proxy);
}

Object UniqueKeyTableConstraintContextProxy::indexType() {
  IndexTypeContextProxy proxy(((MySqlParser::UniqueKeyTableConstraintContext*)orig) -> indexType());
  return to_ruby(proxy);
}

Object UniqueKeyTableConstraintContextProxy::indexOption() {
  std::vector<MySqlParser::IndexOptionContext *> vec = ((MySqlParser::UniqueKeyTableConstraintContext*)orig) -> indexOption();
  return Array(vec.begin(), vec.end());
}

Object UniqueKeyTableConstraintContextProxy::indexOptionAt(size_t i) {
  IndexOptionContextProxy proxy(((MySqlParser::UniqueKeyTableConstraintContext*)orig) -> indexOption(i));
  return to_ruby(proxy);
}

Object UniqueKeyTableConstraintContextProxy::uid() {
  std::vector<MySqlParser::UidContext *> vec = ((MySqlParser::UniqueKeyTableConstraintContext*)orig) -> uid();
  return Array(vec.begin(), vec.end());
}

Object UniqueKeyTableConstraintContextProxy::uidAt(size_t i) {
  UidContextProxy proxy(((MySqlParser::UniqueKeyTableConstraintContext*)orig) -> uid(i));
  return to_ruby(proxy);
}

Object CheckTableConstraintContextProxy::expression() {
  ExpressionContextProxy proxy(((MySqlParser::CheckTableConstraintContext*)orig) -> expression());
  return to_ruby(proxy);
}

Object CheckTableConstraintContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::CheckTableConstraintContext*)orig) -> uid());
  return to_ruby(proxy);
}

Object PrimaryKeyTableConstraintContextProxy::indexColumnNames() {
  IndexColumnNamesContextProxy proxy(((MySqlParser::PrimaryKeyTableConstraintContext*)orig) -> indexColumnNames());
  return to_ruby(proxy);
}

Object PrimaryKeyTableConstraintContextProxy::indexType() {
  IndexTypeContextProxy proxy(((MySqlParser::PrimaryKeyTableConstraintContext*)orig) -> indexType());
  return to_ruby(proxy);
}

Object PrimaryKeyTableConstraintContextProxy::indexOption() {
  std::vector<MySqlParser::IndexOptionContext *> vec = ((MySqlParser::PrimaryKeyTableConstraintContext*)orig) -> indexOption();
  return Array(vec.begin(), vec.end());
}

Object PrimaryKeyTableConstraintContextProxy::indexOptionAt(size_t i) {
  IndexOptionContextProxy proxy(((MySqlParser::PrimaryKeyTableConstraintContext*)orig) -> indexOption(i));
  return to_ruby(proxy);
}

Object PrimaryKeyTableConstraintContextProxy::uid() {
  std::vector<MySqlParser::UidContext *> vec = ((MySqlParser::PrimaryKeyTableConstraintContext*)orig) -> uid();
  return Array(vec.begin(), vec.end());
}

Object PrimaryKeyTableConstraintContextProxy::uidAt(size_t i) {
  UidContextProxy proxy(((MySqlParser::PrimaryKeyTableConstraintContext*)orig) -> uid(i));
  return to_ruby(proxy);
}

Object ForeignKeyTableConstraintContextProxy::indexColumnNames() {
  IndexColumnNamesContextProxy proxy(((MySqlParser::ForeignKeyTableConstraintContext*)orig) -> indexColumnNames());
  return to_ruby(proxy);
}

Object ForeignKeyTableConstraintContextProxy::referenceDefinition() {
  ReferenceDefinitionContextProxy proxy(((MySqlParser::ForeignKeyTableConstraintContext*)orig) -> referenceDefinition());
  return to_ruby(proxy);
}

Object ForeignKeyTableConstraintContextProxy::uid() {
  std::vector<MySqlParser::UidContext *> vec = ((MySqlParser::ForeignKeyTableConstraintContext*)orig) -> uid();
  return Array(vec.begin(), vec.end());
}

Object ForeignKeyTableConstraintContextProxy::uidAt(size_t i) {
  UidContextProxy proxy(((MySqlParser::ForeignKeyTableConstraintContext*)orig) -> uid(i));
  return to_ruby(proxy);
}

Object ReferenceActionContextProxy::referenceControlType() {
  std::vector<MySqlParser::ReferenceControlTypeContext *> vec = ((MySqlParser::ReferenceActionContext*)orig) -> referenceControlType();
  return Array(vec.begin(), vec.end());
}

Object ReferenceActionContextProxy::referenceControlTypeAt(size_t i) {
  ReferenceControlTypeContextProxy proxy(((MySqlParser::ReferenceActionContext*)orig) -> referenceControlType(i));
  return to_ruby(proxy);
}

Object SpecialIndexDeclarationContextProxy::indexColumnNames() {
  IndexColumnNamesContextProxy proxy(((MySqlParser::SpecialIndexDeclarationContext*)orig) -> indexColumnNames());
  return to_ruby(proxy);
}

Object SpecialIndexDeclarationContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::SpecialIndexDeclarationContext*)orig) -> uid());
  return to_ruby(proxy);
}

Object SpecialIndexDeclarationContextProxy::indexOption() {
  std::vector<MySqlParser::IndexOptionContext *> vec = ((MySqlParser::SpecialIndexDeclarationContext*)orig) -> indexOption();
  return Array(vec.begin(), vec.end());
}

Object SpecialIndexDeclarationContextProxy::indexOptionAt(size_t i) {
  IndexOptionContextProxy proxy(((MySqlParser::SpecialIndexDeclarationContext*)orig) -> indexOption(i));
  return to_ruby(proxy);
}

Object SimpleIndexDeclarationContextProxy::indexColumnNames() {
  IndexColumnNamesContextProxy proxy(((MySqlParser::SimpleIndexDeclarationContext*)orig) -> indexColumnNames());
  return to_ruby(proxy);
}

Object SimpleIndexDeclarationContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::SimpleIndexDeclarationContext*)orig) -> uid());
  return to_ruby(proxy);
}

Object SimpleIndexDeclarationContextProxy::indexType() {
  IndexTypeContextProxy proxy(((MySqlParser::SimpleIndexDeclarationContext*)orig) -> indexType());
  return to_ruby(proxy);
}

Object SimpleIndexDeclarationContextProxy::indexOption() {
  std::vector<MySqlParser::IndexOptionContext *> vec = ((MySqlParser::SimpleIndexDeclarationContext*)orig) -> indexOption();
  return Array(vec.begin(), vec.end());
}

Object SimpleIndexDeclarationContextProxy::indexOptionAt(size_t i) {
  IndexOptionContextProxy proxy(((MySqlParser::SimpleIndexDeclarationContext*)orig) -> indexOption(i));
  return to_ruby(proxy);
}

Object TableOptionEngineContextProxy::engineName() {
  EngineNameContextProxy proxy(((MySqlParser::TableOptionEngineContext*)orig) -> engineName());
  return to_ruby(proxy);
}

Object TableOptionMaxRowsContextProxy::decimalLiteral() {
  DecimalLiteralContextProxy proxy(((MySqlParser::TableOptionMaxRowsContext*)orig) -> decimalLiteral());
  return to_ruby(proxy);
}

Object TableOptionCollateContextProxy::collationName() {
  CollationNameContextProxy proxy(((MySqlParser::TableOptionCollateContext*)orig) -> collationName());
  return to_ruby(proxy);
}

Object TableOptionTablespaceContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::TableOptionTablespaceContext*)orig) -> uid());
  return to_ruby(proxy);
}

Object TableOptionTablespaceContextProxy::tablespaceStorage() {
  TablespaceStorageContextProxy proxy(((MySqlParser::TableOptionTablespaceContext*)orig) -> tablespaceStorage());
  return to_ruby(proxy);
}

Object TableOptionUnionContextProxy::tables() {
  TablesContextProxy proxy(((MySqlParser::TableOptionUnionContext*)orig) -> tables());
  return to_ruby(proxy);
}

Object TablesContextProxy::tableName() {
  std::vector<MySqlParser::TableNameContext *> vec = ((MySqlParser::TablesContext*)orig) -> tableName();
  return Array(vec.begin(), vec.end());
}

Object TablesContextProxy::tableNameAt(size_t i) {
  TableNameContextProxy proxy(((MySqlParser::TablesContext*)orig) -> tableName(i));
  return to_ruby(proxy);
}

Object TableOptionSamplePageContextProxy::decimalLiteral() {
  DecimalLiteralContextProxy proxy(((MySqlParser::TableOptionSamplePageContext*)orig) -> decimalLiteral());
  return to_ruby(proxy);
}

Object TableOptionCharsetContextProxy::charsetName() {
  CharsetNameContextProxy proxy(((MySqlParser::TableOptionCharsetContext*)orig) -> charsetName());
  return to_ruby(proxy);
}

Object TableOptionKeyBlockSizeContextProxy::fileSizeLiteral() {
  FileSizeLiteralContextProxy proxy(((MySqlParser::TableOptionKeyBlockSizeContext*)orig) -> fileSizeLiteral());
  return to_ruby(proxy);
}

Object TableOptionAutoIncrementContextProxy::decimalLiteral() {
  DecimalLiteralContextProxy proxy(((MySqlParser::TableOptionAutoIncrementContext*)orig) -> decimalLiteral());
  return to_ruby(proxy);
}

Object TableOptionAverageContextProxy::decimalLiteral() {
  DecimalLiteralContextProxy proxy(((MySqlParser::TableOptionAverageContext*)orig) -> decimalLiteral());
  return to_ruby(proxy);
}

Object TableOptionMinRowsContextProxy::decimalLiteral() {
  DecimalLiteralContextProxy proxy(((MySqlParser::TableOptionMinRowsContext*)orig) -> decimalLiteral());
  return to_ruby(proxy);
}

Object PartitionFunctionKeyContextProxy::uidList() {
  UidListContextProxy proxy(((MySqlParser::PartitionFunctionKeyContext*)orig) -> uidList());
  return to_ruby(proxy);
}

Object PartitionFunctionHashContextProxy::expression() {
  ExpressionContextProxy proxy(((MySqlParser::PartitionFunctionHashContext*)orig) -> expression());
  return to_ruby(proxy);
}

Object PartitionFunctionListContextProxy::expression() {
  ExpressionContextProxy proxy(((MySqlParser::PartitionFunctionListContext*)orig) -> expression());
  return to_ruby(proxy);
}

Object PartitionFunctionListContextProxy::uidList() {
  UidListContextProxy proxy(((MySqlParser::PartitionFunctionListContext*)orig) -> uidList());
  return to_ruby(proxy);
}

Object PartitionFunctionRangeContextProxy::expression() {
  ExpressionContextProxy proxy(((MySqlParser::PartitionFunctionRangeContext*)orig) -> expression());
  return to_ruby(proxy);
}

Object PartitionFunctionRangeContextProxy::uidList() {
  UidListContextProxy proxy(((MySqlParser::PartitionFunctionRangeContext*)orig) -> uidList());
  return to_ruby(proxy);
}

Object SubPartitionFunctionHashContextProxy::expression() {
  ExpressionContextProxy proxy(((MySqlParser::SubPartitionFunctionHashContext*)orig) -> expression());
  return to_ruby(proxy);
}

Object SubPartitionFunctionKeyContextProxy::uidList() {
  UidListContextProxy proxy(((MySqlParser::SubPartitionFunctionKeyContext*)orig) -> uidList());
  return to_ruby(proxy);
}

Object PartitionComparisionContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::PartitionComparisionContext*)orig) -> uid());
  return to_ruby(proxy);
}

Object PartitionComparisionContextProxy::partitionDefinerAtom() {
  std::vector<MySqlParser::PartitionDefinerAtomContext *> vec = ((MySqlParser::PartitionComparisionContext*)orig) -> partitionDefinerAtom();
  return Array(vec.begin(), vec.end());
}

Object PartitionComparisionContextProxy::partitionDefinerAtomAt(size_t i) {
  PartitionDefinerAtomContextProxy proxy(((MySqlParser::PartitionComparisionContext*)orig) -> partitionDefinerAtom(i));
  return to_ruby(proxy);
}

Object PartitionComparisionContextProxy::partitionOption() {
  std::vector<MySqlParser::PartitionOptionContext *> vec = ((MySqlParser::PartitionComparisionContext*)orig) -> partitionOption();
  return Array(vec.begin(), vec.end());
}

Object PartitionComparisionContextProxy::partitionOptionAt(size_t i) {
  PartitionOptionContextProxy proxy(((MySqlParser::PartitionComparisionContext*)orig) -> partitionOption(i));
  return to_ruby(proxy);
}

Object PartitionComparisionContextProxy::subpartitionDefinition() {
  std::vector<MySqlParser::SubpartitionDefinitionContext *> vec = ((MySqlParser::PartitionComparisionContext*)orig) -> subpartitionDefinition();
  return Array(vec.begin(), vec.end());
}

Object PartitionComparisionContextProxy::subpartitionDefinitionAt(size_t i) {
  SubpartitionDefinitionContextProxy proxy(((MySqlParser::PartitionComparisionContext*)orig) -> subpartitionDefinition(i));
  return to_ruby(proxy);
}

Object PartitionDefinerAtomContextProxy::constant() {
  ConstantContextProxy proxy(((MySqlParser::PartitionDefinerAtomContext*)orig) -> constant());
  return to_ruby(proxy);
}

Object PartitionDefinerAtomContextProxy::expression() {
  ExpressionContextProxy proxy(((MySqlParser::PartitionDefinerAtomContext*)orig) -> expression());
  return to_ruby(proxy);
}

Object SubpartitionDefinitionContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::SubpartitionDefinitionContext*)orig) -> uid());
  return to_ruby(proxy);
}

Object SubpartitionDefinitionContextProxy::partitionOption() {
  std::vector<MySqlParser::PartitionOptionContext *> vec = ((MySqlParser::SubpartitionDefinitionContext*)orig) -> partitionOption();
  return Array(vec.begin(), vec.end());
}

Object SubpartitionDefinitionContextProxy::partitionOptionAt(size_t i) {
  PartitionOptionContextProxy proxy(((MySqlParser::SubpartitionDefinitionContext*)orig) -> partitionOption(i));
  return to_ruby(proxy);
}

Object PartitionListAtomContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::PartitionListAtomContext*)orig) -> uid());
  return to_ruby(proxy);
}

Object PartitionListAtomContextProxy::partitionDefinerAtom() {
  std::vector<MySqlParser::PartitionDefinerAtomContext *> vec = ((MySqlParser::PartitionListAtomContext*)orig) -> partitionDefinerAtom();
  return Array(vec.begin(), vec.end());
}

Object PartitionListAtomContextProxy::partitionDefinerAtomAt(size_t i) {
  PartitionDefinerAtomContextProxy proxy(((MySqlParser::PartitionListAtomContext*)orig) -> partitionDefinerAtom(i));
  return to_ruby(proxy);
}

Object PartitionListAtomContextProxy::partitionOption() {
  std::vector<MySqlParser::PartitionOptionContext *> vec = ((MySqlParser::PartitionListAtomContext*)orig) -> partitionOption();
  return Array(vec.begin(), vec.end());
}

Object PartitionListAtomContextProxy::partitionOptionAt(size_t i) {
  PartitionOptionContextProxy proxy(((MySqlParser::PartitionListAtomContext*)orig) -> partitionOption(i));
  return to_ruby(proxy);
}

Object PartitionListAtomContextProxy::subpartitionDefinition() {
  std::vector<MySqlParser::SubpartitionDefinitionContext *> vec = ((MySqlParser::PartitionListAtomContext*)orig) -> subpartitionDefinition();
  return Array(vec.begin(), vec.end());
}

Object PartitionListAtomContextProxy::subpartitionDefinitionAt(size_t i) {
  SubpartitionDefinitionContextProxy proxy(((MySqlParser::PartitionListAtomContext*)orig) -> subpartitionDefinition(i));
  return to_ruby(proxy);
}

Object PartitionListVectorContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::PartitionListVectorContext*)orig) -> uid());
  return to_ruby(proxy);
}

Object PartitionListVectorContextProxy::partitionDefinerVector() {
  std::vector<MySqlParser::PartitionDefinerVectorContext *> vec = ((MySqlParser::PartitionListVectorContext*)orig) -> partitionDefinerVector();
  return Array(vec.begin(), vec.end());
}

Object PartitionListVectorContextProxy::partitionDefinerVectorAt(size_t i) {
  PartitionDefinerVectorContextProxy proxy(((MySqlParser::PartitionListVectorContext*)orig) -> partitionDefinerVector(i));
  return to_ruby(proxy);
}

Object PartitionListVectorContextProxy::partitionOption() {
  std::vector<MySqlParser::PartitionOptionContext *> vec = ((MySqlParser::PartitionListVectorContext*)orig) -> partitionOption();
  return Array(vec.begin(), vec.end());
}

Object PartitionListVectorContextProxy::partitionOptionAt(size_t i) {
  PartitionOptionContextProxy proxy(((MySqlParser::PartitionListVectorContext*)orig) -> partitionOption(i));
  return to_ruby(proxy);
}

Object PartitionListVectorContextProxy::subpartitionDefinition() {
  std::vector<MySqlParser::SubpartitionDefinitionContext *> vec = ((MySqlParser::PartitionListVectorContext*)orig) -> subpartitionDefinition();
  return Array(vec.begin(), vec.end());
}

Object PartitionListVectorContextProxy::subpartitionDefinitionAt(size_t i) {
  SubpartitionDefinitionContextProxy proxy(((MySqlParser::PartitionListVectorContext*)orig) -> subpartitionDefinition(i));
  return to_ruby(proxy);
}

Object PartitionDefinerVectorContextProxy::partitionDefinerAtom() {
  std::vector<MySqlParser::PartitionDefinerAtomContext *> vec = ((MySqlParser::PartitionDefinerVectorContext*)orig) -> partitionDefinerAtom();
  return Array(vec.begin(), vec.end());
}

Object PartitionDefinerVectorContextProxy::partitionDefinerAtomAt(size_t i) {
  PartitionDefinerAtomContextProxy proxy(((MySqlParser::PartitionDefinerVectorContext*)orig) -> partitionDefinerAtom(i));
  return to_ruby(proxy);
}

Object PartitionSimpleContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::PartitionSimpleContext*)orig) -> uid());
  return to_ruby(proxy);
}

Object PartitionSimpleContextProxy::partitionOption() {
  std::vector<MySqlParser::PartitionOptionContext *> vec = ((MySqlParser::PartitionSimpleContext*)orig) -> partitionOption();
  return Array(vec.begin(), vec.end());
}

Object PartitionSimpleContextProxy::partitionOptionAt(size_t i) {
  PartitionOptionContextProxy proxy(((MySqlParser::PartitionSimpleContext*)orig) -> partitionOption(i));
  return to_ruby(proxy);
}

Object PartitionSimpleContextProxy::subpartitionDefinition() {
  std::vector<MySqlParser::SubpartitionDefinitionContext *> vec = ((MySqlParser::PartitionSimpleContext*)orig) -> subpartitionDefinition();
  return Array(vec.begin(), vec.end());
}

Object PartitionSimpleContextProxy::subpartitionDefinitionAt(size_t i) {
  SubpartitionDefinitionContextProxy proxy(((MySqlParser::PartitionSimpleContext*)orig) -> subpartitionDefinition(i));
  return to_ruby(proxy);
}

Object ConstantContextProxy::stringLiteral() {
  StringLiteralContextProxy proxy(((MySqlParser::ConstantContext*)orig) -> stringLiteral());
  return to_ruby(proxy);
}

Object ConstantContextProxy::decimalLiteral() {
  DecimalLiteralContextProxy proxy(((MySqlParser::ConstantContext*)orig) -> decimalLiteral());
  return to_ruby(proxy);
}

Object ConstantContextProxy::hexadecimalLiteral() {
  HexadecimalLiteralContextProxy proxy(((MySqlParser::ConstantContext*)orig) -> hexadecimalLiteral());
  return to_ruby(proxy);
}

Object ConstantContextProxy::booleanLiteral() {
  BooleanLiteralContextProxy proxy(((MySqlParser::ConstantContext*)orig) -> booleanLiteral());
  return to_ruby(proxy);
}

Object PartitionOptionNodeGroupContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::PartitionOptionNodeGroupContext*)orig) -> uid());
  return to_ruby(proxy);
}

Object PartitionOptionMaxRowsContextProxy::decimalLiteral() {
  DecimalLiteralContextProxy proxy(((MySqlParser::PartitionOptionMaxRowsContext*)orig) -> decimalLiteral());
  return to_ruby(proxy);
}

Object PartitionOptionTablespaceContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::PartitionOptionTablespaceContext*)orig) -> uid());
  return to_ruby(proxy);
}

Object PartitionOptionEngineContextProxy::engineName() {
  EngineNameContextProxy proxy(((MySqlParser::PartitionOptionEngineContext*)orig) -> engineName());
  return to_ruby(proxy);
}

Object PartitionOptionMinRowsContextProxy::decimalLiteral() {
  DecimalLiteralContextProxy proxy(((MySqlParser::PartitionOptionMinRowsContext*)orig) -> decimalLiteral());
  return to_ruby(proxy);
}

Object AlterUpgradeNameContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::AlterUpgradeNameContext*)orig) -> uid());
  return to_ruby(proxy);
}

Object AlterSimpleDatabaseContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::AlterSimpleDatabaseContext*)orig) -> uid());
  return to_ruby(proxy);
}

Object AlterSimpleDatabaseContextProxy::createDatabaseOption() {
  std::vector<MySqlParser::CreateDatabaseOptionContext *> vec = ((MySqlParser::AlterSimpleDatabaseContext*)orig) -> createDatabaseOption();
  return Array(vec.begin(), vec.end());
}

Object AlterSimpleDatabaseContextProxy::createDatabaseOptionAt(size_t i) {
  CreateDatabaseOptionContextProxy proxy(((MySqlParser::AlterSimpleDatabaseContext*)orig) -> createDatabaseOption(i));
  return to_ruby(proxy);
}

Object AlterByDefaultCharsetContextProxy::charsetName() {
  CharsetNameContextProxy proxy(((MySqlParser::AlterByDefaultCharsetContext*)orig) -> charsetName());
  return to_ruby(proxy);
}

Object AlterByDefaultCharsetContextProxy::collationName() {
  CollationNameContextProxy proxy(((MySqlParser::AlterByDefaultCharsetContext*)orig) -> collationName());
  return to_ruby(proxy);
}

Object AlterByRenameColumnContextProxy::uid() {
  std::vector<MySqlParser::UidContext *> vec = ((MySqlParser::AlterByRenameColumnContext*)orig) -> uid();
  return Array(vec.begin(), vec.end());
}

Object AlterByRenameColumnContextProxy::uidAt(size_t i) {
  UidContextProxy proxy(((MySqlParser::AlterByRenameColumnContext*)orig) -> uid(i));
  return to_ruby(proxy);
}

Object AlterByConvertCharsetContextProxy::charsetName() {
  CharsetNameContextProxy proxy(((MySqlParser::AlterByConvertCharsetContext*)orig) -> charsetName());
  return to_ruby(proxy);
}

Object AlterByConvertCharsetContextProxy::collationName() {
  CollationNameContextProxy proxy(((MySqlParser::AlterByConvertCharsetContext*)orig) -> collationName());
  return to_ruby(proxy);
}

Object AlterByAddPartitionContextProxy::partitionDefinition() {
  std::vector<MySqlParser::PartitionDefinitionContext *> vec = ((MySqlParser::AlterByAddPartitionContext*)orig) -> partitionDefinition();
  return Array(vec.begin(), vec.end());
}

Object AlterByAddPartitionContextProxy::partitionDefinitionAt(size_t i) {
  PartitionDefinitionContextProxy proxy(((MySqlParser::AlterByAddPartitionContext*)orig) -> partitionDefinition(i));
  return to_ruby(proxy);
}

Object AlterByAddForeignKeyContextProxy::indexColumnNames() {
  IndexColumnNamesContextProxy proxy(((MySqlParser::AlterByAddForeignKeyContext*)orig) -> indexColumnNames());
  return to_ruby(proxy);
}

Object AlterByAddForeignKeyContextProxy::referenceDefinition() {
  ReferenceDefinitionContextProxy proxy(((MySqlParser::AlterByAddForeignKeyContext*)orig) -> referenceDefinition());
  return to_ruby(proxy);
}

Object AlterByAddForeignKeyContextProxy::uid() {
  std::vector<MySqlParser::UidContext *> vec = ((MySqlParser::AlterByAddForeignKeyContext*)orig) -> uid();
  return Array(vec.begin(), vec.end());
}

Object AlterByAddForeignKeyContextProxy::uidAt(size_t i) {
  UidContextProxy proxy(((MySqlParser::AlterByAddForeignKeyContext*)orig) -> uid(i));
  return to_ruby(proxy);
}

Object AlterByRenameIndexContextProxy::uid() {
  std::vector<MySqlParser::UidContext *> vec = ((MySqlParser::AlterByRenameIndexContext*)orig) -> uid();
  return Array(vec.begin(), vec.end());
}

Object AlterByRenameIndexContextProxy::uidAt(size_t i) {
  UidContextProxy proxy(((MySqlParser::AlterByRenameIndexContext*)orig) -> uid(i));
  return to_ruby(proxy);
}

Object AlterByRenameContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::AlterByRenameContext*)orig) -> uid());
  return to_ruby(proxy);
}

Object AlterByRenameContextProxy::fullId() {
  FullIdContextProxy proxy(((MySqlParser::AlterByRenameContext*)orig) -> fullId());
  return to_ruby(proxy);
}

Object AlterByOptimizePartitionContextProxy::uidList() {
  UidListContextProxy proxy(((MySqlParser::AlterByOptimizePartitionContext*)orig) -> uidList());
  return to_ruby(proxy);
}

Object AlterByCoalescePartitionContextProxy::decimalLiteral() {
  DecimalLiteralContextProxy proxy(((MySqlParser::AlterByCoalescePartitionContext*)orig) -> decimalLiteral());
  return to_ruby(proxy);
}

Object AlterByAddColumnsContextProxy::uid() {
  std::vector<MySqlParser::UidContext *> vec = ((MySqlParser::AlterByAddColumnsContext*)orig) -> uid();
  return Array(vec.begin(), vec.end());
}

Object AlterByAddColumnsContextProxy::uidAt(size_t i) {
  UidContextProxy proxy(((MySqlParser::AlterByAddColumnsContext*)orig) -> uid(i));
  return to_ruby(proxy);
}

Object AlterByAddColumnsContextProxy::columnDefinition() {
  std::vector<MySqlParser::ColumnDefinitionContext *> vec = ((MySqlParser::AlterByAddColumnsContext*)orig) -> columnDefinition();
  return Array(vec.begin(), vec.end());
}

Object AlterByAddColumnsContextProxy::columnDefinitionAt(size_t i) {
  ColumnDefinitionContextProxy proxy(((MySqlParser::AlterByAddColumnsContext*)orig) -> columnDefinition(i));
  return to_ruby(proxy);
}

Object AlterByDropForeignKeyContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::AlterByDropForeignKeyContext*)orig) -> uid());
  return to_ruby(proxy);
}

Object AlterByAddCheckTableConstraintContextProxy::expression() {
  ExpressionContextProxy proxy(((MySqlParser::AlterByAddCheckTableConstraintContext*)orig) -> expression());
  return to_ruby(proxy);
}

Object AlterByAddCheckTableConstraintContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::AlterByAddCheckTableConstraintContext*)orig) -> uid());
  return to_ruby(proxy);
}

Object AlterByRebuildPartitionContextProxy::uidList() {
  UidListContextProxy proxy(((MySqlParser::AlterByRebuildPartitionContext*)orig) -> uidList());
  return to_ruby(proxy);
}

Object AlterByRepairPartitionContextProxy::uidList() {
  UidListContextProxy proxy(((MySqlParser::AlterByRepairPartitionContext*)orig) -> uidList());
  return to_ruby(proxy);
}

Object AlterByExchangePartitionContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::AlterByExchangePartitionContext*)orig) -> uid());
  return to_ruby(proxy);
}

Object AlterByExchangePartitionContextProxy::tableName() {
  TableNameContextProxy proxy(((MySqlParser::AlterByExchangePartitionContext*)orig) -> tableName());
  return to_ruby(proxy);
}

Object AlterByAddIndexContextProxy::indexColumnNames() {
  IndexColumnNamesContextProxy proxy(((MySqlParser::AlterByAddIndexContext*)orig) -> indexColumnNames());
  return to_ruby(proxy);
}

Object AlterByAddIndexContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::AlterByAddIndexContext*)orig) -> uid());
  return to_ruby(proxy);
}

Object AlterByAddIndexContextProxy::indexType() {
  IndexTypeContextProxy proxy(((MySqlParser::AlterByAddIndexContext*)orig) -> indexType());
  return to_ruby(proxy);
}

Object AlterByAddIndexContextProxy::indexOption() {
  std::vector<MySqlParser::IndexOptionContext *> vec = ((MySqlParser::AlterByAddIndexContext*)orig) -> indexOption();
  return Array(vec.begin(), vec.end());
}

Object AlterByAddIndexContextProxy::indexOptionAt(size_t i) {
  IndexOptionContextProxy proxy(((MySqlParser::AlterByAddIndexContext*)orig) -> indexOption(i));
  return to_ruby(proxy);
}

Object AlterByDropColumnContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::AlterByDropColumnContext*)orig) -> uid());
  return to_ruby(proxy);
}

Object AlterByImportPartitionContextProxy::uidList() {
  UidListContextProxy proxy(((MySqlParser::AlterByImportPartitionContext*)orig) -> uidList());
  return to_ruby(proxy);
}

Object AlterByChangeDefaultContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::AlterByChangeDefaultContext*)orig) -> uid());
  return to_ruby(proxy);
}

Object AlterByChangeDefaultContextProxy::defaultValue() {
  DefaultValueContextProxy proxy(((MySqlParser::AlterByChangeDefaultContext*)orig) -> defaultValue());
  return to_ruby(proxy);
}

Object AlterByDropPartitionContextProxy::uidList() {
  UidListContextProxy proxy(((MySqlParser::AlterByDropPartitionContext*)orig) -> uidList());
  return to_ruby(proxy);
}

Object AlterByAddSpecialIndexContextProxy::indexColumnNames() {
  IndexColumnNamesContextProxy proxy(((MySqlParser::AlterByAddSpecialIndexContext*)orig) -> indexColumnNames());
  return to_ruby(proxy);
}

Object AlterByAddSpecialIndexContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::AlterByAddSpecialIndexContext*)orig) -> uid());
  return to_ruby(proxy);
}

Object AlterByAddSpecialIndexContextProxy::indexOption() {
  std::vector<MySqlParser::IndexOptionContext *> vec = ((MySqlParser::AlterByAddSpecialIndexContext*)orig) -> indexOption();
  return Array(vec.begin(), vec.end());
}

Object AlterByAddSpecialIndexContextProxy::indexOptionAt(size_t i) {
  IndexOptionContextProxy proxy(((MySqlParser::AlterByAddSpecialIndexContext*)orig) -> indexOption(i));
  return to_ruby(proxy);
}

Object AlterByModifyColumnContextProxy::uid() {
  std::vector<MySqlParser::UidContext *> vec = ((MySqlParser::AlterByModifyColumnContext*)orig) -> uid();
  return Array(vec.begin(), vec.end());
}

Object AlterByModifyColumnContextProxy::uidAt(size_t i) {
  UidContextProxy proxy(((MySqlParser::AlterByModifyColumnContext*)orig) -> uid(i));
  return to_ruby(proxy);
}

Object AlterByModifyColumnContextProxy::columnDefinition() {
  ColumnDefinitionContextProxy proxy(((MySqlParser::AlterByModifyColumnContext*)orig) -> columnDefinition());
  return to_ruby(proxy);
}

Object AlterByTableOptionContextProxy::tableOption() {
  std::vector<MySqlParser::TableOptionContext *> vec = ((MySqlParser::AlterByTableOptionContext*)orig) -> tableOption();
  return Array(vec.begin(), vec.end());
}

Object AlterByTableOptionContextProxy::tableOptionAt(size_t i) {
  TableOptionContextProxy proxy(((MySqlParser::AlterByTableOptionContext*)orig) -> tableOption(i));
  return to_ruby(proxy);
}

Object AlterByDiscardPartitionContextProxy::uidList() {
  UidListContextProxy proxy(((MySqlParser::AlterByDiscardPartitionContext*)orig) -> uidList());
  return to_ruby(proxy);
}

Object AlterByAddPrimaryKeyContextProxy::indexColumnNames() {
  IndexColumnNamesContextProxy proxy(((MySqlParser::AlterByAddPrimaryKeyContext*)orig) -> indexColumnNames());
  return to_ruby(proxy);
}

Object AlterByAddPrimaryKeyContextProxy::indexType() {
  IndexTypeContextProxy proxy(((MySqlParser::AlterByAddPrimaryKeyContext*)orig) -> indexType());
  return to_ruby(proxy);
}

Object AlterByAddPrimaryKeyContextProxy::indexOption() {
  std::vector<MySqlParser::IndexOptionContext *> vec = ((MySqlParser::AlterByAddPrimaryKeyContext*)orig) -> indexOption();
  return Array(vec.begin(), vec.end());
}

Object AlterByAddPrimaryKeyContextProxy::indexOptionAt(size_t i) {
  IndexOptionContextProxy proxy(((MySqlParser::AlterByAddPrimaryKeyContext*)orig) -> indexOption(i));
  return to_ruby(proxy);
}

Object AlterByAddPrimaryKeyContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::AlterByAddPrimaryKeyContext*)orig) -> uid());
  return to_ruby(proxy);
}

Object AlterByCheckPartitionContextProxy::uidList() {
  UidListContextProxy proxy(((MySqlParser::AlterByCheckPartitionContext*)orig) -> uidList());
  return to_ruby(proxy);
}

Object AlterByReorganizePartitionContextProxy::uidList() {
  UidListContextProxy proxy(((MySqlParser::AlterByReorganizePartitionContext*)orig) -> uidList());
  return to_ruby(proxy);
}

Object AlterByReorganizePartitionContextProxy::partitionDefinition() {
  std::vector<MySqlParser::PartitionDefinitionContext *> vec = ((MySqlParser::AlterByReorganizePartitionContext*)orig) -> partitionDefinition();
  return Array(vec.begin(), vec.end());
}

Object AlterByReorganizePartitionContextProxy::partitionDefinitionAt(size_t i) {
  PartitionDefinitionContextProxy proxy(((MySqlParser::AlterByReorganizePartitionContext*)orig) -> partitionDefinition(i));
  return to_ruby(proxy);
}

Object AlterByAnalyzePartitionContextProxy::uidList() {
  UidListContextProxy proxy(((MySqlParser::AlterByAnalyzePartitionContext*)orig) -> uidList());
  return to_ruby(proxy);
}

Object AlterByChangeColumnContextProxy::columnDefinition() {
  ColumnDefinitionContextProxy proxy(((MySqlParser::AlterByChangeColumnContext*)orig) -> columnDefinition());
  return to_ruby(proxy);
}

Object AlterByChangeColumnContextProxy::uid() {
  std::vector<MySqlParser::UidContext *> vec = ((MySqlParser::AlterByChangeColumnContext*)orig) -> uid();
  return Array(vec.begin(), vec.end());
}

Object AlterByChangeColumnContextProxy::uidAt(size_t i) {
  UidContextProxy proxy(((MySqlParser::AlterByChangeColumnContext*)orig) -> uid(i));
  return to_ruby(proxy);
}

Object AlterByAddUniqueKeyContextProxy::indexColumnNames() {
  IndexColumnNamesContextProxy proxy(((MySqlParser::AlterByAddUniqueKeyContext*)orig) -> indexColumnNames());
  return to_ruby(proxy);
}

Object AlterByAddUniqueKeyContextProxy::indexType() {
  IndexTypeContextProxy proxy(((MySqlParser::AlterByAddUniqueKeyContext*)orig) -> indexType());
  return to_ruby(proxy);
}

Object AlterByAddUniqueKeyContextProxy::indexOption() {
  std::vector<MySqlParser::IndexOptionContext *> vec = ((MySqlParser::AlterByAddUniqueKeyContext*)orig) -> indexOption();
  return Array(vec.begin(), vec.end());
}

Object AlterByAddUniqueKeyContextProxy::indexOptionAt(size_t i) {
  IndexOptionContextProxy proxy(((MySqlParser::AlterByAddUniqueKeyContext*)orig) -> indexOption(i));
  return to_ruby(proxy);
}

Object AlterByAddUniqueKeyContextProxy::uid() {
  std::vector<MySqlParser::UidContext *> vec = ((MySqlParser::AlterByAddUniqueKeyContext*)orig) -> uid();
  return Array(vec.begin(), vec.end());
}

Object AlterByAddUniqueKeyContextProxy::uidAt(size_t i) {
  UidContextProxy proxy(((MySqlParser::AlterByAddUniqueKeyContext*)orig) -> uid(i));
  return to_ruby(proxy);
}

Object AlterByTruncatePartitionContextProxy::uidList() {
  UidListContextProxy proxy(((MySqlParser::AlterByTruncatePartitionContext*)orig) -> uidList());
  return to_ruby(proxy);
}

Object AlterByDropIndexContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::AlterByDropIndexContext*)orig) -> uid());
  return to_ruby(proxy);
}

Object AlterByAddColumnContextProxy::uid() {
  std::vector<MySqlParser::UidContext *> vec = ((MySqlParser::AlterByAddColumnContext*)orig) -> uid();
  return Array(vec.begin(), vec.end());
}

Object AlterByAddColumnContextProxy::uidAt(size_t i) {
  UidContextProxy proxy(((MySqlParser::AlterByAddColumnContext*)orig) -> uid(i));
  return to_ruby(proxy);
}

Object AlterByAddColumnContextProxy::columnDefinition() {
  ColumnDefinitionContextProxy proxy(((MySqlParser::AlterByAddColumnContext*)orig) -> columnDefinition());
  return to_ruby(proxy);
}

Object AlterByOrderContextProxy::uidList() {
  UidListContextProxy proxy(((MySqlParser::AlterByOrderContext*)orig) -> uidList());
  return to_ruby(proxy);
}

Object RenameTableClauseContextProxy::tableName() {
  std::vector<MySqlParser::TableNameContext *> vec = ((MySqlParser::RenameTableClauseContext*)orig) -> tableName();
  return Array(vec.begin(), vec.end());
}

Object RenameTableClauseContextProxy::tableNameAt(size_t i) {
  TableNameContextProxy proxy(((MySqlParser::RenameTableClauseContext*)orig) -> tableName(i));
  return to_ruby(proxy);
}

Object ConstantsContextProxy::constant() {
  std::vector<MySqlParser::ConstantContext *> vec = ((MySqlParser::ConstantsContext*)orig) -> constant();
  return Array(vec.begin(), vec.end());
}

Object ConstantsContextProxy::constantAt(size_t i) {
  ConstantContextProxy proxy(((MySqlParser::ConstantsContext*)orig) -> constant(i));
  return to_ruby(proxy);
}

Object ExpressionsContextProxy::expression() {
  std::vector<MySqlParser::ExpressionContext *> vec = ((MySqlParser::ExpressionsContext*)orig) -> expression();
  return Array(vec.begin(), vec.end());
}

Object ExpressionsContextProxy::expressionAt(size_t i) {
  ExpressionContextProxy proxy(((MySqlParser::ExpressionsContext*)orig) -> expression(i));
  return to_ruby(proxy);
}

Object SingleDeleteStatementContextProxy::tableName() {
  TableNameContextProxy proxy(((MySqlParser::SingleDeleteStatementContext*)orig) -> tableName());
  return to_ruby(proxy);
}

Object SingleDeleteStatementContextProxy::uidList() {
  UidListContextProxy proxy(((MySqlParser::SingleDeleteStatementContext*)orig) -> uidList());
  return to_ruby(proxy);
}

Object SingleDeleteStatementContextProxy::expression() {
  ExpressionContextProxy proxy(((MySqlParser::SingleDeleteStatementContext*)orig) -> expression());
  return to_ruby(proxy);
}

Object SingleDeleteStatementContextProxy::orderByClause() {
  OrderByClauseContextProxy proxy(((MySqlParser::SingleDeleteStatementContext*)orig) -> orderByClause());
  return to_ruby(proxy);
}

Object SingleDeleteStatementContextProxy::decimalLiteral() {
  DecimalLiteralContextProxy proxy(((MySqlParser::SingleDeleteStatementContext*)orig) -> decimalLiteral());
  return to_ruby(proxy);
}

Object MultipleDeleteStatementContextProxy::tableName() {
  std::vector<MySqlParser::TableNameContext *> vec = ((MySqlParser::MultipleDeleteStatementContext*)orig) -> tableName();
  return Array(vec.begin(), vec.end());
}

Object MultipleDeleteStatementContextProxy::tableNameAt(size_t i) {
  TableNameContextProxy proxy(((MySqlParser::MultipleDeleteStatementContext*)orig) -> tableName(i));
  return to_ruby(proxy);
}

Object MultipleDeleteStatementContextProxy::tableSources() {
  TableSourcesContextProxy proxy(((MySqlParser::MultipleDeleteStatementContext*)orig) -> tableSources());
  return to_ruby(proxy);
}

Object MultipleDeleteStatementContextProxy::expression() {
  ExpressionContextProxy proxy(((MySqlParser::MultipleDeleteStatementContext*)orig) -> expression());
  return to_ruby(proxy);
}

Object HandlerOpenStatementContextProxy::tableName() {
  TableNameContextProxy proxy(((MySqlParser::HandlerOpenStatementContext*)orig) -> tableName());
  return to_ruby(proxy);
}

Object HandlerOpenStatementContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::HandlerOpenStatementContext*)orig) -> uid());
  return to_ruby(proxy);
}

Object HandlerReadIndexStatementContextProxy::tableName() {
  TableNameContextProxy proxy(((MySqlParser::HandlerReadIndexStatementContext*)orig) -> tableName());
  return to_ruby(proxy);
}

Object HandlerReadIndexStatementContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::HandlerReadIndexStatementContext*)orig) -> uid());
  return to_ruby(proxy);
}

Object HandlerReadIndexStatementContextProxy::comparisonOperator() {
  ComparisonOperatorContextProxy proxy(((MySqlParser::HandlerReadIndexStatementContext*)orig) -> comparisonOperator());
  return to_ruby(proxy);
}

Object HandlerReadIndexStatementContextProxy::constants() {
  ConstantsContextProxy proxy(((MySqlParser::HandlerReadIndexStatementContext*)orig) -> constants());
  return to_ruby(proxy);
}

Object HandlerReadIndexStatementContextProxy::expression() {
  ExpressionContextProxy proxy(((MySqlParser::HandlerReadIndexStatementContext*)orig) -> expression());
  return to_ruby(proxy);
}

Object HandlerReadIndexStatementContextProxy::decimalLiteral() {
  DecimalLiteralContextProxy proxy(((MySqlParser::HandlerReadIndexStatementContext*)orig) -> decimalLiteral());
  return to_ruby(proxy);
}

Object HandlerReadStatementContextProxy::tableName() {
  TableNameContextProxy proxy(((MySqlParser::HandlerReadStatementContext*)orig) -> tableName());
  return to_ruby(proxy);
}

Object HandlerReadStatementContextProxy::expression() {
  ExpressionContextProxy proxy(((MySqlParser::HandlerReadStatementContext*)orig) -> expression());
  return to_ruby(proxy);
}

Object HandlerReadStatementContextProxy::decimalLiteral() {
  DecimalLiteralContextProxy proxy(((MySqlParser::HandlerReadStatementContext*)orig) -> decimalLiteral());
  return to_ruby(proxy);
}

Object HandlerCloseStatementContextProxy::tableName() {
  TableNameContextProxy proxy(((MySqlParser::HandlerCloseStatementContext*)orig) -> tableName());
  return to_ruby(proxy);
}

Object InsertStatementValueContextProxy::selectStatement() {
  SelectStatementContextProxy proxy(((MySqlParser::InsertStatementValueContext*)orig) -> selectStatement());
  return to_ruby(proxy);
}

Object InsertStatementValueContextProxy::expressionsWithDefaults() {
  std::vector<MySqlParser::ExpressionsWithDefaultsContext *> vec = ((MySqlParser::InsertStatementValueContext*)orig) -> expressionsWithDefaults();
  return Array(vec.begin(), vec.end());
}

Object InsertStatementValueContextProxy::expressionsWithDefaultsAt(size_t i) {
  ExpressionsWithDefaultsContextProxy proxy(((MySqlParser::InsertStatementValueContext*)orig) -> expressionsWithDefaults(i));
  return to_ruby(proxy);
}

Object UpdatedElementContextProxy::fullColumnName() {
  FullColumnNameContextProxy proxy(((MySqlParser::UpdatedElementContext*)orig) -> fullColumnName());
  return to_ruby(proxy);
}

Object UpdatedElementContextProxy::expression() {
  ExpressionContextProxy proxy(((MySqlParser::UpdatedElementContext*)orig) -> expression());
  return to_ruby(proxy);
}

Object AssignmentFieldContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::AssignmentFieldContext*)orig) -> uid());
  return to_ruby(proxy);
}

Object QuerySpecificationNointoContextProxy::selectElements() {
  SelectElementsContextProxy proxy(((MySqlParser::QuerySpecificationNointoContext*)orig) -> selectElements());
  return to_ruby(proxy);
}

Object QuerySpecificationNointoContextProxy::selectSpec() {
  std::vector<MySqlParser::SelectSpecContext *> vec = ((MySqlParser::QuerySpecificationNointoContext*)orig) -> selectSpec();
  return Array(vec.begin(), vec.end());
}

Object QuerySpecificationNointoContextProxy::selectSpecAt(size_t i) {
  SelectSpecContextProxy proxy(((MySqlParser::QuerySpecificationNointoContext*)orig) -> selectSpec(i));
  return to_ruby(proxy);
}

Object QuerySpecificationNointoContextProxy::fromClause() {
  FromClauseContextProxy proxy(((MySqlParser::QuerySpecificationNointoContext*)orig) -> fromClause());
  return to_ruby(proxy);
}

Object QuerySpecificationNointoContextProxy::orderByClause() {
  OrderByClauseContextProxy proxy(((MySqlParser::QuerySpecificationNointoContext*)orig) -> orderByClause());
  return to_ruby(proxy);
}

Object QuerySpecificationNointoContextProxy::limitClause() {
  LimitClauseContextProxy proxy(((MySqlParser::QuerySpecificationNointoContext*)orig) -> limitClause());
  return to_ruby(proxy);
}

Object UnionSelectContextProxy::querySpecificationNointo() {
  QuerySpecificationNointoContextProxy proxy(((MySqlParser::UnionSelectContext*)orig) -> querySpecificationNointo());
  return to_ruby(proxy);
}

Object UnionSelectContextProxy::unionStatement() {
  std::vector<MySqlParser::UnionStatementContext *> vec = ((MySqlParser::UnionSelectContext*)orig) -> unionStatement();
  return Array(vec.begin(), vec.end());
}

Object UnionSelectContextProxy::unionStatementAt(size_t i) {
  UnionStatementContextProxy proxy(((MySqlParser::UnionSelectContext*)orig) -> unionStatement(i));
  return to_ruby(proxy);
}

Object UnionSelectContextProxy::orderByClause() {
  OrderByClauseContextProxy proxy(((MySqlParser::UnionSelectContext*)orig) -> orderByClause());
  return to_ruby(proxy);
}

Object UnionSelectContextProxy::limitClause() {
  LimitClauseContextProxy proxy(((MySqlParser::UnionSelectContext*)orig) -> limitClause());
  return to_ruby(proxy);
}

Object UnionSelectContextProxy::lockClause() {
  LockClauseContextProxy proxy(((MySqlParser::UnionSelectContext*)orig) -> lockClause());
  return to_ruby(proxy);
}

Object UnionSelectContextProxy::querySpecification() {
  QuerySpecificationContextProxy proxy(((MySqlParser::UnionSelectContext*)orig) -> querySpecification());
  return to_ruby(proxy);
}

Object UnionSelectContextProxy::queryExpression() {
  QueryExpressionContextProxy proxy(((MySqlParser::UnionSelectContext*)orig) -> queryExpression());
  return to_ruby(proxy);
}

Object UnionStatementContextProxy::querySpecificationNointo() {
  QuerySpecificationNointoContextProxy proxy(((MySqlParser::UnionStatementContext*)orig) -> querySpecificationNointo());
  return to_ruby(proxy);
}

Object UnionStatementContextProxy::queryExpressionNointo() {
  QueryExpressionNointoContextProxy proxy(((MySqlParser::UnionStatementContext*)orig) -> queryExpressionNointo());
  return to_ruby(proxy);
}

Object OrderByClauseContextProxy::orderByExpression() {
  std::vector<MySqlParser::OrderByExpressionContext *> vec = ((MySqlParser::OrderByClauseContext*)orig) -> orderByExpression();
  return Array(vec.begin(), vec.end());
}

Object OrderByClauseContextProxy::orderByExpressionAt(size_t i) {
  OrderByExpressionContextProxy proxy(((MySqlParser::OrderByClauseContext*)orig) -> orderByExpression(i));
  return to_ruby(proxy);
}

Object LimitClauseContextProxy::limitClauseAtom() {
  std::vector<MySqlParser::LimitClauseAtomContext *> vec = ((MySqlParser::LimitClauseContext*)orig) -> limitClauseAtom();
  return Array(vec.begin(), vec.end());
}

Object LimitClauseContextProxy::limitClauseAtomAt(size_t i) {
  LimitClauseAtomContextProxy proxy(((MySqlParser::LimitClauseContext*)orig) -> limitClauseAtom(i));
  return to_ruby(proxy);
}

Object QuerySpecificationContextProxy::selectElements() {
  SelectElementsContextProxy proxy(((MySqlParser::QuerySpecificationContext*)orig) -> selectElements());
  return to_ruby(proxy);
}

Object QuerySpecificationContextProxy::selectSpec() {
  std::vector<MySqlParser::SelectSpecContext *> vec = ((MySqlParser::QuerySpecificationContext*)orig) -> selectSpec();
  return Array(vec.begin(), vec.end());
}

Object QuerySpecificationContextProxy::selectSpecAt(size_t i) {
  SelectSpecContextProxy proxy(((MySqlParser::QuerySpecificationContext*)orig) -> selectSpec(i));
  return to_ruby(proxy);
}

Object QuerySpecificationContextProxy::selectIntoExpression() {
  SelectIntoExpressionContextProxy proxy(((MySqlParser::QuerySpecificationContext*)orig) -> selectIntoExpression());
  return to_ruby(proxy);
}

Object QuerySpecificationContextProxy::fromClause() {
  FromClauseContextProxy proxy(((MySqlParser::QuerySpecificationContext*)orig) -> fromClause());
  return to_ruby(proxy);
}

Object QuerySpecificationContextProxy::orderByClause() {
  OrderByClauseContextProxy proxy(((MySqlParser::QuerySpecificationContext*)orig) -> orderByClause());
  return to_ruby(proxy);
}

Object QuerySpecificationContextProxy::limitClause() {
  LimitClauseContextProxy proxy(((MySqlParser::QuerySpecificationContext*)orig) -> limitClause());
  return to_ruby(proxy);
}

Object QueryExpressionContextProxy::querySpecification() {
  QuerySpecificationContextProxy proxy(((MySqlParser::QueryExpressionContext*)orig) -> querySpecification());
  return to_ruby(proxy);
}

Object QueryExpressionContextProxy::queryExpression() {
  QueryExpressionContextProxy proxy(((MySqlParser::QueryExpressionContext*)orig) -> queryExpression());
  return to_ruby(proxy);
}

Object QueryExpressionNointoContextProxy::querySpecificationNointo() {
  QuerySpecificationNointoContextProxy proxy(((MySqlParser::QueryExpressionNointoContext*)orig) -> querySpecificationNointo());
  return to_ruby(proxy);
}

Object QueryExpressionNointoContextProxy::queryExpressionNointo() {
  QueryExpressionNointoContextProxy proxy(((MySqlParser::QueryExpressionNointoContext*)orig) -> queryExpressionNointo());
  return to_ruby(proxy);
}

Object UnionParenthesisSelectContextProxy::queryExpressionNointo() {
  QueryExpressionNointoContextProxy proxy(((MySqlParser::UnionParenthesisSelectContext*)orig) -> queryExpressionNointo());
  return to_ruby(proxy);
}

Object UnionParenthesisSelectContextProxy::unionParenthesis() {
  std::vector<MySqlParser::UnionParenthesisContext *> vec = ((MySqlParser::UnionParenthesisSelectContext*)orig) -> unionParenthesis();
  return Array(vec.begin(), vec.end());
}

Object UnionParenthesisSelectContextProxy::unionParenthesisAt(size_t i) {
  UnionParenthesisContextProxy proxy(((MySqlParser::UnionParenthesisSelectContext*)orig) -> unionParenthesis(i));
  return to_ruby(proxy);
}

Object UnionParenthesisSelectContextProxy::queryExpression() {
  QueryExpressionContextProxy proxy(((MySqlParser::UnionParenthesisSelectContext*)orig) -> queryExpression());
  return to_ruby(proxy);
}

Object UnionParenthesisSelectContextProxy::orderByClause() {
  OrderByClauseContextProxy proxy(((MySqlParser::UnionParenthesisSelectContext*)orig) -> orderByClause());
  return to_ruby(proxy);
}

Object UnionParenthesisSelectContextProxy::limitClause() {
  LimitClauseContextProxy proxy(((MySqlParser::UnionParenthesisSelectContext*)orig) -> limitClause());
  return to_ruby(proxy);
}

Object UnionParenthesisSelectContextProxy::lockClause() {
  LockClauseContextProxy proxy(((MySqlParser::UnionParenthesisSelectContext*)orig) -> lockClause());
  return to_ruby(proxy);
}

Object UnionParenthesisContextProxy::queryExpressionNointo() {
  QueryExpressionNointoContextProxy proxy(((MySqlParser::UnionParenthesisContext*)orig) -> queryExpressionNointo());
  return to_ruby(proxy);
}

Object SimpleSelectContextProxy::querySpecification() {
  QuerySpecificationContextProxy proxy(((MySqlParser::SimpleSelectContext*)orig) -> querySpecification());
  return to_ruby(proxy);
}

Object SimpleSelectContextProxy::lockClause() {
  LockClauseContextProxy proxy(((MySqlParser::SimpleSelectContext*)orig) -> lockClause());
  return to_ruby(proxy);
}

Object ParenthesisSelectContextProxy::queryExpression() {
  QueryExpressionContextProxy proxy(((MySqlParser::ParenthesisSelectContext*)orig) -> queryExpression());
  return to_ruby(proxy);
}

Object ParenthesisSelectContextProxy::lockClause() {
  LockClauseContextProxy proxy(((MySqlParser::ParenthesisSelectContext*)orig) -> lockClause());
  return to_ruby(proxy);
}

Object SingleUpdateStatementContextProxy::tableName() {
  TableNameContextProxy proxy(((MySqlParser::SingleUpdateStatementContext*)orig) -> tableName());
  return to_ruby(proxy);
}

Object SingleUpdateStatementContextProxy::updatedElement() {
  std::vector<MySqlParser::UpdatedElementContext *> vec = ((MySqlParser::SingleUpdateStatementContext*)orig) -> updatedElement();
  return Array(vec.begin(), vec.end());
}

Object SingleUpdateStatementContextProxy::updatedElementAt(size_t i) {
  UpdatedElementContextProxy proxy(((MySqlParser::SingleUpdateStatementContext*)orig) -> updatedElement(i));
  return to_ruby(proxy);
}

Object SingleUpdateStatementContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::SingleUpdateStatementContext*)orig) -> uid());
  return to_ruby(proxy);
}

Object SingleUpdateStatementContextProxy::expression() {
  ExpressionContextProxy proxy(((MySqlParser::SingleUpdateStatementContext*)orig) -> expression());
  return to_ruby(proxy);
}

Object SingleUpdateStatementContextProxy::orderByClause() {
  OrderByClauseContextProxy proxy(((MySqlParser::SingleUpdateStatementContext*)orig) -> orderByClause());
  return to_ruby(proxy);
}

Object SingleUpdateStatementContextProxy::limitClause() {
  LimitClauseContextProxy proxy(((MySqlParser::SingleUpdateStatementContext*)orig) -> limitClause());
  return to_ruby(proxy);
}

Object MultipleUpdateStatementContextProxy::tableSources() {
  TableSourcesContextProxy proxy(((MySqlParser::MultipleUpdateStatementContext*)orig) -> tableSources());
  return to_ruby(proxy);
}

Object MultipleUpdateStatementContextProxy::updatedElement() {
  std::vector<MySqlParser::UpdatedElementContext *> vec = ((MySqlParser::MultipleUpdateStatementContext*)orig) -> updatedElement();
  return Array(vec.begin(), vec.end());
}

Object MultipleUpdateStatementContextProxy::updatedElementAt(size_t i) {
  UpdatedElementContextProxy proxy(((MySqlParser::MultipleUpdateStatementContext*)orig) -> updatedElement(i));
  return to_ruby(proxy);
}

Object MultipleUpdateStatementContextProxy::expression() {
  ExpressionContextProxy proxy(((MySqlParser::MultipleUpdateStatementContext*)orig) -> expression());
  return to_ruby(proxy);
}

Object ExpressionsWithDefaultsContextProxy::expressionOrDefault() {
  std::vector<MySqlParser::ExpressionOrDefaultContext *> vec = ((MySqlParser::ExpressionsWithDefaultsContext*)orig) -> expressionOrDefault();
  return Array(vec.begin(), vec.end());
}

Object ExpressionsWithDefaultsContextProxy::expressionOrDefaultAt(size_t i) {
  ExpressionOrDefaultContextProxy proxy(((MySqlParser::ExpressionsWithDefaultsContext*)orig) -> expressionOrDefault(i));
  return to_ruby(proxy);
}

Object FullColumnNameContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::FullColumnNameContext*)orig) -> uid());
  return to_ruby(proxy);
}

Object FullColumnNameContextProxy::dottedId() {
  std::vector<MySqlParser::DottedIdContext *> vec = ((MySqlParser::FullColumnNameContext*)orig) -> dottedId();
  return Array(vec.begin(), vec.end());
}

Object FullColumnNameContextProxy::dottedIdAt(size_t i) {
  DottedIdContextProxy proxy(((MySqlParser::FullColumnNameContext*)orig) -> dottedId(i));
  return to_ruby(proxy);
}

Object TableSourcesContextProxy::tableSource() {
  std::vector<MySqlParser::TableSourceContext *> vec = ((MySqlParser::TableSourcesContext*)orig) -> tableSource();
  return Array(vec.begin(), vec.end());
}

Object TableSourcesContextProxy::tableSourceAt(size_t i) {
  TableSourceContextProxy proxy(((MySqlParser::TableSourcesContext*)orig) -> tableSource(i));
  return to_ruby(proxy);
}

Object OrderByExpressionContextProxy::expression() {
  ExpressionContextProxy proxy(((MySqlParser::OrderByExpressionContext*)orig) -> expression());
  return to_ruby(proxy);
}

Object TableSourceNestedContextProxy::tableSourceItem() {
  TableSourceItemContextProxy proxy(((MySqlParser::TableSourceNestedContext*)orig) -> tableSourceItem());
  return to_ruby(proxy);
}

Object TableSourceNestedContextProxy::joinPart() {
  std::vector<MySqlParser::JoinPartContext *> vec = ((MySqlParser::TableSourceNestedContext*)orig) -> joinPart();
  return Array(vec.begin(), vec.end());
}

Object TableSourceNestedContextProxy::joinPartAt(size_t i) {
  JoinPartContextProxy proxy(((MySqlParser::TableSourceNestedContext*)orig) -> joinPart(i));
  return to_ruby(proxy);
}

Object TableSourceBaseContextProxy::tableSourceItem() {
  TableSourceItemContextProxy proxy(((MySqlParser::TableSourceBaseContext*)orig) -> tableSourceItem());
  return to_ruby(proxy);
}

Object TableSourceBaseContextProxy::joinPart() {
  std::vector<MySqlParser::JoinPartContext *> vec = ((MySqlParser::TableSourceBaseContext*)orig) -> joinPart();
  return Array(vec.begin(), vec.end());
}

Object TableSourceBaseContextProxy::joinPartAt(size_t i) {
  JoinPartContextProxy proxy(((MySqlParser::TableSourceBaseContext*)orig) -> joinPart(i));
  return to_ruby(proxy);
}

Object SubqueryTableItemContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::SubqueryTableItemContext*)orig) -> uid());
  return to_ruby(proxy);
}

Object SubqueryTableItemContextProxy::selectStatement() {
  SelectStatementContextProxy proxy(((MySqlParser::SubqueryTableItemContext*)orig) -> selectStatement());
  return to_ruby(proxy);
}

Object AtomTableItemContextProxy::tableName() {
  TableNameContextProxy proxy(((MySqlParser::AtomTableItemContext*)orig) -> tableName());
  return to_ruby(proxy);
}

Object AtomTableItemContextProxy::uidList() {
  UidListContextProxy proxy(((MySqlParser::AtomTableItemContext*)orig) -> uidList());
  return to_ruby(proxy);
}

Object AtomTableItemContextProxy::indexHint() {
  std::vector<MySqlParser::IndexHintContext *> vec = ((MySqlParser::AtomTableItemContext*)orig) -> indexHint();
  return Array(vec.begin(), vec.end());
}

Object AtomTableItemContextProxy::indexHintAt(size_t i) {
  IndexHintContextProxy proxy(((MySqlParser::AtomTableItemContext*)orig) -> indexHint(i));
  return to_ruby(proxy);
}

Object AtomTableItemContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::AtomTableItemContext*)orig) -> uid());
  return to_ruby(proxy);
}

Object IndexHintContextProxy::uidList() {
  UidListContextProxy proxy(((MySqlParser::IndexHintContext*)orig) -> uidList());
  return to_ruby(proxy);
}

Object IndexHintContextProxy::indexHintType() {
  IndexHintTypeContextProxy proxy(((MySqlParser::IndexHintContext*)orig) -> indexHintType());
  return to_ruby(proxy);
}

Object TableSourcesItemContextProxy::tableSources() {
  TableSourcesContextProxy proxy(((MySqlParser::TableSourcesItemContext*)orig) -> tableSources());
  return to_ruby(proxy);
}

Object InnerJoinContextProxy::tableSourceItem() {
  TableSourceItemContextProxy proxy(((MySqlParser::InnerJoinContext*)orig) -> tableSourceItem());
  return to_ruby(proxy);
}

Object InnerJoinContextProxy::expression() {
  ExpressionContextProxy proxy(((MySqlParser::InnerJoinContext*)orig) -> expression());
  return to_ruby(proxy);
}

Object InnerJoinContextProxy::uidList() {
  UidListContextProxy proxy(((MySqlParser::InnerJoinContext*)orig) -> uidList());
  return to_ruby(proxy);
}

Object NaturalJoinContextProxy::tableSourceItem() {
  TableSourceItemContextProxy proxy(((MySqlParser::NaturalJoinContext*)orig) -> tableSourceItem());
  return to_ruby(proxy);
}

Object OuterJoinContextProxy::tableSourceItem() {
  TableSourceItemContextProxy proxy(((MySqlParser::OuterJoinContext*)orig) -> tableSourceItem());
  return to_ruby(proxy);
}

Object OuterJoinContextProxy::expression() {
  ExpressionContextProxy proxy(((MySqlParser::OuterJoinContext*)orig) -> expression());
  return to_ruby(proxy);
}

Object OuterJoinContextProxy::uidList() {
  UidListContextProxy proxy(((MySqlParser::OuterJoinContext*)orig) -> uidList());
  return to_ruby(proxy);
}

Object StraightJoinContextProxy::tableSourceItem() {
  TableSourceItemContextProxy proxy(((MySqlParser::StraightJoinContext*)orig) -> tableSourceItem());
  return to_ruby(proxy);
}

Object StraightJoinContextProxy::expression() {
  ExpressionContextProxy proxy(((MySqlParser::StraightJoinContext*)orig) -> expression());
  return to_ruby(proxy);
}

Object SelectElementsContextProxy::selectElement() {
  std::vector<MySqlParser::SelectElementContext *> vec = ((MySqlParser::SelectElementsContext*)orig) -> selectElement();
  return Array(vec.begin(), vec.end());
}

Object SelectElementsContextProxy::selectElementAt(size_t i) {
  SelectElementContextProxy proxy(((MySqlParser::SelectElementsContext*)orig) -> selectElement(i));
  return to_ruby(proxy);
}

Object FromClauseContextProxy::tableSources() {
  TableSourcesContextProxy proxy(((MySqlParser::FromClauseContext*)orig) -> tableSources());
  return to_ruby(proxy);
}

Object FromClauseContextProxy::groupByItem() {
  std::vector<MySqlParser::GroupByItemContext *> vec = ((MySqlParser::FromClauseContext*)orig) -> groupByItem();
  return Array(vec.begin(), vec.end());
}

Object FromClauseContextProxy::groupByItemAt(size_t i) {
  GroupByItemContextProxy proxy(((MySqlParser::FromClauseContext*)orig) -> groupByItem(i));
  return to_ruby(proxy);
}

Object FromClauseContextProxy::expression() {
  std::vector<MySqlParser::ExpressionContext *> vec = ((MySqlParser::FromClauseContext*)orig) -> expression();
  return Array(vec.begin(), vec.end());
}

Object FromClauseContextProxy::expressionAt(size_t i) {
  ExpressionContextProxy proxy(((MySqlParser::FromClauseContext*)orig) -> expression(i));
  return to_ruby(proxy);
}

Object SelectExpressionElementContextProxy::expression() {
  ExpressionContextProxy proxy(((MySqlParser::SelectExpressionElementContext*)orig) -> expression());
  return to_ruby(proxy);
}

Object SelectExpressionElementContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::SelectExpressionElementContext*)orig) -> uid());
  return to_ruby(proxy);
}

Object SelectFunctionElementContextProxy::functionCall() {
  FunctionCallContextProxy proxy(((MySqlParser::SelectFunctionElementContext*)orig) -> functionCall());
  return to_ruby(proxy);
}

Object SelectFunctionElementContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::SelectFunctionElementContext*)orig) -> uid());
  return to_ruby(proxy);
}

Object SelectStarElementContextProxy::fullId() {
  FullIdContextProxy proxy(((MySqlParser::SelectStarElementContext*)orig) -> fullId());
  return to_ruby(proxy);
}

Object SelectColumnElementContextProxy::fullColumnName() {
  FullColumnNameContextProxy proxy(((MySqlParser::SelectColumnElementContext*)orig) -> fullColumnName());
  return to_ruby(proxy);
}

Object SelectColumnElementContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::SelectColumnElementContext*)orig) -> uid());
  return to_ruby(proxy);
}

Object SelectIntoVariablesContextProxy::assignmentField() {
  std::vector<MySqlParser::AssignmentFieldContext *> vec = ((MySqlParser::SelectIntoVariablesContext*)orig) -> assignmentField();
  return Array(vec.begin(), vec.end());
}

Object SelectIntoVariablesContextProxy::assignmentFieldAt(size_t i) {
  AssignmentFieldContextProxy proxy(((MySqlParser::SelectIntoVariablesContext*)orig) -> assignmentField(i));
  return to_ruby(proxy);
}

Object SelectIntoTextFileContextProxy::charsetName() {
  CharsetNameContextProxy proxy(((MySqlParser::SelectIntoTextFileContext*)orig) -> charsetName());
  return to_ruby(proxy);
}

Object SelectIntoTextFileContextProxy::selectFieldsInto() {
  std::vector<MySqlParser::SelectFieldsIntoContext *> vec = ((MySqlParser::SelectIntoTextFileContext*)orig) -> selectFieldsInto();
  return Array(vec.begin(), vec.end());
}

Object SelectIntoTextFileContextProxy::selectFieldsIntoAt(size_t i) {
  SelectFieldsIntoContextProxy proxy(((MySqlParser::SelectIntoTextFileContext*)orig) -> selectFieldsInto(i));
  return to_ruby(proxy);
}

Object SelectIntoTextFileContextProxy::selectLinesInto() {
  std::vector<MySqlParser::SelectLinesIntoContext *> vec = ((MySqlParser::SelectIntoTextFileContext*)orig) -> selectLinesInto();
  return Array(vec.begin(), vec.end());
}

Object SelectIntoTextFileContextProxy::selectLinesIntoAt(size_t i) {
  SelectLinesIntoContextProxy proxy(((MySqlParser::SelectIntoTextFileContext*)orig) -> selectLinesInto(i));
  return to_ruby(proxy);
}

Object GroupByItemContextProxy::expression() {
  ExpressionContextProxy proxy(((MySqlParser::GroupByItemContext*)orig) -> expression());
  return to_ruby(proxy);
}

Object LimitClauseAtomContextProxy::decimalLiteral() {
  DecimalLiteralContextProxy proxy(((MySqlParser::LimitClauseAtomContext*)orig) -> decimalLiteral());
  return to_ruby(proxy);
}

Object LimitClauseAtomContextProxy::mysqlVariable() {
  MysqlVariableContextProxy proxy(((MySqlParser::LimitClauseAtomContext*)orig) -> mysqlVariable());
  return to_ruby(proxy);
}

Object LockTableElementContextProxy::tableName() {
  TableNameContextProxy proxy(((MySqlParser::LockTableElementContext*)orig) -> tableName());
  return to_ruby(proxy);
}

Object LockTableElementContextProxy::lockAction() {
  LockActionContextProxy proxy(((MySqlParser::LockTableElementContext*)orig) -> lockAction());
  return to_ruby(proxy);
}

Object LockTableElementContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::LockTableElementContext*)orig) -> uid());
  return to_ruby(proxy);
}

Object SetTransactionStatementContextProxy::transactionOption() {
  std::vector<MySqlParser::TransactionOptionContext *> vec = ((MySqlParser::SetTransactionStatementContext*)orig) -> transactionOption();
  return Array(vec.begin(), vec.end());
}

Object SetTransactionStatementContextProxy::transactionOptionAt(size_t i) {
  TransactionOptionContextProxy proxy(((MySqlParser::SetTransactionStatementContext*)orig) -> transactionOption(i));
  return to_ruby(proxy);
}

Object TransactionOptionContextProxy::transactionLevel() {
  TransactionLevelContextProxy proxy(((MySqlParser::TransactionOptionContext*)orig) -> transactionLevel());
  return to_ruby(proxy);
}

Object MasterStringOptionContextProxy::stringMasterOption() {
  StringMasterOptionContextProxy proxy(((MySqlParser::MasterStringOptionContext*)orig) -> stringMasterOption());
  return to_ruby(proxy);
}

Object MasterBoolOptionContextProxy::boolMasterOption() {
  BoolMasterOptionContextProxy proxy(((MySqlParser::MasterBoolOptionContext*)orig) -> boolMasterOption());
  return to_ruby(proxy);
}

Object MasterUidListOptionContextProxy::uid() {
  std::vector<MySqlParser::UidContext *> vec = ((MySqlParser::MasterUidListOptionContext*)orig) -> uid();
  return Array(vec.begin(), vec.end());
}

Object MasterUidListOptionContextProxy::uidAt(size_t i) {
  UidContextProxy proxy(((MySqlParser::MasterUidListOptionContext*)orig) -> uid(i));
  return to_ruby(proxy);
}

Object MasterDecimalOptionContextProxy::decimalMasterOption() {
  DecimalMasterOptionContextProxy proxy(((MySqlParser::MasterDecimalOptionContext*)orig) -> decimalMasterOption());
  return to_ruby(proxy);
}

Object MasterDecimalOptionContextProxy::decimalLiteral() {
  DecimalLiteralContextProxy proxy(((MySqlParser::MasterDecimalOptionContext*)orig) -> decimalLiteral());
  return to_ruby(proxy);
}

Object WildIgnoreTableReplicationContextProxy::simpleStrings() {
  SimpleStringsContextProxy proxy(((MySqlParser::WildIgnoreTableReplicationContext*)orig) -> simpleStrings());
  return to_ruby(proxy);
}

Object DoTableReplicationContextProxy::tables() {
  TablesContextProxy proxy(((MySqlParser::DoTableReplicationContext*)orig) -> tables());
  return to_ruby(proxy);
}

Object IgnoreTableReplicationContextProxy::tables() {
  TablesContextProxy proxy(((MySqlParser::IgnoreTableReplicationContext*)orig) -> tables());
  return to_ruby(proxy);
}

Object RewriteDbReplicationContextProxy::tablePair() {
  std::vector<MySqlParser::TablePairContext *> vec = ((MySqlParser::RewriteDbReplicationContext*)orig) -> tablePair();
  return Array(vec.begin(), vec.end());
}

Object RewriteDbReplicationContextProxy::tablePairAt(size_t i) {
  TablePairContextProxy proxy(((MySqlParser::RewriteDbReplicationContext*)orig) -> tablePair(i));
  return to_ruby(proxy);
}

Object TablePairContextProxy::tableName() {
  std::vector<MySqlParser::TableNameContext *> vec = ((MySqlParser::TablePairContext*)orig) -> tableName();
  return Array(vec.begin(), vec.end());
}

Object TablePairContextProxy::tableNameAt(size_t i) {
  TableNameContextProxy proxy(((MySqlParser::TablePairContext*)orig) -> tableName(i));
  return to_ruby(proxy);
}

Object DoDbReplicationContextProxy::uidList() {
  UidListContextProxy proxy(((MySqlParser::DoDbReplicationContext*)orig) -> uidList());
  return to_ruby(proxy);
}

Object IgnoreDbReplicationContextProxy::uidList() {
  UidListContextProxy proxy(((MySqlParser::IgnoreDbReplicationContext*)orig) -> uidList());
  return to_ruby(proxy);
}

Object WildDoTableReplicationContextProxy::simpleStrings() {
  SimpleStringsContextProxy proxy(((MySqlParser::WildDoTableReplicationContext*)orig) -> simpleStrings());
  return to_ruby(proxy);
}

Object GtidsUntilOptionContextProxy::gtuidSet() {
  GtuidSetContextProxy proxy(((MySqlParser::GtidsUntilOptionContext*)orig) -> gtuidSet());
  return to_ruby(proxy);
}

Object GtuidSetContextProxy::uuidSet() {
  std::vector<MySqlParser::UuidSetContext *> vec = ((MySqlParser::GtuidSetContext*)orig) -> uuidSet();
  return Array(vec.begin(), vec.end());
}

Object GtuidSetContextProxy::uuidSetAt(size_t i) {
  UuidSetContextProxy proxy(((MySqlParser::GtuidSetContext*)orig) -> uuidSet(i));
  return to_ruby(proxy);
}

Object MasterLogUntilOptionContextProxy::decimalLiteral() {
  DecimalLiteralContextProxy proxy(((MySqlParser::MasterLogUntilOptionContext*)orig) -> decimalLiteral());
  return to_ruby(proxy);
}

Object RelayLogUntilOptionContextProxy::decimalLiteral() {
  DecimalLiteralContextProxy proxy(((MySqlParser::RelayLogUntilOptionContext*)orig) -> decimalLiteral());
  return to_ruby(proxy);
}

Object UuidSetContextProxy::decimalLiteral() {
  std::vector<MySqlParser::DecimalLiteralContext *> vec = ((MySqlParser::UuidSetContext*)orig) -> decimalLiteral();
  return Array(vec.begin(), vec.end());
}

Object UuidSetContextProxy::decimalLiteralAt(size_t i) {
  DecimalLiteralContextProxy proxy(((MySqlParser::UuidSetContext*)orig) -> decimalLiteral(i));
  return to_ruby(proxy);
}

Object XidContextProxy::xuidStringId() {
  std::vector<MySqlParser::XuidStringIdContext *> vec = ((MySqlParser::XidContext*)orig) -> xuidStringId();
  return Array(vec.begin(), vec.end());
}

Object XidContextProxy::xuidStringIdAt(size_t i) {
  XuidStringIdContextProxy proxy(((MySqlParser::XidContext*)orig) -> xuidStringId(i));
  return to_ruby(proxy);
}

Object XidContextProxy::decimalLiteral() {
  DecimalLiteralContextProxy proxy(((MySqlParser::XidContext*)orig) -> decimalLiteral());
  return to_ruby(proxy);
}

Object DeclareVariableContextProxy::uidList() {
  UidListContextProxy proxy(((MySqlParser::DeclareVariableContext*)orig) -> uidList());
  return to_ruby(proxy);
}

Object DeclareVariableContextProxy::dataType() {
  DataTypeContextProxy proxy(((MySqlParser::DeclareVariableContext*)orig) -> dataType());
  return to_ruby(proxy);
}

Object DeclareVariableContextProxy::defaultValue() {
  DefaultValueContextProxy proxy(((MySqlParser::DeclareVariableContext*)orig) -> defaultValue());
  return to_ruby(proxy);
}

Object DeclareConditionContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::DeclareConditionContext*)orig) -> uid());
  return to_ruby(proxy);
}

Object DeclareConditionContextProxy::decimalLiteral() {
  DecimalLiteralContextProxy proxy(((MySqlParser::DeclareConditionContext*)orig) -> decimalLiteral());
  return to_ruby(proxy);
}

Object DeclareCursorContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::DeclareCursorContext*)orig) -> uid());
  return to_ruby(proxy);
}

Object DeclareCursorContextProxy::selectStatement() {
  SelectStatementContextProxy proxy(((MySqlParser::DeclareCursorContext*)orig) -> selectStatement());
  return to_ruby(proxy);
}

Object DeclareHandlerContextProxy::handlerConditionValue() {
  std::vector<MySqlParser::HandlerConditionValueContext *> vec = ((MySqlParser::DeclareHandlerContext*)orig) -> handlerConditionValue();
  return Array(vec.begin(), vec.end());
}

Object DeclareHandlerContextProxy::handlerConditionValueAt(size_t i) {
  HandlerConditionValueContextProxy proxy(((MySqlParser::DeclareHandlerContext*)orig) -> handlerConditionValue(i));
  return to_ruby(proxy);
}

Object DeclareHandlerContextProxy::routineBody() {
  RoutineBodyContextProxy proxy(((MySqlParser::DeclareHandlerContext*)orig) -> routineBody());
  return to_ruby(proxy);
}

Object ProcedureSqlStatementContextProxy::compoundStatement() {
  CompoundStatementContextProxy proxy(((MySqlParser::ProcedureSqlStatementContext*)orig) -> compoundStatement());
  return to_ruby(proxy);
}

Object ProcedureSqlStatementContextProxy::sqlStatement() {
  SqlStatementContextProxy proxy(((MySqlParser::ProcedureSqlStatementContext*)orig) -> sqlStatement());
  return to_ruby(proxy);
}

Object CaseAlternativeContextProxy::constant() {
  ConstantContextProxy proxy(((MySqlParser::CaseAlternativeContext*)orig) -> constant());
  return to_ruby(proxy);
}

Object CaseAlternativeContextProxy::expression() {
  ExpressionContextProxy proxy(((MySqlParser::CaseAlternativeContext*)orig) -> expression());
  return to_ruby(proxy);
}

Object CaseAlternativeContextProxy::procedureSqlStatement() {
  std::vector<MySqlParser::ProcedureSqlStatementContext *> vec = ((MySqlParser::CaseAlternativeContext*)orig) -> procedureSqlStatement();
  return Array(vec.begin(), vec.end());
}

Object CaseAlternativeContextProxy::procedureSqlStatementAt(size_t i) {
  ProcedureSqlStatementContextProxy proxy(((MySqlParser::CaseAlternativeContext*)orig) -> procedureSqlStatement(i));
  return to_ruby(proxy);
}

Object ElifAlternativeContextProxy::expression() {
  ExpressionContextProxy proxy(((MySqlParser::ElifAlternativeContext*)orig) -> expression());
  return to_ruby(proxy);
}

Object ElifAlternativeContextProxy::procedureSqlStatement() {
  std::vector<MySqlParser::ProcedureSqlStatementContext *> vec = ((MySqlParser::ElifAlternativeContext*)orig) -> procedureSqlStatement();
  return Array(vec.begin(), vec.end());
}

Object ElifAlternativeContextProxy::procedureSqlStatementAt(size_t i) {
  ProcedureSqlStatementContextProxy proxy(((MySqlParser::ElifAlternativeContext*)orig) -> procedureSqlStatement(i));
  return to_ruby(proxy);
}

Object CloseCursorContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::CloseCursorContext*)orig) -> uid());
  return to_ruby(proxy);
}

Object OpenCursorContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::OpenCursorContext*)orig) -> uid());
  return to_ruby(proxy);
}

Object FetchCursorContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::FetchCursorContext*)orig) -> uid());
  return to_ruby(proxy);
}

Object FetchCursorContextProxy::uidList() {
  UidListContextProxy proxy(((MySqlParser::FetchCursorContext*)orig) -> uidList());
  return to_ruby(proxy);
}

Object HandlerConditionCodeContextProxy::decimalLiteral() {
  DecimalLiteralContextProxy proxy(((MySqlParser::HandlerConditionCodeContext*)orig) -> decimalLiteral());
  return to_ruby(proxy);
}

Object HandlerConditionNameContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::HandlerConditionNameContext*)orig) -> uid());
  return to_ruby(proxy);
}

Object AlterUserMysqlV56ContextProxy::userSpecification() {
  std::vector<MySqlParser::UserSpecificationContext *> vec = ((MySqlParser::AlterUserMysqlV56Context*)orig) -> userSpecification();
  return Array(vec.begin(), vec.end());
}

Object AlterUserMysqlV56ContextProxy::userSpecificationAt(size_t i) {
  UserSpecificationContextProxy proxy(((MySqlParser::AlterUserMysqlV56Context*)orig) -> userSpecification(i));
  return to_ruby(proxy);
}

Object UserSpecificationContextProxy::userName() {
  UserNameContextProxy proxy(((MySqlParser::UserSpecificationContext*)orig) -> userName());
  return to_ruby(proxy);
}

Object UserSpecificationContextProxy::userPasswordOption() {
  UserPasswordOptionContextProxy proxy(((MySqlParser::UserSpecificationContext*)orig) -> userPasswordOption());
  return to_ruby(proxy);
}

Object AlterUserMysqlV57ContextProxy::userAuthOption() {
  std::vector<MySqlParser::UserAuthOptionContext *> vec = ((MySqlParser::AlterUserMysqlV57Context*)orig) -> userAuthOption();
  return Array(vec.begin(), vec.end());
}

Object AlterUserMysqlV57ContextProxy::userAuthOptionAt(size_t i) {
  UserAuthOptionContextProxy proxy(((MySqlParser::AlterUserMysqlV57Context*)orig) -> userAuthOption(i));
  return to_ruby(proxy);
}

Object AlterUserMysqlV57ContextProxy::ifExists() {
  IfExistsContextProxy proxy(((MySqlParser::AlterUserMysqlV57Context*)orig) -> ifExists());
  return to_ruby(proxy);
}

Object AlterUserMysqlV57ContextProxy::userPasswordOption() {
  std::vector<MySqlParser::UserPasswordOptionContext *> vec = ((MySqlParser::AlterUserMysqlV57Context*)orig) -> userPasswordOption();
  return Array(vec.begin(), vec.end());
}

Object AlterUserMysqlV57ContextProxy::userPasswordOptionAt(size_t i) {
  UserPasswordOptionContextProxy proxy(((MySqlParser::AlterUserMysqlV57Context*)orig) -> userPasswordOption(i));
  return to_ruby(proxy);
}

Object AlterUserMysqlV57ContextProxy::userLockOption() {
  std::vector<MySqlParser::UserLockOptionContext *> vec = ((MySqlParser::AlterUserMysqlV57Context*)orig) -> userLockOption();
  return Array(vec.begin(), vec.end());
}

Object AlterUserMysqlV57ContextProxy::userLockOptionAt(size_t i) {
  UserLockOptionContextProxy proxy(((MySqlParser::AlterUserMysqlV57Context*)orig) -> userLockOption(i));
  return to_ruby(proxy);
}

Object AlterUserMysqlV57ContextProxy::tlsOption() {
  std::vector<MySqlParser::TlsOptionContext *> vec = ((MySqlParser::AlterUserMysqlV57Context*)orig) -> tlsOption();
  return Array(vec.begin(), vec.end());
}

Object AlterUserMysqlV57ContextProxy::tlsOptionAt(size_t i) {
  TlsOptionContextProxy proxy(((MySqlParser::AlterUserMysqlV57Context*)orig) -> tlsOption(i));
  return to_ruby(proxy);
}

Object AlterUserMysqlV57ContextProxy::userResourceOption() {
  std::vector<MySqlParser::UserResourceOptionContext *> vec = ((MySqlParser::AlterUserMysqlV57Context*)orig) -> userResourceOption();
  return Array(vec.begin(), vec.end());
}

Object AlterUserMysqlV57ContextProxy::userResourceOptionAt(size_t i) {
  UserResourceOptionContextProxy proxy(((MySqlParser::AlterUserMysqlV57Context*)orig) -> userResourceOption(i));
  return to_ruby(proxy);
}

Object UserPasswordOptionContextProxy::decimalLiteral() {
  DecimalLiteralContextProxy proxy(((MySqlParser::UserPasswordOptionContext*)orig) -> decimalLiteral());
  return to_ruby(proxy);
}

Object UserResourceOptionContextProxy::decimalLiteral() {
  DecimalLiteralContextProxy proxy(((MySqlParser::UserResourceOptionContext*)orig) -> decimalLiteral());
  return to_ruby(proxy);
}

Object CreateUserMysqlV57ContextProxy::userAuthOption() {
  std::vector<MySqlParser::UserAuthOptionContext *> vec = ((MySqlParser::CreateUserMysqlV57Context*)orig) -> userAuthOption();
  return Array(vec.begin(), vec.end());
}

Object CreateUserMysqlV57ContextProxy::userAuthOptionAt(size_t i) {
  UserAuthOptionContextProxy proxy(((MySqlParser::CreateUserMysqlV57Context*)orig) -> userAuthOption(i));
  return to_ruby(proxy);
}

Object CreateUserMysqlV57ContextProxy::ifNotExists() {
  IfNotExistsContextProxy proxy(((MySqlParser::CreateUserMysqlV57Context*)orig) -> ifNotExists());
  return to_ruby(proxy);
}

Object CreateUserMysqlV57ContextProxy::userPasswordOption() {
  std::vector<MySqlParser::UserPasswordOptionContext *> vec = ((MySqlParser::CreateUserMysqlV57Context*)orig) -> userPasswordOption();
  return Array(vec.begin(), vec.end());
}

Object CreateUserMysqlV57ContextProxy::userPasswordOptionAt(size_t i) {
  UserPasswordOptionContextProxy proxy(((MySqlParser::CreateUserMysqlV57Context*)orig) -> userPasswordOption(i));
  return to_ruby(proxy);
}

Object CreateUserMysqlV57ContextProxy::userLockOption() {
  std::vector<MySqlParser::UserLockOptionContext *> vec = ((MySqlParser::CreateUserMysqlV57Context*)orig) -> userLockOption();
  return Array(vec.begin(), vec.end());
}

Object CreateUserMysqlV57ContextProxy::userLockOptionAt(size_t i) {
  UserLockOptionContextProxy proxy(((MySqlParser::CreateUserMysqlV57Context*)orig) -> userLockOption(i));
  return to_ruby(proxy);
}

Object CreateUserMysqlV57ContextProxy::tlsOption() {
  std::vector<MySqlParser::TlsOptionContext *> vec = ((MySqlParser::CreateUserMysqlV57Context*)orig) -> tlsOption();
  return Array(vec.begin(), vec.end());
}

Object CreateUserMysqlV57ContextProxy::tlsOptionAt(size_t i) {
  TlsOptionContextProxy proxy(((MySqlParser::CreateUserMysqlV57Context*)orig) -> tlsOption(i));
  return to_ruby(proxy);
}

Object CreateUserMysqlV57ContextProxy::userResourceOption() {
  std::vector<MySqlParser::UserResourceOptionContext *> vec = ((MySqlParser::CreateUserMysqlV57Context*)orig) -> userResourceOption();
  return Array(vec.begin(), vec.end());
}

Object CreateUserMysqlV57ContextProxy::userResourceOptionAt(size_t i) {
  UserResourceOptionContextProxy proxy(((MySqlParser::CreateUserMysqlV57Context*)orig) -> userResourceOption(i));
  return to_ruby(proxy);
}

Object CreateUserMysqlV56ContextProxy::userAuthOption() {
  std::vector<MySqlParser::UserAuthOptionContext *> vec = ((MySqlParser::CreateUserMysqlV56Context*)orig) -> userAuthOption();
  return Array(vec.begin(), vec.end());
}

Object CreateUserMysqlV56ContextProxy::userAuthOptionAt(size_t i) {
  UserAuthOptionContextProxy proxy(((MySqlParser::CreateUserMysqlV56Context*)orig) -> userAuthOption(i));
  return to_ruby(proxy);
}

Object PrivelegeClauseContextProxy::privilege() {
  PrivilegeContextProxy proxy(((MySqlParser::PrivelegeClauseContext*)orig) -> privilege());
  return to_ruby(proxy);
}

Object PrivelegeClauseContextProxy::uidList() {
  UidListContextProxy proxy(((MySqlParser::PrivelegeClauseContext*)orig) -> uidList());
  return to_ruby(proxy);
}

Object RenameUserClauseContextProxy::userName() {
  std::vector<MySqlParser::UserNameContext *> vec = ((MySqlParser::RenameUserClauseContext*)orig) -> userName();
  return Array(vec.begin(), vec.end());
}

Object RenameUserClauseContextProxy::userNameAt(size_t i) {
  UserNameContextProxy proxy(((MySqlParser::RenameUserClauseContext*)orig) -> userName(i));
  return to_ruby(proxy);
}

Object DetailRevokeContextProxy::privelegeClause() {
  std::vector<MySqlParser::PrivelegeClauseContext *> vec = ((MySqlParser::DetailRevokeContext*)orig) -> privelegeClause();
  return Array(vec.begin(), vec.end());
}

Object DetailRevokeContextProxy::privelegeClauseAt(size_t i) {
  PrivelegeClauseContextProxy proxy(((MySqlParser::DetailRevokeContext*)orig) -> privelegeClause(i));
  return to_ruby(proxy);
}

Object DetailRevokeContextProxy::privilegeLevel() {
  PrivilegeLevelContextProxy proxy(((MySqlParser::DetailRevokeContext*)orig) -> privilegeLevel());
  return to_ruby(proxy);
}

Object DetailRevokeContextProxy::userName() {
  std::vector<MySqlParser::UserNameContext *> vec = ((MySqlParser::DetailRevokeContext*)orig) -> userName();
  return Array(vec.begin(), vec.end());
}

Object DetailRevokeContextProxy::userNameAt(size_t i) {
  UserNameContextProxy proxy(((MySqlParser::DetailRevokeContext*)orig) -> userName(i));
  return to_ruby(proxy);
}

Object ShortRevokeContextProxy::userName() {
  std::vector<MySqlParser::UserNameContext *> vec = ((MySqlParser::ShortRevokeContext*)orig) -> userName();
  return Array(vec.begin(), vec.end());
}

Object ShortRevokeContextProxy::userNameAt(size_t i) {
  UserNameContextProxy proxy(((MySqlParser::ShortRevokeContext*)orig) -> userName(i));
  return to_ruby(proxy);
}

Object SetPasswordStatementContextProxy::passwordFunctionClause() {
  PasswordFunctionClauseContextProxy proxy(((MySqlParser::SetPasswordStatementContext*)orig) -> passwordFunctionClause());
  return to_ruby(proxy);
}

Object SetPasswordStatementContextProxy::userName() {
  UserNameContextProxy proxy(((MySqlParser::SetPasswordStatementContext*)orig) -> userName());
  return to_ruby(proxy);
}

Object PasswordFunctionClauseContextProxy::functionArg() {
  FunctionArgContextProxy proxy(((MySqlParser::PasswordFunctionClauseContext*)orig) -> functionArg());
  return to_ruby(proxy);
}

Object SimpleAuthOptionContextProxy::userName() {
  UserNameContextProxy proxy(((MySqlParser::SimpleAuthOptionContext*)orig) -> userName());
  return to_ruby(proxy);
}

Object PasswordAuthOptionContextProxy::userName() {
  UserNameContextProxy proxy(((MySqlParser::PasswordAuthOptionContext*)orig) -> userName());
  return to_ruby(proxy);
}

Object StringAuthOptionContextProxy::userName() {
  UserNameContextProxy proxy(((MySqlParser::StringAuthOptionContext*)orig) -> userName());
  return to_ruby(proxy);
}

Object StringAuthOptionContextProxy::authPlugin() {
  AuthPluginContextProxy proxy(((MySqlParser::StringAuthOptionContext*)orig) -> authPlugin());
  return to_ruby(proxy);
}

Object AuthPluginContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::AuthPluginContext*)orig) -> uid());
  return to_ruby(proxy);
}

Object HashAuthOptionContextProxy::userName() {
  UserNameContextProxy proxy(((MySqlParser::HashAuthOptionContext*)orig) -> userName());
  return to_ruby(proxy);
}

Object HashAuthOptionContextProxy::authPlugin() {
  AuthPluginContextProxy proxy(((MySqlParser::HashAuthOptionContext*)orig) -> authPlugin());
  return to_ruby(proxy);
}

Object DefiniteSchemaPrivLevelContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::DefiniteSchemaPrivLevelContext*)orig) -> uid());
  return to_ruby(proxy);
}

Object DefiniteFullTablePrivLevel2ContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::DefiniteFullTablePrivLevel2Context*)orig) -> uid());
  return to_ruby(proxy);
}

Object DefiniteFullTablePrivLevel2ContextProxy::dottedId() {
  DottedIdContextProxy proxy(((MySqlParser::DefiniteFullTablePrivLevel2Context*)orig) -> dottedId());
  return to_ruby(proxy);
}

Object DottedIdContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::DottedIdContext*)orig) -> uid());
  return to_ruby(proxy);
}

Object DefiniteFullTablePrivLevelContextProxy::uid() {
  std::vector<MySqlParser::UidContext *> vec = ((MySqlParser::DefiniteFullTablePrivLevelContext*)orig) -> uid();
  return Array(vec.begin(), vec.end());
}

Object DefiniteFullTablePrivLevelContextProxy::uidAt(size_t i) {
  UidContextProxy proxy(((MySqlParser::DefiniteFullTablePrivLevelContext*)orig) -> uid(i));
  return to_ruby(proxy);
}

Object DefiniteTablePrivLevelContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::DefiniteTablePrivLevelContext*)orig) -> uid());
  return to_ruby(proxy);
}

Object SetTransactionContextProxy::setTransactionStatement() {
  SetTransactionStatementContextProxy proxy(((MySqlParser::SetTransactionContext*)orig) -> setTransactionStatement());
  return to_ruby(proxy);
}

Object SetCharsetContextProxy::charsetName() {
  CharsetNameContextProxy proxy(((MySqlParser::SetCharsetContext*)orig) -> charsetName());
  return to_ruby(proxy);
}

Object SetNamesContextProxy::charsetName() {
  CharsetNameContextProxy proxy(((MySqlParser::SetNamesContext*)orig) -> charsetName());
  return to_ruby(proxy);
}

Object SetNamesContextProxy::collationName() {
  CollationNameContextProxy proxy(((MySqlParser::SetNamesContext*)orig) -> collationName());
  return to_ruby(proxy);
}

Object SetPasswordContextProxy::setPasswordStatement() {
  SetPasswordStatementContextProxy proxy(((MySqlParser::SetPasswordContext*)orig) -> setPasswordStatement());
  return to_ruby(proxy);
}

Object SetAutocommitContextProxy::setAutocommitStatement() {
  SetAutocommitStatementContextProxy proxy(((MySqlParser::SetAutocommitContext*)orig) -> setAutocommitStatement());
  return to_ruby(proxy);
}

Object SetNewValueInsideTriggerContextProxy::fullId() {
  FullIdContextProxy proxy(((MySqlParser::SetNewValueInsideTriggerContext*)orig) -> fullId());
  return to_ruby(proxy);
}

Object SetNewValueInsideTriggerContextProxy::expression() {
  ExpressionContextProxy proxy(((MySqlParser::SetNewValueInsideTriggerContext*)orig) -> expression());
  return to_ruby(proxy);
}

Object SetVariableContextProxy::variableClause() {
  std::vector<MySqlParser::VariableClauseContext *> vec = ((MySqlParser::SetVariableContext*)orig) -> variableClause();
  return Array(vec.begin(), vec.end());
}

Object SetVariableContextProxy::variableClauseAt(size_t i) {
  VariableClauseContextProxy proxy(((MySqlParser::SetVariableContext*)orig) -> variableClause(i));
  return to_ruby(proxy);
}

Object SetVariableContextProxy::expression() {
  std::vector<MySqlParser::ExpressionContext *> vec = ((MySqlParser::SetVariableContext*)orig) -> expression();
  return Array(vec.begin(), vec.end());
}

Object SetVariableContextProxy::expressionAt(size_t i) {
  ExpressionContextProxy proxy(((MySqlParser::SetVariableContext*)orig) -> expression(i));
  return to_ruby(proxy);
}

Object VariableClauseContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::VariableClauseContext*)orig) -> uid());
  return to_ruby(proxy);
}

Object ShowOpenTablesContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::ShowOpenTablesContext*)orig) -> uid());
  return to_ruby(proxy);
}

Object ShowOpenTablesContextProxy::showFilter() {
  ShowFilterContextProxy proxy(((MySqlParser::ShowOpenTablesContext*)orig) -> showFilter());
  return to_ruby(proxy);
}

Object ShowFilterContextProxy::expression() {
  ExpressionContextProxy proxy(((MySqlParser::ShowFilterContext*)orig) -> expression());
  return to_ruby(proxy);
}

Object ShowGlobalInfoContextProxy::showGlobalInfoClause() {
  ShowGlobalInfoClauseContextProxy proxy(((MySqlParser::ShowGlobalInfoContext*)orig) -> showGlobalInfoClause());
  return to_ruby(proxy);
}

Object ShowCreateFullIdObjectContextProxy::fullId() {
  FullIdContextProxy proxy(((MySqlParser::ShowCreateFullIdObjectContext*)orig) -> fullId());
  return to_ruby(proxy);
}

Object ShowCreateUserContextProxy::userName() {
  UserNameContextProxy proxy(((MySqlParser::ShowCreateUserContext*)orig) -> userName());
  return to_ruby(proxy);
}

Object ShowErrorsContextProxy::decimalLiteral() {
  std::vector<MySqlParser::DecimalLiteralContext *> vec = ((MySqlParser::ShowErrorsContext*)orig) -> decimalLiteral();
  return Array(vec.begin(), vec.end());
}

Object ShowErrorsContextProxy::decimalLiteralAt(size_t i) {
  DecimalLiteralContextProxy proxy(((MySqlParser::ShowErrorsContext*)orig) -> decimalLiteral(i));
  return to_ruby(proxy);
}

Object ShowObjectFilterContextProxy::showCommonEntity() {
  ShowCommonEntityContextProxy proxy(((MySqlParser::ShowObjectFilterContext*)orig) -> showCommonEntity());
  return to_ruby(proxy);
}

Object ShowObjectFilterContextProxy::showFilter() {
  ShowFilterContextProxy proxy(((MySqlParser::ShowObjectFilterContext*)orig) -> showFilter());
  return to_ruby(proxy);
}

Object ShowCreateDbContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::ShowCreateDbContext*)orig) -> uid());
  return to_ruby(proxy);
}

Object ShowCreateDbContextProxy::ifNotExists() {
  IfNotExistsContextProxy proxy(((MySqlParser::ShowCreateDbContext*)orig) -> ifNotExists());
  return to_ruby(proxy);
}

Object ShowEngineContextProxy::engineName() {
  EngineNameContextProxy proxy(((MySqlParser::ShowEngineContext*)orig) -> engineName());
  return to_ruby(proxy);
}

Object ShowSchemaFilterContextProxy::showSchemaEntity() {
  ShowSchemaEntityContextProxy proxy(((MySqlParser::ShowSchemaFilterContext*)orig) -> showSchemaEntity());
  return to_ruby(proxy);
}

Object ShowSchemaFilterContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::ShowSchemaFilterContext*)orig) -> uid());
  return to_ruby(proxy);
}

Object ShowSchemaFilterContextProxy::showFilter() {
  ShowFilterContextProxy proxy(((MySqlParser::ShowSchemaFilterContext*)orig) -> showFilter());
  return to_ruby(proxy);
}

Object ShowIndexesContextProxy::tableName() {
  TableNameContextProxy proxy(((MySqlParser::ShowIndexesContext*)orig) -> tableName());
  return to_ruby(proxy);
}

Object ShowIndexesContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::ShowIndexesContext*)orig) -> uid());
  return to_ruby(proxy);
}

Object ShowIndexesContextProxy::expression() {
  ExpressionContextProxy proxy(((MySqlParser::ShowIndexesContext*)orig) -> expression());
  return to_ruby(proxy);
}

Object ShowLogEventsContextProxy::decimalLiteral() {
  std::vector<MySqlParser::DecimalLiteralContext *> vec = ((MySqlParser::ShowLogEventsContext*)orig) -> decimalLiteral();
  return Array(vec.begin(), vec.end());
}

Object ShowLogEventsContextProxy::decimalLiteralAt(size_t i) {
  DecimalLiteralContextProxy proxy(((MySqlParser::ShowLogEventsContext*)orig) -> decimalLiteral(i));
  return to_ruby(proxy);
}

Object ShowGrantsContextProxy::userName() {
  UserNameContextProxy proxy(((MySqlParser::ShowGrantsContext*)orig) -> userName());
  return to_ruby(proxy);
}

Object ShowRoutineContextProxy::fullId() {
  FullIdContextProxy proxy(((MySqlParser::ShowRoutineContext*)orig) -> fullId());
  return to_ruby(proxy);
}

Object ShowProfileContextProxy::showProfileType() {
  std::vector<MySqlParser::ShowProfileTypeContext *> vec = ((MySqlParser::ShowProfileContext*)orig) -> showProfileType();
  return Array(vec.begin(), vec.end());
}

Object ShowProfileContextProxy::showProfileTypeAt(size_t i) {
  ShowProfileTypeContextProxy proxy(((MySqlParser::ShowProfileContext*)orig) -> showProfileType(i));
  return to_ruby(proxy);
}

Object ShowProfileContextProxy::decimalLiteral() {
  std::vector<MySqlParser::DecimalLiteralContext *> vec = ((MySqlParser::ShowProfileContext*)orig) -> decimalLiteral();
  return Array(vec.begin(), vec.end());
}

Object ShowProfileContextProxy::decimalLiteralAt(size_t i) {
  DecimalLiteralContextProxy proxy(((MySqlParser::ShowProfileContext*)orig) -> decimalLiteral(i));
  return to_ruby(proxy);
}

Object ShowColumnsContextProxy::tableName() {
  TableNameContextProxy proxy(((MySqlParser::ShowColumnsContext*)orig) -> tableName());
  return to_ruby(proxy);
}

Object ShowColumnsContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::ShowColumnsContext*)orig) -> uid());
  return to_ruby(proxy);
}

Object ShowColumnsContextProxy::showFilter() {
  ShowFilterContextProxy proxy(((MySqlParser::ShowColumnsContext*)orig) -> showFilter());
  return to_ruby(proxy);
}

Object TableIndexesContextProxy::tableName() {
  TableNameContextProxy proxy(((MySqlParser::TableIndexesContext*)orig) -> tableName());
  return to_ruby(proxy);
}

Object TableIndexesContextProxy::uidList() {
  UidListContextProxy proxy(((MySqlParser::TableIndexesContext*)orig) -> uidList());
  return to_ruby(proxy);
}

Object LoadedTableIndexesContextProxy::tableName() {
  TableNameContextProxy proxy(((MySqlParser::LoadedTableIndexesContext*)orig) -> tableName());
  return to_ruby(proxy);
}

Object LoadedTableIndexesContextProxy::uidList() {
  std::vector<MySqlParser::UidListContext *> vec = ((MySqlParser::LoadedTableIndexesContext*)orig) -> uidList();
  return Array(vec.begin(), vec.end());
}

Object LoadedTableIndexesContextProxy::uidListAt(size_t i) {
  UidListContextProxy proxy(((MySqlParser::LoadedTableIndexesContext*)orig) -> uidList(i));
  return to_ruby(proxy);
}

Object TableFlushOptionContextProxy::tables() {
  TablesContextProxy proxy(((MySqlParser::TableFlushOptionContext*)orig) -> tables());
  return to_ruby(proxy);
}

Object TableFlushOptionContextProxy::flushTableOption() {
  FlushTableOptionContextProxy proxy(((MySqlParser::TableFlushOptionContext*)orig) -> flushTableOption());
  return to_ruby(proxy);
}

Object ChannelFlushOptionContextProxy::channelOption() {
  ChannelOptionContextProxy proxy(((MySqlParser::ChannelFlushOptionContext*)orig) -> channelOption());
  return to_ruby(proxy);
}

Object SignalConditionInformationContextProxy::stringLiteral() {
  StringLiteralContextProxy proxy(((MySqlParser::SignalConditionInformationContext*)orig) -> stringLiteral());
  return to_ruby(proxy);
}

Object DescribeStatementsContextProxy::selectStatement() {
  SelectStatementContextProxy proxy(((MySqlParser::DescribeStatementsContext*)orig) -> selectStatement());
  return to_ruby(proxy);
}

Object DescribeStatementsContextProxy::deleteStatement() {
  DeleteStatementContextProxy proxy(((MySqlParser::DescribeStatementsContext*)orig) -> deleteStatement());
  return to_ruby(proxy);
}

Object DescribeStatementsContextProxy::insertStatement() {
  InsertStatementContextProxy proxy(((MySqlParser::DescribeStatementsContext*)orig) -> insertStatement());
  return to_ruby(proxy);
}

Object DescribeStatementsContextProxy::replaceStatement() {
  ReplaceStatementContextProxy proxy(((MySqlParser::DescribeStatementsContext*)orig) -> replaceStatement());
  return to_ruby(proxy);
}

Object DescribeStatementsContextProxy::updateStatement() {
  UpdateStatementContextProxy proxy(((MySqlParser::DescribeStatementsContext*)orig) -> updateStatement());
  return to_ruby(proxy);
}

Object DescribeConnectionContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::DescribeConnectionContext*)orig) -> uid());
  return to_ruby(proxy);
}

Object IndexColumnNameContextProxy::uid() {
  UidContextProxy proxy(((MySqlParser::IndexColumnNameContext*)orig) -> uid());
  return to_ruby(proxy);
}

Object IndexColumnNameContextProxy::decimalLiteral() {
  DecimalLiteralContextProxy proxy(((MySqlParser::IndexColumnNameContext*)orig) -> decimalLiteral());
  return to_ruby(proxy);
}

Object SimpleIdContextProxy::charsetNameBase() {
  CharsetNameBaseContextProxy proxy(((MySqlParser::SimpleIdContext*)orig) -> charsetNameBase());
  return to_ruby(proxy);
}

Object SimpleIdContextProxy::transactionLevelBase() {
  TransactionLevelBaseContextProxy proxy(((MySqlParser::SimpleIdContext*)orig) -> transactionLevelBase());
  return to_ruby(proxy);
}

Object SimpleIdContextProxy::engineName() {
  EngineNameContextProxy proxy(((MySqlParser::SimpleIdContext*)orig) -> engineName());
  return to_ruby(proxy);
}

Object SimpleIdContextProxy::privilegesBase() {
  PrivilegesBaseContextProxy proxy(((MySqlParser::SimpleIdContext*)orig) -> privilegesBase());
  return to_ruby(proxy);
}

Object SimpleIdContextProxy::intervalTypeBase() {
  IntervalTypeBaseContextProxy proxy(((MySqlParser::SimpleIdContext*)orig) -> intervalTypeBase());
  return to_ruby(proxy);
}

Object SimpleIdContextProxy::dataTypeBase() {
  DataTypeBaseContextProxy proxy(((MySqlParser::SimpleIdContext*)orig) -> dataTypeBase());
  return to_ruby(proxy);
}

Object SimpleIdContextProxy::keywordsCanBeId() {
  KeywordsCanBeIdContextProxy proxy(((MySqlParser::SimpleIdContext*)orig) -> keywordsCanBeId());
  return to_ruby(proxy);
}

Object SimpleIdContextProxy::functionNameBase() {
  FunctionNameBaseContextProxy proxy(((MySqlParser::SimpleIdContext*)orig) -> functionNameBase());
  return to_ruby(proxy);
}

Object CollectionDataTypeContextProxy::collectionOptions() {
  CollectionOptionsContextProxy proxy(((MySqlParser::CollectionDataTypeContext*)orig) -> collectionOptions());
  return to_ruby(proxy);
}

Object CollectionDataTypeContextProxy::charsetName() {
  CharsetNameContextProxy proxy(((MySqlParser::CollectionDataTypeContext*)orig) -> charsetName());
  return to_ruby(proxy);
}

Object NationalVaryingStringDataTypeContextProxy::lengthOneDimension() {
  LengthOneDimensionContextProxy proxy(((MySqlParser::NationalVaryingStringDataTypeContext*)orig) -> lengthOneDimension());
  return to_ruby(proxy);
}

Object LengthOneDimensionContextProxy::decimalLiteral() {
  DecimalLiteralContextProxy proxy(((MySqlParser::LengthOneDimensionContext*)orig) -> decimalLiteral());
  return to_ruby(proxy);
}

Object DimensionDataTypeContextProxy::lengthOneDimension() {
  LengthOneDimensionContextProxy proxy(((MySqlParser::DimensionDataTypeContext*)orig) -> lengthOneDimension());
  return to_ruby(proxy);
}

Object DimensionDataTypeContextProxy::lengthTwoDimension() {
  LengthTwoDimensionContextProxy proxy(((MySqlParser::DimensionDataTypeContext*)orig) -> lengthTwoDimension());
  return to_ruby(proxy);
}

Object DimensionDataTypeContextProxy::lengthTwoOptionalDimension() {
  LengthTwoOptionalDimensionContextProxy proxy(((MySqlParser::DimensionDataTypeContext*)orig) -> lengthTwoOptionalDimension());
  return to_ruby(proxy);
}

Object LengthTwoDimensionContextProxy::decimalLiteral() {
  std::vector<MySqlParser::DecimalLiteralContext *> vec = ((MySqlParser::LengthTwoDimensionContext*)orig) -> decimalLiteral();
  return Array(vec.begin(), vec.end());
}

Object LengthTwoDimensionContextProxy::decimalLiteralAt(size_t i) {
  DecimalLiteralContextProxy proxy(((MySqlParser::LengthTwoDimensionContext*)orig) -> decimalLiteral(i));
  return to_ruby(proxy);
}

Object LengthTwoOptionalDimensionContextProxy::decimalLiteral() {
  std::vector<MySqlParser::DecimalLiteralContext *> vec = ((MySqlParser::LengthTwoOptionalDimensionContext*)orig) -> decimalLiteral();
  return Array(vec.begin(), vec.end());
}

Object LengthTwoOptionalDimensionContextProxy::decimalLiteralAt(size_t i) {
  DecimalLiteralContextProxy proxy(((MySqlParser::LengthTwoOptionalDimensionContext*)orig) -> decimalLiteral(i));
  return to_ruby(proxy);
}

Object StringDataTypeContextProxy::lengthOneDimension() {
  LengthOneDimensionContextProxy proxy(((MySqlParser::StringDataTypeContext*)orig) -> lengthOneDimension());
  return to_ruby(proxy);
}

Object StringDataTypeContextProxy::charsetName() {
  CharsetNameContextProxy proxy(((MySqlParser::StringDataTypeContext*)orig) -> charsetName());
  return to_ruby(proxy);
}

Object StringDataTypeContextProxy::collationName() {
  CollationNameContextProxy proxy(((MySqlParser::StringDataTypeContext*)orig) -> collationName());
  return to_ruby(proxy);
}

Object NationalStringDataTypeContextProxy::lengthOneDimension() {
  LengthOneDimensionContextProxy proxy(((MySqlParser::NationalStringDataTypeContext*)orig) -> lengthOneDimension());
  return to_ruby(proxy);
}

Object ConvertedDataTypeContextProxy::lengthOneDimension() {
  LengthOneDimensionContextProxy proxy(((MySqlParser::ConvertedDataTypeContext*)orig) -> lengthOneDimension());
  return to_ruby(proxy);
}

Object ConvertedDataTypeContextProxy::charsetName() {
  CharsetNameContextProxy proxy(((MySqlParser::ConvertedDataTypeContext*)orig) -> charsetName());
  return to_ruby(proxy);
}

Object ConvertedDataTypeContextProxy::lengthTwoDimension() {
  LengthTwoDimensionContextProxy proxy(((MySqlParser::ConvertedDataTypeContext*)orig) -> lengthTwoDimension());
  return to_ruby(proxy);
}

Object ExpressionOrDefaultContextProxy::expression() {
  ExpressionContextProxy proxy(((MySqlParser::ExpressionOrDefaultContext*)orig) -> expression());
  return to_ruby(proxy);
}

Object SpecificFunctionCallContextProxy::specificFunction() {
  SpecificFunctionContextProxy proxy(((MySqlParser::SpecificFunctionCallContext*)orig) -> specificFunction());
  return to_ruby(proxy);
}

Object PasswordFunctionCallContextProxy::passwordFunctionClause() {
  PasswordFunctionClauseContextProxy proxy(((MySqlParser::PasswordFunctionCallContext*)orig) -> passwordFunctionClause());
  return to_ruby(proxy);
}

Object UdfFunctionCallContextProxy::fullId() {
  FullIdContextProxy proxy(((MySqlParser::UdfFunctionCallContext*)orig) -> fullId());
  return to_ruby(proxy);
}

Object UdfFunctionCallContextProxy::functionArgs() {
  FunctionArgsContextProxy proxy(((MySqlParser::UdfFunctionCallContext*)orig) -> functionArgs());
  return to_ruby(proxy);
}

Object FunctionArgsContextProxy::constant() {
  std::vector<MySqlParser::ConstantContext *> vec = ((MySqlParser::FunctionArgsContext*)orig) -> constant();
  return Array(vec.begin(), vec.end());
}

Object FunctionArgsContextProxy::constantAt(size_t i) {
  ConstantContextProxy proxy(((MySqlParser::FunctionArgsContext*)orig) -> constant(i));
  return to_ruby(proxy);
}

Object FunctionArgsContextProxy::fullColumnName() {
  std::vector<MySqlParser::FullColumnNameContext *> vec = ((MySqlParser::FunctionArgsContext*)orig) -> fullColumnName();
  return Array(vec.begin(), vec.end());
}

Object FunctionArgsContextProxy::fullColumnNameAt(size_t i) {
  FullColumnNameContextProxy proxy(((MySqlParser::FunctionArgsContext*)orig) -> fullColumnName(i));
  return to_ruby(proxy);
}

Object FunctionArgsContextProxy::functionCall() {
  std::vector<MySqlParser::FunctionCallContext *> vec = ((MySqlParser::FunctionArgsContext*)orig) -> functionCall();
  return Array(vec.begin(), vec.end());
}

Object FunctionArgsContextProxy::functionCallAt(size_t i) {
  FunctionCallContextProxy proxy(((MySqlParser::FunctionArgsContext*)orig) -> functionCall(i));
  return to_ruby(proxy);
}

Object FunctionArgsContextProxy::expression() {
  std::vector<MySqlParser::ExpressionContext *> vec = ((MySqlParser::FunctionArgsContext*)orig) -> expression();
  return Array(vec.begin(), vec.end());
}

Object FunctionArgsContextProxy::expressionAt(size_t i) {
  ExpressionContextProxy proxy(((MySqlParser::FunctionArgsContext*)orig) -> expression(i));
  return to_ruby(proxy);
}

Object AggregateWindowedFunctionContextProxy::functionArg() {
  FunctionArgContextProxy proxy(((MySqlParser::AggregateWindowedFunctionContext*)orig) -> functionArg());
  return to_ruby(proxy);
}

Object AggregateWindowedFunctionContextProxy::functionArgs() {
  FunctionArgsContextProxy proxy(((MySqlParser::AggregateWindowedFunctionContext*)orig) -> functionArgs());
  return to_ruby(proxy);
}

Object AggregateWindowedFunctionContextProxy::orderByExpression() {
  std::vector<MySqlParser::OrderByExpressionContext *> vec = ((MySqlParser::AggregateWindowedFunctionContext*)orig) -> orderByExpression();
  return Array(vec.begin(), vec.end());
}

Object AggregateWindowedFunctionContextProxy::orderByExpressionAt(size_t i) {
  OrderByExpressionContextProxy proxy(((MySqlParser::AggregateWindowedFunctionContext*)orig) -> orderByExpression(i));
  return to_ruby(proxy);
}

Object AggregateFunctionCallContextProxy::aggregateWindowedFunction() {
  AggregateWindowedFunctionContextProxy proxy(((MySqlParser::AggregateFunctionCallContext*)orig) -> aggregateWindowedFunction());
  return to_ruby(proxy);
}

Object ScalarFunctionNameContextProxy::functionNameBase() {
  FunctionNameBaseContextProxy proxy(((MySqlParser::ScalarFunctionNameContext*)orig) -> functionNameBase());
  return to_ruby(proxy);
}

Object ScalarFunctionCallContextProxy::scalarFunctionName() {
  ScalarFunctionNameContextProxy proxy(((MySqlParser::ScalarFunctionCallContext*)orig) -> scalarFunctionName());
  return to_ruby(proxy);
}

Object ScalarFunctionCallContextProxy::functionArgs() {
  FunctionArgsContextProxy proxy(((MySqlParser::ScalarFunctionCallContext*)orig) -> functionArgs());
  return to_ruby(proxy);
}

Object PositionFunctionCallContextProxy::stringLiteral() {
  std::vector<MySqlParser::StringLiteralContext *> vec = ((MySqlParser::PositionFunctionCallContext*)orig) -> stringLiteral();
  return Array(vec.begin(), vec.end());
}

Object PositionFunctionCallContextProxy::stringLiteralAt(size_t i) {
  StringLiteralContextProxy proxy(((MySqlParser::PositionFunctionCallContext*)orig) -> stringLiteral(i));
  return to_ruby(proxy);
}

Object PositionFunctionCallContextProxy::expression() {
  std::vector<MySqlParser::ExpressionContext *> vec = ((MySqlParser::PositionFunctionCallContext*)orig) -> expression();
  return Array(vec.begin(), vec.end());
}

Object PositionFunctionCallContextProxy::expressionAt(size_t i) {
  ExpressionContextProxy proxy(((MySqlParser::PositionFunctionCallContext*)orig) -> expression(i));
  return to_ruby(proxy);
}

Object TrimFunctionCallContextProxy::stringLiteral() {
  std::vector<MySqlParser::StringLiteralContext *> vec = ((MySqlParser::TrimFunctionCallContext*)orig) -> stringLiteral();
  return Array(vec.begin(), vec.end());
}

Object TrimFunctionCallContextProxy::stringLiteralAt(size_t i) {
  StringLiteralContextProxy proxy(((MySqlParser::TrimFunctionCallContext*)orig) -> stringLiteral(i));
  return to_ruby(proxy);
}

Object TrimFunctionCallContextProxy::expression() {
  std::vector<MySqlParser::ExpressionContext *> vec = ((MySqlParser::TrimFunctionCallContext*)orig) -> expression();
  return Array(vec.begin(), vec.end());
}

Object TrimFunctionCallContextProxy::expressionAt(size_t i) {
  ExpressionContextProxy proxy(((MySqlParser::TrimFunctionCallContext*)orig) -> expression(i));
  return to_ruby(proxy);
}

Object CharFunctionCallContextProxy::functionArgs() {
  FunctionArgsContextProxy proxy(((MySqlParser::CharFunctionCallContext*)orig) -> functionArgs());
  return to_ruby(proxy);
}

Object CharFunctionCallContextProxy::charsetName() {
  CharsetNameContextProxy proxy(((MySqlParser::CharFunctionCallContext*)orig) -> charsetName());
  return to_ruby(proxy);
}

Object WeightFunctionCallContextProxy::stringLiteral() {
  StringLiteralContextProxy proxy(((MySqlParser::WeightFunctionCallContext*)orig) -> stringLiteral());
  return to_ruby(proxy);
}

Object WeightFunctionCallContextProxy::expression() {
  ExpressionContextProxy proxy(((MySqlParser::WeightFunctionCallContext*)orig) -> expression());
  return to_ruby(proxy);
}

Object WeightFunctionCallContextProxy::decimalLiteral() {
  DecimalLiteralContextProxy proxy(((MySqlParser::WeightFunctionCallContext*)orig) -> decimalLiteral());
  return to_ruby(proxy);
}

Object WeightFunctionCallContextProxy::levelsInWeightString() {
  LevelsInWeightStringContextProxy proxy(((MySqlParser::WeightFunctionCallContext*)orig) -> levelsInWeightString());
  return to_ruby(proxy);
}

Object GetFormatFunctionCallContextProxy::stringLiteral() {
  StringLiteralContextProxy proxy(((MySqlParser::GetFormatFunctionCallContext*)orig) -> stringLiteral());
  return to_ruby(proxy);
}

Object CaseFunctionCallContextProxy::expression() {
  ExpressionContextProxy proxy(((MySqlParser::CaseFunctionCallContext*)orig) -> expression());
  return to_ruby(proxy);
}

Object CaseFunctionCallContextProxy::caseFuncAlternative() {
  std::vector<MySqlParser::CaseFuncAlternativeContext *> vec = ((MySqlParser::CaseFunctionCallContext*)orig) -> caseFuncAlternative();
  return Array(vec.begin(), vec.end());
}

Object CaseFunctionCallContextProxy::caseFuncAlternativeAt(size_t i) {
  CaseFuncAlternativeContextProxy proxy(((MySqlParser::CaseFunctionCallContext*)orig) -> caseFuncAlternative(i));
  return to_ruby(proxy);
}

Object CaseFunctionCallContextProxy::functionArg() {
  FunctionArgContextProxy proxy(((MySqlParser::CaseFunctionCallContext*)orig) -> functionArg());
  return to_ruby(proxy);
}

Object CaseFuncAlternativeContextProxy::functionArg() {
  std::vector<MySqlParser::FunctionArgContext *> vec = ((MySqlParser::CaseFuncAlternativeContext*)orig) -> functionArg();
  return Array(vec.begin(), vec.end());
}

Object CaseFuncAlternativeContextProxy::functionArgAt(size_t i) {
  FunctionArgContextProxy proxy(((MySqlParser::CaseFuncAlternativeContext*)orig) -> functionArg(i));
  return to_ruby(proxy);
}

Object FunctionArgContextProxy::constant() {
  ConstantContextProxy proxy(((MySqlParser::FunctionArgContext*)orig) -> constant());
  return to_ruby(proxy);
}

Object FunctionArgContextProxy::fullColumnName() {
  FullColumnNameContextProxy proxy(((MySqlParser::FunctionArgContext*)orig) -> fullColumnName());
  return to_ruby(proxy);
}

Object FunctionArgContextProxy::functionCall() {
  FunctionCallContextProxy proxy(((MySqlParser::FunctionArgContext*)orig) -> functionCall());
  return to_ruby(proxy);
}

Object FunctionArgContextProxy::expression() {
  ExpressionContextProxy proxy(((MySqlParser::FunctionArgContext*)orig) -> expression());
  return to_ruby(proxy);
}

Object ExtractFunctionCallContextProxy::intervalType() {
  IntervalTypeContextProxy proxy(((MySqlParser::ExtractFunctionCallContext*)orig) -> intervalType());
  return to_ruby(proxy);
}

Object ExtractFunctionCallContextProxy::stringLiteral() {
  StringLiteralContextProxy proxy(((MySqlParser::ExtractFunctionCallContext*)orig) -> stringLiteral());
  return to_ruby(proxy);
}

Object ExtractFunctionCallContextProxy::expression() {
  ExpressionContextProxy proxy(((MySqlParser::ExtractFunctionCallContext*)orig) -> expression());
  return to_ruby(proxy);
}

Object DataTypeFunctionCallContextProxy::expression() {
  ExpressionContextProxy proxy(((MySqlParser::DataTypeFunctionCallContext*)orig) -> expression());
  return to_ruby(proxy);
}

Object DataTypeFunctionCallContextProxy::convertedDataType() {
  ConvertedDataTypeContextProxy proxy(((MySqlParser::DataTypeFunctionCallContext*)orig) -> convertedDataType());
  return to_ruby(proxy);
}

Object DataTypeFunctionCallContextProxy::charsetName() {
  CharsetNameContextProxy proxy(((MySqlParser::DataTypeFunctionCallContext*)orig) -> charsetName());
  return to_ruby(proxy);
}

Object ValuesFunctionCallContextProxy::fullColumnName() {
  FullColumnNameContextProxy proxy(((MySqlParser::ValuesFunctionCallContext*)orig) -> fullColumnName());
  return to_ruby(proxy);
}

Object SubstrFunctionCallContextProxy::stringLiteral() {
  StringLiteralContextProxy proxy(((MySqlParser::SubstrFunctionCallContext*)orig) -> stringLiteral());
  return to_ruby(proxy);
}

Object SubstrFunctionCallContextProxy::expression() {
  std::vector<MySqlParser::ExpressionContext *> vec = ((MySqlParser::SubstrFunctionCallContext*)orig) -> expression();
  return Array(vec.begin(), vec.end());
}

Object SubstrFunctionCallContextProxy::expressionAt(size_t i) {
  ExpressionContextProxy proxy(((MySqlParser::SubstrFunctionCallContext*)orig) -> expression(i));
  return to_ruby(proxy);
}

Object SubstrFunctionCallContextProxy::decimalLiteral() {
  std::vector<MySqlParser::DecimalLiteralContext *> vec = ((MySqlParser::SubstrFunctionCallContext*)orig) -> decimalLiteral();
  return Array(vec.begin(), vec.end());
}

Object SubstrFunctionCallContextProxy::decimalLiteralAt(size_t i) {
  DecimalLiteralContextProxy proxy(((MySqlParser::SubstrFunctionCallContext*)orig) -> decimalLiteral(i));
  return to_ruby(proxy);
}

Object LevelWeightRangeContextProxy::decimalLiteral() {
  std::vector<MySqlParser::DecimalLiteralContext *> vec = ((MySqlParser::LevelWeightRangeContext*)orig) -> decimalLiteral();
  return Array(vec.begin(), vec.end());
}

Object LevelWeightRangeContextProxy::decimalLiteralAt(size_t i) {
  DecimalLiteralContextProxy proxy(((MySqlParser::LevelWeightRangeContext*)orig) -> decimalLiteral(i));
  return to_ruby(proxy);
}

Object LevelWeightListContextProxy::levelInWeightListElement() {
  std::vector<MySqlParser::LevelInWeightListElementContext *> vec = ((MySqlParser::LevelWeightListContext*)orig) -> levelInWeightListElement();
  return Array(vec.begin(), vec.end());
}

Object LevelWeightListContextProxy::levelInWeightListElementAt(size_t i) {
  LevelInWeightListElementContextProxy proxy(((MySqlParser::LevelWeightListContext*)orig) -> levelInWeightListElement(i));
  return to_ruby(proxy);
}

Object LevelInWeightListElementContextProxy::decimalLiteral() {
  DecimalLiteralContextProxy proxy(((MySqlParser::LevelInWeightListElementContext*)orig) -> decimalLiteral());
  return to_ruby(proxy);
}

Object IsExpressionContextProxy::predicate() {
  PredicateContextProxy proxy(((MySqlParser::IsExpressionContext*)orig) -> predicate());
  return to_ruby(proxy);
}

Object NotExpressionContextProxy::expression() {
  ExpressionContextProxy proxy(((MySqlParser::NotExpressionContext*)orig) -> expression());
  return to_ruby(proxy);
}

Object LogicalExpressionContextProxy::expression() {
  std::vector<MySqlParser::ExpressionContext *> vec = ((MySqlParser::LogicalExpressionContext*)orig) -> expression();
  return Array(vec.begin(), vec.end());
}

Object LogicalExpressionContextProxy::expressionAt(size_t i) {
  ExpressionContextProxy proxy(((MySqlParser::LogicalExpressionContext*)orig) -> expression(i));
  return to_ruby(proxy);
}

Object LogicalExpressionContextProxy::logicalOperator() {
  LogicalOperatorContextProxy proxy(((MySqlParser::LogicalExpressionContext*)orig) -> logicalOperator());
  return to_ruby(proxy);
}

Object PredicateExpressionContextProxy::predicate() {
  PredicateContextProxy proxy(((MySqlParser::PredicateExpressionContext*)orig) -> predicate());
  return to_ruby(proxy);
}

Object SoundsLikePredicateContextProxy::predicate() {
  std::vector<MySqlParser::PredicateContext *> vec = ((MySqlParser::SoundsLikePredicateContext*)orig) -> predicate();
  return Array(vec.begin(), vec.end());
}

Object SoundsLikePredicateContextProxy::predicateAt(size_t i) {
  PredicateContextProxy proxy(((MySqlParser::SoundsLikePredicateContext*)orig) -> predicate(i));
  return to_ruby(proxy);
}

Object ExpressionAtomPredicateContextProxy::expressionAtom() {
  ExpressionAtomContextProxy proxy(((MySqlParser::ExpressionAtomPredicateContext*)orig) -> expressionAtom());
  return to_ruby(proxy);
}

Object InPredicateContextProxy::predicate() {
  PredicateContextProxy proxy(((MySqlParser::InPredicateContext*)orig) -> predicate());
  return to_ruby(proxy);
}

Object InPredicateContextProxy::selectStatement() {
  SelectStatementContextProxy proxy(((MySqlParser::InPredicateContext*)orig) -> selectStatement());
  return to_ruby(proxy);
}

Object InPredicateContextProxy::expressions() {
  ExpressionsContextProxy proxy(((MySqlParser::InPredicateContext*)orig) -> expressions());
  return to_ruby(proxy);
}

Object SubqueryComparasionPredicateContextProxy::predicate() {
  PredicateContextProxy proxy(((MySqlParser::SubqueryComparasionPredicateContext*)orig) -> predicate());
  return to_ruby(proxy);
}

Object SubqueryComparasionPredicateContextProxy::comparisonOperator() {
  ComparisonOperatorContextProxy proxy(((MySqlParser::SubqueryComparasionPredicateContext*)orig) -> comparisonOperator());
  return to_ruby(proxy);
}

Object SubqueryComparasionPredicateContextProxy::selectStatement() {
  SelectStatementContextProxy proxy(((MySqlParser::SubqueryComparasionPredicateContext*)orig) -> selectStatement());
  return to_ruby(proxy);
}

Object BetweenPredicateContextProxy::predicate() {
  std::vector<MySqlParser::PredicateContext *> vec = ((MySqlParser::BetweenPredicateContext*)orig) -> predicate();
  return Array(vec.begin(), vec.end());
}

Object BetweenPredicateContextProxy::predicateAt(size_t i) {
  PredicateContextProxy proxy(((MySqlParser::BetweenPredicateContext*)orig) -> predicate(i));
  return to_ruby(proxy);
}

Object BinaryComparasionPredicateContextProxy::comparisonOperator() {
  ComparisonOperatorContextProxy proxy(((MySqlParser::BinaryComparasionPredicateContext*)orig) -> comparisonOperator());
  return to_ruby(proxy);
}

Object BinaryComparasionPredicateContextProxy::predicate() {
  std::vector<MySqlParser::PredicateContext *> vec = ((MySqlParser::BinaryComparasionPredicateContext*)orig) -> predicate();
  return Array(vec.begin(), vec.end());
}

Object BinaryComparasionPredicateContextProxy::predicateAt(size_t i) {
  PredicateContextProxy proxy(((MySqlParser::BinaryComparasionPredicateContext*)orig) -> predicate(i));
  return to_ruby(proxy);
}

Object IsNullPredicateContextProxy::predicate() {
  PredicateContextProxy proxy(((MySqlParser::IsNullPredicateContext*)orig) -> predicate());
  return to_ruby(proxy);
}

Object IsNullPredicateContextProxy::nullNotnull() {
  NullNotnullContextProxy proxy(((MySqlParser::IsNullPredicateContext*)orig) -> nullNotnull());
  return to_ruby(proxy);
}

Object LikePredicateContextProxy::predicate() {
  std::vector<MySqlParser::PredicateContext *> vec = ((MySqlParser::LikePredicateContext*)orig) -> predicate();
  return Array(vec.begin(), vec.end());
}

Object LikePredicateContextProxy::predicateAt(size_t i) {
  PredicateContextProxy proxy(((MySqlParser::LikePredicateContext*)orig) -> predicate(i));
  return to_ruby(proxy);
}

Object RegexpPredicateContextProxy::predicate() {
  std::vector<MySqlParser::PredicateContext *> vec = ((MySqlParser::RegexpPredicateContext*)orig) -> predicate();
  return Array(vec.begin(), vec.end());
}

Object RegexpPredicateContextProxy::predicateAt(size_t i) {
  PredicateContextProxy proxy(((MySqlParser::RegexpPredicateContext*)orig) -> predicate(i));
  return to_ruby(proxy);
}

Object UnaryExpressionAtomContextProxy::unaryOperator() {
  UnaryOperatorContextProxy proxy(((MySqlParser::UnaryExpressionAtomContext*)orig) -> unaryOperator());
  return to_ruby(proxy);
}

Object UnaryExpressionAtomContextProxy::expressionAtom() {
  ExpressionAtomContextProxy proxy(((MySqlParser::UnaryExpressionAtomContext*)orig) -> expressionAtom());
  return to_ruby(proxy);
}

Object CollateExpressionAtomContextProxy::expressionAtom() {
  ExpressionAtomContextProxy proxy(((MySqlParser::CollateExpressionAtomContext*)orig) -> expressionAtom());
  return to_ruby(proxy);
}

Object CollateExpressionAtomContextProxy::collationName() {
  CollationNameContextProxy proxy(((MySqlParser::CollateExpressionAtomContext*)orig) -> collationName());
  return to_ruby(proxy);
}

Object SubqueryExpessionAtomContextProxy::selectStatement() {
  SelectStatementContextProxy proxy(((MySqlParser::SubqueryExpessionAtomContext*)orig) -> selectStatement());
  return to_ruby(proxy);
}

Object MysqlVariableExpressionAtomContextProxy::mysqlVariable() {
  MysqlVariableContextProxy proxy(((MySqlParser::MysqlVariableExpressionAtomContext*)orig) -> mysqlVariable());
  return to_ruby(proxy);
}

Object NestedExpressionAtomContextProxy::expression() {
  std::vector<MySqlParser::ExpressionContext *> vec = ((MySqlParser::NestedExpressionAtomContext*)orig) -> expression();
  return Array(vec.begin(), vec.end());
}

Object NestedExpressionAtomContextProxy::expressionAt(size_t i) {
  ExpressionContextProxy proxy(((MySqlParser::NestedExpressionAtomContext*)orig) -> expression(i));
  return to_ruby(proxy);
}

Object NestedRowExpressionAtomContextProxy::expression() {
  std::vector<MySqlParser::ExpressionContext *> vec = ((MySqlParser::NestedRowExpressionAtomContext*)orig) -> expression();
  return Array(vec.begin(), vec.end());
}

Object NestedRowExpressionAtomContextProxy::expressionAt(size_t i) {
  ExpressionContextProxy proxy(((MySqlParser::NestedRowExpressionAtomContext*)orig) -> expression(i));
  return to_ruby(proxy);
}

Object MathExpressionAtomContextProxy::mathOperator() {
  MathOperatorContextProxy proxy(((MySqlParser::MathExpressionAtomContext*)orig) -> mathOperator());
  return to_ruby(proxy);
}

Object MathExpressionAtomContextProxy::expressionAtom() {
  std::vector<MySqlParser::ExpressionAtomContext *> vec = ((MySqlParser::MathExpressionAtomContext*)orig) -> expressionAtom();
  return Array(vec.begin(), vec.end());
}

Object MathExpressionAtomContextProxy::expressionAtomAt(size_t i) {
  ExpressionAtomContextProxy proxy(((MySqlParser::MathExpressionAtomContext*)orig) -> expressionAtom(i));
  return to_ruby(proxy);
}

Object IntervalExpressionAtomContextProxy::expression() {
  ExpressionContextProxy proxy(((MySqlParser::IntervalExpressionAtomContext*)orig) -> expression());
  return to_ruby(proxy);
}

Object IntervalExpressionAtomContextProxy::intervalType() {
  IntervalTypeContextProxy proxy(((MySqlParser::IntervalExpressionAtomContext*)orig) -> intervalType());
  return to_ruby(proxy);
}

Object ExistsExpessionAtomContextProxy::selectStatement() {
  SelectStatementContextProxy proxy(((MySqlParser::ExistsExpessionAtomContext*)orig) -> selectStatement());
  return to_ruby(proxy);
}

Object ConstantExpressionAtomContextProxy::constant() {
  ConstantContextProxy proxy(((MySqlParser::ConstantExpressionAtomContext*)orig) -> constant());
  return to_ruby(proxy);
}

Object FunctionCallExpressionAtomContextProxy::functionCall() {
  FunctionCallContextProxy proxy(((MySqlParser::FunctionCallExpressionAtomContext*)orig) -> functionCall());
  return to_ruby(proxy);
}

Object BinaryExpressionAtomContextProxy::expressionAtom() {
  ExpressionAtomContextProxy proxy(((MySqlParser::BinaryExpressionAtomContext*)orig) -> expressionAtom());
  return to_ruby(proxy);
}

Object FullColumnNameExpressionAtomContextProxy::fullColumnName() {
  FullColumnNameContextProxy proxy(((MySqlParser::FullColumnNameExpressionAtomContext*)orig) -> fullColumnName());
  return to_ruby(proxy);
}

Object BitExpressionAtomContextProxy::bitOperator() {
  BitOperatorContextProxy proxy(((MySqlParser::BitExpressionAtomContext*)orig) -> bitOperator());
  return to_ruby(proxy);
}

Object BitExpressionAtomContextProxy::expressionAtom() {
  std::vector<MySqlParser::ExpressionAtomContext *> vec = ((MySqlParser::BitExpressionAtomContext*)orig) -> expressionAtom();
  return Array(vec.begin(), vec.end());
}

Object BitExpressionAtomContextProxy::expressionAtomAt(size_t i) {
  ExpressionAtomContextProxy proxy(((MySqlParser::BitExpressionAtomContext*)orig) -> expressionAtom(i));
  return to_ruby(proxy);
}


class MySqlVisitor : public MySqlParserBaseVisitor {
public:
  MySqlVisitor() { }
};


class MySqlVisitorProxy : public MySqlVisitor, public Rice::Director {
public:
  MySqlVisitorProxy(Object self) : Rice::Director(self) { }

  Object ruby_visit(ContextProxy* proxy) {
    visit(proxy -> getOriginal());
    return Rice::Nil;
  }

  Object ruby_visitChildren(ContextProxy* proxy) {
    visitChildren(proxy -> getOriginal());
    return Rice::Nil;
  }

  virtual antlrcpp::Any visitRoot(MySqlParser::RootContext *ctx) override {
    RootContextProxy proxy(ctx);
    return getSelf().call("visit_root", &proxy);
  }

  virtual antlrcpp::Any visitSqlStatements(MySqlParser::SqlStatementsContext *ctx) override {
    SqlStatementsContextProxy proxy(ctx);
    return getSelf().call("visit_sql_statements", &proxy);
  }

  virtual antlrcpp::Any visitSqlStatement(MySqlParser::SqlStatementContext *ctx) override {
    SqlStatementContextProxy proxy(ctx);
    return getSelf().call("visit_sql_statement", &proxy);
  }

  virtual antlrcpp::Any visitEmptyStatement(MySqlParser::EmptyStatementContext *ctx) override {
    EmptyStatementContextProxy proxy(ctx);
    return getSelf().call("visit_empty_statement", &proxy);
  }

  virtual antlrcpp::Any visitDdlStatement(MySqlParser::DdlStatementContext *ctx) override {
    DdlStatementContextProxy proxy(ctx);
    return getSelf().call("visit_ddl_statement", &proxy);
  }

  virtual antlrcpp::Any visitDmlStatement(MySqlParser::DmlStatementContext *ctx) override {
    DmlStatementContextProxy proxy(ctx);
    return getSelf().call("visit_dml_statement", &proxy);
  }

  virtual antlrcpp::Any visitTransactionStatement(MySqlParser::TransactionStatementContext *ctx) override {
    TransactionStatementContextProxy proxy(ctx);
    return getSelf().call("visit_transaction_statement", &proxy);
  }

  virtual antlrcpp::Any visitReplicationStatement(MySqlParser::ReplicationStatementContext *ctx) override {
    ReplicationStatementContextProxy proxy(ctx);
    return getSelf().call("visit_replication_statement", &proxy);
  }

  virtual antlrcpp::Any visitPreparedStatement(MySqlParser::PreparedStatementContext *ctx) override {
    PreparedStatementContextProxy proxy(ctx);
    return getSelf().call("visit_prepared_statement", &proxy);
  }

  virtual antlrcpp::Any visitCompoundStatement(MySqlParser::CompoundStatementContext *ctx) override {
    CompoundStatementContextProxy proxy(ctx);
    return getSelf().call("visit_compound_statement", &proxy);
  }

  virtual antlrcpp::Any visitAdministrationStatement(MySqlParser::AdministrationStatementContext *ctx) override {
    AdministrationStatementContextProxy proxy(ctx);
    return getSelf().call("visit_administration_statement", &proxy);
  }

  virtual antlrcpp::Any visitUtilityStatement(MySqlParser::UtilityStatementContext *ctx) override {
    UtilityStatementContextProxy proxy(ctx);
    return getSelf().call("visit_utility_statement", &proxy);
  }

  virtual antlrcpp::Any visitCreateDatabase(MySqlParser::CreateDatabaseContext *ctx) override {
    CreateDatabaseContextProxy proxy(ctx);
    return getSelf().call("visit_create_database", &proxy);
  }

  virtual antlrcpp::Any visitCreateEvent(MySqlParser::CreateEventContext *ctx) override {
    CreateEventContextProxy proxy(ctx);
    return getSelf().call("visit_create_event", &proxy);
  }

  virtual antlrcpp::Any visitCreateIndex(MySqlParser::CreateIndexContext *ctx) override {
    CreateIndexContextProxy proxy(ctx);
    return getSelf().call("visit_create_index", &proxy);
  }

  virtual antlrcpp::Any visitCreateLogfileGroup(MySqlParser::CreateLogfileGroupContext *ctx) override {
    CreateLogfileGroupContextProxy proxy(ctx);
    return getSelf().call("visit_create_logfile_group", &proxy);
  }

  virtual antlrcpp::Any visitCreateProcedure(MySqlParser::CreateProcedureContext *ctx) override {
    CreateProcedureContextProxy proxy(ctx);
    return getSelf().call("visit_create_procedure", &proxy);
  }

  virtual antlrcpp::Any visitCreateFunction(MySqlParser::CreateFunctionContext *ctx) override {
    CreateFunctionContextProxy proxy(ctx);
    return getSelf().call("visit_create_function", &proxy);
  }

  virtual antlrcpp::Any visitCreateServer(MySqlParser::CreateServerContext *ctx) override {
    CreateServerContextProxy proxy(ctx);
    return getSelf().call("visit_create_server", &proxy);
  }

  virtual antlrcpp::Any visitCopyCreateTable(MySqlParser::CopyCreateTableContext *ctx) override {
    CopyCreateTableContextProxy proxy(ctx);
    return getSelf().call("visit_copy_create_table", &proxy);
  }

  virtual antlrcpp::Any visitQueryCreateTable(MySqlParser::QueryCreateTableContext *ctx) override {
    QueryCreateTableContextProxy proxy(ctx);
    return getSelf().call("visit_query_create_table", &proxy);
  }

  virtual antlrcpp::Any visitColumnCreateTable(MySqlParser::ColumnCreateTableContext *ctx) override {
    ColumnCreateTableContextProxy proxy(ctx);
    return getSelf().call("visit_column_create_table", &proxy);
  }

  virtual antlrcpp::Any visitCreateTablespaceInnodb(MySqlParser::CreateTablespaceInnodbContext *ctx) override {
    CreateTablespaceInnodbContextProxy proxy(ctx);
    return getSelf().call("visit_create_tablespace_innodb", &proxy);
  }

  virtual antlrcpp::Any visitCreateTablespaceNdb(MySqlParser::CreateTablespaceNdbContext *ctx) override {
    CreateTablespaceNdbContextProxy proxy(ctx);
    return getSelf().call("visit_create_tablespace_ndb", &proxy);
  }

  virtual antlrcpp::Any visitCreateTrigger(MySqlParser::CreateTriggerContext *ctx) override {
    CreateTriggerContextProxy proxy(ctx);
    return getSelf().call("visit_create_trigger", &proxy);
  }

  virtual antlrcpp::Any visitCreateView(MySqlParser::CreateViewContext *ctx) override {
    CreateViewContextProxy proxy(ctx);
    return getSelf().call("visit_create_view", &proxy);
  }

  virtual antlrcpp::Any visitCreateDatabaseOption(MySqlParser::CreateDatabaseOptionContext *ctx) override {
    CreateDatabaseOptionContextProxy proxy(ctx);
    return getSelf().call("visit_create_database_option", &proxy);
  }

  virtual antlrcpp::Any visitOwnerStatement(MySqlParser::OwnerStatementContext *ctx) override {
    OwnerStatementContextProxy proxy(ctx);
    return getSelf().call("visit_owner_statement", &proxy);
  }

  virtual antlrcpp::Any visitPreciseSchedule(MySqlParser::PreciseScheduleContext *ctx) override {
    PreciseScheduleContextProxy proxy(ctx);
    return getSelf().call("visit_precise_schedule", &proxy);
  }

  virtual antlrcpp::Any visitIntervalSchedule(MySqlParser::IntervalScheduleContext *ctx) override {
    IntervalScheduleContextProxy proxy(ctx);
    return getSelf().call("visit_interval_schedule", &proxy);
  }

  virtual antlrcpp::Any visitTimestampValue(MySqlParser::TimestampValueContext *ctx) override {
    TimestampValueContextProxy proxy(ctx);
    return getSelf().call("visit_timestamp_value", &proxy);
  }

  virtual antlrcpp::Any visitIntervalExpr(MySqlParser::IntervalExprContext *ctx) override {
    IntervalExprContextProxy proxy(ctx);
    return getSelf().call("visit_interval_expr", &proxy);
  }

  virtual antlrcpp::Any visitIntervalType(MySqlParser::IntervalTypeContext *ctx) override {
    IntervalTypeContextProxy proxy(ctx);
    return getSelf().call("visit_interval_type", &proxy);
  }

  virtual antlrcpp::Any visitEnableType(MySqlParser::EnableTypeContext *ctx) override {
    EnableTypeContextProxy proxy(ctx);
    return getSelf().call("visit_enable_type", &proxy);
  }

  virtual antlrcpp::Any visitIndexType(MySqlParser::IndexTypeContext *ctx) override {
    IndexTypeContextProxy proxy(ctx);
    return getSelf().call("visit_index_type", &proxy);
  }

  virtual antlrcpp::Any visitIndexOption(MySqlParser::IndexOptionContext *ctx) override {
    IndexOptionContextProxy proxy(ctx);
    return getSelf().call("visit_index_option", &proxy);
  }

  virtual antlrcpp::Any visitProcedureParameter(MySqlParser::ProcedureParameterContext *ctx) override {
    ProcedureParameterContextProxy proxy(ctx);
    return getSelf().call("visit_procedure_parameter", &proxy);
  }

  virtual antlrcpp::Any visitFunctionParameter(MySqlParser::FunctionParameterContext *ctx) override {
    FunctionParameterContextProxy proxy(ctx);
    return getSelf().call("visit_function_parameter", &proxy);
  }

  virtual antlrcpp::Any visitRoutineComment(MySqlParser::RoutineCommentContext *ctx) override {
    RoutineCommentContextProxy proxy(ctx);
    return getSelf().call("visit_routine_comment", &proxy);
  }

  virtual antlrcpp::Any visitRoutineLanguage(MySqlParser::RoutineLanguageContext *ctx) override {
    RoutineLanguageContextProxy proxy(ctx);
    return getSelf().call("visit_routine_language", &proxy);
  }

  virtual antlrcpp::Any visitRoutineBehavior(MySqlParser::RoutineBehaviorContext *ctx) override {
    RoutineBehaviorContextProxy proxy(ctx);
    return getSelf().call("visit_routine_behavior", &proxy);
  }

  virtual antlrcpp::Any visitRoutineData(MySqlParser::RoutineDataContext *ctx) override {
    RoutineDataContextProxy proxy(ctx);
    return getSelf().call("visit_routine_data", &proxy);
  }

  virtual antlrcpp::Any visitRoutineSecurity(MySqlParser::RoutineSecurityContext *ctx) override {
    RoutineSecurityContextProxy proxy(ctx);
    return getSelf().call("visit_routine_security", &proxy);
  }

  virtual antlrcpp::Any visitServerOption(MySqlParser::ServerOptionContext *ctx) override {
    ServerOptionContextProxy proxy(ctx);
    return getSelf().call("visit_server_option", &proxy);
  }

  virtual antlrcpp::Any visitCreateDefinitions(MySqlParser::CreateDefinitionsContext *ctx) override {
    CreateDefinitionsContextProxy proxy(ctx);
    return getSelf().call("visit_create_definitions", &proxy);
  }

  virtual antlrcpp::Any visitColumnDeclaration(MySqlParser::ColumnDeclarationContext *ctx) override {
    ColumnDeclarationContextProxy proxy(ctx);
    return getSelf().call("visit_column_declaration", &proxy);
  }

  virtual antlrcpp::Any visitConstraintDeclaration(MySqlParser::ConstraintDeclarationContext *ctx) override {
    ConstraintDeclarationContextProxy proxy(ctx);
    return getSelf().call("visit_constraint_declaration", &proxy);
  }

  virtual antlrcpp::Any visitIndexDeclaration(MySqlParser::IndexDeclarationContext *ctx) override {
    IndexDeclarationContextProxy proxy(ctx);
    return getSelf().call("visit_index_declaration", &proxy);
  }

  virtual antlrcpp::Any visitColumnDefinition(MySqlParser::ColumnDefinitionContext *ctx) override {
    ColumnDefinitionContextProxy proxy(ctx);
    return getSelf().call("visit_column_definition", &proxy);
  }

  virtual antlrcpp::Any visitNullColumnConstraint(MySqlParser::NullColumnConstraintContext *ctx) override {
    NullColumnConstraintContextProxy proxy(ctx);
    return getSelf().call("visit_null_column_constraint", &proxy);
  }

  virtual antlrcpp::Any visitDefaultColumnConstraint(MySqlParser::DefaultColumnConstraintContext *ctx) override {
    DefaultColumnConstraintContextProxy proxy(ctx);
    return getSelf().call("visit_default_column_constraint", &proxy);
  }

  virtual antlrcpp::Any visitAutoIncrementColumnConstraint(MySqlParser::AutoIncrementColumnConstraintContext *ctx) override {
    AutoIncrementColumnConstraintContextProxy proxy(ctx);
    return getSelf().call("visit_auto_increment_column_constraint", &proxy);
  }

  virtual antlrcpp::Any visitPrimaryKeyColumnConstraint(MySqlParser::PrimaryKeyColumnConstraintContext *ctx) override {
    PrimaryKeyColumnConstraintContextProxy proxy(ctx);
    return getSelf().call("visit_primary_key_column_constraint", &proxy);
  }

  virtual antlrcpp::Any visitUniqueKeyColumnConstraint(MySqlParser::UniqueKeyColumnConstraintContext *ctx) override {
    UniqueKeyColumnConstraintContextProxy proxy(ctx);
    return getSelf().call("visit_unique_key_column_constraint", &proxy);
  }

  virtual antlrcpp::Any visitCommentColumnConstraint(MySqlParser::CommentColumnConstraintContext *ctx) override {
    CommentColumnConstraintContextProxy proxy(ctx);
    return getSelf().call("visit_comment_column_constraint", &proxy);
  }

  virtual antlrcpp::Any visitFormatColumnConstraint(MySqlParser::FormatColumnConstraintContext *ctx) override {
    FormatColumnConstraintContextProxy proxy(ctx);
    return getSelf().call("visit_format_column_constraint", &proxy);
  }

  virtual antlrcpp::Any visitStorageColumnConstraint(MySqlParser::StorageColumnConstraintContext *ctx) override {
    StorageColumnConstraintContextProxy proxy(ctx);
    return getSelf().call("visit_storage_column_constraint", &proxy);
  }

  virtual antlrcpp::Any visitReferenceColumnConstraint(MySqlParser::ReferenceColumnConstraintContext *ctx) override {
    ReferenceColumnConstraintContextProxy proxy(ctx);
    return getSelf().call("visit_reference_column_constraint", &proxy);
  }

  virtual antlrcpp::Any visitCollateColumnConstraint(MySqlParser::CollateColumnConstraintContext *ctx) override {
    CollateColumnConstraintContextProxy proxy(ctx);
    return getSelf().call("visit_collate_column_constraint", &proxy);
  }

  virtual antlrcpp::Any visitGeneratedColumnConstraint(MySqlParser::GeneratedColumnConstraintContext *ctx) override {
    GeneratedColumnConstraintContextProxy proxy(ctx);
    return getSelf().call("visit_generated_column_constraint", &proxy);
  }

  virtual antlrcpp::Any visitSerialDefaultColumnConstraint(MySqlParser::SerialDefaultColumnConstraintContext *ctx) override {
    SerialDefaultColumnConstraintContextProxy proxy(ctx);
    return getSelf().call("visit_serial_default_column_constraint", &proxy);
  }

  virtual antlrcpp::Any visitPrimaryKeyTableConstraint(MySqlParser::PrimaryKeyTableConstraintContext *ctx) override {
    PrimaryKeyTableConstraintContextProxy proxy(ctx);
    return getSelf().call("visit_primary_key_table_constraint", &proxy);
  }

  virtual antlrcpp::Any visitUniqueKeyTableConstraint(MySqlParser::UniqueKeyTableConstraintContext *ctx) override {
    UniqueKeyTableConstraintContextProxy proxy(ctx);
    return getSelf().call("visit_unique_key_table_constraint", &proxy);
  }

  virtual antlrcpp::Any visitForeignKeyTableConstraint(MySqlParser::ForeignKeyTableConstraintContext *ctx) override {
    ForeignKeyTableConstraintContextProxy proxy(ctx);
    return getSelf().call("visit_foreign_key_table_constraint", &proxy);
  }

  virtual antlrcpp::Any visitCheckTableConstraint(MySqlParser::CheckTableConstraintContext *ctx) override {
    CheckTableConstraintContextProxy proxy(ctx);
    return getSelf().call("visit_check_table_constraint", &proxy);
  }

  virtual antlrcpp::Any visitReferenceDefinition(MySqlParser::ReferenceDefinitionContext *ctx) override {
    ReferenceDefinitionContextProxy proxy(ctx);
    return getSelf().call("visit_reference_definition", &proxy);
  }

  virtual antlrcpp::Any visitReferenceAction(MySqlParser::ReferenceActionContext *ctx) override {
    ReferenceActionContextProxy proxy(ctx);
    return getSelf().call("visit_reference_action", &proxy);
  }

  virtual antlrcpp::Any visitReferenceControlType(MySqlParser::ReferenceControlTypeContext *ctx) override {
    ReferenceControlTypeContextProxy proxy(ctx);
    return getSelf().call("visit_reference_control_type", &proxy);
  }

  virtual antlrcpp::Any visitSimpleIndexDeclaration(MySqlParser::SimpleIndexDeclarationContext *ctx) override {
    SimpleIndexDeclarationContextProxy proxy(ctx);
    return getSelf().call("visit_simple_index_declaration", &proxy);
  }

  virtual antlrcpp::Any visitSpecialIndexDeclaration(MySqlParser::SpecialIndexDeclarationContext *ctx) override {
    SpecialIndexDeclarationContextProxy proxy(ctx);
    return getSelf().call("visit_special_index_declaration", &proxy);
  }

  virtual antlrcpp::Any visitTableOptionEngine(MySqlParser::TableOptionEngineContext *ctx) override {
    TableOptionEngineContextProxy proxy(ctx);
    return getSelf().call("visit_table_option_engine", &proxy);
  }

  virtual antlrcpp::Any visitTableOptionAutoIncrement(MySqlParser::TableOptionAutoIncrementContext *ctx) override {
    TableOptionAutoIncrementContextProxy proxy(ctx);
    return getSelf().call("visit_table_option_auto_increment", &proxy);
  }

  virtual antlrcpp::Any visitTableOptionAverage(MySqlParser::TableOptionAverageContext *ctx) override {
    TableOptionAverageContextProxy proxy(ctx);
    return getSelf().call("visit_table_option_average", &proxy);
  }

  virtual antlrcpp::Any visitTableOptionCharset(MySqlParser::TableOptionCharsetContext *ctx) override {
    TableOptionCharsetContextProxy proxy(ctx);
    return getSelf().call("visit_table_option_charset", &proxy);
  }

  virtual antlrcpp::Any visitTableOptionChecksum(MySqlParser::TableOptionChecksumContext *ctx) override {
    TableOptionChecksumContextProxy proxy(ctx);
    return getSelf().call("visit_table_option_checksum", &proxy);
  }

  virtual antlrcpp::Any visitTableOptionCollate(MySqlParser::TableOptionCollateContext *ctx) override {
    TableOptionCollateContextProxy proxy(ctx);
    return getSelf().call("visit_table_option_collate", &proxy);
  }

  virtual antlrcpp::Any visitTableOptionComment(MySqlParser::TableOptionCommentContext *ctx) override {
    TableOptionCommentContextProxy proxy(ctx);
    return getSelf().call("visit_table_option_comment", &proxy);
  }

  virtual antlrcpp::Any visitTableOptionCompression(MySqlParser::TableOptionCompressionContext *ctx) override {
    TableOptionCompressionContextProxy proxy(ctx);
    return getSelf().call("visit_table_option_compression", &proxy);
  }

  virtual antlrcpp::Any visitTableOptionConnection(MySqlParser::TableOptionConnectionContext *ctx) override {
    TableOptionConnectionContextProxy proxy(ctx);
    return getSelf().call("visit_table_option_connection", &proxy);
  }

  virtual antlrcpp::Any visitTableOptionDataDirectory(MySqlParser::TableOptionDataDirectoryContext *ctx) override {
    TableOptionDataDirectoryContextProxy proxy(ctx);
    return getSelf().call("visit_table_option_data_directory", &proxy);
  }

  virtual antlrcpp::Any visitTableOptionDelay(MySqlParser::TableOptionDelayContext *ctx) override {
    TableOptionDelayContextProxy proxy(ctx);
    return getSelf().call("visit_table_option_delay", &proxy);
  }

  virtual antlrcpp::Any visitTableOptionEncryption(MySqlParser::TableOptionEncryptionContext *ctx) override {
    TableOptionEncryptionContextProxy proxy(ctx);
    return getSelf().call("visit_table_option_encryption", &proxy);
  }

  virtual antlrcpp::Any visitTableOptionIndexDirectory(MySqlParser::TableOptionIndexDirectoryContext *ctx) override {
    TableOptionIndexDirectoryContextProxy proxy(ctx);
    return getSelf().call("visit_table_option_index_directory", &proxy);
  }

  virtual antlrcpp::Any visitTableOptionInsertMethod(MySqlParser::TableOptionInsertMethodContext *ctx) override {
    TableOptionInsertMethodContextProxy proxy(ctx);
    return getSelf().call("visit_table_option_insert_method", &proxy);
  }

  virtual antlrcpp::Any visitTableOptionKeyBlockSize(MySqlParser::TableOptionKeyBlockSizeContext *ctx) override {
    TableOptionKeyBlockSizeContextProxy proxy(ctx);
    return getSelf().call("visit_table_option_key_block_size", &proxy);
  }

  virtual antlrcpp::Any visitTableOptionMaxRows(MySqlParser::TableOptionMaxRowsContext *ctx) override {
    TableOptionMaxRowsContextProxy proxy(ctx);
    return getSelf().call("visit_table_option_max_rows", &proxy);
  }

  virtual antlrcpp::Any visitTableOptionMinRows(MySqlParser::TableOptionMinRowsContext *ctx) override {
    TableOptionMinRowsContextProxy proxy(ctx);
    return getSelf().call("visit_table_option_min_rows", &proxy);
  }

  virtual antlrcpp::Any visitTableOptionPackKeys(MySqlParser::TableOptionPackKeysContext *ctx) override {
    TableOptionPackKeysContextProxy proxy(ctx);
    return getSelf().call("visit_table_option_pack_keys", &proxy);
  }

  virtual antlrcpp::Any visitTableOptionPassword(MySqlParser::TableOptionPasswordContext *ctx) override {
    TableOptionPasswordContextProxy proxy(ctx);
    return getSelf().call("visit_table_option_password", &proxy);
  }

  virtual antlrcpp::Any visitTableOptionRowFormat(MySqlParser::TableOptionRowFormatContext *ctx) override {
    TableOptionRowFormatContextProxy proxy(ctx);
    return getSelf().call("visit_table_option_row_format", &proxy);
  }

  virtual antlrcpp::Any visitTableOptionRecalculation(MySqlParser::TableOptionRecalculationContext *ctx) override {
    TableOptionRecalculationContextProxy proxy(ctx);
    return getSelf().call("visit_table_option_recalculation", &proxy);
  }

  virtual antlrcpp::Any visitTableOptionPersistent(MySqlParser::TableOptionPersistentContext *ctx) override {
    TableOptionPersistentContextProxy proxy(ctx);
    return getSelf().call("visit_table_option_persistent", &proxy);
  }

  virtual antlrcpp::Any visitTableOptionSamplePage(MySqlParser::TableOptionSamplePageContext *ctx) override {
    TableOptionSamplePageContextProxy proxy(ctx);
    return getSelf().call("visit_table_option_sample_page", &proxy);
  }

  virtual antlrcpp::Any visitTableOptionTablespace(MySqlParser::TableOptionTablespaceContext *ctx) override {
    TableOptionTablespaceContextProxy proxy(ctx);
    return getSelf().call("visit_table_option_tablespace", &proxy);
  }

  virtual antlrcpp::Any visitTableOptionUnion(MySqlParser::TableOptionUnionContext *ctx) override {
    TableOptionUnionContextProxy proxy(ctx);
    return getSelf().call("visit_table_option_union", &proxy);
  }

  virtual antlrcpp::Any visitTablespaceStorage(MySqlParser::TablespaceStorageContext *ctx) override {
    TablespaceStorageContextProxy proxy(ctx);
    return getSelf().call("visit_tablespace_storage", &proxy);
  }

  virtual antlrcpp::Any visitPartitionDefinitions(MySqlParser::PartitionDefinitionsContext *ctx) override {
    PartitionDefinitionsContextProxy proxy(ctx);
    return getSelf().call("visit_partition_definitions", &proxy);
  }

  virtual antlrcpp::Any visitPartitionFunctionHash(MySqlParser::PartitionFunctionHashContext *ctx) override {
    PartitionFunctionHashContextProxy proxy(ctx);
    return getSelf().call("visit_partition_function_hash", &proxy);
  }

  virtual antlrcpp::Any visitPartitionFunctionKey(MySqlParser::PartitionFunctionKeyContext *ctx) override {
    PartitionFunctionKeyContextProxy proxy(ctx);
    return getSelf().call("visit_partition_function_key", &proxy);
  }

  virtual antlrcpp::Any visitPartitionFunctionRange(MySqlParser::PartitionFunctionRangeContext *ctx) override {
    PartitionFunctionRangeContextProxy proxy(ctx);
    return getSelf().call("visit_partition_function_range", &proxy);
  }

  virtual antlrcpp::Any visitPartitionFunctionList(MySqlParser::PartitionFunctionListContext *ctx) override {
    PartitionFunctionListContextProxy proxy(ctx);
    return getSelf().call("visit_partition_function_list", &proxy);
  }

  virtual antlrcpp::Any visitSubPartitionFunctionHash(MySqlParser::SubPartitionFunctionHashContext *ctx) override {
    SubPartitionFunctionHashContextProxy proxy(ctx);
    return getSelf().call("visit_sub_partition_function_hash", &proxy);
  }

  virtual antlrcpp::Any visitSubPartitionFunctionKey(MySqlParser::SubPartitionFunctionKeyContext *ctx) override {
    SubPartitionFunctionKeyContextProxy proxy(ctx);
    return getSelf().call("visit_sub_partition_function_key", &proxy);
  }

  virtual antlrcpp::Any visitPartitionComparision(MySqlParser::PartitionComparisionContext *ctx) override {
    PartitionComparisionContextProxy proxy(ctx);
    return getSelf().call("visit_partition_comparision", &proxy);
  }

  virtual antlrcpp::Any visitPartitionListAtom(MySqlParser::PartitionListAtomContext *ctx) override {
    PartitionListAtomContextProxy proxy(ctx);
    return getSelf().call("visit_partition_list_atom", &proxy);
  }

  virtual antlrcpp::Any visitPartitionListVector(MySqlParser::PartitionListVectorContext *ctx) override {
    PartitionListVectorContextProxy proxy(ctx);
    return getSelf().call("visit_partition_list_vector", &proxy);
  }

  virtual antlrcpp::Any visitPartitionSimple(MySqlParser::PartitionSimpleContext *ctx) override {
    PartitionSimpleContextProxy proxy(ctx);
    return getSelf().call("visit_partition_simple", &proxy);
  }

  virtual antlrcpp::Any visitPartitionDefinerAtom(MySqlParser::PartitionDefinerAtomContext *ctx) override {
    PartitionDefinerAtomContextProxy proxy(ctx);
    return getSelf().call("visit_partition_definer_atom", &proxy);
  }

  virtual antlrcpp::Any visitPartitionDefinerVector(MySqlParser::PartitionDefinerVectorContext *ctx) override {
    PartitionDefinerVectorContextProxy proxy(ctx);
    return getSelf().call("visit_partition_definer_vector", &proxy);
  }

  virtual antlrcpp::Any visitSubpartitionDefinition(MySqlParser::SubpartitionDefinitionContext *ctx) override {
    SubpartitionDefinitionContextProxy proxy(ctx);
    return getSelf().call("visit_subpartition_definition", &proxy);
  }

  virtual antlrcpp::Any visitPartitionOptionEngine(MySqlParser::PartitionOptionEngineContext *ctx) override {
    PartitionOptionEngineContextProxy proxy(ctx);
    return getSelf().call("visit_partition_option_engine", &proxy);
  }

  virtual antlrcpp::Any visitPartitionOptionComment(MySqlParser::PartitionOptionCommentContext *ctx) override {
    PartitionOptionCommentContextProxy proxy(ctx);
    return getSelf().call("visit_partition_option_comment", &proxy);
  }

  virtual antlrcpp::Any visitPartitionOptionDataDirectory(MySqlParser::PartitionOptionDataDirectoryContext *ctx) override {
    PartitionOptionDataDirectoryContextProxy proxy(ctx);
    return getSelf().call("visit_partition_option_data_directory", &proxy);
  }

  virtual antlrcpp::Any visitPartitionOptionIndexDirectory(MySqlParser::PartitionOptionIndexDirectoryContext *ctx) override {
    PartitionOptionIndexDirectoryContextProxy proxy(ctx);
    return getSelf().call("visit_partition_option_index_directory", &proxy);
  }

  virtual antlrcpp::Any visitPartitionOptionMaxRows(MySqlParser::PartitionOptionMaxRowsContext *ctx) override {
    PartitionOptionMaxRowsContextProxy proxy(ctx);
    return getSelf().call("visit_partition_option_max_rows", &proxy);
  }

  virtual antlrcpp::Any visitPartitionOptionMinRows(MySqlParser::PartitionOptionMinRowsContext *ctx) override {
    PartitionOptionMinRowsContextProxy proxy(ctx);
    return getSelf().call("visit_partition_option_min_rows", &proxy);
  }

  virtual antlrcpp::Any visitPartitionOptionTablespace(MySqlParser::PartitionOptionTablespaceContext *ctx) override {
    PartitionOptionTablespaceContextProxy proxy(ctx);
    return getSelf().call("visit_partition_option_tablespace", &proxy);
  }

  virtual antlrcpp::Any visitPartitionOptionNodeGroup(MySqlParser::PartitionOptionNodeGroupContext *ctx) override {
    PartitionOptionNodeGroupContextProxy proxy(ctx);
    return getSelf().call("visit_partition_option_node_group", &proxy);
  }

  virtual antlrcpp::Any visitAlterSimpleDatabase(MySqlParser::AlterSimpleDatabaseContext *ctx) override {
    AlterSimpleDatabaseContextProxy proxy(ctx);
    return getSelf().call("visit_alter_simple_database", &proxy);
  }

  virtual antlrcpp::Any visitAlterUpgradeName(MySqlParser::AlterUpgradeNameContext *ctx) override {
    AlterUpgradeNameContextProxy proxy(ctx);
    return getSelf().call("visit_alter_upgrade_name", &proxy);
  }

  virtual antlrcpp::Any visitAlterEvent(MySqlParser::AlterEventContext *ctx) override {
    AlterEventContextProxy proxy(ctx);
    return getSelf().call("visit_alter_event", &proxy);
  }

  virtual antlrcpp::Any visitAlterFunction(MySqlParser::AlterFunctionContext *ctx) override {
    AlterFunctionContextProxy proxy(ctx);
    return getSelf().call("visit_alter_function", &proxy);
  }

  virtual antlrcpp::Any visitAlterInstance(MySqlParser::AlterInstanceContext *ctx) override {
    AlterInstanceContextProxy proxy(ctx);
    return getSelf().call("visit_alter_instance", &proxy);
  }

  virtual antlrcpp::Any visitAlterLogfileGroup(MySqlParser::AlterLogfileGroupContext *ctx) override {
    AlterLogfileGroupContextProxy proxy(ctx);
    return getSelf().call("visit_alter_logfile_group", &proxy);
  }

  virtual antlrcpp::Any visitAlterProcedure(MySqlParser::AlterProcedureContext *ctx) override {
    AlterProcedureContextProxy proxy(ctx);
    return getSelf().call("visit_alter_procedure", &proxy);
  }

  virtual antlrcpp::Any visitAlterServer(MySqlParser::AlterServerContext *ctx) override {
    AlterServerContextProxy proxy(ctx);
    return getSelf().call("visit_alter_server", &proxy);
  }

  virtual antlrcpp::Any visitAlterTable(MySqlParser::AlterTableContext *ctx) override {
    AlterTableContextProxy proxy(ctx);
    return getSelf().call("visit_alter_table", &proxy);
  }

  virtual antlrcpp::Any visitAlterTablespace(MySqlParser::AlterTablespaceContext *ctx) override {
    AlterTablespaceContextProxy proxy(ctx);
    return getSelf().call("visit_alter_tablespace", &proxy);
  }

  virtual antlrcpp::Any visitAlterView(MySqlParser::AlterViewContext *ctx) override {
    AlterViewContextProxy proxy(ctx);
    return getSelf().call("visit_alter_view", &proxy);
  }

  virtual antlrcpp::Any visitAlterByTableOption(MySqlParser::AlterByTableOptionContext *ctx) override {
    AlterByTableOptionContextProxy proxy(ctx);
    return getSelf().call("visit_alter_by_table_option", &proxy);
  }

  virtual antlrcpp::Any visitAlterByAddColumn(MySqlParser::AlterByAddColumnContext *ctx) override {
    AlterByAddColumnContextProxy proxy(ctx);
    return getSelf().call("visit_alter_by_add_column", &proxy);
  }

  virtual antlrcpp::Any visitAlterByAddColumns(MySqlParser::AlterByAddColumnsContext *ctx) override {
    AlterByAddColumnsContextProxy proxy(ctx);
    return getSelf().call("visit_alter_by_add_columns", &proxy);
  }

  virtual antlrcpp::Any visitAlterByAddIndex(MySqlParser::AlterByAddIndexContext *ctx) override {
    AlterByAddIndexContextProxy proxy(ctx);
    return getSelf().call("visit_alter_by_add_index", &proxy);
  }

  virtual antlrcpp::Any visitAlterByAddPrimaryKey(MySqlParser::AlterByAddPrimaryKeyContext *ctx) override {
    AlterByAddPrimaryKeyContextProxy proxy(ctx);
    return getSelf().call("visit_alter_by_add_primary_key", &proxy);
  }

  virtual antlrcpp::Any visitAlterByAddUniqueKey(MySqlParser::AlterByAddUniqueKeyContext *ctx) override {
    AlterByAddUniqueKeyContextProxy proxy(ctx);
    return getSelf().call("visit_alter_by_add_unique_key", &proxy);
  }

  virtual antlrcpp::Any visitAlterByAddSpecialIndex(MySqlParser::AlterByAddSpecialIndexContext *ctx) override {
    AlterByAddSpecialIndexContextProxy proxy(ctx);
    return getSelf().call("visit_alter_by_add_special_index", &proxy);
  }

  virtual antlrcpp::Any visitAlterByAddForeignKey(MySqlParser::AlterByAddForeignKeyContext *ctx) override {
    AlterByAddForeignKeyContextProxy proxy(ctx);
    return getSelf().call("visit_alter_by_add_foreign_key", &proxy);
  }

  virtual antlrcpp::Any visitAlterByAddCheckTableConstraint(MySqlParser::AlterByAddCheckTableConstraintContext *ctx) override {
    AlterByAddCheckTableConstraintContextProxy proxy(ctx);
    return getSelf().call("visit_alter_by_add_check_table_constraint", &proxy);
  }

  virtual antlrcpp::Any visitAlterBySetAlgorithm(MySqlParser::AlterBySetAlgorithmContext *ctx) override {
    AlterBySetAlgorithmContextProxy proxy(ctx);
    return getSelf().call("visit_alter_by_set_algorithm", &proxy);
  }

  virtual antlrcpp::Any visitAlterByChangeDefault(MySqlParser::AlterByChangeDefaultContext *ctx) override {
    AlterByChangeDefaultContextProxy proxy(ctx);
    return getSelf().call("visit_alter_by_change_default", &proxy);
  }

  virtual antlrcpp::Any visitAlterByChangeColumn(MySqlParser::AlterByChangeColumnContext *ctx) override {
    AlterByChangeColumnContextProxy proxy(ctx);
    return getSelf().call("visit_alter_by_change_column", &proxy);
  }

  virtual antlrcpp::Any visitAlterByRenameColumn(MySqlParser::AlterByRenameColumnContext *ctx) override {
    AlterByRenameColumnContextProxy proxy(ctx);
    return getSelf().call("visit_alter_by_rename_column", &proxy);
  }

  virtual antlrcpp::Any visitAlterByLock(MySqlParser::AlterByLockContext *ctx) override {
    AlterByLockContextProxy proxy(ctx);
    return getSelf().call("visit_alter_by_lock", &proxy);
  }

  virtual antlrcpp::Any visitAlterByModifyColumn(MySqlParser::AlterByModifyColumnContext *ctx) override {
    AlterByModifyColumnContextProxy proxy(ctx);
    return getSelf().call("visit_alter_by_modify_column", &proxy);
  }

  virtual antlrcpp::Any visitAlterByDropColumn(MySqlParser::AlterByDropColumnContext *ctx) override {
    AlterByDropColumnContextProxy proxy(ctx);
    return getSelf().call("visit_alter_by_drop_column", &proxy);
  }

  virtual antlrcpp::Any visitAlterByDropPrimaryKey(MySqlParser::AlterByDropPrimaryKeyContext *ctx) override {
    AlterByDropPrimaryKeyContextProxy proxy(ctx);
    return getSelf().call("visit_alter_by_drop_primary_key", &proxy);
  }

  virtual antlrcpp::Any visitAlterByRenameIndex(MySqlParser::AlterByRenameIndexContext *ctx) override {
    AlterByRenameIndexContextProxy proxy(ctx);
    return getSelf().call("visit_alter_by_rename_index", &proxy);
  }

  virtual antlrcpp::Any visitAlterByDropIndex(MySqlParser::AlterByDropIndexContext *ctx) override {
    AlterByDropIndexContextProxy proxy(ctx);
    return getSelf().call("visit_alter_by_drop_index", &proxy);
  }

  virtual antlrcpp::Any visitAlterByDropForeignKey(MySqlParser::AlterByDropForeignKeyContext *ctx) override {
    AlterByDropForeignKeyContextProxy proxy(ctx);
    return getSelf().call("visit_alter_by_drop_foreign_key", &proxy);
  }

  virtual antlrcpp::Any visitAlterByDisableKeys(MySqlParser::AlterByDisableKeysContext *ctx) override {
    AlterByDisableKeysContextProxy proxy(ctx);
    return getSelf().call("visit_alter_by_disable_keys", &proxy);
  }

  virtual antlrcpp::Any visitAlterByEnableKeys(MySqlParser::AlterByEnableKeysContext *ctx) override {
    AlterByEnableKeysContextProxy proxy(ctx);
    return getSelf().call("visit_alter_by_enable_keys", &proxy);
  }

  virtual antlrcpp::Any visitAlterByRename(MySqlParser::AlterByRenameContext *ctx) override {
    AlterByRenameContextProxy proxy(ctx);
    return getSelf().call("visit_alter_by_rename", &proxy);
  }

  virtual antlrcpp::Any visitAlterByOrder(MySqlParser::AlterByOrderContext *ctx) override {
    AlterByOrderContextProxy proxy(ctx);
    return getSelf().call("visit_alter_by_order", &proxy);
  }

  virtual antlrcpp::Any visitAlterByConvertCharset(MySqlParser::AlterByConvertCharsetContext *ctx) override {
    AlterByConvertCharsetContextProxy proxy(ctx);
    return getSelf().call("visit_alter_by_convert_charset", &proxy);
  }

  virtual antlrcpp::Any visitAlterByDefaultCharset(MySqlParser::AlterByDefaultCharsetContext *ctx) override {
    AlterByDefaultCharsetContextProxy proxy(ctx);
    return getSelf().call("visit_alter_by_default_charset", &proxy);
  }

  virtual antlrcpp::Any visitAlterByDiscardTablespace(MySqlParser::AlterByDiscardTablespaceContext *ctx) override {
    AlterByDiscardTablespaceContextProxy proxy(ctx);
    return getSelf().call("visit_alter_by_discard_tablespace", &proxy);
  }

  virtual antlrcpp::Any visitAlterByImportTablespace(MySqlParser::AlterByImportTablespaceContext *ctx) override {
    AlterByImportTablespaceContextProxy proxy(ctx);
    return getSelf().call("visit_alter_by_import_tablespace", &proxy);
  }

  virtual antlrcpp::Any visitAlterByForce(MySqlParser::AlterByForceContext *ctx) override {
    AlterByForceContextProxy proxy(ctx);
    return getSelf().call("visit_alter_by_force", &proxy);
  }

  virtual antlrcpp::Any visitAlterByValidate(MySqlParser::AlterByValidateContext *ctx) override {
    AlterByValidateContextProxy proxy(ctx);
    return getSelf().call("visit_alter_by_validate", &proxy);
  }

  virtual antlrcpp::Any visitAlterByAddPartition(MySqlParser::AlterByAddPartitionContext *ctx) override {
    AlterByAddPartitionContextProxy proxy(ctx);
    return getSelf().call("visit_alter_by_add_partition", &proxy);
  }

  virtual antlrcpp::Any visitAlterByDropPartition(MySqlParser::AlterByDropPartitionContext *ctx) override {
    AlterByDropPartitionContextProxy proxy(ctx);
    return getSelf().call("visit_alter_by_drop_partition", &proxy);
  }

  virtual antlrcpp::Any visitAlterByDiscardPartition(MySqlParser::AlterByDiscardPartitionContext *ctx) override {
    AlterByDiscardPartitionContextProxy proxy(ctx);
    return getSelf().call("visit_alter_by_discard_partition", &proxy);
  }

  virtual antlrcpp::Any visitAlterByImportPartition(MySqlParser::AlterByImportPartitionContext *ctx) override {
    AlterByImportPartitionContextProxy proxy(ctx);
    return getSelf().call("visit_alter_by_import_partition", &proxy);
  }

  virtual antlrcpp::Any visitAlterByTruncatePartition(MySqlParser::AlterByTruncatePartitionContext *ctx) override {
    AlterByTruncatePartitionContextProxy proxy(ctx);
    return getSelf().call("visit_alter_by_truncate_partition", &proxy);
  }

  virtual antlrcpp::Any visitAlterByCoalescePartition(MySqlParser::AlterByCoalescePartitionContext *ctx) override {
    AlterByCoalescePartitionContextProxy proxy(ctx);
    return getSelf().call("visit_alter_by_coalesce_partition", &proxy);
  }

  virtual antlrcpp::Any visitAlterByReorganizePartition(MySqlParser::AlterByReorganizePartitionContext *ctx) override {
    AlterByReorganizePartitionContextProxy proxy(ctx);
    return getSelf().call("visit_alter_by_reorganize_partition", &proxy);
  }

  virtual antlrcpp::Any visitAlterByExchangePartition(MySqlParser::AlterByExchangePartitionContext *ctx) override {
    AlterByExchangePartitionContextProxy proxy(ctx);
    return getSelf().call("visit_alter_by_exchange_partition", &proxy);
  }

  virtual antlrcpp::Any visitAlterByAnalyzePartition(MySqlParser::AlterByAnalyzePartitionContext *ctx) override {
    AlterByAnalyzePartitionContextProxy proxy(ctx);
    return getSelf().call("visit_alter_by_analyze_partition", &proxy);
  }

  virtual antlrcpp::Any visitAlterByCheckPartition(MySqlParser::AlterByCheckPartitionContext *ctx) override {
    AlterByCheckPartitionContextProxy proxy(ctx);
    return getSelf().call("visit_alter_by_check_partition", &proxy);
  }

  virtual antlrcpp::Any visitAlterByOptimizePartition(MySqlParser::AlterByOptimizePartitionContext *ctx) override {
    AlterByOptimizePartitionContextProxy proxy(ctx);
    return getSelf().call("visit_alter_by_optimize_partition", &proxy);
  }

  virtual antlrcpp::Any visitAlterByRebuildPartition(MySqlParser::AlterByRebuildPartitionContext *ctx) override {
    AlterByRebuildPartitionContextProxy proxy(ctx);
    return getSelf().call("visit_alter_by_rebuild_partition", &proxy);
  }

  virtual antlrcpp::Any visitAlterByRepairPartition(MySqlParser::AlterByRepairPartitionContext *ctx) override {
    AlterByRepairPartitionContextProxy proxy(ctx);
    return getSelf().call("visit_alter_by_repair_partition", &proxy);
  }

  virtual antlrcpp::Any visitAlterByRemovePartitioning(MySqlParser::AlterByRemovePartitioningContext *ctx) override {
    AlterByRemovePartitioningContextProxy proxy(ctx);
    return getSelf().call("visit_alter_by_remove_partitioning", &proxy);
  }

  virtual antlrcpp::Any visitAlterByUpgradePartitioning(MySqlParser::AlterByUpgradePartitioningContext *ctx) override {
    AlterByUpgradePartitioningContextProxy proxy(ctx);
    return getSelf().call("visit_alter_by_upgrade_partitioning", &proxy);
  }

  virtual antlrcpp::Any visitDropDatabase(MySqlParser::DropDatabaseContext *ctx) override {
    DropDatabaseContextProxy proxy(ctx);
    return getSelf().call("visit_drop_database", &proxy);
  }

  virtual antlrcpp::Any visitDropEvent(MySqlParser::DropEventContext *ctx) override {
    DropEventContextProxy proxy(ctx);
    return getSelf().call("visit_drop_event", &proxy);
  }

  virtual antlrcpp::Any visitDropIndex(MySqlParser::DropIndexContext *ctx) override {
    DropIndexContextProxy proxy(ctx);
    return getSelf().call("visit_drop_index", &proxy);
  }

  virtual antlrcpp::Any visitDropLogfileGroup(MySqlParser::DropLogfileGroupContext *ctx) override {
    DropLogfileGroupContextProxy proxy(ctx);
    return getSelf().call("visit_drop_logfile_group", &proxy);
  }

  virtual antlrcpp::Any visitDropProcedure(MySqlParser::DropProcedureContext *ctx) override {
    DropProcedureContextProxy proxy(ctx);
    return getSelf().call("visit_drop_procedure", &proxy);
  }

  virtual antlrcpp::Any visitDropFunction(MySqlParser::DropFunctionContext *ctx) override {
    DropFunctionContextProxy proxy(ctx);
    return getSelf().call("visit_drop_function", &proxy);
  }

  virtual antlrcpp::Any visitDropServer(MySqlParser::DropServerContext *ctx) override {
    DropServerContextProxy proxy(ctx);
    return getSelf().call("visit_drop_server", &proxy);
  }

  virtual antlrcpp::Any visitDropTable(MySqlParser::DropTableContext *ctx) override {
    DropTableContextProxy proxy(ctx);
    return getSelf().call("visit_drop_table", &proxy);
  }

  virtual antlrcpp::Any visitDropTablespace(MySqlParser::DropTablespaceContext *ctx) override {
    DropTablespaceContextProxy proxy(ctx);
    return getSelf().call("visit_drop_tablespace", &proxy);
  }

  virtual antlrcpp::Any visitDropTrigger(MySqlParser::DropTriggerContext *ctx) override {
    DropTriggerContextProxy proxy(ctx);
    return getSelf().call("visit_drop_trigger", &proxy);
  }

  virtual antlrcpp::Any visitDropView(MySqlParser::DropViewContext *ctx) override {
    DropViewContextProxy proxy(ctx);
    return getSelf().call("visit_drop_view", &proxy);
  }

  virtual antlrcpp::Any visitRenameTable(MySqlParser::RenameTableContext *ctx) override {
    RenameTableContextProxy proxy(ctx);
    return getSelf().call("visit_rename_table", &proxy);
  }

  virtual antlrcpp::Any visitRenameTableClause(MySqlParser::RenameTableClauseContext *ctx) override {
    RenameTableClauseContextProxy proxy(ctx);
    return getSelf().call("visit_rename_table_clause", &proxy);
  }

  virtual antlrcpp::Any visitTruncateTable(MySqlParser::TruncateTableContext *ctx) override {
    TruncateTableContextProxy proxy(ctx);
    return getSelf().call("visit_truncate_table", &proxy);
  }

  virtual antlrcpp::Any visitCallStatement(MySqlParser::CallStatementContext *ctx) override {
    CallStatementContextProxy proxy(ctx);
    return getSelf().call("visit_call_statement", &proxy);
  }

  virtual antlrcpp::Any visitDeleteStatement(MySqlParser::DeleteStatementContext *ctx) override {
    DeleteStatementContextProxy proxy(ctx);
    return getSelf().call("visit_delete_statement", &proxy);
  }

  virtual antlrcpp::Any visitDoStatement(MySqlParser::DoStatementContext *ctx) override {
    DoStatementContextProxy proxy(ctx);
    return getSelf().call("visit_do_statement", &proxy);
  }

  virtual antlrcpp::Any visitHandlerStatement(MySqlParser::HandlerStatementContext *ctx) override {
    HandlerStatementContextProxy proxy(ctx);
    return getSelf().call("visit_handler_statement", &proxy);
  }

  virtual antlrcpp::Any visitInsertStatement(MySqlParser::InsertStatementContext *ctx) override {
    InsertStatementContextProxy proxy(ctx);
    return getSelf().call("visit_insert_statement", &proxy);
  }

  virtual antlrcpp::Any visitLoadDataStatement(MySqlParser::LoadDataStatementContext *ctx) override {
    LoadDataStatementContextProxy proxy(ctx);
    return getSelf().call("visit_load_data_statement", &proxy);
  }

  virtual antlrcpp::Any visitLoadXmlStatement(MySqlParser::LoadXmlStatementContext *ctx) override {
    LoadXmlStatementContextProxy proxy(ctx);
    return getSelf().call("visit_load_xml_statement", &proxy);
  }

  virtual antlrcpp::Any visitReplaceStatement(MySqlParser::ReplaceStatementContext *ctx) override {
    ReplaceStatementContextProxy proxy(ctx);
    return getSelf().call("visit_replace_statement", &proxy);
  }

  virtual antlrcpp::Any visitSimpleSelect(MySqlParser::SimpleSelectContext *ctx) override {
    SimpleSelectContextProxy proxy(ctx);
    return getSelf().call("visit_simple_select", &proxy);
  }

  virtual antlrcpp::Any visitParenthesisSelect(MySqlParser::ParenthesisSelectContext *ctx) override {
    ParenthesisSelectContextProxy proxy(ctx);
    return getSelf().call("visit_parenthesis_select", &proxy);
  }

  virtual antlrcpp::Any visitUnionSelect(MySqlParser::UnionSelectContext *ctx) override {
    UnionSelectContextProxy proxy(ctx);
    return getSelf().call("visit_union_select", &proxy);
  }

  virtual antlrcpp::Any visitUnionParenthesisSelect(MySqlParser::UnionParenthesisSelectContext *ctx) override {
    UnionParenthesisSelectContextProxy proxy(ctx);
    return getSelf().call("visit_union_parenthesis_select", &proxy);
  }

  virtual antlrcpp::Any visitUpdateStatement(MySqlParser::UpdateStatementContext *ctx) override {
    UpdateStatementContextProxy proxy(ctx);
    return getSelf().call("visit_update_statement", &proxy);
  }

  virtual antlrcpp::Any visitInsertStatementValue(MySqlParser::InsertStatementValueContext *ctx) override {
    InsertStatementValueContextProxy proxy(ctx);
    return getSelf().call("visit_insert_statement_value", &proxy);
  }

  virtual antlrcpp::Any visitUpdatedElement(MySqlParser::UpdatedElementContext *ctx) override {
    UpdatedElementContextProxy proxy(ctx);
    return getSelf().call("visit_updated_element", &proxy);
  }

  virtual antlrcpp::Any visitAssignmentField(MySqlParser::AssignmentFieldContext *ctx) override {
    AssignmentFieldContextProxy proxy(ctx);
    return getSelf().call("visit_assignment_field", &proxy);
  }

  virtual antlrcpp::Any visitLockClause(MySqlParser::LockClauseContext *ctx) override {
    LockClauseContextProxy proxy(ctx);
    return getSelf().call("visit_lock_clause", &proxy);
  }

  virtual antlrcpp::Any visitSingleDeleteStatement(MySqlParser::SingleDeleteStatementContext *ctx) override {
    SingleDeleteStatementContextProxy proxy(ctx);
    return getSelf().call("visit_single_delete_statement", &proxy);
  }

  virtual antlrcpp::Any visitMultipleDeleteStatement(MySqlParser::MultipleDeleteStatementContext *ctx) override {
    MultipleDeleteStatementContextProxy proxy(ctx);
    return getSelf().call("visit_multiple_delete_statement", &proxy);
  }

  virtual antlrcpp::Any visitHandlerOpenStatement(MySqlParser::HandlerOpenStatementContext *ctx) override {
    HandlerOpenStatementContextProxy proxy(ctx);
    return getSelf().call("visit_handler_open_statement", &proxy);
  }

  virtual antlrcpp::Any visitHandlerReadIndexStatement(MySqlParser::HandlerReadIndexStatementContext *ctx) override {
    HandlerReadIndexStatementContextProxy proxy(ctx);
    return getSelf().call("visit_handler_read_index_statement", &proxy);
  }

  virtual antlrcpp::Any visitHandlerReadStatement(MySqlParser::HandlerReadStatementContext *ctx) override {
    HandlerReadStatementContextProxy proxy(ctx);
    return getSelf().call("visit_handler_read_statement", &proxy);
  }

  virtual antlrcpp::Any visitHandlerCloseStatement(MySqlParser::HandlerCloseStatementContext *ctx) override {
    HandlerCloseStatementContextProxy proxy(ctx);
    return getSelf().call("visit_handler_close_statement", &proxy);
  }

  virtual antlrcpp::Any visitSingleUpdateStatement(MySqlParser::SingleUpdateStatementContext *ctx) override {
    SingleUpdateStatementContextProxy proxy(ctx);
    return getSelf().call("visit_single_update_statement", &proxy);
  }

  virtual antlrcpp::Any visitMultipleUpdateStatement(MySqlParser::MultipleUpdateStatementContext *ctx) override {
    MultipleUpdateStatementContextProxy proxy(ctx);
    return getSelf().call("visit_multiple_update_statement", &proxy);
  }

  virtual antlrcpp::Any visitOrderByClause(MySqlParser::OrderByClauseContext *ctx) override {
    OrderByClauseContextProxy proxy(ctx);
    return getSelf().call("visit_order_by_clause", &proxy);
  }

  virtual antlrcpp::Any visitOrderByExpression(MySqlParser::OrderByExpressionContext *ctx) override {
    OrderByExpressionContextProxy proxy(ctx);
    return getSelf().call("visit_order_by_expression", &proxy);
  }

  virtual antlrcpp::Any visitTableSources(MySqlParser::TableSourcesContext *ctx) override {
    TableSourcesContextProxy proxy(ctx);
    return getSelf().call("visit_table_sources", &proxy);
  }

  virtual antlrcpp::Any visitTableSourceBase(MySqlParser::TableSourceBaseContext *ctx) override {
    TableSourceBaseContextProxy proxy(ctx);
    return getSelf().call("visit_table_source_base", &proxy);
  }

  virtual antlrcpp::Any visitTableSourceNested(MySqlParser::TableSourceNestedContext *ctx) override {
    TableSourceNestedContextProxy proxy(ctx);
    return getSelf().call("visit_table_source_nested", &proxy);
  }

  virtual antlrcpp::Any visitAtomTableItem(MySqlParser::AtomTableItemContext *ctx) override {
    AtomTableItemContextProxy proxy(ctx);
    return getSelf().call("visit_atom_table_item", &proxy);
  }

  virtual antlrcpp::Any visitSubqueryTableItem(MySqlParser::SubqueryTableItemContext *ctx) override {
    SubqueryTableItemContextProxy proxy(ctx);
    return getSelf().call("visit_subquery_table_item", &proxy);
  }

  virtual antlrcpp::Any visitTableSourcesItem(MySqlParser::TableSourcesItemContext *ctx) override {
    TableSourcesItemContextProxy proxy(ctx);
    return getSelf().call("visit_table_sources_item", &proxy);
  }

  virtual antlrcpp::Any visitIndexHint(MySqlParser::IndexHintContext *ctx) override {
    IndexHintContextProxy proxy(ctx);
    return getSelf().call("visit_index_hint", &proxy);
  }

  virtual antlrcpp::Any visitIndexHintType(MySqlParser::IndexHintTypeContext *ctx) override {
    IndexHintTypeContextProxy proxy(ctx);
    return getSelf().call("visit_index_hint_type", &proxy);
  }

  virtual antlrcpp::Any visitInnerJoin(MySqlParser::InnerJoinContext *ctx) override {
    InnerJoinContextProxy proxy(ctx);
    return getSelf().call("visit_inner_join", &proxy);
  }

  virtual antlrcpp::Any visitStraightJoin(MySqlParser::StraightJoinContext *ctx) override {
    StraightJoinContextProxy proxy(ctx);
    return getSelf().call("visit_straight_join", &proxy);
  }

  virtual antlrcpp::Any visitOuterJoin(MySqlParser::OuterJoinContext *ctx) override {
    OuterJoinContextProxy proxy(ctx);
    return getSelf().call("visit_outer_join", &proxy);
  }

  virtual antlrcpp::Any visitNaturalJoin(MySqlParser::NaturalJoinContext *ctx) override {
    NaturalJoinContextProxy proxy(ctx);
    return getSelf().call("visit_natural_join", &proxy);
  }

  virtual antlrcpp::Any visitQueryExpression(MySqlParser::QueryExpressionContext *ctx) override {
    QueryExpressionContextProxy proxy(ctx);
    return getSelf().call("visit_query_expression", &proxy);
  }

  virtual antlrcpp::Any visitQueryExpressionNointo(MySqlParser::QueryExpressionNointoContext *ctx) override {
    QueryExpressionNointoContextProxy proxy(ctx);
    return getSelf().call("visit_query_expression_nointo", &proxy);
  }

  virtual antlrcpp::Any visitQuerySpecification(MySqlParser::QuerySpecificationContext *ctx) override {
    QuerySpecificationContextProxy proxy(ctx);
    return getSelf().call("visit_query_specification", &proxy);
  }

  virtual antlrcpp::Any visitQuerySpecificationNointo(MySqlParser::QuerySpecificationNointoContext *ctx) override {
    QuerySpecificationNointoContextProxy proxy(ctx);
    return getSelf().call("visit_query_specification_nointo", &proxy);
  }

  virtual antlrcpp::Any visitUnionParenthesis(MySqlParser::UnionParenthesisContext *ctx) override {
    UnionParenthesisContextProxy proxy(ctx);
    return getSelf().call("visit_union_parenthesis", &proxy);
  }

  virtual antlrcpp::Any visitUnionStatement(MySqlParser::UnionStatementContext *ctx) override {
    UnionStatementContextProxy proxy(ctx);
    return getSelf().call("visit_union_statement", &proxy);
  }

  virtual antlrcpp::Any visitSelectSpec(MySqlParser::SelectSpecContext *ctx) override {
    SelectSpecContextProxy proxy(ctx);
    return getSelf().call("visit_select_spec", &proxy);
  }

  virtual antlrcpp::Any visitSelectElements(MySqlParser::SelectElementsContext *ctx) override {
    SelectElementsContextProxy proxy(ctx);
    return getSelf().call("visit_select_elements", &proxy);
  }

  virtual antlrcpp::Any visitSelectStarElement(MySqlParser::SelectStarElementContext *ctx) override {
    SelectStarElementContextProxy proxy(ctx);
    return getSelf().call("visit_select_star_element", &proxy);
  }

  virtual antlrcpp::Any visitSelectColumnElement(MySqlParser::SelectColumnElementContext *ctx) override {
    SelectColumnElementContextProxy proxy(ctx);
    return getSelf().call("visit_select_column_element", &proxy);
  }

  virtual antlrcpp::Any visitSelectFunctionElement(MySqlParser::SelectFunctionElementContext *ctx) override {
    SelectFunctionElementContextProxy proxy(ctx);
    return getSelf().call("visit_select_function_element", &proxy);
  }

  virtual antlrcpp::Any visitSelectExpressionElement(MySqlParser::SelectExpressionElementContext *ctx) override {
    SelectExpressionElementContextProxy proxy(ctx);
    return getSelf().call("visit_select_expression_element", &proxy);
  }

  virtual antlrcpp::Any visitSelectIntoVariables(MySqlParser::SelectIntoVariablesContext *ctx) override {
    SelectIntoVariablesContextProxy proxy(ctx);
    return getSelf().call("visit_select_into_variables", &proxy);
  }

  virtual antlrcpp::Any visitSelectIntoDumpFile(MySqlParser::SelectIntoDumpFileContext *ctx) override {
    SelectIntoDumpFileContextProxy proxy(ctx);
    return getSelf().call("visit_select_into_dump_file", &proxy);
  }

  virtual antlrcpp::Any visitSelectIntoTextFile(MySqlParser::SelectIntoTextFileContext *ctx) override {
    SelectIntoTextFileContextProxy proxy(ctx);
    return getSelf().call("visit_select_into_text_file", &proxy);
  }

  virtual antlrcpp::Any visitSelectFieldsInto(MySqlParser::SelectFieldsIntoContext *ctx) override {
    SelectFieldsIntoContextProxy proxy(ctx);
    return getSelf().call("visit_select_fields_into", &proxy);
  }

  virtual antlrcpp::Any visitSelectLinesInto(MySqlParser::SelectLinesIntoContext *ctx) override {
    SelectLinesIntoContextProxy proxy(ctx);
    return getSelf().call("visit_select_lines_into", &proxy);
  }

  virtual antlrcpp::Any visitFromClause(MySqlParser::FromClauseContext *ctx) override {
    FromClauseContextProxy proxy(ctx);
    return getSelf().call("visit_from_clause", &proxy);
  }

  virtual antlrcpp::Any visitGroupByItem(MySqlParser::GroupByItemContext *ctx) override {
    GroupByItemContextProxy proxy(ctx);
    return getSelf().call("visit_group_by_item", &proxy);
  }

  virtual antlrcpp::Any visitLimitClause(MySqlParser::LimitClauseContext *ctx) override {
    LimitClauseContextProxy proxy(ctx);
    return getSelf().call("visit_limit_clause", &proxy);
  }

  virtual antlrcpp::Any visitLimitClauseAtom(MySqlParser::LimitClauseAtomContext *ctx) override {
    LimitClauseAtomContextProxy proxy(ctx);
    return getSelf().call("visit_limit_clause_atom", &proxy);
  }

  virtual antlrcpp::Any visitStartTransaction(MySqlParser::StartTransactionContext *ctx) override {
    StartTransactionContextProxy proxy(ctx);
    return getSelf().call("visit_start_transaction", &proxy);
  }

  virtual antlrcpp::Any visitBeginWork(MySqlParser::BeginWorkContext *ctx) override {
    BeginWorkContextProxy proxy(ctx);
    return getSelf().call("visit_begin_work", &proxy);
  }

  virtual antlrcpp::Any visitCommitWork(MySqlParser::CommitWorkContext *ctx) override {
    CommitWorkContextProxy proxy(ctx);
    return getSelf().call("visit_commit_work", &proxy);
  }

  virtual antlrcpp::Any visitRollbackWork(MySqlParser::RollbackWorkContext *ctx) override {
    RollbackWorkContextProxy proxy(ctx);
    return getSelf().call("visit_rollback_work", &proxy);
  }

  virtual antlrcpp::Any visitSavepointStatement(MySqlParser::SavepointStatementContext *ctx) override {
    SavepointStatementContextProxy proxy(ctx);
    return getSelf().call("visit_savepoint_statement", &proxy);
  }

  virtual antlrcpp::Any visitRollbackStatement(MySqlParser::RollbackStatementContext *ctx) override {
    RollbackStatementContextProxy proxy(ctx);
    return getSelf().call("visit_rollback_statement", &proxy);
  }

  virtual antlrcpp::Any visitReleaseStatement(MySqlParser::ReleaseStatementContext *ctx) override {
    ReleaseStatementContextProxy proxy(ctx);
    return getSelf().call("visit_release_statement", &proxy);
  }

  virtual antlrcpp::Any visitLockTables(MySqlParser::LockTablesContext *ctx) override {
    LockTablesContextProxy proxy(ctx);
    return getSelf().call("visit_lock_tables", &proxy);
  }

  virtual antlrcpp::Any visitUnlockTables(MySqlParser::UnlockTablesContext *ctx) override {
    UnlockTablesContextProxy proxy(ctx);
    return getSelf().call("visit_unlock_tables", &proxy);
  }

  virtual antlrcpp::Any visitSetAutocommitStatement(MySqlParser::SetAutocommitStatementContext *ctx) override {
    SetAutocommitStatementContextProxy proxy(ctx);
    return getSelf().call("visit_set_autocommit_statement", &proxy);
  }

  virtual antlrcpp::Any visitSetTransactionStatement(MySqlParser::SetTransactionStatementContext *ctx) override {
    SetTransactionStatementContextProxy proxy(ctx);
    return getSelf().call("visit_set_transaction_statement", &proxy);
  }

  virtual antlrcpp::Any visitTransactionMode(MySqlParser::TransactionModeContext *ctx) override {
    TransactionModeContextProxy proxy(ctx);
    return getSelf().call("visit_transaction_mode", &proxy);
  }

  virtual antlrcpp::Any visitLockTableElement(MySqlParser::LockTableElementContext *ctx) override {
    LockTableElementContextProxy proxy(ctx);
    return getSelf().call("visit_lock_table_element", &proxy);
  }

  virtual antlrcpp::Any visitLockAction(MySqlParser::LockActionContext *ctx) override {
    LockActionContextProxy proxy(ctx);
    return getSelf().call("visit_lock_action", &proxy);
  }

  virtual antlrcpp::Any visitTransactionOption(MySqlParser::TransactionOptionContext *ctx) override {
    TransactionOptionContextProxy proxy(ctx);
    return getSelf().call("visit_transaction_option", &proxy);
  }

  virtual antlrcpp::Any visitTransactionLevel(MySqlParser::TransactionLevelContext *ctx) override {
    TransactionLevelContextProxy proxy(ctx);
    return getSelf().call("visit_transaction_level", &proxy);
  }

  virtual antlrcpp::Any visitChangeMaster(MySqlParser::ChangeMasterContext *ctx) override {
    ChangeMasterContextProxy proxy(ctx);
    return getSelf().call("visit_change_master", &proxy);
  }

  virtual antlrcpp::Any visitChangeReplicationFilter(MySqlParser::ChangeReplicationFilterContext *ctx) override {
    ChangeReplicationFilterContextProxy proxy(ctx);
    return getSelf().call("visit_change_replication_filter", &proxy);
  }

  virtual antlrcpp::Any visitPurgeBinaryLogs(MySqlParser::PurgeBinaryLogsContext *ctx) override {
    PurgeBinaryLogsContextProxy proxy(ctx);
    return getSelf().call("visit_purge_binary_logs", &proxy);
  }

  virtual antlrcpp::Any visitResetMaster(MySqlParser::ResetMasterContext *ctx) override {
    ResetMasterContextProxy proxy(ctx);
    return getSelf().call("visit_reset_master", &proxy);
  }

  virtual antlrcpp::Any visitResetSlave(MySqlParser::ResetSlaveContext *ctx) override {
    ResetSlaveContextProxy proxy(ctx);
    return getSelf().call("visit_reset_slave", &proxy);
  }

  virtual antlrcpp::Any visitStartSlave(MySqlParser::StartSlaveContext *ctx) override {
    StartSlaveContextProxy proxy(ctx);
    return getSelf().call("visit_start_slave", &proxy);
  }

  virtual antlrcpp::Any visitStopSlave(MySqlParser::StopSlaveContext *ctx) override {
    StopSlaveContextProxy proxy(ctx);
    return getSelf().call("visit_stop_slave", &proxy);
  }

  virtual antlrcpp::Any visitStartGroupReplication(MySqlParser::StartGroupReplicationContext *ctx) override {
    StartGroupReplicationContextProxy proxy(ctx);
    return getSelf().call("visit_start_group_replication", &proxy);
  }

  virtual antlrcpp::Any visitStopGroupReplication(MySqlParser::StopGroupReplicationContext *ctx) override {
    StopGroupReplicationContextProxy proxy(ctx);
    return getSelf().call("visit_stop_group_replication", &proxy);
  }

  virtual antlrcpp::Any visitMasterStringOption(MySqlParser::MasterStringOptionContext *ctx) override {
    MasterStringOptionContextProxy proxy(ctx);
    return getSelf().call("visit_master_string_option", &proxy);
  }

  virtual antlrcpp::Any visitMasterDecimalOption(MySqlParser::MasterDecimalOptionContext *ctx) override {
    MasterDecimalOptionContextProxy proxy(ctx);
    return getSelf().call("visit_master_decimal_option", &proxy);
  }

  virtual antlrcpp::Any visitMasterBoolOption(MySqlParser::MasterBoolOptionContext *ctx) override {
    MasterBoolOptionContextProxy proxy(ctx);
    return getSelf().call("visit_master_bool_option", &proxy);
  }

  virtual antlrcpp::Any visitMasterRealOption(MySqlParser::MasterRealOptionContext *ctx) override {
    MasterRealOptionContextProxy proxy(ctx);
    return getSelf().call("visit_master_real_option", &proxy);
  }

  virtual antlrcpp::Any visitMasterUidListOption(MySqlParser::MasterUidListOptionContext *ctx) override {
    MasterUidListOptionContextProxy proxy(ctx);
    return getSelf().call("visit_master_uid_list_option", &proxy);
  }

  virtual antlrcpp::Any visitStringMasterOption(MySqlParser::StringMasterOptionContext *ctx) override {
    StringMasterOptionContextProxy proxy(ctx);
    return getSelf().call("visit_string_master_option", &proxy);
  }

  virtual antlrcpp::Any visitDecimalMasterOption(MySqlParser::DecimalMasterOptionContext *ctx) override {
    DecimalMasterOptionContextProxy proxy(ctx);
    return getSelf().call("visit_decimal_master_option", &proxy);
  }

  virtual antlrcpp::Any visitBoolMasterOption(MySqlParser::BoolMasterOptionContext *ctx) override {
    BoolMasterOptionContextProxy proxy(ctx);
    return getSelf().call("visit_bool_master_option", &proxy);
  }

  virtual antlrcpp::Any visitChannelOption(MySqlParser::ChannelOptionContext *ctx) override {
    ChannelOptionContextProxy proxy(ctx);
    return getSelf().call("visit_channel_option", &proxy);
  }

  virtual antlrcpp::Any visitDoDbReplication(MySqlParser::DoDbReplicationContext *ctx) override {
    DoDbReplicationContextProxy proxy(ctx);
    return getSelf().call("visit_do_db_replication", &proxy);
  }

  virtual antlrcpp::Any visitIgnoreDbReplication(MySqlParser::IgnoreDbReplicationContext *ctx) override {
    IgnoreDbReplicationContextProxy proxy(ctx);
    return getSelf().call("visit_ignore_db_replication", &proxy);
  }

  virtual antlrcpp::Any visitDoTableReplication(MySqlParser::DoTableReplicationContext *ctx) override {
    DoTableReplicationContextProxy proxy(ctx);
    return getSelf().call("visit_do_table_replication", &proxy);
  }

  virtual antlrcpp::Any visitIgnoreTableReplication(MySqlParser::IgnoreTableReplicationContext *ctx) override {
    IgnoreTableReplicationContextProxy proxy(ctx);
    return getSelf().call("visit_ignore_table_replication", &proxy);
  }

  virtual antlrcpp::Any visitWildDoTableReplication(MySqlParser::WildDoTableReplicationContext *ctx) override {
    WildDoTableReplicationContextProxy proxy(ctx);
    return getSelf().call("visit_wild_do_table_replication", &proxy);
  }

  virtual antlrcpp::Any visitWildIgnoreTableReplication(MySqlParser::WildIgnoreTableReplicationContext *ctx) override {
    WildIgnoreTableReplicationContextProxy proxy(ctx);
    return getSelf().call("visit_wild_ignore_table_replication", &proxy);
  }

  virtual antlrcpp::Any visitRewriteDbReplication(MySqlParser::RewriteDbReplicationContext *ctx) override {
    RewriteDbReplicationContextProxy proxy(ctx);
    return getSelf().call("visit_rewrite_db_replication", &proxy);
  }

  virtual antlrcpp::Any visitTablePair(MySqlParser::TablePairContext *ctx) override {
    TablePairContextProxy proxy(ctx);
    return getSelf().call("visit_table_pair", &proxy);
  }

  virtual antlrcpp::Any visitThreadType(MySqlParser::ThreadTypeContext *ctx) override {
    ThreadTypeContextProxy proxy(ctx);
    return getSelf().call("visit_thread_type", &proxy);
  }

  virtual antlrcpp::Any visitGtidsUntilOption(MySqlParser::GtidsUntilOptionContext *ctx) override {
    GtidsUntilOptionContextProxy proxy(ctx);
    return getSelf().call("visit_gtids_until_option", &proxy);
  }

  virtual antlrcpp::Any visitMasterLogUntilOption(MySqlParser::MasterLogUntilOptionContext *ctx) override {
    MasterLogUntilOptionContextProxy proxy(ctx);
    return getSelf().call("visit_master_log_until_option", &proxy);
  }

  virtual antlrcpp::Any visitRelayLogUntilOption(MySqlParser::RelayLogUntilOptionContext *ctx) override {
    RelayLogUntilOptionContextProxy proxy(ctx);
    return getSelf().call("visit_relay_log_until_option", &proxy);
  }

  virtual antlrcpp::Any visitSqlGapsUntilOption(MySqlParser::SqlGapsUntilOptionContext *ctx) override {
    SqlGapsUntilOptionContextProxy proxy(ctx);
    return getSelf().call("visit_sql_gaps_until_option", &proxy);
  }

  virtual antlrcpp::Any visitUserConnectionOption(MySqlParser::UserConnectionOptionContext *ctx) override {
    UserConnectionOptionContextProxy proxy(ctx);
    return getSelf().call("visit_user_connection_option", &proxy);
  }

  virtual antlrcpp::Any visitPasswordConnectionOption(MySqlParser::PasswordConnectionOptionContext *ctx) override {
    PasswordConnectionOptionContextProxy proxy(ctx);
    return getSelf().call("visit_password_connection_option", &proxy);
  }

  virtual antlrcpp::Any visitDefaultAuthConnectionOption(MySqlParser::DefaultAuthConnectionOptionContext *ctx) override {
    DefaultAuthConnectionOptionContextProxy proxy(ctx);
    return getSelf().call("visit_default_auth_connection_option", &proxy);
  }

  virtual antlrcpp::Any visitPluginDirConnectionOption(MySqlParser::PluginDirConnectionOptionContext *ctx) override {
    PluginDirConnectionOptionContextProxy proxy(ctx);
    return getSelf().call("visit_plugin_dir_connection_option", &proxy);
  }

  virtual antlrcpp::Any visitGtuidSet(MySqlParser::GtuidSetContext *ctx) override {
    GtuidSetContextProxy proxy(ctx);
    return getSelf().call("visit_gtuid_set", &proxy);
  }

  virtual antlrcpp::Any visitXaStartTransaction(MySqlParser::XaStartTransactionContext *ctx) override {
    XaStartTransactionContextProxy proxy(ctx);
    return getSelf().call("visit_xa_start_transaction", &proxy);
  }

  virtual antlrcpp::Any visitXaEndTransaction(MySqlParser::XaEndTransactionContext *ctx) override {
    XaEndTransactionContextProxy proxy(ctx);
    return getSelf().call("visit_xa_end_transaction", &proxy);
  }

  virtual antlrcpp::Any visitXaPrepareStatement(MySqlParser::XaPrepareStatementContext *ctx) override {
    XaPrepareStatementContextProxy proxy(ctx);
    return getSelf().call("visit_xa_prepare_statement", &proxy);
  }

  virtual antlrcpp::Any visitXaCommitWork(MySqlParser::XaCommitWorkContext *ctx) override {
    XaCommitWorkContextProxy proxy(ctx);
    return getSelf().call("visit_xa_commit_work", &proxy);
  }

  virtual antlrcpp::Any visitXaRollbackWork(MySqlParser::XaRollbackWorkContext *ctx) override {
    XaRollbackWorkContextProxy proxy(ctx);
    return getSelf().call("visit_xa_rollback_work", &proxy);
  }

  virtual antlrcpp::Any visitXaRecoverWork(MySqlParser::XaRecoverWorkContext *ctx) override {
    XaRecoverWorkContextProxy proxy(ctx);
    return getSelf().call("visit_xa_recover_work", &proxy);
  }

  virtual antlrcpp::Any visitPrepareStatement(MySqlParser::PrepareStatementContext *ctx) override {
    PrepareStatementContextProxy proxy(ctx);
    return getSelf().call("visit_prepare_statement", &proxy);
  }

  virtual antlrcpp::Any visitExecuteStatement(MySqlParser::ExecuteStatementContext *ctx) override {
    ExecuteStatementContextProxy proxy(ctx);
    return getSelf().call("visit_execute_statement", &proxy);
  }

  virtual antlrcpp::Any visitDeallocatePrepare(MySqlParser::DeallocatePrepareContext *ctx) override {
    DeallocatePrepareContextProxy proxy(ctx);
    return getSelf().call("visit_deallocate_prepare", &proxy);
  }

  virtual antlrcpp::Any visitRoutineBody(MySqlParser::RoutineBodyContext *ctx) override {
    RoutineBodyContextProxy proxy(ctx);
    return getSelf().call("visit_routine_body", &proxy);
  }

  virtual antlrcpp::Any visitBlockStatement(MySqlParser::BlockStatementContext *ctx) override {
    BlockStatementContextProxy proxy(ctx);
    return getSelf().call("visit_block_statement", &proxy);
  }

  virtual antlrcpp::Any visitCaseStatement(MySqlParser::CaseStatementContext *ctx) override {
    CaseStatementContextProxy proxy(ctx);
    return getSelf().call("visit_case_statement", &proxy);
  }

  virtual antlrcpp::Any visitIfStatement(MySqlParser::IfStatementContext *ctx) override {
    IfStatementContextProxy proxy(ctx);
    return getSelf().call("visit_if_statement", &proxy);
  }

  virtual antlrcpp::Any visitIterateStatement(MySqlParser::IterateStatementContext *ctx) override {
    IterateStatementContextProxy proxy(ctx);
    return getSelf().call("visit_iterate_statement", &proxy);
  }

  virtual antlrcpp::Any visitLeaveStatement(MySqlParser::LeaveStatementContext *ctx) override {
    LeaveStatementContextProxy proxy(ctx);
    return getSelf().call("visit_leave_statement", &proxy);
  }

  virtual antlrcpp::Any visitLoopStatement(MySqlParser::LoopStatementContext *ctx) override {
    LoopStatementContextProxy proxy(ctx);
    return getSelf().call("visit_loop_statement", &proxy);
  }

  virtual antlrcpp::Any visitRepeatStatement(MySqlParser::RepeatStatementContext *ctx) override {
    RepeatStatementContextProxy proxy(ctx);
    return getSelf().call("visit_repeat_statement", &proxy);
  }

  virtual antlrcpp::Any visitReturnStatement(MySqlParser::ReturnStatementContext *ctx) override {
    ReturnStatementContextProxy proxy(ctx);
    return getSelf().call("visit_return_statement", &proxy);
  }

  virtual antlrcpp::Any visitWhileStatement(MySqlParser::WhileStatementContext *ctx) override {
    WhileStatementContextProxy proxy(ctx);
    return getSelf().call("visit_while_statement", &proxy);
  }

  virtual antlrcpp::Any visitCloseCursor(MySqlParser::CloseCursorContext *ctx) override {
    CloseCursorContextProxy proxy(ctx);
    return getSelf().call("visit_close_cursor", &proxy);
  }

  virtual antlrcpp::Any visitFetchCursor(MySqlParser::FetchCursorContext *ctx) override {
    FetchCursorContextProxy proxy(ctx);
    return getSelf().call("visit_fetch_cursor", &proxy);
  }

  virtual antlrcpp::Any visitOpenCursor(MySqlParser::OpenCursorContext *ctx) override {
    OpenCursorContextProxy proxy(ctx);
    return getSelf().call("visit_open_cursor", &proxy);
  }

  virtual antlrcpp::Any visitDeclareVariable(MySqlParser::DeclareVariableContext *ctx) override {
    DeclareVariableContextProxy proxy(ctx);
    return getSelf().call("visit_declare_variable", &proxy);
  }

  virtual antlrcpp::Any visitDeclareCondition(MySqlParser::DeclareConditionContext *ctx) override {
    DeclareConditionContextProxy proxy(ctx);
    return getSelf().call("visit_declare_condition", &proxy);
  }

  virtual antlrcpp::Any visitDeclareCursor(MySqlParser::DeclareCursorContext *ctx) override {
    DeclareCursorContextProxy proxy(ctx);
    return getSelf().call("visit_declare_cursor", &proxy);
  }

  virtual antlrcpp::Any visitDeclareHandler(MySqlParser::DeclareHandlerContext *ctx) override {
    DeclareHandlerContextProxy proxy(ctx);
    return getSelf().call("visit_declare_handler", &proxy);
  }

  virtual antlrcpp::Any visitHandlerConditionCode(MySqlParser::HandlerConditionCodeContext *ctx) override {
    HandlerConditionCodeContextProxy proxy(ctx);
    return getSelf().call("visit_handler_condition_code", &proxy);
  }

  virtual antlrcpp::Any visitHandlerConditionState(MySqlParser::HandlerConditionStateContext *ctx) override {
    HandlerConditionStateContextProxy proxy(ctx);
    return getSelf().call("visit_handler_condition_state", &proxy);
  }

  virtual antlrcpp::Any visitHandlerConditionName(MySqlParser::HandlerConditionNameContext *ctx) override {
    HandlerConditionNameContextProxy proxy(ctx);
    return getSelf().call("visit_handler_condition_name", &proxy);
  }

  virtual antlrcpp::Any visitHandlerConditionWarning(MySqlParser::HandlerConditionWarningContext *ctx) override {
    HandlerConditionWarningContextProxy proxy(ctx);
    return getSelf().call("visit_handler_condition_warning", &proxy);
  }

  virtual antlrcpp::Any visitHandlerConditionNotfound(MySqlParser::HandlerConditionNotfoundContext *ctx) override {
    HandlerConditionNotfoundContextProxy proxy(ctx);
    return getSelf().call("visit_handler_condition_notfound", &proxy);
  }

  virtual antlrcpp::Any visitHandlerConditionException(MySqlParser::HandlerConditionExceptionContext *ctx) override {
    HandlerConditionExceptionContextProxy proxy(ctx);
    return getSelf().call("visit_handler_condition_exception", &proxy);
  }

  virtual antlrcpp::Any visitProcedureSqlStatement(MySqlParser::ProcedureSqlStatementContext *ctx) override {
    ProcedureSqlStatementContextProxy proxy(ctx);
    return getSelf().call("visit_procedure_sql_statement", &proxy);
  }

  virtual antlrcpp::Any visitCaseAlternative(MySqlParser::CaseAlternativeContext *ctx) override {
    CaseAlternativeContextProxy proxy(ctx);
    return getSelf().call("visit_case_alternative", &proxy);
  }

  virtual antlrcpp::Any visitElifAlternative(MySqlParser::ElifAlternativeContext *ctx) override {
    ElifAlternativeContextProxy proxy(ctx);
    return getSelf().call("visit_elif_alternative", &proxy);
  }

  virtual antlrcpp::Any visitAlterUserMysqlV56(MySqlParser::AlterUserMysqlV56Context *ctx) override {
    AlterUserMysqlV56ContextProxy proxy(ctx);
    return getSelf().call("visit_alter_user_mysql_v56", &proxy);
  }

  virtual antlrcpp::Any visitAlterUserMysqlV57(MySqlParser::AlterUserMysqlV57Context *ctx) override {
    AlterUserMysqlV57ContextProxy proxy(ctx);
    return getSelf().call("visit_alter_user_mysql_v57", &proxy);
  }

  virtual antlrcpp::Any visitCreateUserMysqlV56(MySqlParser::CreateUserMysqlV56Context *ctx) override {
    CreateUserMysqlV56ContextProxy proxy(ctx);
    return getSelf().call("visit_create_user_mysql_v56", &proxy);
  }

  virtual antlrcpp::Any visitCreateUserMysqlV57(MySqlParser::CreateUserMysqlV57Context *ctx) override {
    CreateUserMysqlV57ContextProxy proxy(ctx);
    return getSelf().call("visit_create_user_mysql_v57", &proxy);
  }

  virtual antlrcpp::Any visitDropUser(MySqlParser::DropUserContext *ctx) override {
    DropUserContextProxy proxy(ctx);
    return getSelf().call("visit_drop_user", &proxy);
  }

  virtual antlrcpp::Any visitGrantStatement(MySqlParser::GrantStatementContext *ctx) override {
    GrantStatementContextProxy proxy(ctx);
    return getSelf().call("visit_grant_statement", &proxy);
  }

  virtual antlrcpp::Any visitGrantProxy(MySqlParser::GrantProxyContext *ctx) override {
    GrantProxyContextProxy proxy(ctx);
    return getSelf().call("visit_grant_proxy", &proxy);
  }

  virtual antlrcpp::Any visitRenameUser(MySqlParser::RenameUserContext *ctx) override {
    RenameUserContextProxy proxy(ctx);
    return getSelf().call("visit_rename_user", &proxy);
  }

  virtual antlrcpp::Any visitDetailRevoke(MySqlParser::DetailRevokeContext *ctx) override {
    DetailRevokeContextProxy proxy(ctx);
    return getSelf().call("visit_detail_revoke", &proxy);
  }

  virtual antlrcpp::Any visitShortRevoke(MySqlParser::ShortRevokeContext *ctx) override {
    ShortRevokeContextProxy proxy(ctx);
    return getSelf().call("visit_short_revoke", &proxy);
  }

  virtual antlrcpp::Any visitRevokeProxy(MySqlParser::RevokeProxyContext *ctx) override {
    RevokeProxyContextProxy proxy(ctx);
    return getSelf().call("visit_revoke_proxy", &proxy);
  }

  virtual antlrcpp::Any visitSetPasswordStatement(MySqlParser::SetPasswordStatementContext *ctx) override {
    SetPasswordStatementContextProxy proxy(ctx);
    return getSelf().call("visit_set_password_statement", &proxy);
  }

  virtual antlrcpp::Any visitUserSpecification(MySqlParser::UserSpecificationContext *ctx) override {
    UserSpecificationContextProxy proxy(ctx);
    return getSelf().call("visit_user_specification", &proxy);
  }

  virtual antlrcpp::Any visitPasswordAuthOption(MySqlParser::PasswordAuthOptionContext *ctx) override {
    PasswordAuthOptionContextProxy proxy(ctx);
    return getSelf().call("visit_password_auth_option", &proxy);
  }

  virtual antlrcpp::Any visitStringAuthOption(MySqlParser::StringAuthOptionContext *ctx) override {
    StringAuthOptionContextProxy proxy(ctx);
    return getSelf().call("visit_string_auth_option", &proxy);
  }

  virtual antlrcpp::Any visitHashAuthOption(MySqlParser::HashAuthOptionContext *ctx) override {
    HashAuthOptionContextProxy proxy(ctx);
    return getSelf().call("visit_hash_auth_option", &proxy);
  }

  virtual antlrcpp::Any visitSimpleAuthOption(MySqlParser::SimpleAuthOptionContext *ctx) override {
    SimpleAuthOptionContextProxy proxy(ctx);
    return getSelf().call("visit_simple_auth_option", &proxy);
  }

  virtual antlrcpp::Any visitTlsOption(MySqlParser::TlsOptionContext *ctx) override {
    TlsOptionContextProxy proxy(ctx);
    return getSelf().call("visit_tls_option", &proxy);
  }

  virtual antlrcpp::Any visitUserResourceOption(MySqlParser::UserResourceOptionContext *ctx) override {
    UserResourceOptionContextProxy proxy(ctx);
    return getSelf().call("visit_user_resource_option", &proxy);
  }

  virtual antlrcpp::Any visitUserPasswordOption(MySqlParser::UserPasswordOptionContext *ctx) override {
    UserPasswordOptionContextProxy proxy(ctx);
    return getSelf().call("visit_user_password_option", &proxy);
  }

  virtual antlrcpp::Any visitUserLockOption(MySqlParser::UserLockOptionContext *ctx) override {
    UserLockOptionContextProxy proxy(ctx);
    return getSelf().call("visit_user_lock_option", &proxy);
  }

  virtual antlrcpp::Any visitPrivelegeClause(MySqlParser::PrivelegeClauseContext *ctx) override {
    PrivelegeClauseContextProxy proxy(ctx);
    return getSelf().call("visit_privelege_clause", &proxy);
  }

  virtual antlrcpp::Any visitPrivilege(MySqlParser::PrivilegeContext *ctx) override {
    PrivilegeContextProxy proxy(ctx);
    return getSelf().call("visit_privilege", &proxy);
  }

  virtual antlrcpp::Any visitCurrentSchemaPriviLevel(MySqlParser::CurrentSchemaPriviLevelContext *ctx) override {
    CurrentSchemaPriviLevelContextProxy proxy(ctx);
    return getSelf().call("visit_current_schema_privi_level", &proxy);
  }

  virtual antlrcpp::Any visitGlobalPrivLevel(MySqlParser::GlobalPrivLevelContext *ctx) override {
    GlobalPrivLevelContextProxy proxy(ctx);
    return getSelf().call("visit_global_priv_level", &proxy);
  }

  virtual antlrcpp::Any visitDefiniteSchemaPrivLevel(MySqlParser::DefiniteSchemaPrivLevelContext *ctx) override {
    DefiniteSchemaPrivLevelContextProxy proxy(ctx);
    return getSelf().call("visit_definite_schema_priv_level", &proxy);
  }

  virtual antlrcpp::Any visitDefiniteFullTablePrivLevel(MySqlParser::DefiniteFullTablePrivLevelContext *ctx) override {
    DefiniteFullTablePrivLevelContextProxy proxy(ctx);
    return getSelf().call("visit_definite_full_table_priv_level", &proxy);
  }

  virtual antlrcpp::Any visitDefiniteFullTablePrivLevel2(MySqlParser::DefiniteFullTablePrivLevel2Context *ctx) override {
    DefiniteFullTablePrivLevel2ContextProxy proxy(ctx);
    return getSelf().call("visit_definite_full_table_priv_level2", &proxy);
  }

  virtual antlrcpp::Any visitDefiniteTablePrivLevel(MySqlParser::DefiniteTablePrivLevelContext *ctx) override {
    DefiniteTablePrivLevelContextProxy proxy(ctx);
    return getSelf().call("visit_definite_table_priv_level", &proxy);
  }

  virtual antlrcpp::Any visitRenameUserClause(MySqlParser::RenameUserClauseContext *ctx) override {
    RenameUserClauseContextProxy proxy(ctx);
    return getSelf().call("visit_rename_user_clause", &proxy);
  }

  virtual antlrcpp::Any visitAnalyzeTable(MySqlParser::AnalyzeTableContext *ctx) override {
    AnalyzeTableContextProxy proxy(ctx);
    return getSelf().call("visit_analyze_table", &proxy);
  }

  virtual antlrcpp::Any visitCheckTable(MySqlParser::CheckTableContext *ctx) override {
    CheckTableContextProxy proxy(ctx);
    return getSelf().call("visit_check_table", &proxy);
  }

  virtual antlrcpp::Any visitChecksumTable(MySqlParser::ChecksumTableContext *ctx) override {
    ChecksumTableContextProxy proxy(ctx);
    return getSelf().call("visit_checksum_table", &proxy);
  }

  virtual antlrcpp::Any visitOptimizeTable(MySqlParser::OptimizeTableContext *ctx) override {
    OptimizeTableContextProxy proxy(ctx);
    return getSelf().call("visit_optimize_table", &proxy);
  }

  virtual antlrcpp::Any visitRepairTable(MySqlParser::RepairTableContext *ctx) override {
    RepairTableContextProxy proxy(ctx);
    return getSelf().call("visit_repair_table", &proxy);
  }

  virtual antlrcpp::Any visitCheckTableOption(MySqlParser::CheckTableOptionContext *ctx) override {
    CheckTableOptionContextProxy proxy(ctx);
    return getSelf().call("visit_check_table_option", &proxy);
  }

  virtual antlrcpp::Any visitCreateUdfunction(MySqlParser::CreateUdfunctionContext *ctx) override {
    CreateUdfunctionContextProxy proxy(ctx);
    return getSelf().call("visit_create_udfunction", &proxy);
  }

  virtual antlrcpp::Any visitInstallPlugin(MySqlParser::InstallPluginContext *ctx) override {
    InstallPluginContextProxy proxy(ctx);
    return getSelf().call("visit_install_plugin", &proxy);
  }

  virtual antlrcpp::Any visitUninstallPlugin(MySqlParser::UninstallPluginContext *ctx) override {
    UninstallPluginContextProxy proxy(ctx);
    return getSelf().call("visit_uninstall_plugin", &proxy);
  }

  virtual antlrcpp::Any visitSetVariable(MySqlParser::SetVariableContext *ctx) override {
    SetVariableContextProxy proxy(ctx);
    return getSelf().call("visit_set_variable", &proxy);
  }

  virtual antlrcpp::Any visitSetCharset(MySqlParser::SetCharsetContext *ctx) override {
    SetCharsetContextProxy proxy(ctx);
    return getSelf().call("visit_set_charset", &proxy);
  }

  virtual antlrcpp::Any visitSetNames(MySqlParser::SetNamesContext *ctx) override {
    SetNamesContextProxy proxy(ctx);
    return getSelf().call("visit_set_names", &proxy);
  }

  virtual antlrcpp::Any visitSetPassword(MySqlParser::SetPasswordContext *ctx) override {
    SetPasswordContextProxy proxy(ctx);
    return getSelf().call("visit_set_password", &proxy);
  }

  virtual antlrcpp::Any visitSetTransaction(MySqlParser::SetTransactionContext *ctx) override {
    SetTransactionContextProxy proxy(ctx);
    return getSelf().call("visit_set_transaction", &proxy);
  }

  virtual antlrcpp::Any visitSetAutocommit(MySqlParser::SetAutocommitContext *ctx) override {
    SetAutocommitContextProxy proxy(ctx);
    return getSelf().call("visit_set_autocommit", &proxy);
  }

  virtual antlrcpp::Any visitSetNewValueInsideTrigger(MySqlParser::SetNewValueInsideTriggerContext *ctx) override {
    SetNewValueInsideTriggerContextProxy proxy(ctx);
    return getSelf().call("visit_set_new_value_inside_trigger", &proxy);
  }

  virtual antlrcpp::Any visitShowMasterLogs(MySqlParser::ShowMasterLogsContext *ctx) override {
    ShowMasterLogsContextProxy proxy(ctx);
    return getSelf().call("visit_show_master_logs", &proxy);
  }

  virtual antlrcpp::Any visitShowLogEvents(MySqlParser::ShowLogEventsContext *ctx) override {
    ShowLogEventsContextProxy proxy(ctx);
    return getSelf().call("visit_show_log_events", &proxy);
  }

  virtual antlrcpp::Any visitShowObjectFilter(MySqlParser::ShowObjectFilterContext *ctx) override {
    ShowObjectFilterContextProxy proxy(ctx);
    return getSelf().call("visit_show_object_filter", &proxy);
  }

  virtual antlrcpp::Any visitShowColumns(MySqlParser::ShowColumnsContext *ctx) override {
    ShowColumnsContextProxy proxy(ctx);
    return getSelf().call("visit_show_columns", &proxy);
  }

  virtual antlrcpp::Any visitShowCreateDb(MySqlParser::ShowCreateDbContext *ctx) override {
    ShowCreateDbContextProxy proxy(ctx);
    return getSelf().call("visit_show_create_db", &proxy);
  }

  virtual antlrcpp::Any visitShowCreateFullIdObject(MySqlParser::ShowCreateFullIdObjectContext *ctx) override {
    ShowCreateFullIdObjectContextProxy proxy(ctx);
    return getSelf().call("visit_show_create_full_id_object", &proxy);
  }

  virtual antlrcpp::Any visitShowCreateUser(MySqlParser::ShowCreateUserContext *ctx) override {
    ShowCreateUserContextProxy proxy(ctx);
    return getSelf().call("visit_show_create_user", &proxy);
  }

  virtual antlrcpp::Any visitShowEngine(MySqlParser::ShowEngineContext *ctx) override {
    ShowEngineContextProxy proxy(ctx);
    return getSelf().call("visit_show_engine", &proxy);
  }

  virtual antlrcpp::Any visitShowGlobalInfo(MySqlParser::ShowGlobalInfoContext *ctx) override {
    ShowGlobalInfoContextProxy proxy(ctx);
    return getSelf().call("visit_show_global_info", &proxy);
  }

  virtual antlrcpp::Any visitShowErrors(MySqlParser::ShowErrorsContext *ctx) override {
    ShowErrorsContextProxy proxy(ctx);
    return getSelf().call("visit_show_errors", &proxy);
  }

  virtual antlrcpp::Any visitShowCountErrors(MySqlParser::ShowCountErrorsContext *ctx) override {
    ShowCountErrorsContextProxy proxy(ctx);
    return getSelf().call("visit_show_count_errors", &proxy);
  }

  virtual antlrcpp::Any visitShowSchemaFilter(MySqlParser::ShowSchemaFilterContext *ctx) override {
    ShowSchemaFilterContextProxy proxy(ctx);
    return getSelf().call("visit_show_schema_filter", &proxy);
  }

  virtual antlrcpp::Any visitShowRoutine(MySqlParser::ShowRoutineContext *ctx) override {
    ShowRoutineContextProxy proxy(ctx);
    return getSelf().call("visit_show_routine", &proxy);
  }

  virtual antlrcpp::Any visitShowGrants(MySqlParser::ShowGrantsContext *ctx) override {
    ShowGrantsContextProxy proxy(ctx);
    return getSelf().call("visit_show_grants", &proxy);
  }

  virtual antlrcpp::Any visitShowIndexes(MySqlParser::ShowIndexesContext *ctx) override {
    ShowIndexesContextProxy proxy(ctx);
    return getSelf().call("visit_show_indexes", &proxy);
  }

  virtual antlrcpp::Any visitShowOpenTables(MySqlParser::ShowOpenTablesContext *ctx) override {
    ShowOpenTablesContextProxy proxy(ctx);
    return getSelf().call("visit_show_open_tables", &proxy);
  }

  virtual antlrcpp::Any visitShowProfile(MySqlParser::ShowProfileContext *ctx) override {
    ShowProfileContextProxy proxy(ctx);
    return getSelf().call("visit_show_profile", &proxy);
  }

  virtual antlrcpp::Any visitShowSlaveStatus(MySqlParser::ShowSlaveStatusContext *ctx) override {
    ShowSlaveStatusContextProxy proxy(ctx);
    return getSelf().call("visit_show_slave_status", &proxy);
  }

  virtual antlrcpp::Any visitVariableClause(MySqlParser::VariableClauseContext *ctx) override {
    VariableClauseContextProxy proxy(ctx);
    return getSelf().call("visit_variable_clause", &proxy);
  }

  virtual antlrcpp::Any visitShowCommonEntity(MySqlParser::ShowCommonEntityContext *ctx) override {
    ShowCommonEntityContextProxy proxy(ctx);
    return getSelf().call("visit_show_common_entity", &proxy);
  }

  virtual antlrcpp::Any visitShowFilter(MySqlParser::ShowFilterContext *ctx) override {
    ShowFilterContextProxy proxy(ctx);
    return getSelf().call("visit_show_filter", &proxy);
  }

  virtual antlrcpp::Any visitShowGlobalInfoClause(MySqlParser::ShowGlobalInfoClauseContext *ctx) override {
    ShowGlobalInfoClauseContextProxy proxy(ctx);
    return getSelf().call("visit_show_global_info_clause", &proxy);
  }

  virtual antlrcpp::Any visitShowSchemaEntity(MySqlParser::ShowSchemaEntityContext *ctx) override {
    ShowSchemaEntityContextProxy proxy(ctx);
    return getSelf().call("visit_show_schema_entity", &proxy);
  }

  virtual antlrcpp::Any visitShowProfileType(MySqlParser::ShowProfileTypeContext *ctx) override {
    ShowProfileTypeContextProxy proxy(ctx);
    return getSelf().call("visit_show_profile_type", &proxy);
  }

  virtual antlrcpp::Any visitBinlogStatement(MySqlParser::BinlogStatementContext *ctx) override {
    BinlogStatementContextProxy proxy(ctx);
    return getSelf().call("visit_binlog_statement", &proxy);
  }

  virtual antlrcpp::Any visitCacheIndexStatement(MySqlParser::CacheIndexStatementContext *ctx) override {
    CacheIndexStatementContextProxy proxy(ctx);
    return getSelf().call("visit_cache_index_statement", &proxy);
  }

  virtual antlrcpp::Any visitFlushStatement(MySqlParser::FlushStatementContext *ctx) override {
    FlushStatementContextProxy proxy(ctx);
    return getSelf().call("visit_flush_statement", &proxy);
  }

  virtual antlrcpp::Any visitKillStatement(MySqlParser::KillStatementContext *ctx) override {
    KillStatementContextProxy proxy(ctx);
    return getSelf().call("visit_kill_statement", &proxy);
  }

  virtual antlrcpp::Any visitLoadIndexIntoCache(MySqlParser::LoadIndexIntoCacheContext *ctx) override {
    LoadIndexIntoCacheContextProxy proxy(ctx);
    return getSelf().call("visit_load_index_into_cache", &proxy);
  }

  virtual antlrcpp::Any visitResetStatement(MySqlParser::ResetStatementContext *ctx) override {
    ResetStatementContextProxy proxy(ctx);
    return getSelf().call("visit_reset_statement", &proxy);
  }

  virtual antlrcpp::Any visitShutdownStatement(MySqlParser::ShutdownStatementContext *ctx) override {
    ShutdownStatementContextProxy proxy(ctx);
    return getSelf().call("visit_shutdown_statement", &proxy);
  }

  virtual antlrcpp::Any visitTableIndexes(MySqlParser::TableIndexesContext *ctx) override {
    TableIndexesContextProxy proxy(ctx);
    return getSelf().call("visit_table_indexes", &proxy);
  }

  virtual antlrcpp::Any visitSimpleFlushOption(MySqlParser::SimpleFlushOptionContext *ctx) override {
    SimpleFlushOptionContextProxy proxy(ctx);
    return getSelf().call("visit_simple_flush_option", &proxy);
  }

  virtual antlrcpp::Any visitChannelFlushOption(MySqlParser::ChannelFlushOptionContext *ctx) override {
    ChannelFlushOptionContextProxy proxy(ctx);
    return getSelf().call("visit_channel_flush_option", &proxy);
  }

  virtual antlrcpp::Any visitTableFlushOption(MySqlParser::TableFlushOptionContext *ctx) override {
    TableFlushOptionContextProxy proxy(ctx);
    return getSelf().call("visit_table_flush_option", &proxy);
  }

  virtual antlrcpp::Any visitFlushTableOption(MySqlParser::FlushTableOptionContext *ctx) override {
    FlushTableOptionContextProxy proxy(ctx);
    return getSelf().call("visit_flush_table_option", &proxy);
  }

  virtual antlrcpp::Any visitLoadedTableIndexes(MySqlParser::LoadedTableIndexesContext *ctx) override {
    LoadedTableIndexesContextProxy proxy(ctx);
    return getSelf().call("visit_loaded_table_indexes", &proxy);
  }

  virtual antlrcpp::Any visitSimpleDescribeStatement(MySqlParser::SimpleDescribeStatementContext *ctx) override {
    SimpleDescribeStatementContextProxy proxy(ctx);
    return getSelf().call("visit_simple_describe_statement", &proxy);
  }

  virtual antlrcpp::Any visitFullDescribeStatement(MySqlParser::FullDescribeStatementContext *ctx) override {
    FullDescribeStatementContextProxy proxy(ctx);
    return getSelf().call("visit_full_describe_statement", &proxy);
  }

  virtual antlrcpp::Any visitHelpStatement(MySqlParser::HelpStatementContext *ctx) override {
    HelpStatementContextProxy proxy(ctx);
    return getSelf().call("visit_help_statement", &proxy);
  }

  virtual antlrcpp::Any visitUseStatement(MySqlParser::UseStatementContext *ctx) override {
    UseStatementContextProxy proxy(ctx);
    return getSelf().call("visit_use_statement", &proxy);
  }

  virtual antlrcpp::Any visitSignalStatement(MySqlParser::SignalStatementContext *ctx) override {
    SignalStatementContextProxy proxy(ctx);
    return getSelf().call("visit_signal_statement", &proxy);
  }

  virtual antlrcpp::Any visitResignalStatement(MySqlParser::ResignalStatementContext *ctx) override {
    ResignalStatementContextProxy proxy(ctx);
    return getSelf().call("visit_resignal_statement", &proxy);
  }

  virtual antlrcpp::Any visitSignalConditionInformation(MySqlParser::SignalConditionInformationContext *ctx) override {
    SignalConditionInformationContextProxy proxy(ctx);
    return getSelf().call("visit_signal_condition_information", &proxy);
  }

  virtual antlrcpp::Any visitDiagnosticsStatement(MySqlParser::DiagnosticsStatementContext *ctx) override {
    DiagnosticsStatementContextProxy proxy(ctx);
    return getSelf().call("visit_diagnostics_statement", &proxy);
  }

  virtual antlrcpp::Any visitDiagnosticsConditionInformationName(MySqlParser::DiagnosticsConditionInformationNameContext *ctx) override {
    DiagnosticsConditionInformationNameContextProxy proxy(ctx);
    return getSelf().call("visit_diagnostics_condition_information_name", &proxy);
  }

  virtual antlrcpp::Any visitDescribeStatements(MySqlParser::DescribeStatementsContext *ctx) override {
    DescribeStatementsContextProxy proxy(ctx);
    return getSelf().call("visit_describe_statements", &proxy);
  }

  virtual antlrcpp::Any visitDescribeConnection(MySqlParser::DescribeConnectionContext *ctx) override {
    DescribeConnectionContextProxy proxy(ctx);
    return getSelf().call("visit_describe_connection", &proxy);
  }

  virtual antlrcpp::Any visitFullId(MySqlParser::FullIdContext *ctx) override {
    FullIdContextProxy proxy(ctx);
    return getSelf().call("visit_full_id", &proxy);
  }

  virtual antlrcpp::Any visitTableName(MySqlParser::TableNameContext *ctx) override {
    TableNameContextProxy proxy(ctx);
    return getSelf().call("visit_table_name", &proxy);
  }

  virtual antlrcpp::Any visitFullColumnName(MySqlParser::FullColumnNameContext *ctx) override {
    FullColumnNameContextProxy proxy(ctx);
    return getSelf().call("visit_full_column_name", &proxy);
  }

  virtual antlrcpp::Any visitIndexColumnName(MySqlParser::IndexColumnNameContext *ctx) override {
    IndexColumnNameContextProxy proxy(ctx);
    return getSelf().call("visit_index_column_name", &proxy);
  }

  virtual antlrcpp::Any visitUserName(MySqlParser::UserNameContext *ctx) override {
    UserNameContextProxy proxy(ctx);
    return getSelf().call("visit_user_name", &proxy);
  }

  virtual antlrcpp::Any visitMysqlVariable(MySqlParser::MysqlVariableContext *ctx) override {
    MysqlVariableContextProxy proxy(ctx);
    return getSelf().call("visit_mysql_variable", &proxy);
  }

  virtual antlrcpp::Any visitCharsetName(MySqlParser::CharsetNameContext *ctx) override {
    CharsetNameContextProxy proxy(ctx);
    return getSelf().call("visit_charset_name", &proxy);
  }

  virtual antlrcpp::Any visitCollationName(MySqlParser::CollationNameContext *ctx) override {
    CollationNameContextProxy proxy(ctx);
    return getSelf().call("visit_collation_name", &proxy);
  }

  virtual antlrcpp::Any visitEngineName(MySqlParser::EngineNameContext *ctx) override {
    EngineNameContextProxy proxy(ctx);
    return getSelf().call("visit_engine_name", &proxy);
  }

  virtual antlrcpp::Any visitUuidSet(MySqlParser::UuidSetContext *ctx) override {
    UuidSetContextProxy proxy(ctx);
    return getSelf().call("visit_uuid_set", &proxy);
  }

  virtual antlrcpp::Any visitXid(MySqlParser::XidContext *ctx) override {
    XidContextProxy proxy(ctx);
    return getSelf().call("visit_xid", &proxy);
  }

  virtual antlrcpp::Any visitXuidStringId(MySqlParser::XuidStringIdContext *ctx) override {
    XuidStringIdContextProxy proxy(ctx);
    return getSelf().call("visit_xuid_string_id", &proxy);
  }

  virtual antlrcpp::Any visitAuthPlugin(MySqlParser::AuthPluginContext *ctx) override {
    AuthPluginContextProxy proxy(ctx);
    return getSelf().call("visit_auth_plugin", &proxy);
  }

  virtual antlrcpp::Any visitUid(MySqlParser::UidContext *ctx) override {
    UidContextProxy proxy(ctx);
    return getSelf().call("visit_uid", &proxy);
  }

  virtual antlrcpp::Any visitSimpleId(MySqlParser::SimpleIdContext *ctx) override {
    SimpleIdContextProxy proxy(ctx);
    return getSelf().call("visit_simple_id", &proxy);
  }

  virtual antlrcpp::Any visitDottedId(MySqlParser::DottedIdContext *ctx) override {
    DottedIdContextProxy proxy(ctx);
    return getSelf().call("visit_dotted_id", &proxy);
  }

  virtual antlrcpp::Any visitDecimalLiteral(MySqlParser::DecimalLiteralContext *ctx) override {
    DecimalLiteralContextProxy proxy(ctx);
    return getSelf().call("visit_decimal_literal", &proxy);
  }

  virtual antlrcpp::Any visitFileSizeLiteral(MySqlParser::FileSizeLiteralContext *ctx) override {
    FileSizeLiteralContextProxy proxy(ctx);
    return getSelf().call("visit_file_size_literal", &proxy);
  }

  virtual antlrcpp::Any visitStringLiteral(MySqlParser::StringLiteralContext *ctx) override {
    StringLiteralContextProxy proxy(ctx);
    return getSelf().call("visit_string_literal", &proxy);
  }

  virtual antlrcpp::Any visitBooleanLiteral(MySqlParser::BooleanLiteralContext *ctx) override {
    BooleanLiteralContextProxy proxy(ctx);
    return getSelf().call("visit_boolean_literal", &proxy);
  }

  virtual antlrcpp::Any visitHexadecimalLiteral(MySqlParser::HexadecimalLiteralContext *ctx) override {
    HexadecimalLiteralContextProxy proxy(ctx);
    return getSelf().call("visit_hexadecimal_literal", &proxy);
  }

  virtual antlrcpp::Any visitNullNotnull(MySqlParser::NullNotnullContext *ctx) override {
    NullNotnullContextProxy proxy(ctx);
    return getSelf().call("visit_null_notnull", &proxy);
  }

  virtual antlrcpp::Any visitConstant(MySqlParser::ConstantContext *ctx) override {
    ConstantContextProxy proxy(ctx);
    return getSelf().call("visit_constant", &proxy);
  }

  virtual antlrcpp::Any visitStringDataType(MySqlParser::StringDataTypeContext *ctx) override {
    StringDataTypeContextProxy proxy(ctx);
    return getSelf().call("visit_string_data_type", &proxy);
  }

  virtual antlrcpp::Any visitNationalStringDataType(MySqlParser::NationalStringDataTypeContext *ctx) override {
    NationalStringDataTypeContextProxy proxy(ctx);
    return getSelf().call("visit_national_string_data_type", &proxy);
  }

  virtual antlrcpp::Any visitNationalVaryingStringDataType(MySqlParser::NationalVaryingStringDataTypeContext *ctx) override {
    NationalVaryingStringDataTypeContextProxy proxy(ctx);
    return getSelf().call("visit_national_varying_string_data_type", &proxy);
  }

  virtual antlrcpp::Any visitDimensionDataType(MySqlParser::DimensionDataTypeContext *ctx) override {
    DimensionDataTypeContextProxy proxy(ctx);
    return getSelf().call("visit_dimension_data_type", &proxy);
  }

  virtual antlrcpp::Any visitSimpleDataType(MySqlParser::SimpleDataTypeContext *ctx) override {
    SimpleDataTypeContextProxy proxy(ctx);
    return getSelf().call("visit_simple_data_type", &proxy);
  }

  virtual antlrcpp::Any visitCollectionDataType(MySqlParser::CollectionDataTypeContext *ctx) override {
    CollectionDataTypeContextProxy proxy(ctx);
    return getSelf().call("visit_collection_data_type", &proxy);
  }

  virtual antlrcpp::Any visitSpatialDataType(MySqlParser::SpatialDataTypeContext *ctx) override {
    SpatialDataTypeContextProxy proxy(ctx);
    return getSelf().call("visit_spatial_data_type", &proxy);
  }

  virtual antlrcpp::Any visitCollectionOptions(MySqlParser::CollectionOptionsContext *ctx) override {
    CollectionOptionsContextProxy proxy(ctx);
    return getSelf().call("visit_collection_options", &proxy);
  }

  virtual antlrcpp::Any visitConvertedDataType(MySqlParser::ConvertedDataTypeContext *ctx) override {
    ConvertedDataTypeContextProxy proxy(ctx);
    return getSelf().call("visit_converted_data_type", &proxy);
  }

  virtual antlrcpp::Any visitLengthOneDimension(MySqlParser::LengthOneDimensionContext *ctx) override {
    LengthOneDimensionContextProxy proxy(ctx);
    return getSelf().call("visit_length_one_dimension", &proxy);
  }

  virtual antlrcpp::Any visitLengthTwoDimension(MySqlParser::LengthTwoDimensionContext *ctx) override {
    LengthTwoDimensionContextProxy proxy(ctx);
    return getSelf().call("visit_length_two_dimension", &proxy);
  }

  virtual antlrcpp::Any visitLengthTwoOptionalDimension(MySqlParser::LengthTwoOptionalDimensionContext *ctx) override {
    LengthTwoOptionalDimensionContextProxy proxy(ctx);
    return getSelf().call("visit_length_two_optional_dimension", &proxy);
  }

  virtual antlrcpp::Any visitUidList(MySqlParser::UidListContext *ctx) override {
    UidListContextProxy proxy(ctx);
    return getSelf().call("visit_uid_list", &proxy);
  }

  virtual antlrcpp::Any visitTables(MySqlParser::TablesContext *ctx) override {
    TablesContextProxy proxy(ctx);
    return getSelf().call("visit_tables", &proxy);
  }

  virtual antlrcpp::Any visitIndexColumnNames(MySqlParser::IndexColumnNamesContext *ctx) override {
    IndexColumnNamesContextProxy proxy(ctx);
    return getSelf().call("visit_index_column_names", &proxy);
  }

  virtual antlrcpp::Any visitExpressions(MySqlParser::ExpressionsContext *ctx) override {
    ExpressionsContextProxy proxy(ctx);
    return getSelf().call("visit_expressions", &proxy);
  }

  virtual antlrcpp::Any visitExpressionsWithDefaults(MySqlParser::ExpressionsWithDefaultsContext *ctx) override {
    ExpressionsWithDefaultsContextProxy proxy(ctx);
    return getSelf().call("visit_expressions_with_defaults", &proxy);
  }

  virtual antlrcpp::Any visitConstants(MySqlParser::ConstantsContext *ctx) override {
    ConstantsContextProxy proxy(ctx);
    return getSelf().call("visit_constants", &proxy);
  }

  virtual antlrcpp::Any visitSimpleStrings(MySqlParser::SimpleStringsContext *ctx) override {
    SimpleStringsContextProxy proxy(ctx);
    return getSelf().call("visit_simple_strings", &proxy);
  }

  virtual antlrcpp::Any visitUserVariables(MySqlParser::UserVariablesContext *ctx) override {
    UserVariablesContextProxy proxy(ctx);
    return getSelf().call("visit_user_variables", &proxy);
  }

  virtual antlrcpp::Any visitDefaultValue(MySqlParser::DefaultValueContext *ctx) override {
    DefaultValueContextProxy proxy(ctx);
    return getSelf().call("visit_default_value", &proxy);
  }

  virtual antlrcpp::Any visitCurrentTimestamp(MySqlParser::CurrentTimestampContext *ctx) override {
    CurrentTimestampContextProxy proxy(ctx);
    return getSelf().call("visit_current_timestamp", &proxy);
  }

  virtual antlrcpp::Any visitExpressionOrDefault(MySqlParser::ExpressionOrDefaultContext *ctx) override {
    ExpressionOrDefaultContextProxy proxy(ctx);
    return getSelf().call("visit_expression_or_default", &proxy);
  }

  virtual antlrcpp::Any visitIfExists(MySqlParser::IfExistsContext *ctx) override {
    IfExistsContextProxy proxy(ctx);
    return getSelf().call("visit_if_exists", &proxy);
  }

  virtual antlrcpp::Any visitIfNotExists(MySqlParser::IfNotExistsContext *ctx) override {
    IfNotExistsContextProxy proxy(ctx);
    return getSelf().call("visit_if_not_exists", &proxy);
  }

  virtual antlrcpp::Any visitSpecificFunctionCall(MySqlParser::SpecificFunctionCallContext *ctx) override {
    SpecificFunctionCallContextProxy proxy(ctx);
    return getSelf().call("visit_specific_function_call", &proxy);
  }

  virtual antlrcpp::Any visitAggregateFunctionCall(MySqlParser::AggregateFunctionCallContext *ctx) override {
    AggregateFunctionCallContextProxy proxy(ctx);
    return getSelf().call("visit_aggregate_function_call", &proxy);
  }

  virtual antlrcpp::Any visitScalarFunctionCall(MySqlParser::ScalarFunctionCallContext *ctx) override {
    ScalarFunctionCallContextProxy proxy(ctx);
    return getSelf().call("visit_scalar_function_call", &proxy);
  }

  virtual antlrcpp::Any visitUdfFunctionCall(MySqlParser::UdfFunctionCallContext *ctx) override {
    UdfFunctionCallContextProxy proxy(ctx);
    return getSelf().call("visit_udf_function_call", &proxy);
  }

  virtual antlrcpp::Any visitPasswordFunctionCall(MySqlParser::PasswordFunctionCallContext *ctx) override {
    PasswordFunctionCallContextProxy proxy(ctx);
    return getSelf().call("visit_password_function_call", &proxy);
  }

  virtual antlrcpp::Any visitSimpleFunctionCall(MySqlParser::SimpleFunctionCallContext *ctx) override {
    SimpleFunctionCallContextProxy proxy(ctx);
    return getSelf().call("visit_simple_function_call", &proxy);
  }

  virtual antlrcpp::Any visitDataTypeFunctionCall(MySqlParser::DataTypeFunctionCallContext *ctx) override {
    DataTypeFunctionCallContextProxy proxy(ctx);
    return getSelf().call("visit_data_type_function_call", &proxy);
  }

  virtual antlrcpp::Any visitValuesFunctionCall(MySqlParser::ValuesFunctionCallContext *ctx) override {
    ValuesFunctionCallContextProxy proxy(ctx);
    return getSelf().call("visit_values_function_call", &proxy);
  }

  virtual antlrcpp::Any visitCaseFunctionCall(MySqlParser::CaseFunctionCallContext *ctx) override {
    CaseFunctionCallContextProxy proxy(ctx);
    return getSelf().call("visit_case_function_call", &proxy);
  }

  virtual antlrcpp::Any visitCharFunctionCall(MySqlParser::CharFunctionCallContext *ctx) override {
    CharFunctionCallContextProxy proxy(ctx);
    return getSelf().call("visit_char_function_call", &proxy);
  }

  virtual antlrcpp::Any visitPositionFunctionCall(MySqlParser::PositionFunctionCallContext *ctx) override {
    PositionFunctionCallContextProxy proxy(ctx);
    return getSelf().call("visit_position_function_call", &proxy);
  }

  virtual antlrcpp::Any visitSubstrFunctionCall(MySqlParser::SubstrFunctionCallContext *ctx) override {
    SubstrFunctionCallContextProxy proxy(ctx);
    return getSelf().call("visit_substr_function_call", &proxy);
  }

  virtual antlrcpp::Any visitTrimFunctionCall(MySqlParser::TrimFunctionCallContext *ctx) override {
    TrimFunctionCallContextProxy proxy(ctx);
    return getSelf().call("visit_trim_function_call", &proxy);
  }

  virtual antlrcpp::Any visitWeightFunctionCall(MySqlParser::WeightFunctionCallContext *ctx) override {
    WeightFunctionCallContextProxy proxy(ctx);
    return getSelf().call("visit_weight_function_call", &proxy);
  }

  virtual antlrcpp::Any visitExtractFunctionCall(MySqlParser::ExtractFunctionCallContext *ctx) override {
    ExtractFunctionCallContextProxy proxy(ctx);
    return getSelf().call("visit_extract_function_call", &proxy);
  }

  virtual antlrcpp::Any visitGetFormatFunctionCall(MySqlParser::GetFormatFunctionCallContext *ctx) override {
    GetFormatFunctionCallContextProxy proxy(ctx);
    return getSelf().call("visit_get_format_function_call", &proxy);
  }

  virtual antlrcpp::Any visitCaseFuncAlternative(MySqlParser::CaseFuncAlternativeContext *ctx) override {
    CaseFuncAlternativeContextProxy proxy(ctx);
    return getSelf().call("visit_case_func_alternative", &proxy);
  }

  virtual antlrcpp::Any visitLevelWeightList(MySqlParser::LevelWeightListContext *ctx) override {
    LevelWeightListContextProxy proxy(ctx);
    return getSelf().call("visit_level_weight_list", &proxy);
  }

  virtual antlrcpp::Any visitLevelWeightRange(MySqlParser::LevelWeightRangeContext *ctx) override {
    LevelWeightRangeContextProxy proxy(ctx);
    return getSelf().call("visit_level_weight_range", &proxy);
  }

  virtual antlrcpp::Any visitLevelInWeightListElement(MySqlParser::LevelInWeightListElementContext *ctx) override {
    LevelInWeightListElementContextProxy proxy(ctx);
    return getSelf().call("visit_level_in_weight_list_element", &proxy);
  }

  virtual antlrcpp::Any visitAggregateWindowedFunction(MySqlParser::AggregateWindowedFunctionContext *ctx) override {
    AggregateWindowedFunctionContextProxy proxy(ctx);
    return getSelf().call("visit_aggregate_windowed_function", &proxy);
  }

  virtual antlrcpp::Any visitScalarFunctionName(MySqlParser::ScalarFunctionNameContext *ctx) override {
    ScalarFunctionNameContextProxy proxy(ctx);
    return getSelf().call("visit_scalar_function_name", &proxy);
  }

  virtual antlrcpp::Any visitPasswordFunctionClause(MySqlParser::PasswordFunctionClauseContext *ctx) override {
    PasswordFunctionClauseContextProxy proxy(ctx);
    return getSelf().call("visit_password_function_clause", &proxy);
  }

  virtual antlrcpp::Any visitFunctionArgs(MySqlParser::FunctionArgsContext *ctx) override {
    FunctionArgsContextProxy proxy(ctx);
    return getSelf().call("visit_function_args", &proxy);
  }

  virtual antlrcpp::Any visitFunctionArg(MySqlParser::FunctionArgContext *ctx) override {
    FunctionArgContextProxy proxy(ctx);
    return getSelf().call("visit_function_arg", &proxy);
  }

  virtual antlrcpp::Any visitIsExpression(MySqlParser::IsExpressionContext *ctx) override {
    IsExpressionContextProxy proxy(ctx);
    return getSelf().call("visit_is_expression", &proxy);
  }

  virtual antlrcpp::Any visitNotExpression(MySqlParser::NotExpressionContext *ctx) override {
    NotExpressionContextProxy proxy(ctx);
    return getSelf().call("visit_not_expression", &proxy);
  }

  virtual antlrcpp::Any visitLogicalExpression(MySqlParser::LogicalExpressionContext *ctx) override {
    LogicalExpressionContextProxy proxy(ctx);
    return getSelf().call("visit_logical_expression", &proxy);
  }

  virtual antlrcpp::Any visitPredicateExpression(MySqlParser::PredicateExpressionContext *ctx) override {
    PredicateExpressionContextProxy proxy(ctx);
    return getSelf().call("visit_predicate_expression", &proxy);
  }

  virtual antlrcpp::Any visitSoundsLikePredicate(MySqlParser::SoundsLikePredicateContext *ctx) override {
    SoundsLikePredicateContextProxy proxy(ctx);
    return getSelf().call("visit_sounds_like_predicate", &proxy);
  }

  virtual antlrcpp::Any visitExpressionAtomPredicate(MySqlParser::ExpressionAtomPredicateContext *ctx) override {
    ExpressionAtomPredicateContextProxy proxy(ctx);
    return getSelf().call("visit_expression_atom_predicate", &proxy);
  }

  virtual antlrcpp::Any visitInPredicate(MySqlParser::InPredicateContext *ctx) override {
    InPredicateContextProxy proxy(ctx);
    return getSelf().call("visit_in_predicate", &proxy);
  }

  virtual antlrcpp::Any visitSubqueryComparasionPredicate(MySqlParser::SubqueryComparasionPredicateContext *ctx) override {
    SubqueryComparasionPredicateContextProxy proxy(ctx);
    return getSelf().call("visit_subquery_comparasion_predicate", &proxy);
  }

  virtual antlrcpp::Any visitBetweenPredicate(MySqlParser::BetweenPredicateContext *ctx) override {
    BetweenPredicateContextProxy proxy(ctx);
    return getSelf().call("visit_between_predicate", &proxy);
  }

  virtual antlrcpp::Any visitBinaryComparasionPredicate(MySqlParser::BinaryComparasionPredicateContext *ctx) override {
    BinaryComparasionPredicateContextProxy proxy(ctx);
    return getSelf().call("visit_binary_comparasion_predicate", &proxy);
  }

  virtual antlrcpp::Any visitIsNullPredicate(MySqlParser::IsNullPredicateContext *ctx) override {
    IsNullPredicateContextProxy proxy(ctx);
    return getSelf().call("visit_is_null_predicate", &proxy);
  }

  virtual antlrcpp::Any visitLikePredicate(MySqlParser::LikePredicateContext *ctx) override {
    LikePredicateContextProxy proxy(ctx);
    return getSelf().call("visit_like_predicate", &proxy);
  }

  virtual antlrcpp::Any visitRegexpPredicate(MySqlParser::RegexpPredicateContext *ctx) override {
    RegexpPredicateContextProxy proxy(ctx);
    return getSelf().call("visit_regexp_predicate", &proxy);
  }

  virtual antlrcpp::Any visitUnaryExpressionAtom(MySqlParser::UnaryExpressionAtomContext *ctx) override {
    UnaryExpressionAtomContextProxy proxy(ctx);
    return getSelf().call("visit_unary_expression_atom", &proxy);
  }

  virtual antlrcpp::Any visitCollateExpressionAtom(MySqlParser::CollateExpressionAtomContext *ctx) override {
    CollateExpressionAtomContextProxy proxy(ctx);
    return getSelf().call("visit_collate_expression_atom", &proxy);
  }

  virtual antlrcpp::Any visitSubqueryExpessionAtom(MySqlParser::SubqueryExpessionAtomContext *ctx) override {
    SubqueryExpessionAtomContextProxy proxy(ctx);
    return getSelf().call("visit_subquery_expession_atom", &proxy);
  }

  virtual antlrcpp::Any visitMysqlVariableExpressionAtom(MySqlParser::MysqlVariableExpressionAtomContext *ctx) override {
    MysqlVariableExpressionAtomContextProxy proxy(ctx);
    return getSelf().call("visit_mysql_variable_expression_atom", &proxy);
  }

  virtual antlrcpp::Any visitNestedExpressionAtom(MySqlParser::NestedExpressionAtomContext *ctx) override {
    NestedExpressionAtomContextProxy proxy(ctx);
    return getSelf().call("visit_nested_expression_atom", &proxy);
  }

  virtual antlrcpp::Any visitNestedRowExpressionAtom(MySqlParser::NestedRowExpressionAtomContext *ctx) override {
    NestedRowExpressionAtomContextProxy proxy(ctx);
    return getSelf().call("visit_nested_row_expression_atom", &proxy);
  }

  virtual antlrcpp::Any visitMathExpressionAtom(MySqlParser::MathExpressionAtomContext *ctx) override {
    MathExpressionAtomContextProxy proxy(ctx);
    return getSelf().call("visit_math_expression_atom", &proxy);
  }

  virtual antlrcpp::Any visitIntervalExpressionAtom(MySqlParser::IntervalExpressionAtomContext *ctx) override {
    IntervalExpressionAtomContextProxy proxy(ctx);
    return getSelf().call("visit_interval_expression_atom", &proxy);
  }

  virtual antlrcpp::Any visitExistsExpessionAtom(MySqlParser::ExistsExpessionAtomContext *ctx) override {
    ExistsExpessionAtomContextProxy proxy(ctx);
    return getSelf().call("visit_exists_expession_atom", &proxy);
  }

  virtual antlrcpp::Any visitConstantExpressionAtom(MySqlParser::ConstantExpressionAtomContext *ctx) override {
    ConstantExpressionAtomContextProxy proxy(ctx);
    return getSelf().call("visit_constant_expression_atom", &proxy);
  }

  virtual antlrcpp::Any visitFunctionCallExpressionAtom(MySqlParser::FunctionCallExpressionAtomContext *ctx) override {
    FunctionCallExpressionAtomContextProxy proxy(ctx);
    return getSelf().call("visit_function_call_expression_atom", &proxy);
  }

  virtual antlrcpp::Any visitBinaryExpressionAtom(MySqlParser::BinaryExpressionAtomContext *ctx) override {
    BinaryExpressionAtomContextProxy proxy(ctx);
    return getSelf().call("visit_binary_expression_atom", &proxy);
  }

  virtual antlrcpp::Any visitFullColumnNameExpressionAtom(MySqlParser::FullColumnNameExpressionAtomContext *ctx) override {
    FullColumnNameExpressionAtomContextProxy proxy(ctx);
    return getSelf().call("visit_full_column_name_expression_atom", &proxy);
  }

  virtual antlrcpp::Any visitBitExpressionAtom(MySqlParser::BitExpressionAtomContext *ctx) override {
    BitExpressionAtomContextProxy proxy(ctx);
    return getSelf().call("visit_bit_expression_atom", &proxy);
  }

  virtual antlrcpp::Any visitUnaryOperator(MySqlParser::UnaryOperatorContext *ctx) override {
    UnaryOperatorContextProxy proxy(ctx);
    return getSelf().call("visit_unary_operator", &proxy);
  }

  virtual antlrcpp::Any visitComparisonOperator(MySqlParser::ComparisonOperatorContext *ctx) override {
    ComparisonOperatorContextProxy proxy(ctx);
    return getSelf().call("visit_comparison_operator", &proxy);
  }

  virtual antlrcpp::Any visitLogicalOperator(MySqlParser::LogicalOperatorContext *ctx) override {
    LogicalOperatorContextProxy proxy(ctx);
    return getSelf().call("visit_logical_operator", &proxy);
  }

  virtual antlrcpp::Any visitBitOperator(MySqlParser::BitOperatorContext *ctx) override {
    BitOperatorContextProxy proxy(ctx);
    return getSelf().call("visit_bit_operator", &proxy);
  }

  virtual antlrcpp::Any visitMathOperator(MySqlParser::MathOperatorContext *ctx) override {
    MathOperatorContextProxy proxy(ctx);
    return getSelf().call("visit_math_operator", &proxy);
  }

  virtual antlrcpp::Any visitCharsetNameBase(MySqlParser::CharsetNameBaseContext *ctx) override {
    CharsetNameBaseContextProxy proxy(ctx);
    return getSelf().call("visit_charset_name_base", &proxy);
  }

  virtual antlrcpp::Any visitTransactionLevelBase(MySqlParser::TransactionLevelBaseContext *ctx) override {
    TransactionLevelBaseContextProxy proxy(ctx);
    return getSelf().call("visit_transaction_level_base", &proxy);
  }

  virtual antlrcpp::Any visitPrivilegesBase(MySqlParser::PrivilegesBaseContext *ctx) override {
    PrivilegesBaseContextProxy proxy(ctx);
    return getSelf().call("visit_privileges_base", &proxy);
  }

  virtual antlrcpp::Any visitIntervalTypeBase(MySqlParser::IntervalTypeBaseContext *ctx) override {
    IntervalTypeBaseContextProxy proxy(ctx);
    return getSelf().call("visit_interval_type_base", &proxy);
  }

  virtual antlrcpp::Any visitDataTypeBase(MySqlParser::DataTypeBaseContext *ctx) override {
    DataTypeBaseContextProxy proxy(ctx);
    return getSelf().call("visit_data_type_base", &proxy);
  }

  virtual antlrcpp::Any visitKeywordsCanBeId(MySqlParser::KeywordsCanBeIdContext *ctx) override {
    KeywordsCanBeIdContextProxy proxy(ctx);
    return getSelf().call("visit_keywords_can_be_id", &proxy);
  }

  virtual antlrcpp::Any visitFunctionNameBase(MySqlParser::FunctionNameBaseContext *ctx) override {
    FunctionNameBaseContextProxy proxy(ctx);
    return getSelf().call("visit_function_name_base", &proxy);
  }

};


VALUE mysql_parser_parse(string file, MySqlVisitor* visitor) {
  ifstream stream;
  stream.open(file);

  ANTLRInputStream input(stream);
  MySqlLexer lexer(&input);
  CommonTokenStream tokens(&lexer);
  MySqlParser parser(&tokens);
  visitor -> visit(parser.root());
  stream.close();

  return Qnil;
}


extern "C"
void Init_mysql_parser() {
  Module rb_mMySqlParser = define_module("MySqlParser");

  rb_mMySqlParser
    .define_class("Parser")
    .define_method("parse", &mysql_parser_parse);

  rb_cParseTree = rb_mMySqlParser
    .define_class<tree::ParseTree>("ParseTree");

  rb_mMySqlParser
    .define_class<MySqlVisitor>("MySqlVisitor")
    .define_director<MySqlVisitorProxy>()
    .define_constructor(Constructor<MySqlVisitorProxy, Object>())
    .define_method("visit", &MySqlVisitorProxy::ruby_visit)
    .define_method("visit_children", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_root", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_sql_statements", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_sql_statement", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_empty_statement", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_ddl_statement", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_dml_statement", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_transaction_statement", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_replication_statement", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_prepared_statement", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_compound_statement", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_administration_statement", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_utility_statement", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_create_database", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_create_event", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_create_index", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_create_logfile_group", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_create_procedure", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_create_function", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_create_server", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_copy_create_table", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_query_create_table", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_column_create_table", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_create_tablespace_innodb", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_create_tablespace_ndb", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_create_trigger", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_create_view", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_create_database_option", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_owner_statement", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_precise_schedule", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_interval_schedule", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_timestamp_value", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_interval_expr", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_interval_type", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_enable_type", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_index_type", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_index_option", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_procedure_parameter", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_function_parameter", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_routine_comment", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_routine_language", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_routine_behavior", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_routine_data", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_routine_security", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_server_option", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_create_definitions", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_column_declaration", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_constraint_declaration", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_index_declaration", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_column_definition", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_null_column_constraint", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_default_column_constraint", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_auto_increment_column_constraint", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_primary_key_column_constraint", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_unique_key_column_constraint", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_comment_column_constraint", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_format_column_constraint", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_storage_column_constraint", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_reference_column_constraint", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_collate_column_constraint", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_generated_column_constraint", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_serial_default_column_constraint", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_primary_key_table_constraint", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_unique_key_table_constraint", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_foreign_key_table_constraint", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_check_table_constraint", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_reference_definition", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_reference_action", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_reference_control_type", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_simple_index_declaration", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_special_index_declaration", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_table_option_engine", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_table_option_auto_increment", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_table_option_average", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_table_option_charset", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_table_option_checksum", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_table_option_collate", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_table_option_comment", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_table_option_compression", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_table_option_connection", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_table_option_data_directory", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_table_option_delay", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_table_option_encryption", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_table_option_index_directory", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_table_option_insert_method", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_table_option_key_block_size", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_table_option_max_rows", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_table_option_min_rows", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_table_option_pack_keys", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_table_option_password", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_table_option_row_format", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_table_option_recalculation", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_table_option_persistent", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_table_option_sample_page", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_table_option_tablespace", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_table_option_union", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_tablespace_storage", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_partition_definitions", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_partition_function_hash", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_partition_function_key", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_partition_function_range", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_partition_function_list", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_sub_partition_function_hash", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_sub_partition_function_key", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_partition_comparision", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_partition_list_atom", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_partition_list_vector", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_partition_simple", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_partition_definer_atom", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_partition_definer_vector", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_subpartition_definition", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_partition_option_engine", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_partition_option_comment", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_partition_option_data_directory", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_partition_option_index_directory", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_partition_option_max_rows", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_partition_option_min_rows", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_partition_option_tablespace", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_partition_option_node_group", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_alter_simple_database", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_alter_upgrade_name", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_alter_event", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_alter_function", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_alter_instance", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_alter_logfile_group", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_alter_procedure", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_alter_server", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_alter_table", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_alter_tablespace", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_alter_view", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_alter_by_table_option", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_alter_by_add_column", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_alter_by_add_columns", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_alter_by_add_index", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_alter_by_add_primary_key", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_alter_by_add_unique_key", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_alter_by_add_special_index", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_alter_by_add_foreign_key", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_alter_by_add_check_table_constraint", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_alter_by_set_algorithm", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_alter_by_change_default", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_alter_by_change_column", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_alter_by_rename_column", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_alter_by_lock", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_alter_by_modify_column", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_alter_by_drop_column", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_alter_by_drop_primary_key", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_alter_by_rename_index", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_alter_by_drop_index", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_alter_by_drop_foreign_key", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_alter_by_disable_keys", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_alter_by_enable_keys", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_alter_by_rename", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_alter_by_order", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_alter_by_convert_charset", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_alter_by_default_charset", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_alter_by_discard_tablespace", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_alter_by_import_tablespace", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_alter_by_force", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_alter_by_validate", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_alter_by_add_partition", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_alter_by_drop_partition", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_alter_by_discard_partition", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_alter_by_import_partition", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_alter_by_truncate_partition", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_alter_by_coalesce_partition", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_alter_by_reorganize_partition", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_alter_by_exchange_partition", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_alter_by_analyze_partition", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_alter_by_check_partition", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_alter_by_optimize_partition", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_alter_by_rebuild_partition", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_alter_by_repair_partition", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_alter_by_remove_partitioning", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_alter_by_upgrade_partitioning", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_drop_database", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_drop_event", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_drop_index", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_drop_logfile_group", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_drop_procedure", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_drop_function", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_drop_server", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_drop_table", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_drop_tablespace", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_drop_trigger", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_drop_view", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_rename_table", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_rename_table_clause", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_truncate_table", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_call_statement", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_delete_statement", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_do_statement", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_handler_statement", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_insert_statement", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_load_data_statement", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_load_xml_statement", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_replace_statement", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_simple_select", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_parenthesis_select", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_union_select", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_union_parenthesis_select", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_update_statement", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_insert_statement_value", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_updated_element", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_assignment_field", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_lock_clause", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_single_delete_statement", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_multiple_delete_statement", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_handler_open_statement", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_handler_read_index_statement", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_handler_read_statement", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_handler_close_statement", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_single_update_statement", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_multiple_update_statement", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_order_by_clause", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_order_by_expression", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_table_sources", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_table_source_base", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_table_source_nested", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_atom_table_item", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_subquery_table_item", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_table_sources_item", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_index_hint", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_index_hint_type", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_inner_join", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_straight_join", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_outer_join", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_natural_join", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_query_expression", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_query_expression_nointo", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_query_specification", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_query_specification_nointo", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_union_parenthesis", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_union_statement", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_select_spec", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_select_elements", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_select_star_element", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_select_column_element", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_select_function_element", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_select_expression_element", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_select_into_variables", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_select_into_dump_file", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_select_into_text_file", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_select_fields_into", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_select_lines_into", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_from_clause", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_group_by_item", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_limit_clause", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_limit_clause_atom", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_start_transaction", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_begin_work", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_commit_work", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_rollback_work", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_savepoint_statement", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_rollback_statement", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_release_statement", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_lock_tables", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_unlock_tables", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_set_autocommit_statement", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_set_transaction_statement", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_transaction_mode", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_lock_table_element", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_lock_action", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_transaction_option", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_transaction_level", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_change_master", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_change_replication_filter", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_purge_binary_logs", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_reset_master", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_reset_slave", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_start_slave", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_stop_slave", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_start_group_replication", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_stop_group_replication", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_master_string_option", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_master_decimal_option", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_master_bool_option", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_master_real_option", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_master_uid_list_option", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_string_master_option", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_decimal_master_option", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_bool_master_option", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_channel_option", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_do_db_replication", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_ignore_db_replication", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_do_table_replication", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_ignore_table_replication", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_wild_do_table_replication", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_wild_ignore_table_replication", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_rewrite_db_replication", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_table_pair", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_thread_type", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_gtids_until_option", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_master_log_until_option", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_relay_log_until_option", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_sql_gaps_until_option", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_user_connection_option", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_password_connection_option", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_default_auth_connection_option", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_plugin_dir_connection_option", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_gtuid_set", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_xa_start_transaction", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_xa_end_transaction", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_xa_prepare_statement", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_xa_commit_work", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_xa_rollback_work", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_xa_recover_work", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_prepare_statement", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_execute_statement", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_deallocate_prepare", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_routine_body", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_block_statement", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_case_statement", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_if_statement", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_iterate_statement", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_leave_statement", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_loop_statement", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_repeat_statement", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_return_statement", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_while_statement", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_close_cursor", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_fetch_cursor", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_open_cursor", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_declare_variable", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_declare_condition", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_declare_cursor", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_declare_handler", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_handler_condition_code", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_handler_condition_state", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_handler_condition_name", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_handler_condition_warning", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_handler_condition_notfound", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_handler_condition_exception", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_procedure_sql_statement", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_case_alternative", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_elif_alternative", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_alter_user_mysql_v56", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_alter_user_mysql_v57", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_create_user_mysql_v56", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_create_user_mysql_v57", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_drop_user", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_grant_statement", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_grant_proxy", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_rename_user", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_detail_revoke", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_short_revoke", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_revoke_proxy", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_set_password_statement", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_user_specification", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_password_auth_option", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_string_auth_option", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_hash_auth_option", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_simple_auth_option", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_tls_option", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_user_resource_option", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_user_password_option", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_user_lock_option", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_privelege_clause", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_privilege", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_current_schema_privi_level", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_global_priv_level", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_definite_schema_priv_level", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_definite_full_table_priv_level", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_definite_full_table_priv_level2", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_definite_table_priv_level", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_rename_user_clause", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_analyze_table", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_check_table", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_checksum_table", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_optimize_table", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_repair_table", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_check_table_option", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_create_udfunction", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_install_plugin", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_uninstall_plugin", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_set_variable", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_set_charset", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_set_names", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_set_password", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_set_transaction", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_set_autocommit", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_set_new_value_inside_trigger", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_show_master_logs", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_show_log_events", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_show_object_filter", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_show_columns", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_show_create_db", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_show_create_full_id_object", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_show_create_user", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_show_engine", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_show_global_info", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_show_errors", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_show_count_errors", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_show_schema_filter", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_show_routine", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_show_grants", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_show_indexes", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_show_open_tables", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_show_profile", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_show_slave_status", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_variable_clause", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_show_common_entity", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_show_filter", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_show_global_info_clause", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_show_schema_entity", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_show_profile_type", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_binlog_statement", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_cache_index_statement", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_flush_statement", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_kill_statement", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_load_index_into_cache", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_reset_statement", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_shutdown_statement", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_table_indexes", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_simple_flush_option", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_channel_flush_option", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_table_flush_option", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_flush_table_option", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_loaded_table_indexes", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_simple_describe_statement", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_full_describe_statement", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_help_statement", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_use_statement", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_signal_statement", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_resignal_statement", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_signal_condition_information", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_diagnostics_statement", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_diagnostics_condition_information_name", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_describe_statements", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_describe_connection", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_full_id", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_table_name", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_full_column_name", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_index_column_name", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_user_name", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_mysql_variable", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_charset_name", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_collation_name", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_engine_name", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_uuid_set", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_xid", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_xuid_string_id", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_auth_plugin", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_uid", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_simple_id", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_dotted_id", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_decimal_literal", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_file_size_literal", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_string_literal", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_boolean_literal", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_hexadecimal_literal", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_null_notnull", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_constant", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_string_data_type", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_national_string_data_type", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_national_varying_string_data_type", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_dimension_data_type", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_simple_data_type", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_collection_data_type", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_spatial_data_type", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_collection_options", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_converted_data_type", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_length_one_dimension", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_length_two_dimension", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_length_two_optional_dimension", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_uid_list", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_tables", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_index_column_names", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_expressions", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_expressions_with_defaults", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_constants", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_simple_strings", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_user_variables", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_default_value", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_current_timestamp", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_expression_or_default", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_if_exists", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_if_not_exists", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_specific_function_call", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_aggregate_function_call", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_scalar_function_call", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_udf_function_call", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_password_function_call", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_simple_function_call", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_data_type_function_call", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_values_function_call", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_case_function_call", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_char_function_call", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_position_function_call", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_substr_function_call", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_trim_function_call", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_weight_function_call", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_extract_function_call", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_get_format_function_call", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_case_func_alternative", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_level_weight_list", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_level_weight_range", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_level_in_weight_list_element", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_aggregate_windowed_function", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_scalar_function_name", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_password_function_clause", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_function_args", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_function_arg", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_is_expression", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_not_expression", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_logical_expression", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_predicate_expression", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_sounds_like_predicate", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_expression_atom_predicate", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_in_predicate", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_subquery_comparasion_predicate", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_between_predicate", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_binary_comparasion_predicate", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_is_null_predicate", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_like_predicate", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_regexp_predicate", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_unary_expression_atom", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_collate_expression_atom", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_subquery_expession_atom", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_mysql_variable_expression_atom", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_nested_expression_atom", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_nested_row_expression_atom", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_math_expression_atom", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_interval_expression_atom", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_exists_expession_atom", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_constant_expression_atom", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_function_call_expression_atom", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_binary_expression_atom", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_full_column_name_expression_atom", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_bit_expression_atom", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_unary_operator", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_comparison_operator", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_logical_operator", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_bit_operator", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_math_operator", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_charset_name_base", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_transaction_level_base", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_privileges_base", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_interval_type_base", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_data_type_base", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_keywords_can_be_id", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_function_name_base", &MySqlVisitorProxy::ruby_visitChildren);

  rb_mMySqlParser
    .define_class<ContextProxy>("Context");

  rb_cRootContext = rb_mMySqlParser
    .define_class<RootContextProxy, ContextProxy>("RootContext")
    .define_method("sql_statements", &RootContextProxy::sqlStatements);

  rb_cSqlStatementsContext = rb_mMySqlParser
    .define_class<SqlStatementsContextProxy, ContextProxy>("SqlStatementsContext")
    .define_method("sql_statement", &SqlStatementsContextProxy::sqlStatement)
    .define_method("sql_statement_at", &SqlStatementsContextProxy::sqlStatementAt)
    .define_method("empty_statement", &SqlStatementsContextProxy::emptyStatement)
    .define_method("empty_statement_at", &SqlStatementsContextProxy::emptyStatementAt);

  rb_cSqlStatementContext = rb_mMySqlParser
    .define_class<SqlStatementContextProxy, ContextProxy>("SqlStatementContext")
    .define_method("ddl_statement", &SqlStatementContextProxy::ddlStatement)
    .define_method("dml_statement", &SqlStatementContextProxy::dmlStatement)
    .define_method("transaction_statement", &SqlStatementContextProxy::transactionStatement)
    .define_method("replication_statement", &SqlStatementContextProxy::replicationStatement)
    .define_method("prepared_statement", &SqlStatementContextProxy::preparedStatement)
    .define_method("administration_statement", &SqlStatementContextProxy::administrationStatement)
    .define_method("utility_statement", &SqlStatementContextProxy::utilityStatement);

  rb_cEmptyStatementContext = rb_mMySqlParser
    .define_class<EmptyStatementContextProxy, ContextProxy>("EmptyStatementContext");

  rb_cDdlStatementContext = rb_mMySqlParser
    .define_class<DdlStatementContextProxy, ContextProxy>("DdlStatementContext")
    .define_method("create_database", &DdlStatementContextProxy::createDatabase)
    .define_method("create_event", &DdlStatementContextProxy::createEvent)
    .define_method("create_index", &DdlStatementContextProxy::createIndex)
    .define_method("create_logfile_group", &DdlStatementContextProxy::createLogfileGroup)
    .define_method("create_procedure", &DdlStatementContextProxy::createProcedure)
    .define_method("create_function", &DdlStatementContextProxy::createFunction)
    .define_method("create_server", &DdlStatementContextProxy::createServer)
    .define_method("create_table", &DdlStatementContextProxy::createTable)
    .define_method("create_tablespace_innodb", &DdlStatementContextProxy::createTablespaceInnodb)
    .define_method("create_tablespace_ndb", &DdlStatementContextProxy::createTablespaceNdb)
    .define_method("create_trigger", &DdlStatementContextProxy::createTrigger)
    .define_method("create_view", &DdlStatementContextProxy::createView)
    .define_method("alter_database", &DdlStatementContextProxy::alterDatabase)
    .define_method("alter_event", &DdlStatementContextProxy::alterEvent)
    .define_method("alter_function", &DdlStatementContextProxy::alterFunction)
    .define_method("alter_instance", &DdlStatementContextProxy::alterInstance)
    .define_method("alter_logfile_group", &DdlStatementContextProxy::alterLogfileGroup)
    .define_method("alter_procedure", &DdlStatementContextProxy::alterProcedure)
    .define_method("alter_server", &DdlStatementContextProxy::alterServer)
    .define_method("alter_table", &DdlStatementContextProxy::alterTable)
    .define_method("alter_tablespace", &DdlStatementContextProxy::alterTablespace)
    .define_method("alter_view", &DdlStatementContextProxy::alterView)
    .define_method("drop_database", &DdlStatementContextProxy::dropDatabase)
    .define_method("drop_event", &DdlStatementContextProxy::dropEvent)
    .define_method("drop_index", &DdlStatementContextProxy::dropIndex)
    .define_method("drop_logfile_group", &DdlStatementContextProxy::dropLogfileGroup)
    .define_method("drop_procedure", &DdlStatementContextProxy::dropProcedure)
    .define_method("drop_function", &DdlStatementContextProxy::dropFunction)
    .define_method("drop_server", &DdlStatementContextProxy::dropServer)
    .define_method("drop_table", &DdlStatementContextProxy::dropTable)
    .define_method("drop_tablespace", &DdlStatementContextProxy::dropTablespace)
    .define_method("drop_trigger", &DdlStatementContextProxy::dropTrigger)
    .define_method("drop_view", &DdlStatementContextProxy::dropView)
    .define_method("rename_table", &DdlStatementContextProxy::renameTable)
    .define_method("truncate_table", &DdlStatementContextProxy::truncateTable);

  rb_cDmlStatementContext = rb_mMySqlParser
    .define_class<DmlStatementContextProxy, ContextProxy>("DmlStatementContext")
    .define_method("select_statement", &DmlStatementContextProxy::selectStatement)
    .define_method("insert_statement", &DmlStatementContextProxy::insertStatement)
    .define_method("update_statement", &DmlStatementContextProxy::updateStatement)
    .define_method("delete_statement", &DmlStatementContextProxy::deleteStatement)
    .define_method("replace_statement", &DmlStatementContextProxy::replaceStatement)
    .define_method("call_statement", &DmlStatementContextProxy::callStatement)
    .define_method("load_data_statement", &DmlStatementContextProxy::loadDataStatement)
    .define_method("load_xml_statement", &DmlStatementContextProxy::loadXmlStatement)
    .define_method("do_statement", &DmlStatementContextProxy::doStatement)
    .define_method("handler_statement", &DmlStatementContextProxy::handlerStatement);

  rb_cTransactionStatementContext = rb_mMySqlParser
    .define_class<TransactionStatementContextProxy, ContextProxy>("TransactionStatementContext")
    .define_method("start_transaction", &TransactionStatementContextProxy::startTransaction)
    .define_method("begin_work", &TransactionStatementContextProxy::beginWork)
    .define_method("commit_work", &TransactionStatementContextProxy::commitWork)
    .define_method("rollback_work", &TransactionStatementContextProxy::rollbackWork)
    .define_method("savepoint_statement", &TransactionStatementContextProxy::savepointStatement)
    .define_method("rollback_statement", &TransactionStatementContextProxy::rollbackStatement)
    .define_method("release_statement", &TransactionStatementContextProxy::releaseStatement)
    .define_method("lock_tables", &TransactionStatementContextProxy::lockTables)
    .define_method("unlock_tables", &TransactionStatementContextProxy::unlockTables);

  rb_cReplicationStatementContext = rb_mMySqlParser
    .define_class<ReplicationStatementContextProxy, ContextProxy>("ReplicationStatementContext")
    .define_method("change_master", &ReplicationStatementContextProxy::changeMaster)
    .define_method("change_replication_filter", &ReplicationStatementContextProxy::changeReplicationFilter)
    .define_method("purge_binary_logs", &ReplicationStatementContextProxy::purgeBinaryLogs)
    .define_method("reset_master", &ReplicationStatementContextProxy::resetMaster)
    .define_method("reset_slave", &ReplicationStatementContextProxy::resetSlave)
    .define_method("start_slave", &ReplicationStatementContextProxy::startSlave)
    .define_method("stop_slave", &ReplicationStatementContextProxy::stopSlave)
    .define_method("start_group_replication", &ReplicationStatementContextProxy::startGroupReplication)
    .define_method("stop_group_replication", &ReplicationStatementContextProxy::stopGroupReplication)
    .define_method("xa_start_transaction", &ReplicationStatementContextProxy::xaStartTransaction)
    .define_method("xa_end_transaction", &ReplicationStatementContextProxy::xaEndTransaction)
    .define_method("xa_prepare_statement", &ReplicationStatementContextProxy::xaPrepareStatement)
    .define_method("xa_commit_work", &ReplicationStatementContextProxy::xaCommitWork)
    .define_method("xa_rollback_work", &ReplicationStatementContextProxy::xaRollbackWork)
    .define_method("xa_recover_work", &ReplicationStatementContextProxy::xaRecoverWork);

  rb_cPreparedStatementContext = rb_mMySqlParser
    .define_class<PreparedStatementContextProxy, ContextProxy>("PreparedStatementContext")
    .define_method("prepare_statement", &PreparedStatementContextProxy::prepareStatement)
    .define_method("execute_statement", &PreparedStatementContextProxy::executeStatement)
    .define_method("deallocate_prepare", &PreparedStatementContextProxy::deallocatePrepare);

  rb_cAdministrationStatementContext = rb_mMySqlParser
    .define_class<AdministrationStatementContextProxy, ContextProxy>("AdministrationStatementContext")
    .define_method("alter_user", &AdministrationStatementContextProxy::alterUser)
    .define_method("create_user", &AdministrationStatementContextProxy::createUser)
    .define_method("drop_user", &AdministrationStatementContextProxy::dropUser)
    .define_method("grant_statement", &AdministrationStatementContextProxy::grantStatement)
    .define_method("grant_proxy", &AdministrationStatementContextProxy::grantProxy)
    .define_method("rename_user", &AdministrationStatementContextProxy::renameUser)
    .define_method("revoke_statement", &AdministrationStatementContextProxy::revokeStatement)
    .define_method("revoke_proxy", &AdministrationStatementContextProxy::revokeProxy)
    .define_method("analyze_table", &AdministrationStatementContextProxy::analyzeTable)
    .define_method("check_table", &AdministrationStatementContextProxy::checkTable)
    .define_method("checksum_table", &AdministrationStatementContextProxy::checksumTable)
    .define_method("optimize_table", &AdministrationStatementContextProxy::optimizeTable)
    .define_method("repair_table", &AdministrationStatementContextProxy::repairTable)
    .define_method("create_udfunction", &AdministrationStatementContextProxy::createUdfunction)
    .define_method("install_plugin", &AdministrationStatementContextProxy::installPlugin)
    .define_method("uninstall_plugin", &AdministrationStatementContextProxy::uninstallPlugin)
    .define_method("set_statement", &AdministrationStatementContextProxy::setStatement)
    .define_method("show_statement", &AdministrationStatementContextProxy::showStatement)
    .define_method("binlog_statement", &AdministrationStatementContextProxy::binlogStatement)
    .define_method("cache_index_statement", &AdministrationStatementContextProxy::cacheIndexStatement)
    .define_method("flush_statement", &AdministrationStatementContextProxy::flushStatement)
    .define_method("kill_statement", &AdministrationStatementContextProxy::killStatement)
    .define_method("load_index_into_cache", &AdministrationStatementContextProxy::loadIndexIntoCache)
    .define_method("reset_statement", &AdministrationStatementContextProxy::resetStatement)
    .define_method("shutdown_statement", &AdministrationStatementContextProxy::shutdownStatement);

  rb_cUtilityStatementContext = rb_mMySqlParser
    .define_class<UtilityStatementContextProxy, ContextProxy>("UtilityStatementContext")
    .define_method("simple_describe_statement", &UtilityStatementContextProxy::simpleDescribeStatement)
    .define_method("full_describe_statement", &UtilityStatementContextProxy::fullDescribeStatement)
    .define_method("help_statement", &UtilityStatementContextProxy::helpStatement)
    .define_method("use_statement", &UtilityStatementContextProxy::useStatement)
    .define_method("signal_statement", &UtilityStatementContextProxy::signalStatement)
    .define_method("resignal_statement", &UtilityStatementContextProxy::resignalStatement)
    .define_method("diagnostics_statement", &UtilityStatementContextProxy::diagnosticsStatement);

  rb_cCreateDatabaseContext = rb_mMySqlParser
    .define_class<CreateDatabaseContextProxy, ContextProxy>("CreateDatabaseContext")
    .define_method("uid", &CreateDatabaseContextProxy::uid)
    .define_method("if_not_exists", &CreateDatabaseContextProxy::ifNotExists)
    .define_method("create_database_option", &CreateDatabaseContextProxy::createDatabaseOption)
    .define_method("create_database_option_at", &CreateDatabaseContextProxy::createDatabaseOptionAt);

  rb_cCreateEventContext = rb_mMySqlParser
    .define_class<CreateEventContextProxy, ContextProxy>("CreateEventContext")
    .define_method("full_id", &CreateEventContextProxy::fullId)
    .define_method("schedule_expression", &CreateEventContextProxy::scheduleExpression)
    .define_method("routine_body", &CreateEventContextProxy::routineBody)
    .define_method("owner_statement", &CreateEventContextProxy::ownerStatement)
    .define_method("if_not_exists", &CreateEventContextProxy::ifNotExists)
    .define_method("enable_type", &CreateEventContextProxy::enableType);

  rb_cCreateIndexContext = rb_mMySqlParser
    .define_class<CreateIndexContextProxy, ContextProxy>("CreateIndexContext")
    .define_method("uid", &CreateIndexContextProxy::uid)
    .define_method("table_name", &CreateIndexContextProxy::tableName)
    .define_method("index_column_names", &CreateIndexContextProxy::indexColumnNames)
    .define_method("index_type", &CreateIndexContextProxy::indexType)
    .define_method("index_option", &CreateIndexContextProxy::indexOption)
    .define_method("index_option_at", &CreateIndexContextProxy::indexOptionAt);

  rb_cCreateLogfileGroupContext = rb_mMySqlParser
    .define_class<CreateLogfileGroupContextProxy, ContextProxy>("CreateLogfileGroupContext")
    .define_method("uid", &CreateLogfileGroupContextProxy::uid)
    .define_method("uid_at", &CreateLogfileGroupContextProxy::uidAt)
    .define_method("engine_name", &CreateLogfileGroupContextProxy::engineName)
    .define_method("file_size_literal", &CreateLogfileGroupContextProxy::fileSizeLiteral)
    .define_method("file_size_literal_at", &CreateLogfileGroupContextProxy::fileSizeLiteralAt);

  rb_cCreateProcedureContext = rb_mMySqlParser
    .define_class<CreateProcedureContextProxy, ContextProxy>("CreateProcedureContext")
    .define_method("full_id", &CreateProcedureContextProxy::fullId)
    .define_method("routine_body", &CreateProcedureContextProxy::routineBody)
    .define_method("owner_statement", &CreateProcedureContextProxy::ownerStatement)
    .define_method("procedure_parameter", &CreateProcedureContextProxy::procedureParameter)
    .define_method("procedure_parameter_at", &CreateProcedureContextProxy::procedureParameterAt)
    .define_method("routine_option", &CreateProcedureContextProxy::routineOption)
    .define_method("routine_option_at", &CreateProcedureContextProxy::routineOptionAt);

  rb_cCreateFunctionContext = rb_mMySqlParser
    .define_class<CreateFunctionContextProxy, ContextProxy>("CreateFunctionContext")
    .define_method("full_id", &CreateFunctionContextProxy::fullId)
    .define_method("data_type", &CreateFunctionContextProxy::dataType)
    .define_method("routine_body", &CreateFunctionContextProxy::routineBody)
    .define_method("return_statement", &CreateFunctionContextProxy::returnStatement)
    .define_method("owner_statement", &CreateFunctionContextProxy::ownerStatement)
    .define_method("function_parameter", &CreateFunctionContextProxy::functionParameter)
    .define_method("function_parameter_at", &CreateFunctionContextProxy::functionParameterAt)
    .define_method("routine_option", &CreateFunctionContextProxy::routineOption)
    .define_method("routine_option_at", &CreateFunctionContextProxy::routineOptionAt);

  rb_cCreateServerContext = rb_mMySqlParser
    .define_class<CreateServerContextProxy, ContextProxy>("CreateServerContext")
    .define_method("uid", &CreateServerContextProxy::uid)
    .define_method("server_option", &CreateServerContextProxy::serverOption)
    .define_method("server_option_at", &CreateServerContextProxy::serverOptionAt);

  rb_cCreateTableContext = rb_mMySqlParser
    .define_class<CreateTableContextProxy, ContextProxy>("CreateTableContext");

  rb_cCreateTablespaceInnodbContext = rb_mMySqlParser
    .define_class<CreateTablespaceInnodbContextProxy, ContextProxy>("CreateTablespaceInnodbContext")
    .define_method("uid", &CreateTablespaceInnodbContextProxy::uid)
    .define_method("engine_name", &CreateTablespaceInnodbContextProxy::engineName)
    .define_method("file_size_literal", &CreateTablespaceInnodbContextProxy::fileSizeLiteral);

  rb_cCreateTablespaceNdbContext = rb_mMySqlParser
    .define_class<CreateTablespaceNdbContextProxy, ContextProxy>("CreateTablespaceNdbContext")
    .define_method("uid", &CreateTablespaceNdbContextProxy::uid)
    .define_method("uid_at", &CreateTablespaceNdbContextProxy::uidAt)
    .define_method("engine_name", &CreateTablespaceNdbContextProxy::engineName)
    .define_method("file_size_literal", &CreateTablespaceNdbContextProxy::fileSizeLiteral)
    .define_method("file_size_literal_at", &CreateTablespaceNdbContextProxy::fileSizeLiteralAt);

  rb_cCreateTriggerContext = rb_mMySqlParser
    .define_class<CreateTriggerContextProxy, ContextProxy>("CreateTriggerContext")
    .define_method("table_name", &CreateTriggerContextProxy::tableName)
    .define_method("routine_body", &CreateTriggerContextProxy::routineBody)
    .define_method("full_id", &CreateTriggerContextProxy::fullId)
    .define_method("full_id_at", &CreateTriggerContextProxy::fullIdAt)
    .define_method("owner_statement", &CreateTriggerContextProxy::ownerStatement);

  rb_cCreateViewContext = rb_mMySqlParser
    .define_class<CreateViewContextProxy, ContextProxy>("CreateViewContext")
    .define_method("full_id", &CreateViewContextProxy::fullId)
    .define_method("select_statement", &CreateViewContextProxy::selectStatement)
    .define_method("owner_statement", &CreateViewContextProxy::ownerStatement)
    .define_method("uid_list", &CreateViewContextProxy::uidList);

  rb_cAlterDatabaseContext = rb_mMySqlParser
    .define_class<AlterDatabaseContextProxy, ContextProxy>("AlterDatabaseContext");

  rb_cAlterEventContext = rb_mMySqlParser
    .define_class<AlterEventContextProxy, ContextProxy>("AlterEventContext")
    .define_method("full_id", &AlterEventContextProxy::fullId)
    .define_method("full_id_at", &AlterEventContextProxy::fullIdAt)
    .define_method("owner_statement", &AlterEventContextProxy::ownerStatement)
    .define_method("schedule_expression", &AlterEventContextProxy::scheduleExpression)
    .define_method("enable_type", &AlterEventContextProxy::enableType)
    .define_method("routine_body", &AlterEventContextProxy::routineBody);

  rb_cAlterFunctionContext = rb_mMySqlParser
    .define_class<AlterFunctionContextProxy, ContextProxy>("AlterFunctionContext")
    .define_method("full_id", &AlterFunctionContextProxy::fullId)
    .define_method("routine_option", &AlterFunctionContextProxy::routineOption)
    .define_method("routine_option_at", &AlterFunctionContextProxy::routineOptionAt);

  rb_cAlterInstanceContext = rb_mMySqlParser
    .define_class<AlterInstanceContextProxy, ContextProxy>("AlterInstanceContext");

  rb_cAlterLogfileGroupContext = rb_mMySqlParser
    .define_class<AlterLogfileGroupContextProxy, ContextProxy>("AlterLogfileGroupContext")
    .define_method("uid", &AlterLogfileGroupContextProxy::uid)
    .define_method("engine_name", &AlterLogfileGroupContextProxy::engineName)
    .define_method("file_size_literal", &AlterLogfileGroupContextProxy::fileSizeLiteral);

  rb_cAlterProcedureContext = rb_mMySqlParser
    .define_class<AlterProcedureContextProxy, ContextProxy>("AlterProcedureContext")
    .define_method("full_id", &AlterProcedureContextProxy::fullId)
    .define_method("routine_option", &AlterProcedureContextProxy::routineOption)
    .define_method("routine_option_at", &AlterProcedureContextProxy::routineOptionAt);

  rb_cAlterServerContext = rb_mMySqlParser
    .define_class<AlterServerContextProxy, ContextProxy>("AlterServerContext")
    .define_method("uid", &AlterServerContextProxy::uid)
    .define_method("server_option", &AlterServerContextProxy::serverOption)
    .define_method("server_option_at", &AlterServerContextProxy::serverOptionAt);

  rb_cAlterTableContext = rb_mMySqlParser
    .define_class<AlterTableContextProxy, ContextProxy>("AlterTableContext")
    .define_method("table_name", &AlterTableContextProxy::tableName)
    .define_method("alter_specification", &AlterTableContextProxy::alterSpecification)
    .define_method("alter_specification_at", &AlterTableContextProxy::alterSpecificationAt)
    .define_method("partition_definitions", &AlterTableContextProxy::partitionDefinitions);

  rb_cAlterTablespaceContext = rb_mMySqlParser
    .define_class<AlterTablespaceContextProxy, ContextProxy>("AlterTablespaceContext")
    .define_method("uid", &AlterTablespaceContextProxy::uid)
    .define_method("engine_name", &AlterTablespaceContextProxy::engineName)
    .define_method("file_size_literal", &AlterTablespaceContextProxy::fileSizeLiteral);

  rb_cAlterViewContext = rb_mMySqlParser
    .define_class<AlterViewContextProxy, ContextProxy>("AlterViewContext")
    .define_method("full_id", &AlterViewContextProxy::fullId)
    .define_method("select_statement", &AlterViewContextProxy::selectStatement)
    .define_method("owner_statement", &AlterViewContextProxy::ownerStatement)
    .define_method("uid_list", &AlterViewContextProxy::uidList);

  rb_cDropDatabaseContext = rb_mMySqlParser
    .define_class<DropDatabaseContextProxy, ContextProxy>("DropDatabaseContext")
    .define_method("uid", &DropDatabaseContextProxy::uid)
    .define_method("if_exists", &DropDatabaseContextProxy::ifExists);

  rb_cDropEventContext = rb_mMySqlParser
    .define_class<DropEventContextProxy, ContextProxy>("DropEventContext")
    .define_method("full_id", &DropEventContextProxy::fullId)
    .define_method("if_exists", &DropEventContextProxy::ifExists);

  rb_cDropIndexContext = rb_mMySqlParser
    .define_class<DropIndexContextProxy, ContextProxy>("DropIndexContext")
    .define_method("uid", &DropIndexContextProxy::uid)
    .define_method("table_name", &DropIndexContextProxy::tableName);

  rb_cDropLogfileGroupContext = rb_mMySqlParser
    .define_class<DropLogfileGroupContextProxy, ContextProxy>("DropLogfileGroupContext")
    .define_method("uid", &DropLogfileGroupContextProxy::uid)
    .define_method("engine_name", &DropLogfileGroupContextProxy::engineName);

  rb_cDropProcedureContext = rb_mMySqlParser
    .define_class<DropProcedureContextProxy, ContextProxy>("DropProcedureContext")
    .define_method("full_id", &DropProcedureContextProxy::fullId)
    .define_method("if_exists", &DropProcedureContextProxy::ifExists);

  rb_cDropFunctionContext = rb_mMySqlParser
    .define_class<DropFunctionContextProxy, ContextProxy>("DropFunctionContext")
    .define_method("full_id", &DropFunctionContextProxy::fullId)
    .define_method("if_exists", &DropFunctionContextProxy::ifExists);

  rb_cDropServerContext = rb_mMySqlParser
    .define_class<DropServerContextProxy, ContextProxy>("DropServerContext")
    .define_method("uid", &DropServerContextProxy::uid)
    .define_method("if_exists", &DropServerContextProxy::ifExists);

  rb_cDropTableContext = rb_mMySqlParser
    .define_class<DropTableContextProxy, ContextProxy>("DropTableContext")
    .define_method("tables", &DropTableContextProxy::tables)
    .define_method("if_exists", &DropTableContextProxy::ifExists);

  rb_cDropTablespaceContext = rb_mMySqlParser
    .define_class<DropTablespaceContextProxy, ContextProxy>("DropTablespaceContext")
    .define_method("uid", &DropTablespaceContextProxy::uid)
    .define_method("engine_name", &DropTablespaceContextProxy::engineName);

  rb_cDropTriggerContext = rb_mMySqlParser
    .define_class<DropTriggerContextProxy, ContextProxy>("DropTriggerContext")
    .define_method("full_id", &DropTriggerContextProxy::fullId)
    .define_method("if_exists", &DropTriggerContextProxy::ifExists);

  rb_cDropViewContext = rb_mMySqlParser
    .define_class<DropViewContextProxy, ContextProxy>("DropViewContext")
    .define_method("full_id", &DropViewContextProxy::fullId)
    .define_method("full_id_at", &DropViewContextProxy::fullIdAt)
    .define_method("if_exists", &DropViewContextProxy::ifExists);

  rb_cRenameTableContext = rb_mMySqlParser
    .define_class<RenameTableContextProxy, ContextProxy>("RenameTableContext")
    .define_method("rename_table_clause", &RenameTableContextProxy::renameTableClause)
    .define_method("rename_table_clause_at", &RenameTableContextProxy::renameTableClauseAt);

  rb_cTruncateTableContext = rb_mMySqlParser
    .define_class<TruncateTableContextProxy, ContextProxy>("TruncateTableContext")
    .define_method("table_name", &TruncateTableContextProxy::tableName);

  rb_cSelectStatementContext = rb_mMySqlParser
    .define_class<SelectStatementContextProxy, ContextProxy>("SelectStatementContext");

  rb_cInsertStatementContext = rb_mMySqlParser
    .define_class<InsertStatementContextProxy, ContextProxy>("InsertStatementContext")
    .define_method("table_name", &InsertStatementContextProxy::tableName)
    .define_method("insert_statement_value", &InsertStatementContextProxy::insertStatementValue)
    .define_method("updated_element", &InsertStatementContextProxy::updatedElement)
    .define_method("updated_element_at", &InsertStatementContextProxy::updatedElementAt)
    .define_method("uid_list", &InsertStatementContextProxy::uidList)
    .define_method("uid_list_at", &InsertStatementContextProxy::uidListAt);

  rb_cUpdateStatementContext = rb_mMySqlParser
    .define_class<UpdateStatementContextProxy, ContextProxy>("UpdateStatementContext")
    .define_method("single_update_statement", &UpdateStatementContextProxy::singleUpdateStatement)
    .define_method("multiple_update_statement", &UpdateStatementContextProxy::multipleUpdateStatement);

  rb_cDeleteStatementContext = rb_mMySqlParser
    .define_class<DeleteStatementContextProxy, ContextProxy>("DeleteStatementContext")
    .define_method("single_delete_statement", &DeleteStatementContextProxy::singleDeleteStatement)
    .define_method("multiple_delete_statement", &DeleteStatementContextProxy::multipleDeleteStatement);

  rb_cReplaceStatementContext = rb_mMySqlParser
    .define_class<ReplaceStatementContextProxy, ContextProxy>("ReplaceStatementContext")
    .define_method("table_name", &ReplaceStatementContextProxy::tableName)
    .define_method("insert_statement_value", &ReplaceStatementContextProxy::insertStatementValue)
    .define_method("updated_element", &ReplaceStatementContextProxy::updatedElement)
    .define_method("updated_element_at", &ReplaceStatementContextProxy::updatedElementAt)
    .define_method("uid_list", &ReplaceStatementContextProxy::uidList)
    .define_method("uid_list_at", &ReplaceStatementContextProxy::uidListAt);

  rb_cCallStatementContext = rb_mMySqlParser
    .define_class<CallStatementContextProxy, ContextProxy>("CallStatementContext")
    .define_method("full_id", &CallStatementContextProxy::fullId)
    .define_method("constants", &CallStatementContextProxy::constants)
    .define_method("expressions", &CallStatementContextProxy::expressions);

  rb_cLoadDataStatementContext = rb_mMySqlParser
    .define_class<LoadDataStatementContextProxy, ContextProxy>("LoadDataStatementContext")
    .define_method("table_name", &LoadDataStatementContextProxy::tableName)
    .define_method("uid_list", &LoadDataStatementContextProxy::uidList)
    .define_method("decimal_literal", &LoadDataStatementContextProxy::decimalLiteral)
    .define_method("assignment_field", &LoadDataStatementContextProxy::assignmentField)
    .define_method("assignment_field_at", &LoadDataStatementContextProxy::assignmentFieldAt)
    .define_method("updated_element", &LoadDataStatementContextProxy::updatedElement)
    .define_method("updated_element_at", &LoadDataStatementContextProxy::updatedElementAt)
    .define_method("charset_name", &LoadDataStatementContextProxy::charsetName)
    .define_method("select_fields_into", &LoadDataStatementContextProxy::selectFieldsInto)
    .define_method("select_fields_into_at", &LoadDataStatementContextProxy::selectFieldsIntoAt)
    .define_method("select_lines_into", &LoadDataStatementContextProxy::selectLinesInto)
    .define_method("select_lines_into_at", &LoadDataStatementContextProxy::selectLinesIntoAt);

  rb_cLoadXmlStatementContext = rb_mMySqlParser
    .define_class<LoadXmlStatementContextProxy, ContextProxy>("LoadXmlStatementContext")
    .define_method("table_name", &LoadXmlStatementContextProxy::tableName)
    .define_method("decimal_literal", &LoadXmlStatementContextProxy::decimalLiteral)
    .define_method("assignment_field", &LoadXmlStatementContextProxy::assignmentField)
    .define_method("assignment_field_at", &LoadXmlStatementContextProxy::assignmentFieldAt)
    .define_method("updated_element", &LoadXmlStatementContextProxy::updatedElement)
    .define_method("updated_element_at", &LoadXmlStatementContextProxy::updatedElementAt)
    .define_method("charset_name", &LoadXmlStatementContextProxy::charsetName);

  rb_cDoStatementContext = rb_mMySqlParser
    .define_class<DoStatementContextProxy, ContextProxy>("DoStatementContext")
    .define_method("expressions", &DoStatementContextProxy::expressions);

  rb_cHandlerStatementContext = rb_mMySqlParser
    .define_class<HandlerStatementContextProxy, ContextProxy>("HandlerStatementContext")
    .define_method("handler_open_statement", &HandlerStatementContextProxy::handlerOpenStatement)
    .define_method("handler_read_index_statement", &HandlerStatementContextProxy::handlerReadIndexStatement)
    .define_method("handler_read_statement", &HandlerStatementContextProxy::handlerReadStatement)
    .define_method("handler_close_statement", &HandlerStatementContextProxy::handlerCloseStatement);

  rb_cStartTransactionContext = rb_mMySqlParser
    .define_class<StartTransactionContextProxy, ContextProxy>("StartTransactionContext")
    .define_method("transaction_mode", &StartTransactionContextProxy::transactionMode)
    .define_method("transaction_mode_at", &StartTransactionContextProxy::transactionModeAt);

  rb_cBeginWorkContext = rb_mMySqlParser
    .define_class<BeginWorkContextProxy, ContextProxy>("BeginWorkContext");

  rb_cCommitWorkContext = rb_mMySqlParser
    .define_class<CommitWorkContextProxy, ContextProxy>("CommitWorkContext");

  rb_cRollbackWorkContext = rb_mMySqlParser
    .define_class<RollbackWorkContextProxy, ContextProxy>("RollbackWorkContext");

  rb_cSavepointStatementContext = rb_mMySqlParser
    .define_class<SavepointStatementContextProxy, ContextProxy>("SavepointStatementContext")
    .define_method("uid", &SavepointStatementContextProxy::uid);

  rb_cRollbackStatementContext = rb_mMySqlParser
    .define_class<RollbackStatementContextProxy, ContextProxy>("RollbackStatementContext")
    .define_method("uid", &RollbackStatementContextProxy::uid);

  rb_cReleaseStatementContext = rb_mMySqlParser
    .define_class<ReleaseStatementContextProxy, ContextProxy>("ReleaseStatementContext")
    .define_method("uid", &ReleaseStatementContextProxy::uid);

  rb_cLockTablesContext = rb_mMySqlParser
    .define_class<LockTablesContextProxy, ContextProxy>("LockTablesContext")
    .define_method("lock_table_element", &LockTablesContextProxy::lockTableElement)
    .define_method("lock_table_element_at", &LockTablesContextProxy::lockTableElementAt);

  rb_cUnlockTablesContext = rb_mMySqlParser
    .define_class<UnlockTablesContextProxy, ContextProxy>("UnlockTablesContext");

  rb_cChangeMasterContext = rb_mMySqlParser
    .define_class<ChangeMasterContextProxy, ContextProxy>("ChangeMasterContext")
    .define_method("master_option", &ChangeMasterContextProxy::masterOption)
    .define_method("master_option_at", &ChangeMasterContextProxy::masterOptionAt)
    .define_method("channel_option", &ChangeMasterContextProxy::channelOption);

  rb_cChangeReplicationFilterContext = rb_mMySqlParser
    .define_class<ChangeReplicationFilterContextProxy, ContextProxy>("ChangeReplicationFilterContext")
    .define_method("replication_filter", &ChangeReplicationFilterContextProxy::replicationFilter)
    .define_method("replication_filter_at", &ChangeReplicationFilterContextProxy::replicationFilterAt);

  rb_cPurgeBinaryLogsContext = rb_mMySqlParser
    .define_class<PurgeBinaryLogsContextProxy, ContextProxy>("PurgeBinaryLogsContext");

  rb_cResetMasterContext = rb_mMySqlParser
    .define_class<ResetMasterContextProxy, ContextProxy>("ResetMasterContext");

  rb_cResetSlaveContext = rb_mMySqlParser
    .define_class<ResetSlaveContextProxy, ContextProxy>("ResetSlaveContext")
    .define_method("channel_option", &ResetSlaveContextProxy::channelOption);

  rb_cStartSlaveContext = rb_mMySqlParser
    .define_class<StartSlaveContextProxy, ContextProxy>("StartSlaveContext")
    .define_method("thread_type", &StartSlaveContextProxy::threadType)
    .define_method("thread_type_at", &StartSlaveContextProxy::threadTypeAt)
    .define_method("until_option", &StartSlaveContextProxy::untilOption)
    .define_method("connection_option", &StartSlaveContextProxy::connectionOption)
    .define_method("connection_option_at", &StartSlaveContextProxy::connectionOptionAt)
    .define_method("channel_option", &StartSlaveContextProxy::channelOption);

  rb_cStopSlaveContext = rb_mMySqlParser
    .define_class<StopSlaveContextProxy, ContextProxy>("StopSlaveContext")
    .define_method("thread_type", &StopSlaveContextProxy::threadType)
    .define_method("thread_type_at", &StopSlaveContextProxy::threadTypeAt);

  rb_cStartGroupReplicationContext = rb_mMySqlParser
    .define_class<StartGroupReplicationContextProxy, ContextProxy>("StartGroupReplicationContext");

  rb_cStopGroupReplicationContext = rb_mMySqlParser
    .define_class<StopGroupReplicationContextProxy, ContextProxy>("StopGroupReplicationContext");

  rb_cXaStartTransactionContext = rb_mMySqlParser
    .define_class<XaStartTransactionContextProxy, ContextProxy>("XaStartTransactionContext")
    .define_method("xid", &XaStartTransactionContextProxy::xid);

  rb_cXaEndTransactionContext = rb_mMySqlParser
    .define_class<XaEndTransactionContextProxy, ContextProxy>("XaEndTransactionContext")
    .define_method("xid", &XaEndTransactionContextProxy::xid);

  rb_cXaPrepareStatementContext = rb_mMySqlParser
    .define_class<XaPrepareStatementContextProxy, ContextProxy>("XaPrepareStatementContext")
    .define_method("xid", &XaPrepareStatementContextProxy::xid);

  rb_cXaCommitWorkContext = rb_mMySqlParser
    .define_class<XaCommitWorkContextProxy, ContextProxy>("XaCommitWorkContext")
    .define_method("xid", &XaCommitWorkContextProxy::xid);

  rb_cXaRollbackWorkContext = rb_mMySqlParser
    .define_class<XaRollbackWorkContextProxy, ContextProxy>("XaRollbackWorkContext")
    .define_method("xid", &XaRollbackWorkContextProxy::xid);

  rb_cXaRecoverWorkContext = rb_mMySqlParser
    .define_class<XaRecoverWorkContextProxy, ContextProxy>("XaRecoverWorkContext")
    .define_method("xid", &XaRecoverWorkContextProxy::xid);

  rb_cPrepareStatementContext = rb_mMySqlParser
    .define_class<PrepareStatementContextProxy, ContextProxy>("PrepareStatementContext")
    .define_method("uid", &PrepareStatementContextProxy::uid);

  rb_cExecuteStatementContext = rb_mMySqlParser
    .define_class<ExecuteStatementContextProxy, ContextProxy>("ExecuteStatementContext")
    .define_method("uid", &ExecuteStatementContextProxy::uid)
    .define_method("user_variables", &ExecuteStatementContextProxy::userVariables);

  rb_cDeallocatePrepareContext = rb_mMySqlParser
    .define_class<DeallocatePrepareContextProxy, ContextProxy>("DeallocatePrepareContext")
    .define_method("uid", &DeallocatePrepareContextProxy::uid);

  rb_cCompoundStatementContext = rb_mMySqlParser
    .define_class<CompoundStatementContextProxy, ContextProxy>("CompoundStatementContext")
    .define_method("block_statement", &CompoundStatementContextProxy::blockStatement)
    .define_method("case_statement", &CompoundStatementContextProxy::caseStatement)
    .define_method("if_statement", &CompoundStatementContextProxy::ifStatement)
    .define_method("leave_statement", &CompoundStatementContextProxy::leaveStatement)
    .define_method("loop_statement", &CompoundStatementContextProxy::loopStatement)
    .define_method("repeat_statement", &CompoundStatementContextProxy::repeatStatement)
    .define_method("while_statement", &CompoundStatementContextProxy::whileStatement)
    .define_method("iterate_statement", &CompoundStatementContextProxy::iterateStatement)
    .define_method("return_statement", &CompoundStatementContextProxy::returnStatement)
    .define_method("cursor_statement", &CompoundStatementContextProxy::cursorStatement);

  rb_cBlockStatementContext = rb_mMySqlParser
    .define_class<BlockStatementContextProxy, ContextProxy>("BlockStatementContext")
    .define_method("uid", &BlockStatementContextProxy::uid)
    .define_method("uid_at", &BlockStatementContextProxy::uidAt)
    .define_method("declare_variable", &BlockStatementContextProxy::declareVariable)
    .define_method("declare_variable_at", &BlockStatementContextProxy::declareVariableAt)
    .define_method("declare_condition", &BlockStatementContextProxy::declareCondition)
    .define_method("declare_condition_at", &BlockStatementContextProxy::declareConditionAt)
    .define_method("declare_cursor", &BlockStatementContextProxy::declareCursor)
    .define_method("declare_cursor_at", &BlockStatementContextProxy::declareCursorAt)
    .define_method("declare_handler", &BlockStatementContextProxy::declareHandler)
    .define_method("declare_handler_at", &BlockStatementContextProxy::declareHandlerAt)
    .define_method("procedure_sql_statement", &BlockStatementContextProxy::procedureSqlStatement)
    .define_method("procedure_sql_statement_at", &BlockStatementContextProxy::procedureSqlStatementAt);

  rb_cCaseStatementContext = rb_mMySqlParser
    .define_class<CaseStatementContextProxy, ContextProxy>("CaseStatementContext")
    .define_method("uid", &CaseStatementContextProxy::uid)
    .define_method("expression", &CaseStatementContextProxy::expression)
    .define_method("case_alternative", &CaseStatementContextProxy::caseAlternative)
    .define_method("case_alternative_at", &CaseStatementContextProxy::caseAlternativeAt)
    .define_method("procedure_sql_statement", &CaseStatementContextProxy::procedureSqlStatement)
    .define_method("procedure_sql_statement_at", &CaseStatementContextProxy::procedureSqlStatementAt);

  rb_cIfStatementContext = rb_mMySqlParser
    .define_class<IfStatementContextProxy, ContextProxy>("IfStatementContext")
    .define_method("expression", &IfStatementContextProxy::expression)
    .define_method("elif_alternative", &IfStatementContextProxy::elifAlternative)
    .define_method("elif_alternative_at", &IfStatementContextProxy::elifAlternativeAt)
    .define_method("procedure_sql_statement", &IfStatementContextProxy::procedureSqlStatement)
    .define_method("procedure_sql_statement_at", &IfStatementContextProxy::procedureSqlStatementAt);

  rb_cLeaveStatementContext = rb_mMySqlParser
    .define_class<LeaveStatementContextProxy, ContextProxy>("LeaveStatementContext")
    .define_method("uid", &LeaveStatementContextProxy::uid);

  rb_cLoopStatementContext = rb_mMySqlParser
    .define_class<LoopStatementContextProxy, ContextProxy>("LoopStatementContext")
    .define_method("uid", &LoopStatementContextProxy::uid)
    .define_method("uid_at", &LoopStatementContextProxy::uidAt)
    .define_method("procedure_sql_statement", &LoopStatementContextProxy::procedureSqlStatement)
    .define_method("procedure_sql_statement_at", &LoopStatementContextProxy::procedureSqlStatementAt);

  rb_cRepeatStatementContext = rb_mMySqlParser
    .define_class<RepeatStatementContextProxy, ContextProxy>("RepeatStatementContext")
    .define_method("expression", &RepeatStatementContextProxy::expression)
    .define_method("uid", &RepeatStatementContextProxy::uid)
    .define_method("uid_at", &RepeatStatementContextProxy::uidAt)
    .define_method("procedure_sql_statement", &RepeatStatementContextProxy::procedureSqlStatement)
    .define_method("procedure_sql_statement_at", &RepeatStatementContextProxy::procedureSqlStatementAt);

  rb_cWhileStatementContext = rb_mMySqlParser
    .define_class<WhileStatementContextProxy, ContextProxy>("WhileStatementContext")
    .define_method("expression", &WhileStatementContextProxy::expression)
    .define_method("uid", &WhileStatementContextProxy::uid)
    .define_method("uid_at", &WhileStatementContextProxy::uidAt)
    .define_method("procedure_sql_statement", &WhileStatementContextProxy::procedureSqlStatement)
    .define_method("procedure_sql_statement_at", &WhileStatementContextProxy::procedureSqlStatementAt);

  rb_cIterateStatementContext = rb_mMySqlParser
    .define_class<IterateStatementContextProxy, ContextProxy>("IterateStatementContext")
    .define_method("uid", &IterateStatementContextProxy::uid);

  rb_cReturnStatementContext = rb_mMySqlParser
    .define_class<ReturnStatementContextProxy, ContextProxy>("ReturnStatementContext")
    .define_method("expression", &ReturnStatementContextProxy::expression);

  rb_cCursorStatementContext = rb_mMySqlParser
    .define_class<CursorStatementContextProxy, ContextProxy>("CursorStatementContext");

  rb_cAlterUserContext = rb_mMySqlParser
    .define_class<AlterUserContextProxy, ContextProxy>("AlterUserContext");

  rb_cCreateUserContext = rb_mMySqlParser
    .define_class<CreateUserContextProxy, ContextProxy>("CreateUserContext");

  rb_cDropUserContext = rb_mMySqlParser
    .define_class<DropUserContextProxy, ContextProxy>("DropUserContext")
    .define_method("user_name", &DropUserContextProxy::userName)
    .define_method("user_name_at", &DropUserContextProxy::userNameAt)
    .define_method("if_exists", &DropUserContextProxy::ifExists);

  rb_cGrantStatementContext = rb_mMySqlParser
    .define_class<GrantStatementContextProxy, ContextProxy>("GrantStatementContext")
    .define_method("privelege_clause", &GrantStatementContextProxy::privelegeClause)
    .define_method("privelege_clause_at", &GrantStatementContextProxy::privelegeClauseAt)
    .define_method("privilege_level", &GrantStatementContextProxy::privilegeLevel)
    .define_method("user_auth_option", &GrantStatementContextProxy::userAuthOption)
    .define_method("user_auth_option_at", &GrantStatementContextProxy::userAuthOptionAt)
    .define_method("tls_option", &GrantStatementContextProxy::tlsOption)
    .define_method("tls_option_at", &GrantStatementContextProxy::tlsOptionAt)
    .define_method("user_resource_option", &GrantStatementContextProxy::userResourceOption)
    .define_method("user_resource_option_at", &GrantStatementContextProxy::userResourceOptionAt);

  rb_cGrantProxyContext = rb_mMySqlParser
    .define_class<GrantProxyContextProxy, ContextProxy>("GrantProxyContext")
    .define_method("user_name", &GrantProxyContextProxy::userName)
    .define_method("user_name_at", &GrantProxyContextProxy::userNameAt);

  rb_cRenameUserContext = rb_mMySqlParser
    .define_class<RenameUserContextProxy, ContextProxy>("RenameUserContext")
    .define_method("rename_user_clause", &RenameUserContextProxy::renameUserClause)
    .define_method("rename_user_clause_at", &RenameUserContextProxy::renameUserClauseAt);

  rb_cRevokeStatementContext = rb_mMySqlParser
    .define_class<RevokeStatementContextProxy, ContextProxy>("RevokeStatementContext");

  rb_cRevokeProxyContext = rb_mMySqlParser
    .define_class<RevokeProxyContextProxy, ContextProxy>("RevokeProxyContext")
    .define_method("user_name", &RevokeProxyContextProxy::userName)
    .define_method("user_name_at", &RevokeProxyContextProxy::userNameAt);

  rb_cAnalyzeTableContext = rb_mMySqlParser
    .define_class<AnalyzeTableContextProxy, ContextProxy>("AnalyzeTableContext")
    .define_method("tables", &AnalyzeTableContextProxy::tables);

  rb_cCheckTableContext = rb_mMySqlParser
    .define_class<CheckTableContextProxy, ContextProxy>("CheckTableContext")
    .define_method("tables", &CheckTableContextProxy::tables)
    .define_method("check_table_option", &CheckTableContextProxy::checkTableOption)
    .define_method("check_table_option_at", &CheckTableContextProxy::checkTableOptionAt);

  rb_cChecksumTableContext = rb_mMySqlParser
    .define_class<ChecksumTableContextProxy, ContextProxy>("ChecksumTableContext")
    .define_method("tables", &ChecksumTableContextProxy::tables);

  rb_cOptimizeTableContext = rb_mMySqlParser
    .define_class<OptimizeTableContextProxy, ContextProxy>("OptimizeTableContext")
    .define_method("tables", &OptimizeTableContextProxy::tables);

  rb_cRepairTableContext = rb_mMySqlParser
    .define_class<RepairTableContextProxy, ContextProxy>("RepairTableContext")
    .define_method("tables", &RepairTableContextProxy::tables);

  rb_cCreateUdfunctionContext = rb_mMySqlParser
    .define_class<CreateUdfunctionContextProxy, ContextProxy>("CreateUdfunctionContext")
    .define_method("uid", &CreateUdfunctionContextProxy::uid);

  rb_cInstallPluginContext = rb_mMySqlParser
    .define_class<InstallPluginContextProxy, ContextProxy>("InstallPluginContext")
    .define_method("uid", &InstallPluginContextProxy::uid);

  rb_cUninstallPluginContext = rb_mMySqlParser
    .define_class<UninstallPluginContextProxy, ContextProxy>("UninstallPluginContext")
    .define_method("uid", &UninstallPluginContextProxy::uid);

  rb_cSetStatementContext = rb_mMySqlParser
    .define_class<SetStatementContextProxy, ContextProxy>("SetStatementContext");

  rb_cShowStatementContext = rb_mMySqlParser
    .define_class<ShowStatementContextProxy, ContextProxy>("ShowStatementContext");

  rb_cBinlogStatementContext = rb_mMySqlParser
    .define_class<BinlogStatementContextProxy, ContextProxy>("BinlogStatementContext");

  rb_cCacheIndexStatementContext = rb_mMySqlParser
    .define_class<CacheIndexStatementContextProxy, ContextProxy>("CacheIndexStatementContext")
    .define_method("table_indexes", &CacheIndexStatementContextProxy::tableIndexes)
    .define_method("table_indexes_at", &CacheIndexStatementContextProxy::tableIndexesAt)
    .define_method("uid", &CacheIndexStatementContextProxy::uid)
    .define_method("uid_list", &CacheIndexStatementContextProxy::uidList);

  rb_cFlushStatementContext = rb_mMySqlParser
    .define_class<FlushStatementContextProxy, ContextProxy>("FlushStatementContext")
    .define_method("flush_option", &FlushStatementContextProxy::flushOption)
    .define_method("flush_option_at", &FlushStatementContextProxy::flushOptionAt);

  rb_cKillStatementContext = rb_mMySqlParser
    .define_class<KillStatementContextProxy, ContextProxy>("KillStatementContext")
    .define_method("decimal_literal", &KillStatementContextProxy::decimalLiteral)
    .define_method("decimal_literal_at", &KillStatementContextProxy::decimalLiteralAt);

  rb_cLoadIndexIntoCacheContext = rb_mMySqlParser
    .define_class<LoadIndexIntoCacheContextProxy, ContextProxy>("LoadIndexIntoCacheContext")
    .define_method("loaded_table_indexes", &LoadIndexIntoCacheContextProxy::loadedTableIndexes)
    .define_method("loaded_table_indexes_at", &LoadIndexIntoCacheContextProxy::loadedTableIndexesAt);

  rb_cResetStatementContext = rb_mMySqlParser
    .define_class<ResetStatementContextProxy, ContextProxy>("ResetStatementContext");

  rb_cShutdownStatementContext = rb_mMySqlParser
    .define_class<ShutdownStatementContextProxy, ContextProxy>("ShutdownStatementContext");

  rb_cSimpleDescribeStatementContext = rb_mMySqlParser
    .define_class<SimpleDescribeStatementContextProxy, ContextProxy>("SimpleDescribeStatementContext")
    .define_method("table_name", &SimpleDescribeStatementContextProxy::tableName)
    .define_method("uid", &SimpleDescribeStatementContextProxy::uid);

  rb_cFullDescribeStatementContext = rb_mMySqlParser
    .define_class<FullDescribeStatementContextProxy, ContextProxy>("FullDescribeStatementContext")
    .define_method("describe_object_clause", &FullDescribeStatementContextProxy::describeObjectClause);

  rb_cHelpStatementContext = rb_mMySqlParser
    .define_class<HelpStatementContextProxy, ContextProxy>("HelpStatementContext");

  rb_cUseStatementContext = rb_mMySqlParser
    .define_class<UseStatementContextProxy, ContextProxy>("UseStatementContext")
    .define_method("uid", &UseStatementContextProxy::uid);

  rb_cSignalStatementContext = rb_mMySqlParser
    .define_class<SignalStatementContextProxy, ContextProxy>("SignalStatementContext")
    .define_method("signal_condition_information", &SignalStatementContextProxy::signalConditionInformation)
    .define_method("signal_condition_information_at", &SignalStatementContextProxy::signalConditionInformationAt)
    .define_method("string_literal", &SignalStatementContextProxy::stringLiteral);

  rb_cResignalStatementContext = rb_mMySqlParser
    .define_class<ResignalStatementContextProxy, ContextProxy>("ResignalStatementContext")
    .define_method("signal_condition_information", &ResignalStatementContextProxy::signalConditionInformation)
    .define_method("signal_condition_information_at", &ResignalStatementContextProxy::signalConditionInformationAt)
    .define_method("string_literal", &ResignalStatementContextProxy::stringLiteral);

  rb_cDiagnosticsStatementContext = rb_mMySqlParser
    .define_class<DiagnosticsStatementContextProxy, ContextProxy>("DiagnosticsStatementContext")
    .define_method("variable_clause", &DiagnosticsStatementContextProxy::variableClause)
    .define_method("variable_clause_at", &DiagnosticsStatementContextProxy::variableClauseAt)
    .define_method("diagnostics_condition_information_name", &DiagnosticsStatementContextProxy::diagnosticsConditionInformationName)
    .define_method("diagnostics_condition_information_name_at", &DiagnosticsStatementContextProxy::diagnosticsConditionInformationNameAt)
    .define_method("decimal_literal", &DiagnosticsStatementContextProxy::decimalLiteral);

  rb_cUidContext = rb_mMySqlParser
    .define_class<UidContextProxy, ContextProxy>("UidContext")
    .define_method("simple_id", &UidContextProxy::simpleId);

  rb_cIfNotExistsContext = rb_mMySqlParser
    .define_class<IfNotExistsContextProxy, ContextProxy>("IfNotExistsContext");

  rb_cCreateDatabaseOptionContext = rb_mMySqlParser
    .define_class<CreateDatabaseOptionContextProxy, ContextProxy>("CreateDatabaseOptionContext")
    .define_method("charset_name", &CreateDatabaseOptionContextProxy::charsetName)
    .define_method("collation_name", &CreateDatabaseOptionContextProxy::collationName);

  rb_cFullIdContext = rb_mMySqlParser
    .define_class<FullIdContextProxy, ContextProxy>("FullIdContext")
    .define_method("uid", &FullIdContextProxy::uid)
    .define_method("uid_at", &FullIdContextProxy::uidAt);

  rb_cScheduleExpressionContext = rb_mMySqlParser
    .define_class<ScheduleExpressionContextProxy, ContextProxy>("ScheduleExpressionContext");

  rb_cRoutineBodyContext = rb_mMySqlParser
    .define_class<RoutineBodyContextProxy, ContextProxy>("RoutineBodyContext")
    .define_method("block_statement", &RoutineBodyContextProxy::blockStatement)
    .define_method("sql_statement", &RoutineBodyContextProxy::sqlStatement);

  rb_cOwnerStatementContext = rb_mMySqlParser
    .define_class<OwnerStatementContextProxy, ContextProxy>("OwnerStatementContext")
    .define_method("user_name", &OwnerStatementContextProxy::userName);

  rb_cEnableTypeContext = rb_mMySqlParser
    .define_class<EnableTypeContextProxy, ContextProxy>("EnableTypeContext");

  rb_cTableNameContext = rb_mMySqlParser
    .define_class<TableNameContextProxy, ContextProxy>("TableNameContext")
    .define_method("full_id", &TableNameContextProxy::fullId);

  rb_cIndexColumnNamesContext = rb_mMySqlParser
    .define_class<IndexColumnNamesContextProxy, ContextProxy>("IndexColumnNamesContext")
    .define_method("index_column_name", &IndexColumnNamesContextProxy::indexColumnName)
    .define_method("index_column_name_at", &IndexColumnNamesContextProxy::indexColumnNameAt);

  rb_cIndexTypeContext = rb_mMySqlParser
    .define_class<IndexTypeContextProxy, ContextProxy>("IndexTypeContext");

  rb_cIndexOptionContext = rb_mMySqlParser
    .define_class<IndexOptionContextProxy, ContextProxy>("IndexOptionContext")
    .define_method("file_size_literal", &IndexOptionContextProxy::fileSizeLiteral)
    .define_method("index_type", &IndexOptionContextProxy::indexType)
    .define_method("uid", &IndexOptionContextProxy::uid);

  rb_cEngineNameContext = rb_mMySqlParser
    .define_class<EngineNameContextProxy, ContextProxy>("EngineNameContext");

  rb_cFileSizeLiteralContext = rb_mMySqlParser
    .define_class<FileSizeLiteralContextProxy, ContextProxy>("FileSizeLiteralContext")
    .define_method("decimal_literal", &FileSizeLiteralContextProxy::decimalLiteral);

  rb_cProcedureParameterContext = rb_mMySqlParser
    .define_class<ProcedureParameterContextProxy, ContextProxy>("ProcedureParameterContext")
    .define_method("uid", &ProcedureParameterContextProxy::uid)
    .define_method("data_type", &ProcedureParameterContextProxy::dataType);

  rb_cRoutineOptionContext = rb_mMySqlParser
    .define_class<RoutineOptionContextProxy, ContextProxy>("RoutineOptionContext");

  rb_cDataTypeContext = rb_mMySqlParser
    .define_class<DataTypeContextProxy, ContextProxy>("DataTypeContext");

  rb_cFunctionParameterContext = rb_mMySqlParser
    .define_class<FunctionParameterContextProxy, ContextProxy>("FunctionParameterContext")
    .define_method("uid", &FunctionParameterContextProxy::uid)
    .define_method("data_type", &FunctionParameterContextProxy::dataType);

  rb_cServerOptionContext = rb_mMySqlParser
    .define_class<ServerOptionContextProxy, ContextProxy>("ServerOptionContext")
    .define_method("decimal_literal", &ServerOptionContextProxy::decimalLiteral);

  rb_cCopyCreateTableContext = rb_mMySqlParser
    .define_class<CopyCreateTableContextProxy, ContextProxy>("CopyCreateTableContext")
    .define_method("table_name", &CopyCreateTableContextProxy::tableName)
    .define_method("table_name_at", &CopyCreateTableContextProxy::tableNameAt)
    .define_method("if_not_exists", &CopyCreateTableContextProxy::ifNotExists);

  rb_cColumnCreateTableContext = rb_mMySqlParser
    .define_class<ColumnCreateTableContextProxy, ContextProxy>("ColumnCreateTableContext")
    .define_method("table_name", &ColumnCreateTableContextProxy::tableName)
    .define_method("create_definitions", &ColumnCreateTableContextProxy::createDefinitions)
    .define_method("if_not_exists", &ColumnCreateTableContextProxy::ifNotExists)
    .define_method("table_option", &ColumnCreateTableContextProxy::tableOption)
    .define_method("table_option_at", &ColumnCreateTableContextProxy::tableOptionAt)
    .define_method("partition_definitions", &ColumnCreateTableContextProxy::partitionDefinitions);

  rb_cCreateDefinitionsContext = rb_mMySqlParser
    .define_class<CreateDefinitionsContextProxy, ContextProxy>("CreateDefinitionsContext")
    .define_method("create_definition", &CreateDefinitionsContextProxy::createDefinition)
    .define_method("create_definition_at", &CreateDefinitionsContextProxy::createDefinitionAt);

  rb_cTableOptionContext = rb_mMySqlParser
    .define_class<TableOptionContextProxy, ContextProxy>("TableOptionContext");

  rb_cPartitionDefinitionsContext = rb_mMySqlParser
    .define_class<PartitionDefinitionsContextProxy, ContextProxy>("PartitionDefinitionsContext")
    .define_method("partition_function_definition", &PartitionDefinitionsContextProxy::partitionFunctionDefinition)
    .define_method("subpartition_function_definition", &PartitionDefinitionsContextProxy::subpartitionFunctionDefinition)
    .define_method("partition_definition", &PartitionDefinitionsContextProxy::partitionDefinition)
    .define_method("partition_definition_at", &PartitionDefinitionsContextProxy::partitionDefinitionAt)
    .define_method("decimal_literal", &PartitionDefinitionsContextProxy::decimalLiteral)
    .define_method("decimal_literal_at", &PartitionDefinitionsContextProxy::decimalLiteralAt);

  rb_cQueryCreateTableContext = rb_mMySqlParser
    .define_class<QueryCreateTableContextProxy, ContextProxy>("QueryCreateTableContext")
    .define_method("table_name", &QueryCreateTableContextProxy::tableName)
    .define_method("select_statement", &QueryCreateTableContextProxy::selectStatement)
    .define_method("if_not_exists", &QueryCreateTableContextProxy::ifNotExists)
    .define_method("create_definitions", &QueryCreateTableContextProxy::createDefinitions)
    .define_method("table_option", &QueryCreateTableContextProxy::tableOption)
    .define_method("table_option_at", &QueryCreateTableContextProxy::tableOptionAt)
    .define_method("partition_definitions", &QueryCreateTableContextProxy::partitionDefinitions);

  rb_cUidListContext = rb_mMySqlParser
    .define_class<UidListContextProxy, ContextProxy>("UidListContext")
    .define_method("uid", &UidListContextProxy::uid)
    .define_method("uid_at", &UidListContextProxy::uidAt);

  rb_cCharsetNameContext = rb_mMySqlParser
    .define_class<CharsetNameContextProxy, ContextProxy>("CharsetNameContext")
    .define_method("charset_name_base", &CharsetNameContextProxy::charsetNameBase);

  rb_cCollationNameContext = rb_mMySqlParser
    .define_class<CollationNameContextProxy, ContextProxy>("CollationNameContext")
    .define_method("uid", &CollationNameContextProxy::uid);

  rb_cUserNameContext = rb_mMySqlParser
    .define_class<UserNameContextProxy, ContextProxy>("UserNameContext");

  rb_cPreciseScheduleContext = rb_mMySqlParser
    .define_class<PreciseScheduleContextProxy, ContextProxy>("PreciseScheduleContext")
    .define_method("timestamp_value", &PreciseScheduleContextProxy::timestampValue)
    .define_method("interval_expr", &PreciseScheduleContextProxy::intervalExpr)
    .define_method("interval_expr_at", &PreciseScheduleContextProxy::intervalExprAt);

  rb_cTimestampValueContext = rb_mMySqlParser
    .define_class<TimestampValueContextProxy, ContextProxy>("TimestampValueContext")
    .define_method("string_literal", &TimestampValueContextProxy::stringLiteral)
    .define_method("decimal_literal", &TimestampValueContextProxy::decimalLiteral)
    .define_method("expression", &TimestampValueContextProxy::expression);

  rb_cIntervalExprContext = rb_mMySqlParser
    .define_class<IntervalExprContextProxy, ContextProxy>("IntervalExprContext")
    .define_method("interval_type", &IntervalExprContextProxy::intervalType)
    .define_method("decimal_literal", &IntervalExprContextProxy::decimalLiteral)
    .define_method("expression", &IntervalExprContextProxy::expression);

  rb_cIntervalScheduleContext = rb_mMySqlParser
    .define_class<IntervalScheduleContextProxy, ContextProxy>("IntervalScheduleContext")
    .define_method("interval_type", &IntervalScheduleContextProxy::intervalType)
    .define_method("decimal_literal", &IntervalScheduleContextProxy::decimalLiteral)
    .define_method("expression", &IntervalScheduleContextProxy::expression)
    .define_method("timestamp_value", &IntervalScheduleContextProxy::timestampValue)
    .define_method("timestamp_value_at", &IntervalScheduleContextProxy::timestampValueAt)
    .define_method("interval_expr", &IntervalScheduleContextProxy::intervalExpr)
    .define_method("interval_expr_at", &IntervalScheduleContextProxy::intervalExprAt);

  rb_cIntervalTypeContext = rb_mMySqlParser
    .define_class<IntervalTypeContextProxy, ContextProxy>("IntervalTypeContext")
    .define_method("interval_type_base", &IntervalTypeContextProxy::intervalTypeBase);

  rb_cDecimalLiteralContext = rb_mMySqlParser
    .define_class<DecimalLiteralContextProxy, ContextProxy>("DecimalLiteralContext");

  rb_cExpressionContext = rb_mMySqlParser
    .define_class<ExpressionContextProxy, ContextProxy>("ExpressionContext");

  rb_cStringLiteralContext = rb_mMySqlParser
    .define_class<StringLiteralContextProxy, ContextProxy>("StringLiteralContext")
    .define_method("collation_name", &StringLiteralContextProxy::collationName);

  rb_cIntervalTypeBaseContext = rb_mMySqlParser
    .define_class<IntervalTypeBaseContextProxy, ContextProxy>("IntervalTypeBaseContext");

  rb_cRoutineBehaviorContext = rb_mMySqlParser
    .define_class<RoutineBehaviorContextProxy, ContextProxy>("RoutineBehaviorContext");

  rb_cRoutineLanguageContext = rb_mMySqlParser
    .define_class<RoutineLanguageContextProxy, ContextProxy>("RoutineLanguageContext");

  rb_cRoutineCommentContext = rb_mMySqlParser
    .define_class<RoutineCommentContextProxy, ContextProxy>("RoutineCommentContext");

  rb_cRoutineSecurityContext = rb_mMySqlParser
    .define_class<RoutineSecurityContextProxy, ContextProxy>("RoutineSecurityContext");

  rb_cRoutineDataContext = rb_mMySqlParser
    .define_class<RoutineDataContextProxy, ContextProxy>("RoutineDataContext");

  rb_cCreateDefinitionContext = rb_mMySqlParser
    .define_class<CreateDefinitionContextProxy, ContextProxy>("CreateDefinitionContext");

  rb_cColumnDeclarationContext = rb_mMySqlParser
    .define_class<ColumnDeclarationContextProxy, ContextProxy>("ColumnDeclarationContext")
    .define_method("uid", &ColumnDeclarationContextProxy::uid)
    .define_method("column_definition", &ColumnDeclarationContextProxy::columnDefinition);

  rb_cColumnDefinitionContext = rb_mMySqlParser
    .define_class<ColumnDefinitionContextProxy, ContextProxy>("ColumnDefinitionContext")
    .define_method("data_type", &ColumnDefinitionContextProxy::dataType)
    .define_method("column_constraint", &ColumnDefinitionContextProxy::columnConstraint)
    .define_method("column_constraint_at", &ColumnDefinitionContextProxy::columnConstraintAt);

  rb_cTableConstraintContext = rb_mMySqlParser
    .define_class<TableConstraintContextProxy, ContextProxy>("TableConstraintContext");

  rb_cConstraintDeclarationContext = rb_mMySqlParser
    .define_class<ConstraintDeclarationContextProxy, ContextProxy>("ConstraintDeclarationContext")
    .define_method("table_constraint", &ConstraintDeclarationContextProxy::tableConstraint);

  rb_cIndexColumnDefinitionContext = rb_mMySqlParser
    .define_class<IndexColumnDefinitionContextProxy, ContextProxy>("IndexColumnDefinitionContext");

  rb_cIndexDeclarationContext = rb_mMySqlParser
    .define_class<IndexDeclarationContextProxy, ContextProxy>("IndexDeclarationContext")
    .define_method("index_column_definition", &IndexDeclarationContextProxy::indexColumnDefinition);

  rb_cColumnConstraintContext = rb_mMySqlParser
    .define_class<ColumnConstraintContextProxy, ContextProxy>("ColumnConstraintContext");

  rb_cStorageColumnConstraintContext = rb_mMySqlParser
    .define_class<StorageColumnConstraintContextProxy, ContextProxy>("StorageColumnConstraintContext");

  rb_cFormatColumnConstraintContext = rb_mMySqlParser
    .define_class<FormatColumnConstraintContextProxy, ContextProxy>("FormatColumnConstraintContext");

  rb_cCollateColumnConstraintContext = rb_mMySqlParser
    .define_class<CollateColumnConstraintContextProxy, ContextProxy>("CollateColumnConstraintContext")
    .define_method("collation_name", &CollateColumnConstraintContextProxy::collationName);

  rb_cAutoIncrementColumnConstraintContext = rb_mMySqlParser
    .define_class<AutoIncrementColumnConstraintContextProxy, ContextProxy>("AutoIncrementColumnConstraintContext")
    .define_method("current_timestamp", &AutoIncrementColumnConstraintContextProxy::currentTimestamp);

  rb_cCurrentTimestampContext = rb_mMySqlParser
    .define_class<CurrentTimestampContextProxy, ContextProxy>("CurrentTimestampContext")
    .define_method("decimal_literal", &CurrentTimestampContextProxy::decimalLiteral);

  rb_cCommentColumnConstraintContext = rb_mMySqlParser
    .define_class<CommentColumnConstraintContextProxy, ContextProxy>("CommentColumnConstraintContext");

  rb_cPrimaryKeyColumnConstraintContext = rb_mMySqlParser
    .define_class<PrimaryKeyColumnConstraintContextProxy, ContextProxy>("PrimaryKeyColumnConstraintContext");

  rb_cUniqueKeyColumnConstraintContext = rb_mMySqlParser
    .define_class<UniqueKeyColumnConstraintContextProxy, ContextProxy>("UniqueKeyColumnConstraintContext");

  rb_cSerialDefaultColumnConstraintContext = rb_mMySqlParser
    .define_class<SerialDefaultColumnConstraintContextProxy, ContextProxy>("SerialDefaultColumnConstraintContext");

  rb_cNullNotnullContext = rb_mMySqlParser
    .define_class<NullNotnullContextProxy, ContextProxy>("NullNotnullContext");

  rb_cNullColumnConstraintContext = rb_mMySqlParser
    .define_class<NullColumnConstraintContextProxy, ContextProxy>("NullColumnConstraintContext")
    .define_method("null_notnull", &NullColumnConstraintContextProxy::nullNotnull);

  rb_cDefaultColumnConstraintContext = rb_mMySqlParser
    .define_class<DefaultColumnConstraintContextProxy, ContextProxy>("DefaultColumnConstraintContext")
    .define_method("default_value", &DefaultColumnConstraintContextProxy::defaultValue);

  rb_cDefaultValueContext = rb_mMySqlParser
    .define_class<DefaultValueContextProxy, ContextProxy>("DefaultValueContext")
    .define_method("constant", &DefaultValueContextProxy::constant)
    .define_method("unary_operator", &DefaultValueContextProxy::unaryOperator)
    .define_method("current_timestamp", &DefaultValueContextProxy::currentTimestamp)
    .define_method("current_timestamp_at", &DefaultValueContextProxy::currentTimestampAt);

  rb_cReferenceDefinitionContext = rb_mMySqlParser
    .define_class<ReferenceDefinitionContextProxy, ContextProxy>("ReferenceDefinitionContext")
    .define_method("table_name", &ReferenceDefinitionContextProxy::tableName)
    .define_method("index_column_names", &ReferenceDefinitionContextProxy::indexColumnNames)
    .define_method("reference_action", &ReferenceDefinitionContextProxy::referenceAction);

  rb_cReferenceColumnConstraintContext = rb_mMySqlParser
    .define_class<ReferenceColumnConstraintContextProxy, ContextProxy>("ReferenceColumnConstraintContext")
    .define_method("reference_definition", &ReferenceColumnConstraintContextProxy::referenceDefinition);

  rb_cGeneratedColumnConstraintContext = rb_mMySqlParser
    .define_class<GeneratedColumnConstraintContextProxy, ContextProxy>("GeneratedColumnConstraintContext")
    .define_method("expression", &GeneratedColumnConstraintContextProxy::expression);

  rb_cUniqueKeyTableConstraintContext = rb_mMySqlParser
    .define_class<UniqueKeyTableConstraintContextProxy, ContextProxy>("UniqueKeyTableConstraintContext")
    .define_method("index_column_names", &UniqueKeyTableConstraintContextProxy::indexColumnNames)
    .define_method("index_type", &UniqueKeyTableConstraintContextProxy::indexType)
    .define_method("index_option", &UniqueKeyTableConstraintContextProxy::indexOption)
    .define_method("index_option_at", &UniqueKeyTableConstraintContextProxy::indexOptionAt)
    .define_method("uid", &UniqueKeyTableConstraintContextProxy::uid)
    .define_method("uid_at", &UniqueKeyTableConstraintContextProxy::uidAt);

  rb_cCheckTableConstraintContext = rb_mMySqlParser
    .define_class<CheckTableConstraintContextProxy, ContextProxy>("CheckTableConstraintContext")
    .define_method("expression", &CheckTableConstraintContextProxy::expression)
    .define_method("uid", &CheckTableConstraintContextProxy::uid);

  rb_cPrimaryKeyTableConstraintContext = rb_mMySqlParser
    .define_class<PrimaryKeyTableConstraintContextProxy, ContextProxy>("PrimaryKeyTableConstraintContext")
    .define_method("index_column_names", &PrimaryKeyTableConstraintContextProxy::indexColumnNames)
    .define_method("index_type", &PrimaryKeyTableConstraintContextProxy::indexType)
    .define_method("index_option", &PrimaryKeyTableConstraintContextProxy::indexOption)
    .define_method("index_option_at", &PrimaryKeyTableConstraintContextProxy::indexOptionAt)
    .define_method("uid", &PrimaryKeyTableConstraintContextProxy::uid)
    .define_method("uid_at", &PrimaryKeyTableConstraintContextProxy::uidAt);

  rb_cForeignKeyTableConstraintContext = rb_mMySqlParser
    .define_class<ForeignKeyTableConstraintContextProxy, ContextProxy>("ForeignKeyTableConstraintContext")
    .define_method("index_column_names", &ForeignKeyTableConstraintContextProxy::indexColumnNames)
    .define_method("reference_definition", &ForeignKeyTableConstraintContextProxy::referenceDefinition)
    .define_method("uid", &ForeignKeyTableConstraintContextProxy::uid)
    .define_method("uid_at", &ForeignKeyTableConstraintContextProxy::uidAt);

  rb_cReferenceActionContext = rb_mMySqlParser
    .define_class<ReferenceActionContextProxy, ContextProxy>("ReferenceActionContext")
    .define_method("reference_control_type", &ReferenceActionContextProxy::referenceControlType)
    .define_method("reference_control_type_at", &ReferenceActionContextProxy::referenceControlTypeAt);

  rb_cReferenceControlTypeContext = rb_mMySqlParser
    .define_class<ReferenceControlTypeContextProxy, ContextProxy>("ReferenceControlTypeContext");

  rb_cSpecialIndexDeclarationContext = rb_mMySqlParser
    .define_class<SpecialIndexDeclarationContextProxy, ContextProxy>("SpecialIndexDeclarationContext")
    .define_method("index_column_names", &SpecialIndexDeclarationContextProxy::indexColumnNames)
    .define_method("uid", &SpecialIndexDeclarationContextProxy::uid)
    .define_method("index_option", &SpecialIndexDeclarationContextProxy::indexOption)
    .define_method("index_option_at", &SpecialIndexDeclarationContextProxy::indexOptionAt);

  rb_cSimpleIndexDeclarationContext = rb_mMySqlParser
    .define_class<SimpleIndexDeclarationContextProxy, ContextProxy>("SimpleIndexDeclarationContext")
    .define_method("index_column_names", &SimpleIndexDeclarationContextProxy::indexColumnNames)
    .define_method("uid", &SimpleIndexDeclarationContextProxy::uid)
    .define_method("index_type", &SimpleIndexDeclarationContextProxy::indexType)
    .define_method("index_option", &SimpleIndexDeclarationContextProxy::indexOption)
    .define_method("index_option_at", &SimpleIndexDeclarationContextProxy::indexOptionAt);

  rb_cTableOptionEngineContext = rb_mMySqlParser
    .define_class<TableOptionEngineContextProxy, ContextProxy>("TableOptionEngineContext")
    .define_method("engine_name", &TableOptionEngineContextProxy::engineName);

  rb_cTableOptionMaxRowsContext = rb_mMySqlParser
    .define_class<TableOptionMaxRowsContextProxy, ContextProxy>("TableOptionMaxRowsContext")
    .define_method("decimal_literal", &TableOptionMaxRowsContextProxy::decimalLiteral);

  rb_cTableOptionCollateContext = rb_mMySqlParser
    .define_class<TableOptionCollateContextProxy, ContextProxy>("TableOptionCollateContext")
    .define_method("collation_name", &TableOptionCollateContextProxy::collationName);

  rb_cTableOptionPersistentContext = rb_mMySqlParser
    .define_class<TableOptionPersistentContextProxy, ContextProxy>("TableOptionPersistentContext");

  rb_cTableOptionTablespaceContext = rb_mMySqlParser
    .define_class<TableOptionTablespaceContextProxy, ContextProxy>("TableOptionTablespaceContext")
    .define_method("uid", &TableOptionTablespaceContextProxy::uid)
    .define_method("tablespace_storage", &TableOptionTablespaceContextProxy::tablespaceStorage);

  rb_cTablespaceStorageContext = rb_mMySqlParser
    .define_class<TablespaceStorageContextProxy, ContextProxy>("TablespaceStorageContext");

  rb_cTableOptionPackKeysContext = rb_mMySqlParser
    .define_class<TableOptionPackKeysContextProxy, ContextProxy>("TableOptionPackKeysContext");

  rb_cTableOptionPasswordContext = rb_mMySqlParser
    .define_class<TableOptionPasswordContextProxy, ContextProxy>("TableOptionPasswordContext");

  rb_cTableOptionUnionContext = rb_mMySqlParser
    .define_class<TableOptionUnionContextProxy, ContextProxy>("TableOptionUnionContext")
    .define_method("tables", &TableOptionUnionContextProxy::tables);

  rb_cTablesContext = rb_mMySqlParser
    .define_class<TablesContextProxy, ContextProxy>("TablesContext")
    .define_method("table_name", &TablesContextProxy::tableName)
    .define_method("table_name_at", &TablesContextProxy::tableNameAt);

  rb_cTableOptionSamplePageContext = rb_mMySqlParser
    .define_class<TableOptionSamplePageContextProxy, ContextProxy>("TableOptionSamplePageContext")
    .define_method("decimal_literal", &TableOptionSamplePageContextProxy::decimalLiteral);

  rb_cTableOptionCharsetContext = rb_mMySqlParser
    .define_class<TableOptionCharsetContextProxy, ContextProxy>("TableOptionCharsetContext")
    .define_method("charset_name", &TableOptionCharsetContextProxy::charsetName);

  rb_cTableOptionIndexDirectoryContext = rb_mMySqlParser
    .define_class<TableOptionIndexDirectoryContextProxy, ContextProxy>("TableOptionIndexDirectoryContext");

  rb_cTableOptionKeyBlockSizeContext = rb_mMySqlParser
    .define_class<TableOptionKeyBlockSizeContextProxy, ContextProxy>("TableOptionKeyBlockSizeContext")
    .define_method("file_size_literal", &TableOptionKeyBlockSizeContextProxy::fileSizeLiteral);

  rb_cTableOptionEncryptionContext = rb_mMySqlParser
    .define_class<TableOptionEncryptionContextProxy, ContextProxy>("TableOptionEncryptionContext");

  rb_cTableOptionDataDirectoryContext = rb_mMySqlParser
    .define_class<TableOptionDataDirectoryContextProxy, ContextProxy>("TableOptionDataDirectoryContext");

  rb_cTableOptionRecalculationContext = rb_mMySqlParser
    .define_class<TableOptionRecalculationContextProxy, ContextProxy>("TableOptionRecalculationContext");

  rb_cTableOptionAutoIncrementContext = rb_mMySqlParser
    .define_class<TableOptionAutoIncrementContextProxy, ContextProxy>("TableOptionAutoIncrementContext")
    .define_method("decimal_literal", &TableOptionAutoIncrementContextProxy::decimalLiteral);

  rb_cTableOptionChecksumContext = rb_mMySqlParser
    .define_class<TableOptionChecksumContextProxy, ContextProxy>("TableOptionChecksumContext");

  rb_cTableOptionDelayContext = rb_mMySqlParser
    .define_class<TableOptionDelayContextProxy, ContextProxy>("TableOptionDelayContext");

  rb_cTableOptionConnectionContext = rb_mMySqlParser
    .define_class<TableOptionConnectionContextProxy, ContextProxy>("TableOptionConnectionContext");

  rb_cTableOptionCommentContext = rb_mMySqlParser
    .define_class<TableOptionCommentContextProxy, ContextProxy>("TableOptionCommentContext");

  rb_cTableOptionAverageContext = rb_mMySqlParser
    .define_class<TableOptionAverageContextProxy, ContextProxy>("TableOptionAverageContext")
    .define_method("decimal_literal", &TableOptionAverageContextProxy::decimalLiteral);

  rb_cTableOptionRowFormatContext = rb_mMySqlParser
    .define_class<TableOptionRowFormatContextProxy, ContextProxy>("TableOptionRowFormatContext");

  rb_cTableOptionCompressionContext = rb_mMySqlParser
    .define_class<TableOptionCompressionContextProxy, ContextProxy>("TableOptionCompressionContext");

  rb_cTableOptionInsertMethodContext = rb_mMySqlParser
    .define_class<TableOptionInsertMethodContextProxy, ContextProxy>("TableOptionInsertMethodContext");

  rb_cTableOptionMinRowsContext = rb_mMySqlParser
    .define_class<TableOptionMinRowsContextProxy, ContextProxy>("TableOptionMinRowsContext")
    .define_method("decimal_literal", &TableOptionMinRowsContextProxy::decimalLiteral);

  rb_cPartitionFunctionDefinitionContext = rb_mMySqlParser
    .define_class<PartitionFunctionDefinitionContextProxy, ContextProxy>("PartitionFunctionDefinitionContext");

  rb_cSubpartitionFunctionDefinitionContext = rb_mMySqlParser
    .define_class<SubpartitionFunctionDefinitionContextProxy, ContextProxy>("SubpartitionFunctionDefinitionContext");

  rb_cPartitionDefinitionContext = rb_mMySqlParser
    .define_class<PartitionDefinitionContextProxy, ContextProxy>("PartitionDefinitionContext");

  rb_cPartitionFunctionKeyContext = rb_mMySqlParser
    .define_class<PartitionFunctionKeyContextProxy, ContextProxy>("PartitionFunctionKeyContext")
    .define_method("uid_list", &PartitionFunctionKeyContextProxy::uidList);

  rb_cPartitionFunctionHashContext = rb_mMySqlParser
    .define_class<PartitionFunctionHashContextProxy, ContextProxy>("PartitionFunctionHashContext")
    .define_method("expression", &PartitionFunctionHashContextProxy::expression);

  rb_cPartitionFunctionListContext = rb_mMySqlParser
    .define_class<PartitionFunctionListContextProxy, ContextProxy>("PartitionFunctionListContext")
    .define_method("expression", &PartitionFunctionListContextProxy::expression)
    .define_method("uid_list", &PartitionFunctionListContextProxy::uidList);

  rb_cPartitionFunctionRangeContext = rb_mMySqlParser
    .define_class<PartitionFunctionRangeContextProxy, ContextProxy>("PartitionFunctionRangeContext")
    .define_method("expression", &PartitionFunctionRangeContextProxy::expression)
    .define_method("uid_list", &PartitionFunctionRangeContextProxy::uidList);

  rb_cSubPartitionFunctionHashContext = rb_mMySqlParser
    .define_class<SubPartitionFunctionHashContextProxy, ContextProxy>("SubPartitionFunctionHashContext")
    .define_method("expression", &SubPartitionFunctionHashContextProxy::expression);

  rb_cSubPartitionFunctionKeyContext = rb_mMySqlParser
    .define_class<SubPartitionFunctionKeyContextProxy, ContextProxy>("SubPartitionFunctionKeyContext")
    .define_method("uid_list", &SubPartitionFunctionKeyContextProxy::uidList);

  rb_cPartitionComparisionContext = rb_mMySqlParser
    .define_class<PartitionComparisionContextProxy, ContextProxy>("PartitionComparisionContext")
    .define_method("uid", &PartitionComparisionContextProxy::uid)
    .define_method("partition_definer_atom", &PartitionComparisionContextProxy::partitionDefinerAtom)
    .define_method("partition_definer_atom_at", &PartitionComparisionContextProxy::partitionDefinerAtomAt)
    .define_method("partition_option", &PartitionComparisionContextProxy::partitionOption)
    .define_method("partition_option_at", &PartitionComparisionContextProxy::partitionOptionAt)
    .define_method("subpartition_definition", &PartitionComparisionContextProxy::subpartitionDefinition)
    .define_method("subpartition_definition_at", &PartitionComparisionContextProxy::subpartitionDefinitionAt);

  rb_cPartitionDefinerAtomContext = rb_mMySqlParser
    .define_class<PartitionDefinerAtomContextProxy, ContextProxy>("PartitionDefinerAtomContext")
    .define_method("constant", &PartitionDefinerAtomContextProxy::constant)
    .define_method("expression", &PartitionDefinerAtomContextProxy::expression);

  rb_cPartitionOptionContext = rb_mMySqlParser
    .define_class<PartitionOptionContextProxy, ContextProxy>("PartitionOptionContext");

  rb_cSubpartitionDefinitionContext = rb_mMySqlParser
    .define_class<SubpartitionDefinitionContextProxy, ContextProxy>("SubpartitionDefinitionContext")
    .define_method("uid", &SubpartitionDefinitionContextProxy::uid)
    .define_method("partition_option", &SubpartitionDefinitionContextProxy::partitionOption)
    .define_method("partition_option_at", &SubpartitionDefinitionContextProxy::partitionOptionAt);

  rb_cPartitionListAtomContext = rb_mMySqlParser
    .define_class<PartitionListAtomContextProxy, ContextProxy>("PartitionListAtomContext")
    .define_method("uid", &PartitionListAtomContextProxy::uid)
    .define_method("partition_definer_atom", &PartitionListAtomContextProxy::partitionDefinerAtom)
    .define_method("partition_definer_atom_at", &PartitionListAtomContextProxy::partitionDefinerAtomAt)
    .define_method("partition_option", &PartitionListAtomContextProxy::partitionOption)
    .define_method("partition_option_at", &PartitionListAtomContextProxy::partitionOptionAt)
    .define_method("subpartition_definition", &PartitionListAtomContextProxy::subpartitionDefinition)
    .define_method("subpartition_definition_at", &PartitionListAtomContextProxy::subpartitionDefinitionAt);

  rb_cPartitionListVectorContext = rb_mMySqlParser
    .define_class<PartitionListVectorContextProxy, ContextProxy>("PartitionListVectorContext")
    .define_method("uid", &PartitionListVectorContextProxy::uid)
    .define_method("partition_definer_vector", &PartitionListVectorContextProxy::partitionDefinerVector)
    .define_method("partition_definer_vector_at", &PartitionListVectorContextProxy::partitionDefinerVectorAt)
    .define_method("partition_option", &PartitionListVectorContextProxy::partitionOption)
    .define_method("partition_option_at", &PartitionListVectorContextProxy::partitionOptionAt)
    .define_method("subpartition_definition", &PartitionListVectorContextProxy::subpartitionDefinition)
    .define_method("subpartition_definition_at", &PartitionListVectorContextProxy::subpartitionDefinitionAt);

  rb_cPartitionDefinerVectorContext = rb_mMySqlParser
    .define_class<PartitionDefinerVectorContextProxy, ContextProxy>("PartitionDefinerVectorContext")
    .define_method("partition_definer_atom", &PartitionDefinerVectorContextProxy::partitionDefinerAtom)
    .define_method("partition_definer_atom_at", &PartitionDefinerVectorContextProxy::partitionDefinerAtomAt);

  rb_cPartitionSimpleContext = rb_mMySqlParser
    .define_class<PartitionSimpleContextProxy, ContextProxy>("PartitionSimpleContext")
    .define_method("uid", &PartitionSimpleContextProxy::uid)
    .define_method("partition_option", &PartitionSimpleContextProxy::partitionOption)
    .define_method("partition_option_at", &PartitionSimpleContextProxy::partitionOptionAt)
    .define_method("subpartition_definition", &PartitionSimpleContextProxy::subpartitionDefinition)
    .define_method("subpartition_definition_at", &PartitionSimpleContextProxy::subpartitionDefinitionAt);

  rb_cConstantContext = rb_mMySqlParser
    .define_class<ConstantContextProxy, ContextProxy>("ConstantContext")
    .define_method("string_literal", &ConstantContextProxy::stringLiteral)
    .define_method("decimal_literal", &ConstantContextProxy::decimalLiteral)
    .define_method("hexadecimal_literal", &ConstantContextProxy::hexadecimalLiteral)
    .define_method("boolean_literal", &ConstantContextProxy::booleanLiteral);

  rb_cPartitionOptionCommentContext = rb_mMySqlParser
    .define_class<PartitionOptionCommentContextProxy, ContextProxy>("PartitionOptionCommentContext");

  rb_cPartitionOptionNodeGroupContext = rb_mMySqlParser
    .define_class<PartitionOptionNodeGroupContextProxy, ContextProxy>("PartitionOptionNodeGroupContext")
    .define_method("uid", &PartitionOptionNodeGroupContextProxy::uid);

  rb_cPartitionOptionIndexDirectoryContext = rb_mMySqlParser
    .define_class<PartitionOptionIndexDirectoryContextProxy, ContextProxy>("PartitionOptionIndexDirectoryContext");

  rb_cPartitionOptionMaxRowsContext = rb_mMySqlParser
    .define_class<PartitionOptionMaxRowsContextProxy, ContextProxy>("PartitionOptionMaxRowsContext")
    .define_method("decimal_literal", &PartitionOptionMaxRowsContextProxy::decimalLiteral);

  rb_cPartitionOptionTablespaceContext = rb_mMySqlParser
    .define_class<PartitionOptionTablespaceContextProxy, ContextProxy>("PartitionOptionTablespaceContext")
    .define_method("uid", &PartitionOptionTablespaceContextProxy::uid);

  rb_cPartitionOptionEngineContext = rb_mMySqlParser
    .define_class<PartitionOptionEngineContextProxy, ContextProxy>("PartitionOptionEngineContext")
    .define_method("engine_name", &PartitionOptionEngineContextProxy::engineName);

  rb_cPartitionOptionMinRowsContext = rb_mMySqlParser
    .define_class<PartitionOptionMinRowsContextProxy, ContextProxy>("PartitionOptionMinRowsContext")
    .define_method("decimal_literal", &PartitionOptionMinRowsContextProxy::decimalLiteral);

  rb_cPartitionOptionDataDirectoryContext = rb_mMySqlParser
    .define_class<PartitionOptionDataDirectoryContextProxy, ContextProxy>("PartitionOptionDataDirectoryContext");

  rb_cAlterUpgradeNameContext = rb_mMySqlParser
    .define_class<AlterUpgradeNameContextProxy, ContextProxy>("AlterUpgradeNameContext")
    .define_method("uid", &AlterUpgradeNameContextProxy::uid);

  rb_cAlterSimpleDatabaseContext = rb_mMySqlParser
    .define_class<AlterSimpleDatabaseContextProxy, ContextProxy>("AlterSimpleDatabaseContext")
    .define_method("uid", &AlterSimpleDatabaseContextProxy::uid)
    .define_method("create_database_option", &AlterSimpleDatabaseContextProxy::createDatabaseOption)
    .define_method("create_database_option_at", &AlterSimpleDatabaseContextProxy::createDatabaseOptionAt);

  rb_cAlterSpecificationContext = rb_mMySqlParser
    .define_class<AlterSpecificationContextProxy, ContextProxy>("AlterSpecificationContext");

  rb_cAlterByDisableKeysContext = rb_mMySqlParser
    .define_class<AlterByDisableKeysContextProxy, ContextProxy>("AlterByDisableKeysContext");

  rb_cAlterByDefaultCharsetContext = rb_mMySqlParser
    .define_class<AlterByDefaultCharsetContextProxy, ContextProxy>("AlterByDefaultCharsetContext")
    .define_method("charset_name", &AlterByDefaultCharsetContextProxy::charsetName)
    .define_method("collation_name", &AlterByDefaultCharsetContextProxy::collationName);

  rb_cAlterByRenameColumnContext = rb_mMySqlParser
    .define_class<AlterByRenameColumnContextProxy, ContextProxy>("AlterByRenameColumnContext")
    .define_method("uid", &AlterByRenameColumnContextProxy::uid)
    .define_method("uid_at", &AlterByRenameColumnContextProxy::uidAt);

  rb_cAlterByConvertCharsetContext = rb_mMySqlParser
    .define_class<AlterByConvertCharsetContextProxy, ContextProxy>("AlterByConvertCharsetContext")
    .define_method("charset_name", &AlterByConvertCharsetContextProxy::charsetName)
    .define_method("collation_name", &AlterByConvertCharsetContextProxy::collationName);

  rb_cAlterByAddPartitionContext = rb_mMySqlParser
    .define_class<AlterByAddPartitionContextProxy, ContextProxy>("AlterByAddPartitionContext")
    .define_method("partition_definition", &AlterByAddPartitionContextProxy::partitionDefinition)
    .define_method("partition_definition_at", &AlterByAddPartitionContextProxy::partitionDefinitionAt);

  rb_cAlterByAddForeignKeyContext = rb_mMySqlParser
    .define_class<AlterByAddForeignKeyContextProxy, ContextProxy>("AlterByAddForeignKeyContext")
    .define_method("index_column_names", &AlterByAddForeignKeyContextProxy::indexColumnNames)
    .define_method("reference_definition", &AlterByAddForeignKeyContextProxy::referenceDefinition)
    .define_method("uid", &AlterByAddForeignKeyContextProxy::uid)
    .define_method("uid_at", &AlterByAddForeignKeyContextProxy::uidAt);

  rb_cAlterByRenameIndexContext = rb_mMySqlParser
    .define_class<AlterByRenameIndexContextProxy, ContextProxy>("AlterByRenameIndexContext")
    .define_method("uid", &AlterByRenameIndexContextProxy::uid)
    .define_method("uid_at", &AlterByRenameIndexContextProxy::uidAt);

  rb_cAlterByRemovePartitioningContext = rb_mMySqlParser
    .define_class<AlterByRemovePartitioningContextProxy, ContextProxy>("AlterByRemovePartitioningContext");

  rb_cAlterByRenameContext = rb_mMySqlParser
    .define_class<AlterByRenameContextProxy, ContextProxy>("AlterByRenameContext")
    .define_method("uid", &AlterByRenameContextProxy::uid)
    .define_method("full_id", &AlterByRenameContextProxy::fullId);

  rb_cAlterByOptimizePartitionContext = rb_mMySqlParser
    .define_class<AlterByOptimizePartitionContextProxy, ContextProxy>("AlterByOptimizePartitionContext")
    .define_method("uid_list", &AlterByOptimizePartitionContextProxy::uidList);

  rb_cAlterByImportTablespaceContext = rb_mMySqlParser
    .define_class<AlterByImportTablespaceContextProxy, ContextProxy>("AlterByImportTablespaceContext");

  rb_cAlterByCoalescePartitionContext = rb_mMySqlParser
    .define_class<AlterByCoalescePartitionContextProxy, ContextProxy>("AlterByCoalescePartitionContext")
    .define_method("decimal_literal", &AlterByCoalescePartitionContextProxy::decimalLiteral);

  rb_cAlterByAddColumnsContext = rb_mMySqlParser
    .define_class<AlterByAddColumnsContextProxy, ContextProxy>("AlterByAddColumnsContext")
    .define_method("uid", &AlterByAddColumnsContextProxy::uid)
    .define_method("uid_at", &AlterByAddColumnsContextProxy::uidAt)
    .define_method("column_definition", &AlterByAddColumnsContextProxy::columnDefinition)
    .define_method("column_definition_at", &AlterByAddColumnsContextProxy::columnDefinitionAt);

  rb_cAlterByDropForeignKeyContext = rb_mMySqlParser
    .define_class<AlterByDropForeignKeyContextProxy, ContextProxy>("AlterByDropForeignKeyContext")
    .define_method("uid", &AlterByDropForeignKeyContextProxy::uid);

  rb_cAlterByAddCheckTableConstraintContext = rb_mMySqlParser
    .define_class<AlterByAddCheckTableConstraintContextProxy, ContextProxy>("AlterByAddCheckTableConstraintContext")
    .define_method("expression", &AlterByAddCheckTableConstraintContextProxy::expression)
    .define_method("uid", &AlterByAddCheckTableConstraintContextProxy::uid);

  rb_cAlterByRebuildPartitionContext = rb_mMySqlParser
    .define_class<AlterByRebuildPartitionContextProxy, ContextProxy>("AlterByRebuildPartitionContext")
    .define_method("uid_list", &AlterByRebuildPartitionContextProxy::uidList);

  rb_cAlterByUpgradePartitioningContext = rb_mMySqlParser
    .define_class<AlterByUpgradePartitioningContextProxy, ContextProxy>("AlterByUpgradePartitioningContext");

  rb_cAlterByRepairPartitionContext = rb_mMySqlParser
    .define_class<AlterByRepairPartitionContextProxy, ContextProxy>("AlterByRepairPartitionContext")
    .define_method("uid_list", &AlterByRepairPartitionContextProxy::uidList);

  rb_cAlterByExchangePartitionContext = rb_mMySqlParser
    .define_class<AlterByExchangePartitionContextProxy, ContextProxy>("AlterByExchangePartitionContext")
    .define_method("uid", &AlterByExchangePartitionContextProxy::uid)
    .define_method("table_name", &AlterByExchangePartitionContextProxy::tableName);

  rb_cAlterByAddIndexContext = rb_mMySqlParser
    .define_class<AlterByAddIndexContextProxy, ContextProxy>("AlterByAddIndexContext")
    .define_method("index_column_names", &AlterByAddIndexContextProxy::indexColumnNames)
    .define_method("uid", &AlterByAddIndexContextProxy::uid)
    .define_method("index_type", &AlterByAddIndexContextProxy::indexType)
    .define_method("index_option", &AlterByAddIndexContextProxy::indexOption)
    .define_method("index_option_at", &AlterByAddIndexContextProxy::indexOptionAt);

  rb_cAlterByDropColumnContext = rb_mMySqlParser
    .define_class<AlterByDropColumnContextProxy, ContextProxy>("AlterByDropColumnContext")
    .define_method("uid", &AlterByDropColumnContextProxy::uid);

  rb_cAlterByImportPartitionContext = rb_mMySqlParser
    .define_class<AlterByImportPartitionContextProxy, ContextProxy>("AlterByImportPartitionContext")
    .define_method("uid_list", &AlterByImportPartitionContextProxy::uidList);

  rb_cAlterByChangeDefaultContext = rb_mMySqlParser
    .define_class<AlterByChangeDefaultContextProxy, ContextProxy>("AlterByChangeDefaultContext")
    .define_method("uid", &AlterByChangeDefaultContextProxy::uid)
    .define_method("default_value", &AlterByChangeDefaultContextProxy::defaultValue);

  rb_cAlterByForceContext = rb_mMySqlParser
    .define_class<AlterByForceContextProxy, ContextProxy>("AlterByForceContext");

  rb_cAlterByDropPartitionContext = rb_mMySqlParser
    .define_class<AlterByDropPartitionContextProxy, ContextProxy>("AlterByDropPartitionContext")
    .define_method("uid_list", &AlterByDropPartitionContextProxy::uidList);

  rb_cAlterByAddSpecialIndexContext = rb_mMySqlParser
    .define_class<AlterByAddSpecialIndexContextProxy, ContextProxy>("AlterByAddSpecialIndexContext")
    .define_method("index_column_names", &AlterByAddSpecialIndexContextProxy::indexColumnNames)
    .define_method("uid", &AlterByAddSpecialIndexContextProxy::uid)
    .define_method("index_option", &AlterByAddSpecialIndexContextProxy::indexOption)
    .define_method("index_option_at", &AlterByAddSpecialIndexContextProxy::indexOptionAt);

  rb_cAlterByModifyColumnContext = rb_mMySqlParser
    .define_class<AlterByModifyColumnContextProxy, ContextProxy>("AlterByModifyColumnContext")
    .define_method("uid", &AlterByModifyColumnContextProxy::uid)
    .define_method("uid_at", &AlterByModifyColumnContextProxy::uidAt)
    .define_method("column_definition", &AlterByModifyColumnContextProxy::columnDefinition);

  rb_cAlterByTableOptionContext = rb_mMySqlParser
    .define_class<AlterByTableOptionContextProxy, ContextProxy>("AlterByTableOptionContext")
    .define_method("table_option", &AlterByTableOptionContextProxy::tableOption)
    .define_method("table_option_at", &AlterByTableOptionContextProxy::tableOptionAt);

  rb_cAlterByDropPrimaryKeyContext = rb_mMySqlParser
    .define_class<AlterByDropPrimaryKeyContextProxy, ContextProxy>("AlterByDropPrimaryKeyContext");

  rb_cAlterByLockContext = rb_mMySqlParser
    .define_class<AlterByLockContextProxy, ContextProxy>("AlterByLockContext");

  rb_cAlterByDiscardPartitionContext = rb_mMySqlParser
    .define_class<AlterByDiscardPartitionContextProxy, ContextProxy>("AlterByDiscardPartitionContext")
    .define_method("uid_list", &AlterByDiscardPartitionContextProxy::uidList);

  rb_cAlterByDiscardTablespaceContext = rb_mMySqlParser
    .define_class<AlterByDiscardTablespaceContextProxy, ContextProxy>("AlterByDiscardTablespaceContext");

  rb_cAlterByValidateContext = rb_mMySqlParser
    .define_class<AlterByValidateContextProxy, ContextProxy>("AlterByValidateContext");

  rb_cAlterByAddPrimaryKeyContext = rb_mMySqlParser
    .define_class<AlterByAddPrimaryKeyContextProxy, ContextProxy>("AlterByAddPrimaryKeyContext")
    .define_method("index_column_names", &AlterByAddPrimaryKeyContextProxy::indexColumnNames)
    .define_method("index_type", &AlterByAddPrimaryKeyContextProxy::indexType)
    .define_method("index_option", &AlterByAddPrimaryKeyContextProxy::indexOption)
    .define_method("index_option_at", &AlterByAddPrimaryKeyContextProxy::indexOptionAt)
    .define_method("uid", &AlterByAddPrimaryKeyContextProxy::uid);

  rb_cAlterByCheckPartitionContext = rb_mMySqlParser
    .define_class<AlterByCheckPartitionContextProxy, ContextProxy>("AlterByCheckPartitionContext")
    .define_method("uid_list", &AlterByCheckPartitionContextProxy::uidList);

  rb_cAlterByEnableKeysContext = rb_mMySqlParser
    .define_class<AlterByEnableKeysContextProxy, ContextProxy>("AlterByEnableKeysContext");

  rb_cAlterByReorganizePartitionContext = rb_mMySqlParser
    .define_class<AlterByReorganizePartitionContextProxy, ContextProxy>("AlterByReorganizePartitionContext")
    .define_method("uid_list", &AlterByReorganizePartitionContextProxy::uidList)
    .define_method("partition_definition", &AlterByReorganizePartitionContextProxy::partitionDefinition)
    .define_method("partition_definition_at", &AlterByReorganizePartitionContextProxy::partitionDefinitionAt);

  rb_cAlterBySetAlgorithmContext = rb_mMySqlParser
    .define_class<AlterBySetAlgorithmContextProxy, ContextProxy>("AlterBySetAlgorithmContext");

  rb_cAlterByAnalyzePartitionContext = rb_mMySqlParser
    .define_class<AlterByAnalyzePartitionContextProxy, ContextProxy>("AlterByAnalyzePartitionContext")
    .define_method("uid_list", &AlterByAnalyzePartitionContextProxy::uidList);

  rb_cAlterByChangeColumnContext = rb_mMySqlParser
    .define_class<AlterByChangeColumnContextProxy, ContextProxy>("AlterByChangeColumnContext")
    .define_method("column_definition", &AlterByChangeColumnContextProxy::columnDefinition)
    .define_method("uid", &AlterByChangeColumnContextProxy::uid)
    .define_method("uid_at", &AlterByChangeColumnContextProxy::uidAt);

  rb_cAlterByAddUniqueKeyContext = rb_mMySqlParser
    .define_class<AlterByAddUniqueKeyContextProxy, ContextProxy>("AlterByAddUniqueKeyContext")
    .define_method("index_column_names", &AlterByAddUniqueKeyContextProxy::indexColumnNames)
    .define_method("index_type", &AlterByAddUniqueKeyContextProxy::indexType)
    .define_method("index_option", &AlterByAddUniqueKeyContextProxy::indexOption)
    .define_method("index_option_at", &AlterByAddUniqueKeyContextProxy::indexOptionAt)
    .define_method("uid", &AlterByAddUniqueKeyContextProxy::uid)
    .define_method("uid_at", &AlterByAddUniqueKeyContextProxy::uidAt);

  rb_cAlterByTruncatePartitionContext = rb_mMySqlParser
    .define_class<AlterByTruncatePartitionContextProxy, ContextProxy>("AlterByTruncatePartitionContext")
    .define_method("uid_list", &AlterByTruncatePartitionContextProxy::uidList);

  rb_cAlterByDropIndexContext = rb_mMySqlParser
    .define_class<AlterByDropIndexContextProxy, ContextProxy>("AlterByDropIndexContext")
    .define_method("uid", &AlterByDropIndexContextProxy::uid);

  rb_cAlterByAddColumnContext = rb_mMySqlParser
    .define_class<AlterByAddColumnContextProxy, ContextProxy>("AlterByAddColumnContext")
    .define_method("uid", &AlterByAddColumnContextProxy::uid)
    .define_method("uid_at", &AlterByAddColumnContextProxy::uidAt)
    .define_method("column_definition", &AlterByAddColumnContextProxy::columnDefinition);

  rb_cAlterByOrderContext = rb_mMySqlParser
    .define_class<AlterByOrderContextProxy, ContextProxy>("AlterByOrderContext")
    .define_method("uid_list", &AlterByOrderContextProxy::uidList);

  rb_cIfExistsContext = rb_mMySqlParser
    .define_class<IfExistsContextProxy, ContextProxy>("IfExistsContext");

  rb_cRenameTableClauseContext = rb_mMySqlParser
    .define_class<RenameTableClauseContextProxy, ContextProxy>("RenameTableClauseContext")
    .define_method("table_name", &RenameTableClauseContextProxy::tableName)
    .define_method("table_name_at", &RenameTableClauseContextProxy::tableNameAt);

  rb_cConstantsContext = rb_mMySqlParser
    .define_class<ConstantsContextProxy, ContextProxy>("ConstantsContext")
    .define_method("constant", &ConstantsContextProxy::constant)
    .define_method("constant_at", &ConstantsContextProxy::constantAt);

  rb_cExpressionsContext = rb_mMySqlParser
    .define_class<ExpressionsContextProxy, ContextProxy>("ExpressionsContext")
    .define_method("expression", &ExpressionsContextProxy::expression)
    .define_method("expression_at", &ExpressionsContextProxy::expressionAt);

  rb_cSingleDeleteStatementContext = rb_mMySqlParser
    .define_class<SingleDeleteStatementContextProxy, ContextProxy>("SingleDeleteStatementContext")
    .define_method("table_name", &SingleDeleteStatementContextProxy::tableName)
    .define_method("uid_list", &SingleDeleteStatementContextProxy::uidList)
    .define_method("expression", &SingleDeleteStatementContextProxy::expression)
    .define_method("order_by_clause", &SingleDeleteStatementContextProxy::orderByClause)
    .define_method("decimal_literal", &SingleDeleteStatementContextProxy::decimalLiteral);

  rb_cMultipleDeleteStatementContext = rb_mMySqlParser
    .define_class<MultipleDeleteStatementContextProxy, ContextProxy>("MultipleDeleteStatementContext")
    .define_method("table_name", &MultipleDeleteStatementContextProxy::tableName)
    .define_method("table_name_at", &MultipleDeleteStatementContextProxy::tableNameAt)
    .define_method("table_sources", &MultipleDeleteStatementContextProxy::tableSources)
    .define_method("expression", &MultipleDeleteStatementContextProxy::expression);

  rb_cHandlerOpenStatementContext = rb_mMySqlParser
    .define_class<HandlerOpenStatementContextProxy, ContextProxy>("HandlerOpenStatementContext")
    .define_method("table_name", &HandlerOpenStatementContextProxy::tableName)
    .define_method("uid", &HandlerOpenStatementContextProxy::uid);

  rb_cHandlerReadIndexStatementContext = rb_mMySqlParser
    .define_class<HandlerReadIndexStatementContextProxy, ContextProxy>("HandlerReadIndexStatementContext")
    .define_method("table_name", &HandlerReadIndexStatementContextProxy::tableName)
    .define_method("uid", &HandlerReadIndexStatementContextProxy::uid)
    .define_method("comparison_operator", &HandlerReadIndexStatementContextProxy::comparisonOperator)
    .define_method("constants", &HandlerReadIndexStatementContextProxy::constants)
    .define_method("expression", &HandlerReadIndexStatementContextProxy::expression)
    .define_method("decimal_literal", &HandlerReadIndexStatementContextProxy::decimalLiteral);

  rb_cHandlerReadStatementContext = rb_mMySqlParser
    .define_class<HandlerReadStatementContextProxy, ContextProxy>("HandlerReadStatementContext")
    .define_method("table_name", &HandlerReadStatementContextProxy::tableName)
    .define_method("expression", &HandlerReadStatementContextProxy::expression)
    .define_method("decimal_literal", &HandlerReadStatementContextProxy::decimalLiteral);

  rb_cHandlerCloseStatementContext = rb_mMySqlParser
    .define_class<HandlerCloseStatementContextProxy, ContextProxy>("HandlerCloseStatementContext")
    .define_method("table_name", &HandlerCloseStatementContextProxy::tableName);

  rb_cInsertStatementValueContext = rb_mMySqlParser
    .define_class<InsertStatementValueContextProxy, ContextProxy>("InsertStatementValueContext")
    .define_method("select_statement", &InsertStatementValueContextProxy::selectStatement)
    .define_method("expressions_with_defaults", &InsertStatementValueContextProxy::expressionsWithDefaults)
    .define_method("expressions_with_defaults_at", &InsertStatementValueContextProxy::expressionsWithDefaultsAt);

  rb_cUpdatedElementContext = rb_mMySqlParser
    .define_class<UpdatedElementContextProxy, ContextProxy>("UpdatedElementContext")
    .define_method("full_column_name", &UpdatedElementContextProxy::fullColumnName)
    .define_method("expression", &UpdatedElementContextProxy::expression);

  rb_cAssignmentFieldContext = rb_mMySqlParser
    .define_class<AssignmentFieldContextProxy, ContextProxy>("AssignmentFieldContext")
    .define_method("uid", &AssignmentFieldContextProxy::uid);

  rb_cSelectFieldsIntoContext = rb_mMySqlParser
    .define_class<SelectFieldsIntoContextProxy, ContextProxy>("SelectFieldsIntoContext");

  rb_cSelectLinesIntoContext = rb_mMySqlParser
    .define_class<SelectLinesIntoContextProxy, ContextProxy>("SelectLinesIntoContext");

  rb_cQuerySpecificationNointoContext = rb_mMySqlParser
    .define_class<QuerySpecificationNointoContextProxy, ContextProxy>("QuerySpecificationNointoContext")
    .define_method("select_elements", &QuerySpecificationNointoContextProxy::selectElements)
    .define_method("select_spec", &QuerySpecificationNointoContextProxy::selectSpec)
    .define_method("select_spec_at", &QuerySpecificationNointoContextProxy::selectSpecAt)
    .define_method("from_clause", &QuerySpecificationNointoContextProxy::fromClause)
    .define_method("order_by_clause", &QuerySpecificationNointoContextProxy::orderByClause)
    .define_method("limit_clause", &QuerySpecificationNointoContextProxy::limitClause);

  rb_cUnionSelectContext = rb_mMySqlParser
    .define_class<UnionSelectContextProxy, ContextProxy>("UnionSelectContext")
    .define_method("query_specification_nointo", &UnionSelectContextProxy::querySpecificationNointo)
    .define_method("union_statement", &UnionSelectContextProxy::unionStatement)
    .define_method("union_statement_at", &UnionSelectContextProxy::unionStatementAt)
    .define_method("order_by_clause", &UnionSelectContextProxy::orderByClause)
    .define_method("limit_clause", &UnionSelectContextProxy::limitClause)
    .define_method("lock_clause", &UnionSelectContextProxy::lockClause)
    .define_method("query_specification", &UnionSelectContextProxy::querySpecification)
    .define_method("query_expression", &UnionSelectContextProxy::queryExpression);

  rb_cUnionStatementContext = rb_mMySqlParser
    .define_class<UnionStatementContextProxy, ContextProxy>("UnionStatementContext")
    .define_method("query_specification_nointo", &UnionStatementContextProxy::querySpecificationNointo)
    .define_method("query_expression_nointo", &UnionStatementContextProxy::queryExpressionNointo);

  rb_cOrderByClauseContext = rb_mMySqlParser
    .define_class<OrderByClauseContextProxy, ContextProxy>("OrderByClauseContext")
    .define_method("order_by_expression", &OrderByClauseContextProxy::orderByExpression)
    .define_method("order_by_expression_at", &OrderByClauseContextProxy::orderByExpressionAt);

  rb_cLimitClauseContext = rb_mMySqlParser
    .define_class<LimitClauseContextProxy, ContextProxy>("LimitClauseContext")
    .define_method("limit_clause_atom", &LimitClauseContextProxy::limitClauseAtom)
    .define_method("limit_clause_atom_at", &LimitClauseContextProxy::limitClauseAtomAt);

  rb_cLockClauseContext = rb_mMySqlParser
    .define_class<LockClauseContextProxy, ContextProxy>("LockClauseContext");

  rb_cQuerySpecificationContext = rb_mMySqlParser
    .define_class<QuerySpecificationContextProxy, ContextProxy>("QuerySpecificationContext")
    .define_method("select_elements", &QuerySpecificationContextProxy::selectElements)
    .define_method("select_spec", &QuerySpecificationContextProxy::selectSpec)
    .define_method("select_spec_at", &QuerySpecificationContextProxy::selectSpecAt)
    .define_method("select_into_expression", &QuerySpecificationContextProxy::selectIntoExpression)
    .define_method("from_clause", &QuerySpecificationContextProxy::fromClause)
    .define_method("order_by_clause", &QuerySpecificationContextProxy::orderByClause)
    .define_method("limit_clause", &QuerySpecificationContextProxy::limitClause);

  rb_cQueryExpressionContext = rb_mMySqlParser
    .define_class<QueryExpressionContextProxy, ContextProxy>("QueryExpressionContext")
    .define_method("query_specification", &QueryExpressionContextProxy::querySpecification)
    .define_method("query_expression", &QueryExpressionContextProxy::queryExpression);

  rb_cQueryExpressionNointoContext = rb_mMySqlParser
    .define_class<QueryExpressionNointoContextProxy, ContextProxy>("QueryExpressionNointoContext")
    .define_method("query_specification_nointo", &QueryExpressionNointoContextProxy::querySpecificationNointo)
    .define_method("query_expression_nointo", &QueryExpressionNointoContextProxy::queryExpressionNointo);

  rb_cUnionParenthesisSelectContext = rb_mMySqlParser
    .define_class<UnionParenthesisSelectContextProxy, ContextProxy>("UnionParenthesisSelectContext")
    .define_method("query_expression_nointo", &UnionParenthesisSelectContextProxy::queryExpressionNointo)
    .define_method("union_parenthesis", &UnionParenthesisSelectContextProxy::unionParenthesis)
    .define_method("union_parenthesis_at", &UnionParenthesisSelectContextProxy::unionParenthesisAt)
    .define_method("query_expression", &UnionParenthesisSelectContextProxy::queryExpression)
    .define_method("order_by_clause", &UnionParenthesisSelectContextProxy::orderByClause)
    .define_method("limit_clause", &UnionParenthesisSelectContextProxy::limitClause)
    .define_method("lock_clause", &UnionParenthesisSelectContextProxy::lockClause);

  rb_cUnionParenthesisContext = rb_mMySqlParser
    .define_class<UnionParenthesisContextProxy, ContextProxy>("UnionParenthesisContext")
    .define_method("query_expression_nointo", &UnionParenthesisContextProxy::queryExpressionNointo);

  rb_cSimpleSelectContext = rb_mMySqlParser
    .define_class<SimpleSelectContextProxy, ContextProxy>("SimpleSelectContext")
    .define_method("query_specification", &SimpleSelectContextProxy::querySpecification)
    .define_method("lock_clause", &SimpleSelectContextProxy::lockClause);

  rb_cParenthesisSelectContext = rb_mMySqlParser
    .define_class<ParenthesisSelectContextProxy, ContextProxy>("ParenthesisSelectContext")
    .define_method("query_expression", &ParenthesisSelectContextProxy::queryExpression)
    .define_method("lock_clause", &ParenthesisSelectContextProxy::lockClause);

  rb_cSingleUpdateStatementContext = rb_mMySqlParser
    .define_class<SingleUpdateStatementContextProxy, ContextProxy>("SingleUpdateStatementContext")
    .define_method("table_name", &SingleUpdateStatementContextProxy::tableName)
    .define_method("updated_element", &SingleUpdateStatementContextProxy::updatedElement)
    .define_method("updated_element_at", &SingleUpdateStatementContextProxy::updatedElementAt)
    .define_method("uid", &SingleUpdateStatementContextProxy::uid)
    .define_method("expression", &SingleUpdateStatementContextProxy::expression)
    .define_method("order_by_clause", &SingleUpdateStatementContextProxy::orderByClause)
    .define_method("limit_clause", &SingleUpdateStatementContextProxy::limitClause);

  rb_cMultipleUpdateStatementContext = rb_mMySqlParser
    .define_class<MultipleUpdateStatementContextProxy, ContextProxy>("MultipleUpdateStatementContext")
    .define_method("table_sources", &MultipleUpdateStatementContextProxy::tableSources)
    .define_method("updated_element", &MultipleUpdateStatementContextProxy::updatedElement)
    .define_method("updated_element_at", &MultipleUpdateStatementContextProxy::updatedElementAt)
    .define_method("expression", &MultipleUpdateStatementContextProxy::expression);

  rb_cExpressionsWithDefaultsContext = rb_mMySqlParser
    .define_class<ExpressionsWithDefaultsContextProxy, ContextProxy>("ExpressionsWithDefaultsContext")
    .define_method("expression_or_default", &ExpressionsWithDefaultsContextProxy::expressionOrDefault)
    .define_method("expression_or_default_at", &ExpressionsWithDefaultsContextProxy::expressionOrDefaultAt);

  rb_cFullColumnNameContext = rb_mMySqlParser
    .define_class<FullColumnNameContextProxy, ContextProxy>("FullColumnNameContext")
    .define_method("uid", &FullColumnNameContextProxy::uid)
    .define_method("dotted_id", &FullColumnNameContextProxy::dottedId)
    .define_method("dotted_id_at", &FullColumnNameContextProxy::dottedIdAt);

  rb_cTableSourcesContext = rb_mMySqlParser
    .define_class<TableSourcesContextProxy, ContextProxy>("TableSourcesContext")
    .define_method("table_source", &TableSourcesContextProxy::tableSource)
    .define_method("table_source_at", &TableSourcesContextProxy::tableSourceAt);

  rb_cComparisonOperatorContext = rb_mMySqlParser
    .define_class<ComparisonOperatorContextProxy, ContextProxy>("ComparisonOperatorContext");

  rb_cOrderByExpressionContext = rb_mMySqlParser
    .define_class<OrderByExpressionContextProxy, ContextProxy>("OrderByExpressionContext")
    .define_method("expression", &OrderByExpressionContextProxy::expression);

  rb_cTableSourceContext = rb_mMySqlParser
    .define_class<TableSourceContextProxy, ContextProxy>("TableSourceContext");

  rb_cTableSourceNestedContext = rb_mMySqlParser
    .define_class<TableSourceNestedContextProxy, ContextProxy>("TableSourceNestedContext")
    .define_method("table_source_item", &TableSourceNestedContextProxy::tableSourceItem)
    .define_method("join_part", &TableSourceNestedContextProxy::joinPart)
    .define_method("join_part_at", &TableSourceNestedContextProxy::joinPartAt);

  rb_cTableSourceItemContext = rb_mMySqlParser
    .define_class<TableSourceItemContextProxy, ContextProxy>("TableSourceItemContext");

  rb_cJoinPartContext = rb_mMySqlParser
    .define_class<JoinPartContextProxy, ContextProxy>("JoinPartContext");

  rb_cTableSourceBaseContext = rb_mMySqlParser
    .define_class<TableSourceBaseContextProxy, ContextProxy>("TableSourceBaseContext")
    .define_method("table_source_item", &TableSourceBaseContextProxy::tableSourceItem)
    .define_method("join_part", &TableSourceBaseContextProxy::joinPart)
    .define_method("join_part_at", &TableSourceBaseContextProxy::joinPartAt);

  rb_cSubqueryTableItemContext = rb_mMySqlParser
    .define_class<SubqueryTableItemContextProxy, ContextProxy>("SubqueryTableItemContext")
    .define_method("uid", &SubqueryTableItemContextProxy::uid)
    .define_method("select_statement", &SubqueryTableItemContextProxy::selectStatement);

  rb_cAtomTableItemContext = rb_mMySqlParser
    .define_class<AtomTableItemContextProxy, ContextProxy>("AtomTableItemContext")
    .define_method("table_name", &AtomTableItemContextProxy::tableName)
    .define_method("uid_list", &AtomTableItemContextProxy::uidList)
    .define_method("index_hint", &AtomTableItemContextProxy::indexHint)
    .define_method("index_hint_at", &AtomTableItemContextProxy::indexHintAt)
    .define_method("uid", &AtomTableItemContextProxy::uid);

  rb_cIndexHintContext = rb_mMySqlParser
    .define_class<IndexHintContextProxy, ContextProxy>("IndexHintContext")
    .define_method("uid_list", &IndexHintContextProxy::uidList)
    .define_method("index_hint_type", &IndexHintContextProxy::indexHintType);

  rb_cTableSourcesItemContext = rb_mMySqlParser
    .define_class<TableSourcesItemContextProxy, ContextProxy>("TableSourcesItemContext")
    .define_method("table_sources", &TableSourcesItemContextProxy::tableSources);

  rb_cIndexHintTypeContext = rb_mMySqlParser
    .define_class<IndexHintTypeContextProxy, ContextProxy>("IndexHintTypeContext");

  rb_cInnerJoinContext = rb_mMySqlParser
    .define_class<InnerJoinContextProxy, ContextProxy>("InnerJoinContext")
    .define_method("table_source_item", &InnerJoinContextProxy::tableSourceItem)
    .define_method("expression", &InnerJoinContextProxy::expression)
    .define_method("uid_list", &InnerJoinContextProxy::uidList);

  rb_cNaturalJoinContext = rb_mMySqlParser
    .define_class<NaturalJoinContextProxy, ContextProxy>("NaturalJoinContext")
    .define_method("table_source_item", &NaturalJoinContextProxy::tableSourceItem);

  rb_cOuterJoinContext = rb_mMySqlParser
    .define_class<OuterJoinContextProxy, ContextProxy>("OuterJoinContext")
    .define_method("table_source_item", &OuterJoinContextProxy::tableSourceItem)
    .define_method("expression", &OuterJoinContextProxy::expression)
    .define_method("uid_list", &OuterJoinContextProxy::uidList);

  rb_cStraightJoinContext = rb_mMySqlParser
    .define_class<StraightJoinContextProxy, ContextProxy>("StraightJoinContext")
    .define_method("table_source_item", &StraightJoinContextProxy::tableSourceItem)
    .define_method("expression", &StraightJoinContextProxy::expression);

  rb_cSelectElementsContext = rb_mMySqlParser
    .define_class<SelectElementsContextProxy, ContextProxy>("SelectElementsContext")
    .define_method("select_element", &SelectElementsContextProxy::selectElement)
    .define_method("select_element_at", &SelectElementsContextProxy::selectElementAt);

  rb_cSelectSpecContext = rb_mMySqlParser
    .define_class<SelectSpecContextProxy, ContextProxy>("SelectSpecContext");

  rb_cSelectIntoExpressionContext = rb_mMySqlParser
    .define_class<SelectIntoExpressionContextProxy, ContextProxy>("SelectIntoExpressionContext");

  rb_cFromClauseContext = rb_mMySqlParser
    .define_class<FromClauseContextProxy, ContextProxy>("FromClauseContext")
    .define_method("table_sources", &FromClauseContextProxy::tableSources)
    .define_method("group_by_item", &FromClauseContextProxy::groupByItem)
    .define_method("group_by_item_at", &FromClauseContextProxy::groupByItemAt)
    .define_method("expression", &FromClauseContextProxy::expression)
    .define_method("expression_at", &FromClauseContextProxy::expressionAt);

  rb_cSelectElementContext = rb_mMySqlParser
    .define_class<SelectElementContextProxy, ContextProxy>("SelectElementContext");

  rb_cSelectExpressionElementContext = rb_mMySqlParser
    .define_class<SelectExpressionElementContextProxy, ContextProxy>("SelectExpressionElementContext")
    .define_method("expression", &SelectExpressionElementContextProxy::expression)
    .define_method("uid", &SelectExpressionElementContextProxy::uid);

  rb_cFunctionCallContext = rb_mMySqlParser
    .define_class<FunctionCallContextProxy, ContextProxy>("FunctionCallContext");

  rb_cSelectFunctionElementContext = rb_mMySqlParser
    .define_class<SelectFunctionElementContextProxy, ContextProxy>("SelectFunctionElementContext")
    .define_method("function_call", &SelectFunctionElementContextProxy::functionCall)
    .define_method("uid", &SelectFunctionElementContextProxy::uid);

  rb_cSelectStarElementContext = rb_mMySqlParser
    .define_class<SelectStarElementContextProxy, ContextProxy>("SelectStarElementContext")
    .define_method("full_id", &SelectStarElementContextProxy::fullId);

  rb_cSelectColumnElementContext = rb_mMySqlParser
    .define_class<SelectColumnElementContextProxy, ContextProxy>("SelectColumnElementContext")
    .define_method("full_column_name", &SelectColumnElementContextProxy::fullColumnName)
    .define_method("uid", &SelectColumnElementContextProxy::uid);

  rb_cSelectIntoVariablesContext = rb_mMySqlParser
    .define_class<SelectIntoVariablesContextProxy, ContextProxy>("SelectIntoVariablesContext")
    .define_method("assignment_field", &SelectIntoVariablesContextProxy::assignmentField)
    .define_method("assignment_field_at", &SelectIntoVariablesContextProxy::assignmentFieldAt);

  rb_cSelectIntoTextFileContext = rb_mMySqlParser
    .define_class<SelectIntoTextFileContextProxy, ContextProxy>("SelectIntoTextFileContext")
    .define_method("charset_name", &SelectIntoTextFileContextProxy::charsetName)
    .define_method("select_fields_into", &SelectIntoTextFileContextProxy::selectFieldsInto)
    .define_method("select_fields_into_at", &SelectIntoTextFileContextProxy::selectFieldsIntoAt)
    .define_method("select_lines_into", &SelectIntoTextFileContextProxy::selectLinesInto)
    .define_method("select_lines_into_at", &SelectIntoTextFileContextProxy::selectLinesIntoAt);

  rb_cSelectIntoDumpFileContext = rb_mMySqlParser
    .define_class<SelectIntoDumpFileContextProxy, ContextProxy>("SelectIntoDumpFileContext");

  rb_cGroupByItemContext = rb_mMySqlParser
    .define_class<GroupByItemContextProxy, ContextProxy>("GroupByItemContext")
    .define_method("expression", &GroupByItemContextProxy::expression);

  rb_cLimitClauseAtomContext = rb_mMySqlParser
    .define_class<LimitClauseAtomContextProxy, ContextProxy>("LimitClauseAtomContext")
    .define_method("decimal_literal", &LimitClauseAtomContextProxy::decimalLiteral)
    .define_method("mysql_variable", &LimitClauseAtomContextProxy::mysqlVariable);

  rb_cMysqlVariableContext = rb_mMySqlParser
    .define_class<MysqlVariableContextProxy, ContextProxy>("MysqlVariableContext");

  rb_cTransactionModeContext = rb_mMySqlParser
    .define_class<TransactionModeContextProxy, ContextProxy>("TransactionModeContext");

  rb_cLockTableElementContext = rb_mMySqlParser
    .define_class<LockTableElementContextProxy, ContextProxy>("LockTableElementContext")
    .define_method("table_name", &LockTableElementContextProxy::tableName)
    .define_method("lock_action", &LockTableElementContextProxy::lockAction)
    .define_method("uid", &LockTableElementContextProxy::uid);

  rb_cSetAutocommitStatementContext = rb_mMySqlParser
    .define_class<SetAutocommitStatementContextProxy, ContextProxy>("SetAutocommitStatementContext");

  rb_cSetTransactionStatementContext = rb_mMySqlParser
    .define_class<SetTransactionStatementContextProxy, ContextProxy>("SetTransactionStatementContext")
    .define_method("transaction_option", &SetTransactionStatementContextProxy::transactionOption)
    .define_method("transaction_option_at", &SetTransactionStatementContextProxy::transactionOptionAt);

  rb_cTransactionOptionContext = rb_mMySqlParser
    .define_class<TransactionOptionContextProxy, ContextProxy>("TransactionOptionContext")
    .define_method("transaction_level", &TransactionOptionContextProxy::transactionLevel);

  rb_cLockActionContext = rb_mMySqlParser
    .define_class<LockActionContextProxy, ContextProxy>("LockActionContext");

  rb_cTransactionLevelContext = rb_mMySqlParser
    .define_class<TransactionLevelContextProxy, ContextProxy>("TransactionLevelContext");

  rb_cMasterOptionContext = rb_mMySqlParser
    .define_class<MasterOptionContextProxy, ContextProxy>("MasterOptionContext");

  rb_cChannelOptionContext = rb_mMySqlParser
    .define_class<ChannelOptionContextProxy, ContextProxy>("ChannelOptionContext");

  rb_cReplicationFilterContext = rb_mMySqlParser
    .define_class<ReplicationFilterContextProxy, ContextProxy>("ReplicationFilterContext");

  rb_cThreadTypeContext = rb_mMySqlParser
    .define_class<ThreadTypeContextProxy, ContextProxy>("ThreadTypeContext");

  rb_cUntilOptionContext = rb_mMySqlParser
    .define_class<UntilOptionContextProxy, ContextProxy>("UntilOptionContext");

  rb_cConnectionOptionContext = rb_mMySqlParser
    .define_class<ConnectionOptionContextProxy, ContextProxy>("ConnectionOptionContext");

  rb_cStringMasterOptionContext = rb_mMySqlParser
    .define_class<StringMasterOptionContextProxy, ContextProxy>("StringMasterOptionContext");

  rb_cMasterStringOptionContext = rb_mMySqlParser
    .define_class<MasterStringOptionContextProxy, ContextProxy>("MasterStringOptionContext")
    .define_method("string_master_option", &MasterStringOptionContextProxy::stringMasterOption);

  rb_cMasterRealOptionContext = rb_mMySqlParser
    .define_class<MasterRealOptionContextProxy, ContextProxy>("MasterRealOptionContext");

  rb_cBoolMasterOptionContext = rb_mMySqlParser
    .define_class<BoolMasterOptionContextProxy, ContextProxy>("BoolMasterOptionContext");

  rb_cMasterBoolOptionContext = rb_mMySqlParser
    .define_class<MasterBoolOptionContextProxy, ContextProxy>("MasterBoolOptionContext")
    .define_method("bool_master_option", &MasterBoolOptionContextProxy::boolMasterOption);

  rb_cMasterUidListOptionContext = rb_mMySqlParser
    .define_class<MasterUidListOptionContextProxy, ContextProxy>("MasterUidListOptionContext")
    .define_method("uid", &MasterUidListOptionContextProxy::uid)
    .define_method("uid_at", &MasterUidListOptionContextProxy::uidAt);

  rb_cDecimalMasterOptionContext = rb_mMySqlParser
    .define_class<DecimalMasterOptionContextProxy, ContextProxy>("DecimalMasterOptionContext");

  rb_cMasterDecimalOptionContext = rb_mMySqlParser
    .define_class<MasterDecimalOptionContextProxy, ContextProxy>("MasterDecimalOptionContext")
    .define_method("decimal_master_option", &MasterDecimalOptionContextProxy::decimalMasterOption)
    .define_method("decimal_literal", &MasterDecimalOptionContextProxy::decimalLiteral);

  rb_cWildIgnoreTableReplicationContext = rb_mMySqlParser
    .define_class<WildIgnoreTableReplicationContextProxy, ContextProxy>("WildIgnoreTableReplicationContext")
    .define_method("simple_strings", &WildIgnoreTableReplicationContextProxy::simpleStrings);

  rb_cSimpleStringsContext = rb_mMySqlParser
    .define_class<SimpleStringsContextProxy, ContextProxy>("SimpleStringsContext");

  rb_cDoTableReplicationContext = rb_mMySqlParser
    .define_class<DoTableReplicationContextProxy, ContextProxy>("DoTableReplicationContext")
    .define_method("tables", &DoTableReplicationContextProxy::tables);

  rb_cIgnoreTableReplicationContext = rb_mMySqlParser
    .define_class<IgnoreTableReplicationContextProxy, ContextProxy>("IgnoreTableReplicationContext")
    .define_method("tables", &IgnoreTableReplicationContextProxy::tables);

  rb_cRewriteDbReplicationContext = rb_mMySqlParser
    .define_class<RewriteDbReplicationContextProxy, ContextProxy>("RewriteDbReplicationContext")
    .define_method("table_pair", &RewriteDbReplicationContextProxy::tablePair)
    .define_method("table_pair_at", &RewriteDbReplicationContextProxy::tablePairAt);

  rb_cTablePairContext = rb_mMySqlParser
    .define_class<TablePairContextProxy, ContextProxy>("TablePairContext")
    .define_method("table_name", &TablePairContextProxy::tableName)
    .define_method("table_name_at", &TablePairContextProxy::tableNameAt);

  rb_cDoDbReplicationContext = rb_mMySqlParser
    .define_class<DoDbReplicationContextProxy, ContextProxy>("DoDbReplicationContext")
    .define_method("uid_list", &DoDbReplicationContextProxy::uidList);

  rb_cIgnoreDbReplicationContext = rb_mMySqlParser
    .define_class<IgnoreDbReplicationContextProxy, ContextProxy>("IgnoreDbReplicationContext")
    .define_method("uid_list", &IgnoreDbReplicationContextProxy::uidList);

  rb_cWildDoTableReplicationContext = rb_mMySqlParser
    .define_class<WildDoTableReplicationContextProxy, ContextProxy>("WildDoTableReplicationContext")
    .define_method("simple_strings", &WildDoTableReplicationContextProxy::simpleStrings);

  rb_cGtidsUntilOptionContext = rb_mMySqlParser
    .define_class<GtidsUntilOptionContextProxy, ContextProxy>("GtidsUntilOptionContext")
    .define_method("gtuid_set", &GtidsUntilOptionContextProxy::gtuidSet);

  rb_cGtuidSetContext = rb_mMySqlParser
    .define_class<GtuidSetContextProxy, ContextProxy>("GtuidSetContext")
    .define_method("uuid_set", &GtuidSetContextProxy::uuidSet)
    .define_method("uuid_set_at", &GtuidSetContextProxy::uuidSetAt);

  rb_cSqlGapsUntilOptionContext = rb_mMySqlParser
    .define_class<SqlGapsUntilOptionContextProxy, ContextProxy>("SqlGapsUntilOptionContext");

  rb_cMasterLogUntilOptionContext = rb_mMySqlParser
    .define_class<MasterLogUntilOptionContextProxy, ContextProxy>("MasterLogUntilOptionContext")
    .define_method("decimal_literal", &MasterLogUntilOptionContextProxy::decimalLiteral);

  rb_cRelayLogUntilOptionContext = rb_mMySqlParser
    .define_class<RelayLogUntilOptionContextProxy, ContextProxy>("RelayLogUntilOptionContext")
    .define_method("decimal_literal", &RelayLogUntilOptionContextProxy::decimalLiteral);

  rb_cPluginDirConnectionOptionContext = rb_mMySqlParser
    .define_class<PluginDirConnectionOptionContextProxy, ContextProxy>("PluginDirConnectionOptionContext");

  rb_cUserConnectionOptionContext = rb_mMySqlParser
    .define_class<UserConnectionOptionContextProxy, ContextProxy>("UserConnectionOptionContext");

  rb_cDefaultAuthConnectionOptionContext = rb_mMySqlParser
    .define_class<DefaultAuthConnectionOptionContextProxy, ContextProxy>("DefaultAuthConnectionOptionContext");

  rb_cPasswordConnectionOptionContext = rb_mMySqlParser
    .define_class<PasswordConnectionOptionContextProxy, ContextProxy>("PasswordConnectionOptionContext");

  rb_cUuidSetContext = rb_mMySqlParser
    .define_class<UuidSetContextProxy, ContextProxy>("UuidSetContext")
    .define_method("decimal_literal", &UuidSetContextProxy::decimalLiteral)
    .define_method("decimal_literal_at", &UuidSetContextProxy::decimalLiteralAt);

  rb_cXidContext = rb_mMySqlParser
    .define_class<XidContextProxy, ContextProxy>("XidContext")
    .define_method("xuid_string_id", &XidContextProxy::xuidStringId)
    .define_method("xuid_string_id_at", &XidContextProxy::xuidStringIdAt)
    .define_method("decimal_literal", &XidContextProxy::decimalLiteral);

  rb_cUserVariablesContext = rb_mMySqlParser
    .define_class<UserVariablesContextProxy, ContextProxy>("UserVariablesContext");

  rb_cDeclareVariableContext = rb_mMySqlParser
    .define_class<DeclareVariableContextProxy, ContextProxy>("DeclareVariableContext")
    .define_method("uid_list", &DeclareVariableContextProxy::uidList)
    .define_method("data_type", &DeclareVariableContextProxy::dataType)
    .define_method("default_value", &DeclareVariableContextProxy::defaultValue);

  rb_cDeclareConditionContext = rb_mMySqlParser
    .define_class<DeclareConditionContextProxy, ContextProxy>("DeclareConditionContext")
    .define_method("uid", &DeclareConditionContextProxy::uid)
    .define_method("decimal_literal", &DeclareConditionContextProxy::decimalLiteral);

  rb_cDeclareCursorContext = rb_mMySqlParser
    .define_class<DeclareCursorContextProxy, ContextProxy>("DeclareCursorContext")
    .define_method("uid", &DeclareCursorContextProxy::uid)
    .define_method("select_statement", &DeclareCursorContextProxy::selectStatement);

  rb_cDeclareHandlerContext = rb_mMySqlParser
    .define_class<DeclareHandlerContextProxy, ContextProxy>("DeclareHandlerContext")
    .define_method("handler_condition_value", &DeclareHandlerContextProxy::handlerConditionValue)
    .define_method("handler_condition_value_at", &DeclareHandlerContextProxy::handlerConditionValueAt)
    .define_method("routine_body", &DeclareHandlerContextProxy::routineBody);

  rb_cProcedureSqlStatementContext = rb_mMySqlParser
    .define_class<ProcedureSqlStatementContextProxy, ContextProxy>("ProcedureSqlStatementContext")
    .define_method("compound_statement", &ProcedureSqlStatementContextProxy::compoundStatement)
    .define_method("sql_statement", &ProcedureSqlStatementContextProxy::sqlStatement);

  rb_cCaseAlternativeContext = rb_mMySqlParser
    .define_class<CaseAlternativeContextProxy, ContextProxy>("CaseAlternativeContext")
    .define_method("constant", &CaseAlternativeContextProxy::constant)
    .define_method("expression", &CaseAlternativeContextProxy::expression)
    .define_method("procedure_sql_statement", &CaseAlternativeContextProxy::procedureSqlStatement)
    .define_method("procedure_sql_statement_at", &CaseAlternativeContextProxy::procedureSqlStatementAt);

  rb_cElifAlternativeContext = rb_mMySqlParser
    .define_class<ElifAlternativeContextProxy, ContextProxy>("ElifAlternativeContext")
    .define_method("expression", &ElifAlternativeContextProxy::expression)
    .define_method("procedure_sql_statement", &ElifAlternativeContextProxy::procedureSqlStatement)
    .define_method("procedure_sql_statement_at", &ElifAlternativeContextProxy::procedureSqlStatementAt);

  rb_cCloseCursorContext = rb_mMySqlParser
    .define_class<CloseCursorContextProxy, ContextProxy>("CloseCursorContext")
    .define_method("uid", &CloseCursorContextProxy::uid);

  rb_cOpenCursorContext = rb_mMySqlParser
    .define_class<OpenCursorContextProxy, ContextProxy>("OpenCursorContext")
    .define_method("uid", &OpenCursorContextProxy::uid);

  rb_cFetchCursorContext = rb_mMySqlParser
    .define_class<FetchCursorContextProxy, ContextProxy>("FetchCursorContext")
    .define_method("uid", &FetchCursorContextProxy::uid)
    .define_method("uid_list", &FetchCursorContextProxy::uidList);

  rb_cHandlerConditionValueContext = rb_mMySqlParser
    .define_class<HandlerConditionValueContextProxy, ContextProxy>("HandlerConditionValueContext");

  rb_cHandlerConditionWarningContext = rb_mMySqlParser
    .define_class<HandlerConditionWarningContextProxy, ContextProxy>("HandlerConditionWarningContext");

  rb_cHandlerConditionCodeContext = rb_mMySqlParser
    .define_class<HandlerConditionCodeContextProxy, ContextProxy>("HandlerConditionCodeContext")
    .define_method("decimal_literal", &HandlerConditionCodeContextProxy::decimalLiteral);

  rb_cHandlerConditionNotfoundContext = rb_mMySqlParser
    .define_class<HandlerConditionNotfoundContextProxy, ContextProxy>("HandlerConditionNotfoundContext");

  rb_cHandlerConditionStateContext = rb_mMySqlParser
    .define_class<HandlerConditionStateContextProxy, ContextProxy>("HandlerConditionStateContext");

  rb_cHandlerConditionExceptionContext = rb_mMySqlParser
    .define_class<HandlerConditionExceptionContextProxy, ContextProxy>("HandlerConditionExceptionContext");

  rb_cHandlerConditionNameContext = rb_mMySqlParser
    .define_class<HandlerConditionNameContextProxy, ContextProxy>("HandlerConditionNameContext")
    .define_method("uid", &HandlerConditionNameContextProxy::uid);

  rb_cAlterUserMysqlV56Context = rb_mMySqlParser
    .define_class<AlterUserMysqlV56ContextProxy, ContextProxy>("AlterUserMysqlV56Context")
    .define_method("user_specification", &AlterUserMysqlV56ContextProxy::userSpecification)
    .define_method("user_specification_at", &AlterUserMysqlV56ContextProxy::userSpecificationAt);

  rb_cUserSpecificationContext = rb_mMySqlParser
    .define_class<UserSpecificationContextProxy, ContextProxy>("UserSpecificationContext")
    .define_method("user_name", &UserSpecificationContextProxy::userName)
    .define_method("user_password_option", &UserSpecificationContextProxy::userPasswordOption);

  rb_cAlterUserMysqlV57Context = rb_mMySqlParser
    .define_class<AlterUserMysqlV57ContextProxy, ContextProxy>("AlterUserMysqlV57Context")
    .define_method("user_auth_option", &AlterUserMysqlV57ContextProxy::userAuthOption)
    .define_method("user_auth_option_at", &AlterUserMysqlV57ContextProxy::userAuthOptionAt)
    .define_method("if_exists", &AlterUserMysqlV57ContextProxy::ifExists)
    .define_method("user_password_option", &AlterUserMysqlV57ContextProxy::userPasswordOption)
    .define_method("user_password_option_at", &AlterUserMysqlV57ContextProxy::userPasswordOptionAt)
    .define_method("user_lock_option", &AlterUserMysqlV57ContextProxy::userLockOption)
    .define_method("user_lock_option_at", &AlterUserMysqlV57ContextProxy::userLockOptionAt)
    .define_method("tls_option", &AlterUserMysqlV57ContextProxy::tlsOption)
    .define_method("tls_option_at", &AlterUserMysqlV57ContextProxy::tlsOptionAt)
    .define_method("user_resource_option", &AlterUserMysqlV57ContextProxy::userResourceOption)
    .define_method("user_resource_option_at", &AlterUserMysqlV57ContextProxy::userResourceOptionAt);

  rb_cUserAuthOptionContext = rb_mMySqlParser
    .define_class<UserAuthOptionContextProxy, ContextProxy>("UserAuthOptionContext");

  rb_cUserPasswordOptionContext = rb_mMySqlParser
    .define_class<UserPasswordOptionContextProxy, ContextProxy>("UserPasswordOptionContext")
    .define_method("decimal_literal", &UserPasswordOptionContextProxy::decimalLiteral);

  rb_cUserLockOptionContext = rb_mMySqlParser
    .define_class<UserLockOptionContextProxy, ContextProxy>("UserLockOptionContext");

  rb_cTlsOptionContext = rb_mMySqlParser
    .define_class<TlsOptionContextProxy, ContextProxy>("TlsOptionContext");

  rb_cUserResourceOptionContext = rb_mMySqlParser
    .define_class<UserResourceOptionContextProxy, ContextProxy>("UserResourceOptionContext")
    .define_method("decimal_literal", &UserResourceOptionContextProxy::decimalLiteral);

  rb_cCreateUserMysqlV57Context = rb_mMySqlParser
    .define_class<CreateUserMysqlV57ContextProxy, ContextProxy>("CreateUserMysqlV57Context")
    .define_method("user_auth_option", &CreateUserMysqlV57ContextProxy::userAuthOption)
    .define_method("user_auth_option_at", &CreateUserMysqlV57ContextProxy::userAuthOptionAt)
    .define_method("if_not_exists", &CreateUserMysqlV57ContextProxy::ifNotExists)
    .define_method("user_password_option", &CreateUserMysqlV57ContextProxy::userPasswordOption)
    .define_method("user_password_option_at", &CreateUserMysqlV57ContextProxy::userPasswordOptionAt)
    .define_method("user_lock_option", &CreateUserMysqlV57ContextProxy::userLockOption)
    .define_method("user_lock_option_at", &CreateUserMysqlV57ContextProxy::userLockOptionAt)
    .define_method("tls_option", &CreateUserMysqlV57ContextProxy::tlsOption)
    .define_method("tls_option_at", &CreateUserMysqlV57ContextProxy::tlsOptionAt)
    .define_method("user_resource_option", &CreateUserMysqlV57ContextProxy::userResourceOption)
    .define_method("user_resource_option_at", &CreateUserMysqlV57ContextProxy::userResourceOptionAt);

  rb_cCreateUserMysqlV56Context = rb_mMySqlParser
    .define_class<CreateUserMysqlV56ContextProxy, ContextProxy>("CreateUserMysqlV56Context")
    .define_method("user_auth_option", &CreateUserMysqlV56ContextProxy::userAuthOption)
    .define_method("user_auth_option_at", &CreateUserMysqlV56ContextProxy::userAuthOptionAt);

  rb_cPrivelegeClauseContext = rb_mMySqlParser
    .define_class<PrivelegeClauseContextProxy, ContextProxy>("PrivelegeClauseContext")
    .define_method("privilege", &PrivelegeClauseContextProxy::privilege)
    .define_method("uid_list", &PrivelegeClauseContextProxy::uidList);

  rb_cPrivilegeLevelContext = rb_mMySqlParser
    .define_class<PrivilegeLevelContextProxy, ContextProxy>("PrivilegeLevelContext");

  rb_cRenameUserClauseContext = rb_mMySqlParser
    .define_class<RenameUserClauseContextProxy, ContextProxy>("RenameUserClauseContext")
    .define_method("user_name", &RenameUserClauseContextProxy::userName)
    .define_method("user_name_at", &RenameUserClauseContextProxy::userNameAt);

  rb_cDetailRevokeContext = rb_mMySqlParser
    .define_class<DetailRevokeContextProxy, ContextProxy>("DetailRevokeContext")
    .define_method("privelege_clause", &DetailRevokeContextProxy::privelegeClause)
    .define_method("privelege_clause_at", &DetailRevokeContextProxy::privelegeClauseAt)
    .define_method("privilege_level", &DetailRevokeContextProxy::privilegeLevel)
    .define_method("user_name", &DetailRevokeContextProxy::userName)
    .define_method("user_name_at", &DetailRevokeContextProxy::userNameAt);

  rb_cShortRevokeContext = rb_mMySqlParser
    .define_class<ShortRevokeContextProxy, ContextProxy>("ShortRevokeContext")
    .define_method("user_name", &ShortRevokeContextProxy::userName)
    .define_method("user_name_at", &ShortRevokeContextProxy::userNameAt);

  rb_cSetPasswordStatementContext = rb_mMySqlParser
    .define_class<SetPasswordStatementContextProxy, ContextProxy>("SetPasswordStatementContext")
    .define_method("password_function_clause", &SetPasswordStatementContextProxy::passwordFunctionClause)
    .define_method("user_name", &SetPasswordStatementContextProxy::userName);

  rb_cPasswordFunctionClauseContext = rb_mMySqlParser
    .define_class<PasswordFunctionClauseContextProxy, ContextProxy>("PasswordFunctionClauseContext")
    .define_method("function_arg", &PasswordFunctionClauseContextProxy::functionArg);

  rb_cSimpleAuthOptionContext = rb_mMySqlParser
    .define_class<SimpleAuthOptionContextProxy, ContextProxy>("SimpleAuthOptionContext")
    .define_method("user_name", &SimpleAuthOptionContextProxy::userName);

  rb_cPasswordAuthOptionContext = rb_mMySqlParser
    .define_class<PasswordAuthOptionContextProxy, ContextProxy>("PasswordAuthOptionContext")
    .define_method("user_name", &PasswordAuthOptionContextProxy::userName);

  rb_cStringAuthOptionContext = rb_mMySqlParser
    .define_class<StringAuthOptionContextProxy, ContextProxy>("StringAuthOptionContext")
    .define_method("user_name", &StringAuthOptionContextProxy::userName)
    .define_method("auth_plugin", &StringAuthOptionContextProxy::authPlugin);

  rb_cAuthPluginContext = rb_mMySqlParser
    .define_class<AuthPluginContextProxy, ContextProxy>("AuthPluginContext")
    .define_method("uid", &AuthPluginContextProxy::uid);

  rb_cHashAuthOptionContext = rb_mMySqlParser
    .define_class<HashAuthOptionContextProxy, ContextProxy>("HashAuthOptionContext")
    .define_method("user_name", &HashAuthOptionContextProxy::userName)
    .define_method("auth_plugin", &HashAuthOptionContextProxy::authPlugin);

  rb_cPrivilegeContext = rb_mMySqlParser
    .define_class<PrivilegeContextProxy, ContextProxy>("PrivilegeContext");

  rb_cDefiniteSchemaPrivLevelContext = rb_mMySqlParser
    .define_class<DefiniteSchemaPrivLevelContextProxy, ContextProxy>("DefiniteSchemaPrivLevelContext")
    .define_method("uid", &DefiniteSchemaPrivLevelContextProxy::uid);

  rb_cDefiniteFullTablePrivLevel2Context = rb_mMySqlParser
    .define_class<DefiniteFullTablePrivLevel2ContextProxy, ContextProxy>("DefiniteFullTablePrivLevel2Context")
    .define_method("uid", &DefiniteFullTablePrivLevel2ContextProxy::uid)
    .define_method("dotted_id", &DefiniteFullTablePrivLevel2ContextProxy::dottedId);

  rb_cDottedIdContext = rb_mMySqlParser
    .define_class<DottedIdContextProxy, ContextProxy>("DottedIdContext")
    .define_method("uid", &DottedIdContextProxy::uid);

  rb_cDefiniteFullTablePrivLevelContext = rb_mMySqlParser
    .define_class<DefiniteFullTablePrivLevelContextProxy, ContextProxy>("DefiniteFullTablePrivLevelContext")
    .define_method("uid", &DefiniteFullTablePrivLevelContextProxy::uid)
    .define_method("uid_at", &DefiniteFullTablePrivLevelContextProxy::uidAt);

  rb_cGlobalPrivLevelContext = rb_mMySqlParser
    .define_class<GlobalPrivLevelContextProxy, ContextProxy>("GlobalPrivLevelContext");

  rb_cDefiniteTablePrivLevelContext = rb_mMySqlParser
    .define_class<DefiniteTablePrivLevelContextProxy, ContextProxy>("DefiniteTablePrivLevelContext")
    .define_method("uid", &DefiniteTablePrivLevelContextProxy::uid);

  rb_cCurrentSchemaPriviLevelContext = rb_mMySqlParser
    .define_class<CurrentSchemaPriviLevelContextProxy, ContextProxy>("CurrentSchemaPriviLevelContext");

  rb_cCheckTableOptionContext = rb_mMySqlParser
    .define_class<CheckTableOptionContextProxy, ContextProxy>("CheckTableOptionContext");

  rb_cSetTransactionContext = rb_mMySqlParser
    .define_class<SetTransactionContextProxy, ContextProxy>("SetTransactionContext")
    .define_method("set_transaction_statement", &SetTransactionContextProxy::setTransactionStatement);

  rb_cSetCharsetContext = rb_mMySqlParser
    .define_class<SetCharsetContextProxy, ContextProxy>("SetCharsetContext")
    .define_method("charset_name", &SetCharsetContextProxy::charsetName);

  rb_cSetNamesContext = rb_mMySqlParser
    .define_class<SetNamesContextProxy, ContextProxy>("SetNamesContext")
    .define_method("charset_name", &SetNamesContextProxy::charsetName)
    .define_method("collation_name", &SetNamesContextProxy::collationName);

  rb_cSetPasswordContext = rb_mMySqlParser
    .define_class<SetPasswordContextProxy, ContextProxy>("SetPasswordContext")
    .define_method("set_password_statement", &SetPasswordContextProxy::setPasswordStatement);

  rb_cSetAutocommitContext = rb_mMySqlParser
    .define_class<SetAutocommitContextProxy, ContextProxy>("SetAutocommitContext")
    .define_method("set_autocommit_statement", &SetAutocommitContextProxy::setAutocommitStatement);

  rb_cSetNewValueInsideTriggerContext = rb_mMySqlParser
    .define_class<SetNewValueInsideTriggerContextProxy, ContextProxy>("SetNewValueInsideTriggerContext")
    .define_method("full_id", &SetNewValueInsideTriggerContextProxy::fullId)
    .define_method("expression", &SetNewValueInsideTriggerContextProxy::expression);

  rb_cSetVariableContext = rb_mMySqlParser
    .define_class<SetVariableContextProxy, ContextProxy>("SetVariableContext")
    .define_method("variable_clause", &SetVariableContextProxy::variableClause)
    .define_method("variable_clause_at", &SetVariableContextProxy::variableClauseAt)
    .define_method("expression", &SetVariableContextProxy::expression)
    .define_method("expression_at", &SetVariableContextProxy::expressionAt);

  rb_cVariableClauseContext = rb_mMySqlParser
    .define_class<VariableClauseContextProxy, ContextProxy>("VariableClauseContext")
    .define_method("uid", &VariableClauseContextProxy::uid);

  rb_cShowOpenTablesContext = rb_mMySqlParser
    .define_class<ShowOpenTablesContextProxy, ContextProxy>("ShowOpenTablesContext")
    .define_method("uid", &ShowOpenTablesContextProxy::uid)
    .define_method("show_filter", &ShowOpenTablesContextProxy::showFilter);

  rb_cShowFilterContext = rb_mMySqlParser
    .define_class<ShowFilterContextProxy, ContextProxy>("ShowFilterContext")
    .define_method("expression", &ShowFilterContextProxy::expression);

  rb_cShowGlobalInfoContext = rb_mMySqlParser
    .define_class<ShowGlobalInfoContextProxy, ContextProxy>("ShowGlobalInfoContext")
    .define_method("show_global_info_clause", &ShowGlobalInfoContextProxy::showGlobalInfoClause);

  rb_cShowGlobalInfoClauseContext = rb_mMySqlParser
    .define_class<ShowGlobalInfoClauseContextProxy, ContextProxy>("ShowGlobalInfoClauseContext");

  rb_cShowCreateFullIdObjectContext = rb_mMySqlParser
    .define_class<ShowCreateFullIdObjectContextProxy, ContextProxy>("ShowCreateFullIdObjectContext")
    .define_method("full_id", &ShowCreateFullIdObjectContextProxy::fullId);

  rb_cShowCreateUserContext = rb_mMySqlParser
    .define_class<ShowCreateUserContextProxy, ContextProxy>("ShowCreateUserContext")
    .define_method("user_name", &ShowCreateUserContextProxy::userName);

  rb_cShowErrorsContext = rb_mMySqlParser
    .define_class<ShowErrorsContextProxy, ContextProxy>("ShowErrorsContext")
    .define_method("decimal_literal", &ShowErrorsContextProxy::decimalLiteral)
    .define_method("decimal_literal_at", &ShowErrorsContextProxy::decimalLiteralAt);

  rb_cShowCountErrorsContext = rb_mMySqlParser
    .define_class<ShowCountErrorsContextProxy, ContextProxy>("ShowCountErrorsContext");

  rb_cShowObjectFilterContext = rb_mMySqlParser
    .define_class<ShowObjectFilterContextProxy, ContextProxy>("ShowObjectFilterContext")
    .define_method("show_common_entity", &ShowObjectFilterContextProxy::showCommonEntity)
    .define_method("show_filter", &ShowObjectFilterContextProxy::showFilter);

  rb_cShowCommonEntityContext = rb_mMySqlParser
    .define_class<ShowCommonEntityContextProxy, ContextProxy>("ShowCommonEntityContext");

  rb_cShowCreateDbContext = rb_mMySqlParser
    .define_class<ShowCreateDbContextProxy, ContextProxy>("ShowCreateDbContext")
    .define_method("uid", &ShowCreateDbContextProxy::uid)
    .define_method("if_not_exists", &ShowCreateDbContextProxy::ifNotExists);

  rb_cShowEngineContext = rb_mMySqlParser
    .define_class<ShowEngineContextProxy, ContextProxy>("ShowEngineContext")
    .define_method("engine_name", &ShowEngineContextProxy::engineName);

  rb_cShowSchemaFilterContext = rb_mMySqlParser
    .define_class<ShowSchemaFilterContextProxy, ContextProxy>("ShowSchemaFilterContext")
    .define_method("show_schema_entity", &ShowSchemaFilterContextProxy::showSchemaEntity)
    .define_method("uid", &ShowSchemaFilterContextProxy::uid)
    .define_method("show_filter", &ShowSchemaFilterContextProxy::showFilter);

  rb_cShowSchemaEntityContext = rb_mMySqlParser
    .define_class<ShowSchemaEntityContextProxy, ContextProxy>("ShowSchemaEntityContext");

  rb_cShowIndexesContext = rb_mMySqlParser
    .define_class<ShowIndexesContextProxy, ContextProxy>("ShowIndexesContext")
    .define_method("table_name", &ShowIndexesContextProxy::tableName)
    .define_method("uid", &ShowIndexesContextProxy::uid)
    .define_method("expression", &ShowIndexesContextProxy::expression);

  rb_cShowLogEventsContext = rb_mMySqlParser
    .define_class<ShowLogEventsContextProxy, ContextProxy>("ShowLogEventsContext")
    .define_method("decimal_literal", &ShowLogEventsContextProxy::decimalLiteral)
    .define_method("decimal_literal_at", &ShowLogEventsContextProxy::decimalLiteralAt);

  rb_cShowMasterLogsContext = rb_mMySqlParser
    .define_class<ShowMasterLogsContextProxy, ContextProxy>("ShowMasterLogsContext");

  rb_cShowGrantsContext = rb_mMySqlParser
    .define_class<ShowGrantsContextProxy, ContextProxy>("ShowGrantsContext")
    .define_method("user_name", &ShowGrantsContextProxy::userName);

  rb_cShowSlaveStatusContext = rb_mMySqlParser
    .define_class<ShowSlaveStatusContextProxy, ContextProxy>("ShowSlaveStatusContext");

  rb_cShowRoutineContext = rb_mMySqlParser
    .define_class<ShowRoutineContextProxy, ContextProxy>("ShowRoutineContext")
    .define_method("full_id", &ShowRoutineContextProxy::fullId);

  rb_cShowProfileContext = rb_mMySqlParser
    .define_class<ShowProfileContextProxy, ContextProxy>("ShowProfileContext")
    .define_method("show_profile_type", &ShowProfileContextProxy::showProfileType)
    .define_method("show_profile_type_at", &ShowProfileContextProxy::showProfileTypeAt)
    .define_method("decimal_literal", &ShowProfileContextProxy::decimalLiteral)
    .define_method("decimal_literal_at", &ShowProfileContextProxy::decimalLiteralAt);

  rb_cShowProfileTypeContext = rb_mMySqlParser
    .define_class<ShowProfileTypeContextProxy, ContextProxy>("ShowProfileTypeContext");

  rb_cShowColumnsContext = rb_mMySqlParser
    .define_class<ShowColumnsContextProxy, ContextProxy>("ShowColumnsContext")
    .define_method("table_name", &ShowColumnsContextProxy::tableName)
    .define_method("uid", &ShowColumnsContextProxy::uid)
    .define_method("show_filter", &ShowColumnsContextProxy::showFilter);

  rb_cTableIndexesContext = rb_mMySqlParser
    .define_class<TableIndexesContextProxy, ContextProxy>("TableIndexesContext")
    .define_method("table_name", &TableIndexesContextProxy::tableName)
    .define_method("uid_list", &TableIndexesContextProxy::uidList);

  rb_cFlushOptionContext = rb_mMySqlParser
    .define_class<FlushOptionContextProxy, ContextProxy>("FlushOptionContext");

  rb_cLoadedTableIndexesContext = rb_mMySqlParser
    .define_class<LoadedTableIndexesContextProxy, ContextProxy>("LoadedTableIndexesContext")
    .define_method("table_name", &LoadedTableIndexesContextProxy::tableName)
    .define_method("uid_list", &LoadedTableIndexesContextProxy::uidList)
    .define_method("uid_list_at", &LoadedTableIndexesContextProxy::uidListAt);

  rb_cTableFlushOptionContext = rb_mMySqlParser
    .define_class<TableFlushOptionContextProxy, ContextProxy>("TableFlushOptionContext")
    .define_method("tables", &TableFlushOptionContextProxy::tables)
    .define_method("flush_table_option", &TableFlushOptionContextProxy::flushTableOption);

  rb_cFlushTableOptionContext = rb_mMySqlParser
    .define_class<FlushTableOptionContextProxy, ContextProxy>("FlushTableOptionContext");

  rb_cChannelFlushOptionContext = rb_mMySqlParser
    .define_class<ChannelFlushOptionContextProxy, ContextProxy>("ChannelFlushOptionContext")
    .define_method("channel_option", &ChannelFlushOptionContextProxy::channelOption);

  rb_cSimpleFlushOptionContext = rb_mMySqlParser
    .define_class<SimpleFlushOptionContextProxy, ContextProxy>("SimpleFlushOptionContext");

  rb_cDescribeObjectClauseContext = rb_mMySqlParser
    .define_class<DescribeObjectClauseContextProxy, ContextProxy>("DescribeObjectClauseContext");

  rb_cSignalConditionInformationContext = rb_mMySqlParser
    .define_class<SignalConditionInformationContextProxy, ContextProxy>("SignalConditionInformationContext")
    .define_method("string_literal", &SignalConditionInformationContextProxy::stringLiteral);

  rb_cDiagnosticsConditionInformationNameContext = rb_mMySqlParser
    .define_class<DiagnosticsConditionInformationNameContextProxy, ContextProxy>("DiagnosticsConditionInformationNameContext");

  rb_cDescribeStatementsContext = rb_mMySqlParser
    .define_class<DescribeStatementsContextProxy, ContextProxy>("DescribeStatementsContext")
    .define_method("select_statement", &DescribeStatementsContextProxy::selectStatement)
    .define_method("delete_statement", &DescribeStatementsContextProxy::deleteStatement)
    .define_method("insert_statement", &DescribeStatementsContextProxy::insertStatement)
    .define_method("replace_statement", &DescribeStatementsContextProxy::replaceStatement)
    .define_method("update_statement", &DescribeStatementsContextProxy::updateStatement);

  rb_cDescribeConnectionContext = rb_mMySqlParser
    .define_class<DescribeConnectionContextProxy, ContextProxy>("DescribeConnectionContext")
    .define_method("uid", &DescribeConnectionContextProxy::uid);

  rb_cIndexColumnNameContext = rb_mMySqlParser
    .define_class<IndexColumnNameContextProxy, ContextProxy>("IndexColumnNameContext")
    .define_method("uid", &IndexColumnNameContextProxy::uid)
    .define_method("decimal_literal", &IndexColumnNameContextProxy::decimalLiteral);

  rb_cCharsetNameBaseContext = rb_mMySqlParser
    .define_class<CharsetNameBaseContextProxy, ContextProxy>("CharsetNameBaseContext");

  rb_cXuidStringIdContext = rb_mMySqlParser
    .define_class<XuidStringIdContextProxy, ContextProxy>("XuidStringIdContext");

  rb_cSimpleIdContext = rb_mMySqlParser
    .define_class<SimpleIdContextProxy, ContextProxy>("SimpleIdContext")
    .define_method("charset_name_base", &SimpleIdContextProxy::charsetNameBase)
    .define_method("transaction_level_base", &SimpleIdContextProxy::transactionLevelBase)
    .define_method("engine_name", &SimpleIdContextProxy::engineName)
    .define_method("privileges_base", &SimpleIdContextProxy::privilegesBase)
    .define_method("interval_type_base", &SimpleIdContextProxy::intervalTypeBase)
    .define_method("data_type_base", &SimpleIdContextProxy::dataTypeBase)
    .define_method("keywords_can_be_id", &SimpleIdContextProxy::keywordsCanBeId)
    .define_method("function_name_base", &SimpleIdContextProxy::functionNameBase);

  rb_cTransactionLevelBaseContext = rb_mMySqlParser
    .define_class<TransactionLevelBaseContextProxy, ContextProxy>("TransactionLevelBaseContext");

  rb_cPrivilegesBaseContext = rb_mMySqlParser
    .define_class<PrivilegesBaseContextProxy, ContextProxy>("PrivilegesBaseContext");

  rb_cDataTypeBaseContext = rb_mMySqlParser
    .define_class<DataTypeBaseContextProxy, ContextProxy>("DataTypeBaseContext");

  rb_cKeywordsCanBeIdContext = rb_mMySqlParser
    .define_class<KeywordsCanBeIdContextProxy, ContextProxy>("KeywordsCanBeIdContext");

  rb_cFunctionNameBaseContext = rb_mMySqlParser
    .define_class<FunctionNameBaseContextProxy, ContextProxy>("FunctionNameBaseContext");

  rb_cBooleanLiteralContext = rb_mMySqlParser
    .define_class<BooleanLiteralContextProxy, ContextProxy>("BooleanLiteralContext");

  rb_cHexadecimalLiteralContext = rb_mMySqlParser
    .define_class<HexadecimalLiteralContextProxy, ContextProxy>("HexadecimalLiteralContext");

  rb_cSpatialDataTypeContext = rb_mMySqlParser
    .define_class<SpatialDataTypeContextProxy, ContextProxy>("SpatialDataTypeContext");

  rb_cCollectionOptionsContext = rb_mMySqlParser
    .define_class<CollectionOptionsContextProxy, ContextProxy>("CollectionOptionsContext");

  rb_cCollectionDataTypeContext = rb_mMySqlParser
    .define_class<CollectionDataTypeContextProxy, ContextProxy>("CollectionDataTypeContext")
    .define_method("collection_options", &CollectionDataTypeContextProxy::collectionOptions)
    .define_method("charset_name", &CollectionDataTypeContextProxy::charsetName);

  rb_cNationalVaryingStringDataTypeContext = rb_mMySqlParser
    .define_class<NationalVaryingStringDataTypeContextProxy, ContextProxy>("NationalVaryingStringDataTypeContext")
    .define_method("length_one_dimension", &NationalVaryingStringDataTypeContextProxy::lengthOneDimension);

  rb_cLengthOneDimensionContext = rb_mMySqlParser
    .define_class<LengthOneDimensionContextProxy, ContextProxy>("LengthOneDimensionContext")
    .define_method("decimal_literal", &LengthOneDimensionContextProxy::decimalLiteral);

  rb_cDimensionDataTypeContext = rb_mMySqlParser
    .define_class<DimensionDataTypeContextProxy, ContextProxy>("DimensionDataTypeContext")
    .define_method("length_one_dimension", &DimensionDataTypeContextProxy::lengthOneDimension)
    .define_method("length_two_dimension", &DimensionDataTypeContextProxy::lengthTwoDimension)
    .define_method("length_two_optional_dimension", &DimensionDataTypeContextProxy::lengthTwoOptionalDimension);

  rb_cLengthTwoDimensionContext = rb_mMySqlParser
    .define_class<LengthTwoDimensionContextProxy, ContextProxy>("LengthTwoDimensionContext")
    .define_method("decimal_literal", &LengthTwoDimensionContextProxy::decimalLiteral)
    .define_method("decimal_literal_at", &LengthTwoDimensionContextProxy::decimalLiteralAt);

  rb_cLengthTwoOptionalDimensionContext = rb_mMySqlParser
    .define_class<LengthTwoOptionalDimensionContextProxy, ContextProxy>("LengthTwoOptionalDimensionContext")
    .define_method("decimal_literal", &LengthTwoOptionalDimensionContextProxy::decimalLiteral)
    .define_method("decimal_literal_at", &LengthTwoOptionalDimensionContextProxy::decimalLiteralAt);

  rb_cStringDataTypeContext = rb_mMySqlParser
    .define_class<StringDataTypeContextProxy, ContextProxy>("StringDataTypeContext")
    .define_method("length_one_dimension", &StringDataTypeContextProxy::lengthOneDimension)
    .define_method("charset_name", &StringDataTypeContextProxy::charsetName)
    .define_method("collation_name", &StringDataTypeContextProxy::collationName);

  rb_cNationalStringDataTypeContext = rb_mMySqlParser
    .define_class<NationalStringDataTypeContextProxy, ContextProxy>("NationalStringDataTypeContext")
    .define_method("length_one_dimension", &NationalStringDataTypeContextProxy::lengthOneDimension);

  rb_cSimpleDataTypeContext = rb_mMySqlParser
    .define_class<SimpleDataTypeContextProxy, ContextProxy>("SimpleDataTypeContext");

  rb_cConvertedDataTypeContext = rb_mMySqlParser
    .define_class<ConvertedDataTypeContextProxy, ContextProxy>("ConvertedDataTypeContext")
    .define_method("length_one_dimension", &ConvertedDataTypeContextProxy::lengthOneDimension)
    .define_method("charset_name", &ConvertedDataTypeContextProxy::charsetName)
    .define_method("length_two_dimension", &ConvertedDataTypeContextProxy::lengthTwoDimension);

  rb_cExpressionOrDefaultContext = rb_mMySqlParser
    .define_class<ExpressionOrDefaultContextProxy, ContextProxy>("ExpressionOrDefaultContext")
    .define_method("expression", &ExpressionOrDefaultContextProxy::expression);

  rb_cUnaryOperatorContext = rb_mMySqlParser
    .define_class<UnaryOperatorContextProxy, ContextProxy>("UnaryOperatorContext");

  rb_cSpecificFunctionContext = rb_mMySqlParser
    .define_class<SpecificFunctionContextProxy, ContextProxy>("SpecificFunctionContext");

  rb_cSpecificFunctionCallContext = rb_mMySqlParser
    .define_class<SpecificFunctionCallContextProxy, ContextProxy>("SpecificFunctionCallContext")
    .define_method("specific_function", &SpecificFunctionCallContextProxy::specificFunction);

  rb_cPasswordFunctionCallContext = rb_mMySqlParser
    .define_class<PasswordFunctionCallContextProxy, ContextProxy>("PasswordFunctionCallContext")
    .define_method("password_function_clause", &PasswordFunctionCallContextProxy::passwordFunctionClause);

  rb_cUdfFunctionCallContext = rb_mMySqlParser
    .define_class<UdfFunctionCallContextProxy, ContextProxy>("UdfFunctionCallContext")
    .define_method("full_id", &UdfFunctionCallContextProxy::fullId)
    .define_method("function_args", &UdfFunctionCallContextProxy::functionArgs);

  rb_cFunctionArgsContext = rb_mMySqlParser
    .define_class<FunctionArgsContextProxy, ContextProxy>("FunctionArgsContext")
    .define_method("constant", &FunctionArgsContextProxy::constant)
    .define_method("constant_at", &FunctionArgsContextProxy::constantAt)
    .define_method("full_column_name", &FunctionArgsContextProxy::fullColumnName)
    .define_method("full_column_name_at", &FunctionArgsContextProxy::fullColumnNameAt)
    .define_method("function_call", &FunctionArgsContextProxy::functionCall)
    .define_method("function_call_at", &FunctionArgsContextProxy::functionCallAt)
    .define_method("expression", &FunctionArgsContextProxy::expression)
    .define_method("expression_at", &FunctionArgsContextProxy::expressionAt);

  rb_cAggregateWindowedFunctionContext = rb_mMySqlParser
    .define_class<AggregateWindowedFunctionContextProxy, ContextProxy>("AggregateWindowedFunctionContext")
    .define_method("function_arg", &AggregateWindowedFunctionContextProxy::functionArg)
    .define_method("function_args", &AggregateWindowedFunctionContextProxy::functionArgs)
    .define_method("order_by_expression", &AggregateWindowedFunctionContextProxy::orderByExpression)
    .define_method("order_by_expression_at", &AggregateWindowedFunctionContextProxy::orderByExpressionAt);

  rb_cAggregateFunctionCallContext = rb_mMySqlParser
    .define_class<AggregateFunctionCallContextProxy, ContextProxy>("AggregateFunctionCallContext")
    .define_method("aggregate_windowed_function", &AggregateFunctionCallContextProxy::aggregateWindowedFunction);

  rb_cScalarFunctionNameContext = rb_mMySqlParser
    .define_class<ScalarFunctionNameContextProxy, ContextProxy>("ScalarFunctionNameContext")
    .define_method("function_name_base", &ScalarFunctionNameContextProxy::functionNameBase);

  rb_cScalarFunctionCallContext = rb_mMySqlParser
    .define_class<ScalarFunctionCallContextProxy, ContextProxy>("ScalarFunctionCallContext")
    .define_method("scalar_function_name", &ScalarFunctionCallContextProxy::scalarFunctionName)
    .define_method("function_args", &ScalarFunctionCallContextProxy::functionArgs);

  rb_cPositionFunctionCallContext = rb_mMySqlParser
    .define_class<PositionFunctionCallContextProxy, ContextProxy>("PositionFunctionCallContext")
    .define_method("string_literal", &PositionFunctionCallContextProxy::stringLiteral)
    .define_method("string_literal_at", &PositionFunctionCallContextProxy::stringLiteralAt)
    .define_method("expression", &PositionFunctionCallContextProxy::expression)
    .define_method("expression_at", &PositionFunctionCallContextProxy::expressionAt);

  rb_cTrimFunctionCallContext = rb_mMySqlParser
    .define_class<TrimFunctionCallContextProxy, ContextProxy>("TrimFunctionCallContext")
    .define_method("string_literal", &TrimFunctionCallContextProxy::stringLiteral)
    .define_method("string_literal_at", &TrimFunctionCallContextProxy::stringLiteralAt)
    .define_method("expression", &TrimFunctionCallContextProxy::expression)
    .define_method("expression_at", &TrimFunctionCallContextProxy::expressionAt);

  rb_cSimpleFunctionCallContext = rb_mMySqlParser
    .define_class<SimpleFunctionCallContextProxy, ContextProxy>("SimpleFunctionCallContext");

  rb_cCharFunctionCallContext = rb_mMySqlParser
    .define_class<CharFunctionCallContextProxy, ContextProxy>("CharFunctionCallContext")
    .define_method("function_args", &CharFunctionCallContextProxy::functionArgs)
    .define_method("charset_name", &CharFunctionCallContextProxy::charsetName);

  rb_cWeightFunctionCallContext = rb_mMySqlParser
    .define_class<WeightFunctionCallContextProxy, ContextProxy>("WeightFunctionCallContext")
    .define_method("string_literal", &WeightFunctionCallContextProxy::stringLiteral)
    .define_method("expression", &WeightFunctionCallContextProxy::expression)
    .define_method("decimal_literal", &WeightFunctionCallContextProxy::decimalLiteral)
    .define_method("levels_in_weight_string", &WeightFunctionCallContextProxy::levelsInWeightString);

  rb_cLevelsInWeightStringContext = rb_mMySqlParser
    .define_class<LevelsInWeightStringContextProxy, ContextProxy>("LevelsInWeightStringContext");

  rb_cGetFormatFunctionCallContext = rb_mMySqlParser
    .define_class<GetFormatFunctionCallContextProxy, ContextProxy>("GetFormatFunctionCallContext")
    .define_method("string_literal", &GetFormatFunctionCallContextProxy::stringLiteral);

  rb_cCaseFunctionCallContext = rb_mMySqlParser
    .define_class<CaseFunctionCallContextProxy, ContextProxy>("CaseFunctionCallContext")
    .define_method("expression", &CaseFunctionCallContextProxy::expression)
    .define_method("case_func_alternative", &CaseFunctionCallContextProxy::caseFuncAlternative)
    .define_method("case_func_alternative_at", &CaseFunctionCallContextProxy::caseFuncAlternativeAt)
    .define_method("function_arg", &CaseFunctionCallContextProxy::functionArg);

  rb_cCaseFuncAlternativeContext = rb_mMySqlParser
    .define_class<CaseFuncAlternativeContextProxy, ContextProxy>("CaseFuncAlternativeContext")
    .define_method("function_arg", &CaseFuncAlternativeContextProxy::functionArg)
    .define_method("function_arg_at", &CaseFuncAlternativeContextProxy::functionArgAt);

  rb_cFunctionArgContext = rb_mMySqlParser
    .define_class<FunctionArgContextProxy, ContextProxy>("FunctionArgContext")
    .define_method("constant", &FunctionArgContextProxy::constant)
    .define_method("full_column_name", &FunctionArgContextProxy::fullColumnName)
    .define_method("function_call", &FunctionArgContextProxy::functionCall)
    .define_method("expression", &FunctionArgContextProxy::expression);

  rb_cExtractFunctionCallContext = rb_mMySqlParser
    .define_class<ExtractFunctionCallContextProxy, ContextProxy>("ExtractFunctionCallContext")
    .define_method("interval_type", &ExtractFunctionCallContextProxy::intervalType)
    .define_method("string_literal", &ExtractFunctionCallContextProxy::stringLiteral)
    .define_method("expression", &ExtractFunctionCallContextProxy::expression);

  rb_cDataTypeFunctionCallContext = rb_mMySqlParser
    .define_class<DataTypeFunctionCallContextProxy, ContextProxy>("DataTypeFunctionCallContext")
    .define_method("expression", &DataTypeFunctionCallContextProxy::expression)
    .define_method("converted_data_type", &DataTypeFunctionCallContextProxy::convertedDataType)
    .define_method("charset_name", &DataTypeFunctionCallContextProxy::charsetName);

  rb_cValuesFunctionCallContext = rb_mMySqlParser
    .define_class<ValuesFunctionCallContextProxy, ContextProxy>("ValuesFunctionCallContext")
    .define_method("full_column_name", &ValuesFunctionCallContextProxy::fullColumnName);

  rb_cSubstrFunctionCallContext = rb_mMySqlParser
    .define_class<SubstrFunctionCallContextProxy, ContextProxy>("SubstrFunctionCallContext")
    .define_method("string_literal", &SubstrFunctionCallContextProxy::stringLiteral)
    .define_method("expression", &SubstrFunctionCallContextProxy::expression)
    .define_method("expression_at", &SubstrFunctionCallContextProxy::expressionAt)
    .define_method("decimal_literal", &SubstrFunctionCallContextProxy::decimalLiteral)
    .define_method("decimal_literal_at", &SubstrFunctionCallContextProxy::decimalLiteralAt);

  rb_cLevelWeightRangeContext = rb_mMySqlParser
    .define_class<LevelWeightRangeContextProxy, ContextProxy>("LevelWeightRangeContext")
    .define_method("decimal_literal", &LevelWeightRangeContextProxy::decimalLiteral)
    .define_method("decimal_literal_at", &LevelWeightRangeContextProxy::decimalLiteralAt);

  rb_cLevelWeightListContext = rb_mMySqlParser
    .define_class<LevelWeightListContextProxy, ContextProxy>("LevelWeightListContext")
    .define_method("level_in_weight_list_element", &LevelWeightListContextProxy::levelInWeightListElement)
    .define_method("level_in_weight_list_element_at", &LevelWeightListContextProxy::levelInWeightListElementAt);

  rb_cLevelInWeightListElementContext = rb_mMySqlParser
    .define_class<LevelInWeightListElementContextProxy, ContextProxy>("LevelInWeightListElementContext")
    .define_method("decimal_literal", &LevelInWeightListElementContextProxy::decimalLiteral);

  rb_cPredicateContext = rb_mMySqlParser
    .define_class<PredicateContextProxy, ContextProxy>("PredicateContext");

  rb_cIsExpressionContext = rb_mMySqlParser
    .define_class<IsExpressionContextProxy, ContextProxy>("IsExpressionContext")
    .define_method("predicate", &IsExpressionContextProxy::predicate);

  rb_cNotExpressionContext = rb_mMySqlParser
    .define_class<NotExpressionContextProxy, ContextProxy>("NotExpressionContext")
    .define_method("expression", &NotExpressionContextProxy::expression);

  rb_cLogicalExpressionContext = rb_mMySqlParser
    .define_class<LogicalExpressionContextProxy, ContextProxy>("LogicalExpressionContext")
    .define_method("expression", &LogicalExpressionContextProxy::expression)
    .define_method("expression_at", &LogicalExpressionContextProxy::expressionAt)
    .define_method("logical_operator", &LogicalExpressionContextProxy::logicalOperator);

  rb_cLogicalOperatorContext = rb_mMySqlParser
    .define_class<LogicalOperatorContextProxy, ContextProxy>("LogicalOperatorContext");

  rb_cPredicateExpressionContext = rb_mMySqlParser
    .define_class<PredicateExpressionContextProxy, ContextProxy>("PredicateExpressionContext")
    .define_method("predicate", &PredicateExpressionContextProxy::predicate);

  rb_cSoundsLikePredicateContext = rb_mMySqlParser
    .define_class<SoundsLikePredicateContextProxy, ContextProxy>("SoundsLikePredicateContext")
    .define_method("predicate", &SoundsLikePredicateContextProxy::predicate)
    .define_method("predicate_at", &SoundsLikePredicateContextProxy::predicateAt);

  rb_cExpressionAtomContext = rb_mMySqlParser
    .define_class<ExpressionAtomContextProxy, ContextProxy>("ExpressionAtomContext");

  rb_cExpressionAtomPredicateContext = rb_mMySqlParser
    .define_class<ExpressionAtomPredicateContextProxy, ContextProxy>("ExpressionAtomPredicateContext")
    .define_method("expression_atom", &ExpressionAtomPredicateContextProxy::expressionAtom);

  rb_cInPredicateContext = rb_mMySqlParser
    .define_class<InPredicateContextProxy, ContextProxy>("InPredicateContext")
    .define_method("predicate", &InPredicateContextProxy::predicate)
    .define_method("select_statement", &InPredicateContextProxy::selectStatement)
    .define_method("expressions", &InPredicateContextProxy::expressions);

  rb_cSubqueryComparasionPredicateContext = rb_mMySqlParser
    .define_class<SubqueryComparasionPredicateContextProxy, ContextProxy>("SubqueryComparasionPredicateContext")
    .define_method("predicate", &SubqueryComparasionPredicateContextProxy::predicate)
    .define_method("comparison_operator", &SubqueryComparasionPredicateContextProxy::comparisonOperator)
    .define_method("select_statement", &SubqueryComparasionPredicateContextProxy::selectStatement);

  rb_cBetweenPredicateContext = rb_mMySqlParser
    .define_class<BetweenPredicateContextProxy, ContextProxy>("BetweenPredicateContext")
    .define_method("predicate", &BetweenPredicateContextProxy::predicate)
    .define_method("predicate_at", &BetweenPredicateContextProxy::predicateAt);

  rb_cBinaryComparasionPredicateContext = rb_mMySqlParser
    .define_class<BinaryComparasionPredicateContextProxy, ContextProxy>("BinaryComparasionPredicateContext")
    .define_method("comparison_operator", &BinaryComparasionPredicateContextProxy::comparisonOperator)
    .define_method("predicate", &BinaryComparasionPredicateContextProxy::predicate)
    .define_method("predicate_at", &BinaryComparasionPredicateContextProxy::predicateAt);

  rb_cIsNullPredicateContext = rb_mMySqlParser
    .define_class<IsNullPredicateContextProxy, ContextProxy>("IsNullPredicateContext")
    .define_method("predicate", &IsNullPredicateContextProxy::predicate)
    .define_method("null_notnull", &IsNullPredicateContextProxy::nullNotnull);

  rb_cLikePredicateContext = rb_mMySqlParser
    .define_class<LikePredicateContextProxy, ContextProxy>("LikePredicateContext")
    .define_method("predicate", &LikePredicateContextProxy::predicate)
    .define_method("predicate_at", &LikePredicateContextProxy::predicateAt);

  rb_cRegexpPredicateContext = rb_mMySqlParser
    .define_class<RegexpPredicateContextProxy, ContextProxy>("RegexpPredicateContext")
    .define_method("predicate", &RegexpPredicateContextProxy::predicate)
    .define_method("predicate_at", &RegexpPredicateContextProxy::predicateAt);

  rb_cUnaryExpressionAtomContext = rb_mMySqlParser
    .define_class<UnaryExpressionAtomContextProxy, ContextProxy>("UnaryExpressionAtomContext")
    .define_method("unary_operator", &UnaryExpressionAtomContextProxy::unaryOperator)
    .define_method("expression_atom", &UnaryExpressionAtomContextProxy::expressionAtom);

  rb_cCollateExpressionAtomContext = rb_mMySqlParser
    .define_class<CollateExpressionAtomContextProxy, ContextProxy>("CollateExpressionAtomContext")
    .define_method("expression_atom", &CollateExpressionAtomContextProxy::expressionAtom)
    .define_method("collation_name", &CollateExpressionAtomContextProxy::collationName);

  rb_cSubqueryExpessionAtomContext = rb_mMySqlParser
    .define_class<SubqueryExpessionAtomContextProxy, ContextProxy>("SubqueryExpessionAtomContext")
    .define_method("select_statement", &SubqueryExpessionAtomContextProxy::selectStatement);

  rb_cMysqlVariableExpressionAtomContext = rb_mMySqlParser
    .define_class<MysqlVariableExpressionAtomContextProxy, ContextProxy>("MysqlVariableExpressionAtomContext")
    .define_method("mysql_variable", &MysqlVariableExpressionAtomContextProxy::mysqlVariable);

  rb_cNestedExpressionAtomContext = rb_mMySqlParser
    .define_class<NestedExpressionAtomContextProxy, ContextProxy>("NestedExpressionAtomContext")
    .define_method("expression", &NestedExpressionAtomContextProxy::expression)
    .define_method("expression_at", &NestedExpressionAtomContextProxy::expressionAt);

  rb_cNestedRowExpressionAtomContext = rb_mMySqlParser
    .define_class<NestedRowExpressionAtomContextProxy, ContextProxy>("NestedRowExpressionAtomContext")
    .define_method("expression", &NestedRowExpressionAtomContextProxy::expression)
    .define_method("expression_at", &NestedRowExpressionAtomContextProxy::expressionAt);

  rb_cMathOperatorContext = rb_mMySqlParser
    .define_class<MathOperatorContextProxy, ContextProxy>("MathOperatorContext");

  rb_cMathExpressionAtomContext = rb_mMySqlParser
    .define_class<MathExpressionAtomContextProxy, ContextProxy>("MathExpressionAtomContext")
    .define_method("math_operator", &MathExpressionAtomContextProxy::mathOperator)
    .define_method("expression_atom", &MathExpressionAtomContextProxy::expressionAtom)
    .define_method("expression_atom_at", &MathExpressionAtomContextProxy::expressionAtomAt);

  rb_cIntervalExpressionAtomContext = rb_mMySqlParser
    .define_class<IntervalExpressionAtomContextProxy, ContextProxy>("IntervalExpressionAtomContext")
    .define_method("expression", &IntervalExpressionAtomContextProxy::expression)
    .define_method("interval_type", &IntervalExpressionAtomContextProxy::intervalType);

  rb_cExistsExpessionAtomContext = rb_mMySqlParser
    .define_class<ExistsExpessionAtomContextProxy, ContextProxy>("ExistsExpessionAtomContext")
    .define_method("select_statement", &ExistsExpessionAtomContextProxy::selectStatement);

  rb_cConstantExpressionAtomContext = rb_mMySqlParser
    .define_class<ConstantExpressionAtomContextProxy, ContextProxy>("ConstantExpressionAtomContext")
    .define_method("constant", &ConstantExpressionAtomContextProxy::constant);

  rb_cFunctionCallExpressionAtomContext = rb_mMySqlParser
    .define_class<FunctionCallExpressionAtomContextProxy, ContextProxy>("FunctionCallExpressionAtomContext")
    .define_method("function_call", &FunctionCallExpressionAtomContextProxy::functionCall);

  rb_cBinaryExpressionAtomContext = rb_mMySqlParser
    .define_class<BinaryExpressionAtomContextProxy, ContextProxy>("BinaryExpressionAtomContext")
    .define_method("expression_atom", &BinaryExpressionAtomContextProxy::expressionAtom);

  rb_cFullColumnNameExpressionAtomContext = rb_mMySqlParser
    .define_class<FullColumnNameExpressionAtomContextProxy, ContextProxy>("FullColumnNameExpressionAtomContext")
    .define_method("full_column_name", &FullColumnNameExpressionAtomContextProxy::fullColumnName);

  rb_cBitOperatorContext = rb_mMySqlParser
    .define_class<BitOperatorContextProxy, ContextProxy>("BitOperatorContext");

  rb_cBitExpressionAtomContext = rb_mMySqlParser
    .define_class<BitExpressionAtomContextProxy, ContextProxy>("BitExpressionAtomContext")
    .define_method("bit_operator", &BitExpressionAtomContextProxy::bitOperator)
    .define_method("expression_atom", &BitExpressionAtomContextProxy::expressionAtom)
    .define_method("expression_atom_at", &BitExpressionAtomContextProxy::expressionAtomAt);
}


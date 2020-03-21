
// Generated from MySqlParser.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "MySqlParserVisitor.h"


/**
 * This class provides an empty implementation of MySqlParserVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  MySqlParserBaseVisitor : public MySqlParserVisitor {
public:

  virtual antlrcpp::Any visitRoot(MySqlParser::RootContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSqlStatements(MySqlParser::SqlStatementsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSqlStatement(MySqlParser::SqlStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEmptyStatement(MySqlParser::EmptyStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDdlStatement(MySqlParser::DdlStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDmlStatement(MySqlParser::DmlStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTransactionStatement(MySqlParser::TransactionStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitReplicationStatement(MySqlParser::ReplicationStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPreparedStatement(MySqlParser::PreparedStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCompoundStatement(MySqlParser::CompoundStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAdministrationStatement(MySqlParser::AdministrationStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUtilityStatement(MySqlParser::UtilityStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCreateDatabase(MySqlParser::CreateDatabaseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCreateEvent(MySqlParser::CreateEventContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCreateIndex(MySqlParser::CreateIndexContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCreateLogfileGroup(MySqlParser::CreateLogfileGroupContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCreateProcedure(MySqlParser::CreateProcedureContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCreateFunction(MySqlParser::CreateFunctionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCreateServer(MySqlParser::CreateServerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCopyCreateTable(MySqlParser::CopyCreateTableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitQueryCreateTable(MySqlParser::QueryCreateTableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitColumnCreateTable(MySqlParser::ColumnCreateTableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCreateTablespaceInnodb(MySqlParser::CreateTablespaceInnodbContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCreateTablespaceNdb(MySqlParser::CreateTablespaceNdbContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCreateTrigger(MySqlParser::CreateTriggerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCreateView(MySqlParser::CreateViewContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCreateDatabaseOption(MySqlParser::CreateDatabaseOptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOwnerStatement(MySqlParser::OwnerStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPreciseSchedule(MySqlParser::PreciseScheduleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIntervalSchedule(MySqlParser::IntervalScheduleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTimestampValue(MySqlParser::TimestampValueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIntervalExpr(MySqlParser::IntervalExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIntervalType(MySqlParser::IntervalTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEnableType(MySqlParser::EnableTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIndexType(MySqlParser::IndexTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIndexOption(MySqlParser::IndexOptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProcedureParameter(MySqlParser::ProcedureParameterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionParameter(MySqlParser::FunctionParameterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRoutineComment(MySqlParser::RoutineCommentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRoutineLanguage(MySqlParser::RoutineLanguageContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRoutineBehavior(MySqlParser::RoutineBehaviorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRoutineData(MySqlParser::RoutineDataContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRoutineSecurity(MySqlParser::RoutineSecurityContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitServerOption(MySqlParser::ServerOptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCreateDefinitions(MySqlParser::CreateDefinitionsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitColumnDeclaration(MySqlParser::ColumnDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstraintDeclaration(MySqlParser::ConstraintDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIndexDeclaration(MySqlParser::IndexDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitColumnDefinition(MySqlParser::ColumnDefinitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNullColumnConstraint(MySqlParser::NullColumnConstraintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDefaultColumnConstraint(MySqlParser::DefaultColumnConstraintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAutoIncrementColumnConstraint(MySqlParser::AutoIncrementColumnConstraintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPrimaryKeyColumnConstraint(MySqlParser::PrimaryKeyColumnConstraintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUniqueKeyColumnConstraint(MySqlParser::UniqueKeyColumnConstraintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCommentColumnConstraint(MySqlParser::CommentColumnConstraintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFormatColumnConstraint(MySqlParser::FormatColumnConstraintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStorageColumnConstraint(MySqlParser::StorageColumnConstraintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitReferenceColumnConstraint(MySqlParser::ReferenceColumnConstraintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCollateColumnConstraint(MySqlParser::CollateColumnConstraintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGeneratedColumnConstraint(MySqlParser::GeneratedColumnConstraintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSerialDefaultColumnConstraint(MySqlParser::SerialDefaultColumnConstraintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPrimaryKeyTableConstraint(MySqlParser::PrimaryKeyTableConstraintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUniqueKeyTableConstraint(MySqlParser::UniqueKeyTableConstraintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitForeignKeyTableConstraint(MySqlParser::ForeignKeyTableConstraintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCheckTableConstraint(MySqlParser::CheckTableConstraintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitReferenceDefinition(MySqlParser::ReferenceDefinitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitReferenceAction(MySqlParser::ReferenceActionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitReferenceControlType(MySqlParser::ReferenceControlTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSimpleIndexDeclaration(MySqlParser::SimpleIndexDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSpecialIndexDeclaration(MySqlParser::SpecialIndexDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTableOptionEngine(MySqlParser::TableOptionEngineContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTableOptionAutoIncrement(MySqlParser::TableOptionAutoIncrementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTableOptionAverage(MySqlParser::TableOptionAverageContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTableOptionCharset(MySqlParser::TableOptionCharsetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTableOptionChecksum(MySqlParser::TableOptionChecksumContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTableOptionCollate(MySqlParser::TableOptionCollateContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTableOptionComment(MySqlParser::TableOptionCommentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTableOptionCompression(MySqlParser::TableOptionCompressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTableOptionConnection(MySqlParser::TableOptionConnectionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTableOptionDataDirectory(MySqlParser::TableOptionDataDirectoryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTableOptionDelay(MySqlParser::TableOptionDelayContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTableOptionEncryption(MySqlParser::TableOptionEncryptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTableOptionIndexDirectory(MySqlParser::TableOptionIndexDirectoryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTableOptionInsertMethod(MySqlParser::TableOptionInsertMethodContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTableOptionKeyBlockSize(MySqlParser::TableOptionKeyBlockSizeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTableOptionMaxRows(MySqlParser::TableOptionMaxRowsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTableOptionMinRows(MySqlParser::TableOptionMinRowsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTableOptionPackKeys(MySqlParser::TableOptionPackKeysContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTableOptionPassword(MySqlParser::TableOptionPasswordContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTableOptionRowFormat(MySqlParser::TableOptionRowFormatContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTableOptionRecalculation(MySqlParser::TableOptionRecalculationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTableOptionPersistent(MySqlParser::TableOptionPersistentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTableOptionSamplePage(MySqlParser::TableOptionSamplePageContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTableOptionTablespace(MySqlParser::TableOptionTablespaceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTableOptionUnion(MySqlParser::TableOptionUnionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTablespaceStorage(MySqlParser::TablespaceStorageContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPartitionDefinitions(MySqlParser::PartitionDefinitionsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPartitionFunctionHash(MySqlParser::PartitionFunctionHashContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPartitionFunctionKey(MySqlParser::PartitionFunctionKeyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPartitionFunctionRange(MySqlParser::PartitionFunctionRangeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPartitionFunctionList(MySqlParser::PartitionFunctionListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSubPartitionFunctionHash(MySqlParser::SubPartitionFunctionHashContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSubPartitionFunctionKey(MySqlParser::SubPartitionFunctionKeyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPartitionComparision(MySqlParser::PartitionComparisionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPartitionListAtom(MySqlParser::PartitionListAtomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPartitionListVector(MySqlParser::PartitionListVectorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPartitionSimple(MySqlParser::PartitionSimpleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPartitionDefinerAtom(MySqlParser::PartitionDefinerAtomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPartitionDefinerVector(MySqlParser::PartitionDefinerVectorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSubpartitionDefinition(MySqlParser::SubpartitionDefinitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPartitionOptionEngine(MySqlParser::PartitionOptionEngineContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPartitionOptionComment(MySqlParser::PartitionOptionCommentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPartitionOptionDataDirectory(MySqlParser::PartitionOptionDataDirectoryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPartitionOptionIndexDirectory(MySqlParser::PartitionOptionIndexDirectoryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPartitionOptionMaxRows(MySqlParser::PartitionOptionMaxRowsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPartitionOptionMinRows(MySqlParser::PartitionOptionMinRowsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPartitionOptionTablespace(MySqlParser::PartitionOptionTablespaceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPartitionOptionNodeGroup(MySqlParser::PartitionOptionNodeGroupContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAlterSimpleDatabase(MySqlParser::AlterSimpleDatabaseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAlterUpgradeName(MySqlParser::AlterUpgradeNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAlterEvent(MySqlParser::AlterEventContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAlterFunction(MySqlParser::AlterFunctionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAlterInstance(MySqlParser::AlterInstanceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAlterLogfileGroup(MySqlParser::AlterLogfileGroupContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAlterProcedure(MySqlParser::AlterProcedureContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAlterServer(MySqlParser::AlterServerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAlterTable(MySqlParser::AlterTableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAlterTablespace(MySqlParser::AlterTablespaceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAlterView(MySqlParser::AlterViewContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAlterByTableOption(MySqlParser::AlterByTableOptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAlterByAddColumn(MySqlParser::AlterByAddColumnContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAlterByAddColumns(MySqlParser::AlterByAddColumnsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAlterByAddIndex(MySqlParser::AlterByAddIndexContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAlterByAddPrimaryKey(MySqlParser::AlterByAddPrimaryKeyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAlterByAddUniqueKey(MySqlParser::AlterByAddUniqueKeyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAlterByAddSpecialIndex(MySqlParser::AlterByAddSpecialIndexContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAlterByAddForeignKey(MySqlParser::AlterByAddForeignKeyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAlterByAddCheckTableConstraint(MySqlParser::AlterByAddCheckTableConstraintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAlterBySetAlgorithm(MySqlParser::AlterBySetAlgorithmContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAlterByChangeDefault(MySqlParser::AlterByChangeDefaultContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAlterByChangeColumn(MySqlParser::AlterByChangeColumnContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAlterByRenameColumn(MySqlParser::AlterByRenameColumnContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAlterByLock(MySqlParser::AlterByLockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAlterByModifyColumn(MySqlParser::AlterByModifyColumnContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAlterByDropColumn(MySqlParser::AlterByDropColumnContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAlterByDropPrimaryKey(MySqlParser::AlterByDropPrimaryKeyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAlterByRenameIndex(MySqlParser::AlterByRenameIndexContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAlterByDropIndex(MySqlParser::AlterByDropIndexContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAlterByDropForeignKey(MySqlParser::AlterByDropForeignKeyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAlterByDisableKeys(MySqlParser::AlterByDisableKeysContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAlterByEnableKeys(MySqlParser::AlterByEnableKeysContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAlterByRename(MySqlParser::AlterByRenameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAlterByOrder(MySqlParser::AlterByOrderContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAlterByConvertCharset(MySqlParser::AlterByConvertCharsetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAlterByDefaultCharset(MySqlParser::AlterByDefaultCharsetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAlterByDiscardTablespace(MySqlParser::AlterByDiscardTablespaceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAlterByImportTablespace(MySqlParser::AlterByImportTablespaceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAlterByForce(MySqlParser::AlterByForceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAlterByValidate(MySqlParser::AlterByValidateContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAlterByAddPartition(MySqlParser::AlterByAddPartitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAlterByDropPartition(MySqlParser::AlterByDropPartitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAlterByDiscardPartition(MySqlParser::AlterByDiscardPartitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAlterByImportPartition(MySqlParser::AlterByImportPartitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAlterByTruncatePartition(MySqlParser::AlterByTruncatePartitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAlterByCoalescePartition(MySqlParser::AlterByCoalescePartitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAlterByReorganizePartition(MySqlParser::AlterByReorganizePartitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAlterByExchangePartition(MySqlParser::AlterByExchangePartitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAlterByAnalyzePartition(MySqlParser::AlterByAnalyzePartitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAlterByCheckPartition(MySqlParser::AlterByCheckPartitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAlterByOptimizePartition(MySqlParser::AlterByOptimizePartitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAlterByRebuildPartition(MySqlParser::AlterByRebuildPartitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAlterByRepairPartition(MySqlParser::AlterByRepairPartitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAlterByRemovePartitioning(MySqlParser::AlterByRemovePartitioningContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAlterByUpgradePartitioning(MySqlParser::AlterByUpgradePartitioningContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDropDatabase(MySqlParser::DropDatabaseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDropEvent(MySqlParser::DropEventContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDropIndex(MySqlParser::DropIndexContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDropLogfileGroup(MySqlParser::DropLogfileGroupContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDropProcedure(MySqlParser::DropProcedureContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDropFunction(MySqlParser::DropFunctionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDropServer(MySqlParser::DropServerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDropTable(MySqlParser::DropTableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDropTablespace(MySqlParser::DropTablespaceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDropTrigger(MySqlParser::DropTriggerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDropView(MySqlParser::DropViewContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRenameTable(MySqlParser::RenameTableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRenameTableClause(MySqlParser::RenameTableClauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTruncateTable(MySqlParser::TruncateTableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCallStatement(MySqlParser::CallStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeleteStatement(MySqlParser::DeleteStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDoStatement(MySqlParser::DoStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitHandlerStatement(MySqlParser::HandlerStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInsertStatement(MySqlParser::InsertStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLoadDataStatement(MySqlParser::LoadDataStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLoadXmlStatement(MySqlParser::LoadXmlStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitReplaceStatement(MySqlParser::ReplaceStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSimpleSelect(MySqlParser::SimpleSelectContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParenthesisSelect(MySqlParser::ParenthesisSelectContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnionSelect(MySqlParser::UnionSelectContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnionParenthesisSelect(MySqlParser::UnionParenthesisSelectContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUpdateStatement(MySqlParser::UpdateStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInsertStatementValue(MySqlParser::InsertStatementValueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUpdatedElement(MySqlParser::UpdatedElementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssignmentField(MySqlParser::AssignmentFieldContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLockClause(MySqlParser::LockClauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSingleDeleteStatement(MySqlParser::SingleDeleteStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMultipleDeleteStatement(MySqlParser::MultipleDeleteStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitHandlerOpenStatement(MySqlParser::HandlerOpenStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitHandlerReadIndexStatement(MySqlParser::HandlerReadIndexStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitHandlerReadStatement(MySqlParser::HandlerReadStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitHandlerCloseStatement(MySqlParser::HandlerCloseStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSingleUpdateStatement(MySqlParser::SingleUpdateStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMultipleUpdateStatement(MySqlParser::MultipleUpdateStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOrderByClause(MySqlParser::OrderByClauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOrderByExpression(MySqlParser::OrderByExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTableSources(MySqlParser::TableSourcesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTableSourceBase(MySqlParser::TableSourceBaseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTableSourceNested(MySqlParser::TableSourceNestedContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAtomTableItem(MySqlParser::AtomTableItemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSubqueryTableItem(MySqlParser::SubqueryTableItemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTableSourcesItem(MySqlParser::TableSourcesItemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIndexHint(MySqlParser::IndexHintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIndexHintType(MySqlParser::IndexHintTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInnerJoin(MySqlParser::InnerJoinContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStraightJoin(MySqlParser::StraightJoinContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOuterJoin(MySqlParser::OuterJoinContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNaturalJoin(MySqlParser::NaturalJoinContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitQueryExpression(MySqlParser::QueryExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitQueryExpressionNointo(MySqlParser::QueryExpressionNointoContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitQuerySpecification(MySqlParser::QuerySpecificationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitQuerySpecificationNointo(MySqlParser::QuerySpecificationNointoContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnionParenthesis(MySqlParser::UnionParenthesisContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnionStatement(MySqlParser::UnionStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSelectSpec(MySqlParser::SelectSpecContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSelectElements(MySqlParser::SelectElementsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSelectStarElement(MySqlParser::SelectStarElementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSelectColumnElement(MySqlParser::SelectColumnElementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSelectFunctionElement(MySqlParser::SelectFunctionElementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSelectExpressionElement(MySqlParser::SelectExpressionElementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSelectIntoVariables(MySqlParser::SelectIntoVariablesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSelectIntoDumpFile(MySqlParser::SelectIntoDumpFileContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSelectIntoTextFile(MySqlParser::SelectIntoTextFileContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSelectFieldsInto(MySqlParser::SelectFieldsIntoContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSelectLinesInto(MySqlParser::SelectLinesIntoContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFromClause(MySqlParser::FromClauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGroupByItem(MySqlParser::GroupByItemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLimitClause(MySqlParser::LimitClauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLimitClauseAtom(MySqlParser::LimitClauseAtomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStartTransaction(MySqlParser::StartTransactionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBeginWork(MySqlParser::BeginWorkContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCommitWork(MySqlParser::CommitWorkContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRollbackWork(MySqlParser::RollbackWorkContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSavepointStatement(MySqlParser::SavepointStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRollbackStatement(MySqlParser::RollbackStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitReleaseStatement(MySqlParser::ReleaseStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLockTables(MySqlParser::LockTablesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnlockTables(MySqlParser::UnlockTablesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSetAutocommitStatement(MySqlParser::SetAutocommitStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSetTransactionStatement(MySqlParser::SetTransactionStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTransactionMode(MySqlParser::TransactionModeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLockTableElement(MySqlParser::LockTableElementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLockAction(MySqlParser::LockActionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTransactionOption(MySqlParser::TransactionOptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTransactionLevel(MySqlParser::TransactionLevelContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitChangeMaster(MySqlParser::ChangeMasterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitChangeReplicationFilter(MySqlParser::ChangeReplicationFilterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPurgeBinaryLogs(MySqlParser::PurgeBinaryLogsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitResetMaster(MySqlParser::ResetMasterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitResetSlave(MySqlParser::ResetSlaveContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStartSlave(MySqlParser::StartSlaveContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStopSlave(MySqlParser::StopSlaveContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStartGroupReplication(MySqlParser::StartGroupReplicationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStopGroupReplication(MySqlParser::StopGroupReplicationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMasterStringOption(MySqlParser::MasterStringOptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMasterDecimalOption(MySqlParser::MasterDecimalOptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMasterBoolOption(MySqlParser::MasterBoolOptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMasterRealOption(MySqlParser::MasterRealOptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMasterUidListOption(MySqlParser::MasterUidListOptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStringMasterOption(MySqlParser::StringMasterOptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDecimalMasterOption(MySqlParser::DecimalMasterOptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBoolMasterOption(MySqlParser::BoolMasterOptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitChannelOption(MySqlParser::ChannelOptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDoDbReplication(MySqlParser::DoDbReplicationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIgnoreDbReplication(MySqlParser::IgnoreDbReplicationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDoTableReplication(MySqlParser::DoTableReplicationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIgnoreTableReplication(MySqlParser::IgnoreTableReplicationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWildDoTableReplication(MySqlParser::WildDoTableReplicationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWildIgnoreTableReplication(MySqlParser::WildIgnoreTableReplicationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRewriteDbReplication(MySqlParser::RewriteDbReplicationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTablePair(MySqlParser::TablePairContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitThreadType(MySqlParser::ThreadTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGtidsUntilOption(MySqlParser::GtidsUntilOptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMasterLogUntilOption(MySqlParser::MasterLogUntilOptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRelayLogUntilOption(MySqlParser::RelayLogUntilOptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSqlGapsUntilOption(MySqlParser::SqlGapsUntilOptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUserConnectionOption(MySqlParser::UserConnectionOptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPasswordConnectionOption(MySqlParser::PasswordConnectionOptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDefaultAuthConnectionOption(MySqlParser::DefaultAuthConnectionOptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPluginDirConnectionOption(MySqlParser::PluginDirConnectionOptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGtuidSet(MySqlParser::GtuidSetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitXaStartTransaction(MySqlParser::XaStartTransactionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitXaEndTransaction(MySqlParser::XaEndTransactionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitXaPrepareStatement(MySqlParser::XaPrepareStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitXaCommitWork(MySqlParser::XaCommitWorkContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitXaRollbackWork(MySqlParser::XaRollbackWorkContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitXaRecoverWork(MySqlParser::XaRecoverWorkContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPrepareStatement(MySqlParser::PrepareStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExecuteStatement(MySqlParser::ExecuteStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeallocatePrepare(MySqlParser::DeallocatePrepareContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRoutineBody(MySqlParser::RoutineBodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBlockStatement(MySqlParser::BlockStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCaseStatement(MySqlParser::CaseStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIfStatement(MySqlParser::IfStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIterateStatement(MySqlParser::IterateStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLeaveStatement(MySqlParser::LeaveStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLoopStatement(MySqlParser::LoopStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRepeatStatement(MySqlParser::RepeatStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitReturnStatement(MySqlParser::ReturnStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWhileStatement(MySqlParser::WhileStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCloseCursor(MySqlParser::CloseCursorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFetchCursor(MySqlParser::FetchCursorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOpenCursor(MySqlParser::OpenCursorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeclareVariable(MySqlParser::DeclareVariableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeclareCondition(MySqlParser::DeclareConditionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeclareCursor(MySqlParser::DeclareCursorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeclareHandler(MySqlParser::DeclareHandlerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitHandlerConditionCode(MySqlParser::HandlerConditionCodeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitHandlerConditionState(MySqlParser::HandlerConditionStateContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitHandlerConditionName(MySqlParser::HandlerConditionNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitHandlerConditionWarning(MySqlParser::HandlerConditionWarningContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitHandlerConditionNotfound(MySqlParser::HandlerConditionNotfoundContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitHandlerConditionException(MySqlParser::HandlerConditionExceptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProcedureSqlStatement(MySqlParser::ProcedureSqlStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCaseAlternative(MySqlParser::CaseAlternativeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitElifAlternative(MySqlParser::ElifAlternativeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAlterUserMysqlV56(MySqlParser::AlterUserMysqlV56Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAlterUserMysqlV57(MySqlParser::AlterUserMysqlV57Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCreateUserMysqlV56(MySqlParser::CreateUserMysqlV56Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCreateUserMysqlV57(MySqlParser::CreateUserMysqlV57Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDropUser(MySqlParser::DropUserContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGrantStatement(MySqlParser::GrantStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGrantProxy(MySqlParser::GrantProxyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRenameUser(MySqlParser::RenameUserContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDetailRevoke(MySqlParser::DetailRevokeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitShortRevoke(MySqlParser::ShortRevokeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRevokeProxy(MySqlParser::RevokeProxyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSetPasswordStatement(MySqlParser::SetPasswordStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUserSpecification(MySqlParser::UserSpecificationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPasswordAuthOption(MySqlParser::PasswordAuthOptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStringAuthOption(MySqlParser::StringAuthOptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitHashAuthOption(MySqlParser::HashAuthOptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSimpleAuthOption(MySqlParser::SimpleAuthOptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTlsOption(MySqlParser::TlsOptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUserResourceOption(MySqlParser::UserResourceOptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUserPasswordOption(MySqlParser::UserPasswordOptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUserLockOption(MySqlParser::UserLockOptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPrivelegeClause(MySqlParser::PrivelegeClauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPrivilege(MySqlParser::PrivilegeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCurrentSchemaPriviLevel(MySqlParser::CurrentSchemaPriviLevelContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGlobalPrivLevel(MySqlParser::GlobalPrivLevelContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDefiniteSchemaPrivLevel(MySqlParser::DefiniteSchemaPrivLevelContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDefiniteFullTablePrivLevel(MySqlParser::DefiniteFullTablePrivLevelContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDefiniteFullTablePrivLevel2(MySqlParser::DefiniteFullTablePrivLevel2Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDefiniteTablePrivLevel(MySqlParser::DefiniteTablePrivLevelContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRenameUserClause(MySqlParser::RenameUserClauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAnalyzeTable(MySqlParser::AnalyzeTableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCheckTable(MySqlParser::CheckTableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitChecksumTable(MySqlParser::ChecksumTableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOptimizeTable(MySqlParser::OptimizeTableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRepairTable(MySqlParser::RepairTableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCheckTableOption(MySqlParser::CheckTableOptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCreateUdfunction(MySqlParser::CreateUdfunctionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInstallPlugin(MySqlParser::InstallPluginContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUninstallPlugin(MySqlParser::UninstallPluginContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSetVariable(MySqlParser::SetVariableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSetCharset(MySqlParser::SetCharsetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSetNames(MySqlParser::SetNamesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSetPassword(MySqlParser::SetPasswordContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSetTransaction(MySqlParser::SetTransactionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSetAutocommit(MySqlParser::SetAutocommitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSetNewValueInsideTrigger(MySqlParser::SetNewValueInsideTriggerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitShowMasterLogs(MySqlParser::ShowMasterLogsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitShowLogEvents(MySqlParser::ShowLogEventsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitShowObjectFilter(MySqlParser::ShowObjectFilterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitShowColumns(MySqlParser::ShowColumnsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitShowCreateDb(MySqlParser::ShowCreateDbContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitShowCreateFullIdObject(MySqlParser::ShowCreateFullIdObjectContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitShowCreateUser(MySqlParser::ShowCreateUserContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitShowEngine(MySqlParser::ShowEngineContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitShowGlobalInfo(MySqlParser::ShowGlobalInfoContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitShowErrors(MySqlParser::ShowErrorsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitShowCountErrors(MySqlParser::ShowCountErrorsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitShowSchemaFilter(MySqlParser::ShowSchemaFilterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitShowRoutine(MySqlParser::ShowRoutineContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitShowGrants(MySqlParser::ShowGrantsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitShowIndexes(MySqlParser::ShowIndexesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitShowOpenTables(MySqlParser::ShowOpenTablesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitShowProfile(MySqlParser::ShowProfileContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitShowSlaveStatus(MySqlParser::ShowSlaveStatusContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariableClause(MySqlParser::VariableClauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitShowCommonEntity(MySqlParser::ShowCommonEntityContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitShowFilter(MySqlParser::ShowFilterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitShowGlobalInfoClause(MySqlParser::ShowGlobalInfoClauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitShowSchemaEntity(MySqlParser::ShowSchemaEntityContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitShowProfileType(MySqlParser::ShowProfileTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBinlogStatement(MySqlParser::BinlogStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCacheIndexStatement(MySqlParser::CacheIndexStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlushStatement(MySqlParser::FlushStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitKillStatement(MySqlParser::KillStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLoadIndexIntoCache(MySqlParser::LoadIndexIntoCacheContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitResetStatement(MySqlParser::ResetStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitShutdownStatement(MySqlParser::ShutdownStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTableIndexes(MySqlParser::TableIndexesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSimpleFlushOption(MySqlParser::SimpleFlushOptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitChannelFlushOption(MySqlParser::ChannelFlushOptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTableFlushOption(MySqlParser::TableFlushOptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlushTableOption(MySqlParser::FlushTableOptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLoadedTableIndexes(MySqlParser::LoadedTableIndexesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSimpleDescribeStatement(MySqlParser::SimpleDescribeStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFullDescribeStatement(MySqlParser::FullDescribeStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitHelpStatement(MySqlParser::HelpStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUseStatement(MySqlParser::UseStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSignalStatement(MySqlParser::SignalStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitResignalStatement(MySqlParser::ResignalStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSignalConditionInformation(MySqlParser::SignalConditionInformationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDiagnosticsStatement(MySqlParser::DiagnosticsStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDiagnosticsConditionInformationName(MySqlParser::DiagnosticsConditionInformationNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDescribeStatements(MySqlParser::DescribeStatementsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDescribeConnection(MySqlParser::DescribeConnectionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFullId(MySqlParser::FullIdContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTableName(MySqlParser::TableNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFullColumnName(MySqlParser::FullColumnNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIndexColumnName(MySqlParser::IndexColumnNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUserName(MySqlParser::UserNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMysqlVariable(MySqlParser::MysqlVariableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCharsetName(MySqlParser::CharsetNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCollationName(MySqlParser::CollationNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEngineName(MySqlParser::EngineNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUuidSet(MySqlParser::UuidSetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitXid(MySqlParser::XidContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitXuidStringId(MySqlParser::XuidStringIdContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAuthPlugin(MySqlParser::AuthPluginContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUid(MySqlParser::UidContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSimpleId(MySqlParser::SimpleIdContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDottedId(MySqlParser::DottedIdContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDecimalLiteral(MySqlParser::DecimalLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFileSizeLiteral(MySqlParser::FileSizeLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStringLiteral(MySqlParser::StringLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBooleanLiteral(MySqlParser::BooleanLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitHexadecimalLiteral(MySqlParser::HexadecimalLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNullNotnull(MySqlParser::NullNotnullContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstant(MySqlParser::ConstantContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStringDataType(MySqlParser::StringDataTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNationalStringDataType(MySqlParser::NationalStringDataTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNationalVaryingStringDataType(MySqlParser::NationalVaryingStringDataTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDimensionDataType(MySqlParser::DimensionDataTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSimpleDataType(MySqlParser::SimpleDataTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCollectionDataType(MySqlParser::CollectionDataTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSpatialDataType(MySqlParser::SpatialDataTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCollectionOptions(MySqlParser::CollectionOptionsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConvertedDataType(MySqlParser::ConvertedDataTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLengthOneDimension(MySqlParser::LengthOneDimensionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLengthTwoDimension(MySqlParser::LengthTwoDimensionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLengthTwoOptionalDimension(MySqlParser::LengthTwoOptionalDimensionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUidList(MySqlParser::UidListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTables(MySqlParser::TablesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIndexColumnNames(MySqlParser::IndexColumnNamesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpressions(MySqlParser::ExpressionsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpressionsWithDefaults(MySqlParser::ExpressionsWithDefaultsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstants(MySqlParser::ConstantsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSimpleStrings(MySqlParser::SimpleStringsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUserVariables(MySqlParser::UserVariablesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDefaultValue(MySqlParser::DefaultValueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCurrentTimestamp(MySqlParser::CurrentTimestampContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpressionOrDefault(MySqlParser::ExpressionOrDefaultContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIfExists(MySqlParser::IfExistsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIfNotExists(MySqlParser::IfNotExistsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSpecificFunctionCall(MySqlParser::SpecificFunctionCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAggregateFunctionCall(MySqlParser::AggregateFunctionCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitScalarFunctionCall(MySqlParser::ScalarFunctionCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUdfFunctionCall(MySqlParser::UdfFunctionCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPasswordFunctionCall(MySqlParser::PasswordFunctionCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSimpleFunctionCall(MySqlParser::SimpleFunctionCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDataTypeFunctionCall(MySqlParser::DataTypeFunctionCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitValuesFunctionCall(MySqlParser::ValuesFunctionCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCaseFunctionCall(MySqlParser::CaseFunctionCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCharFunctionCall(MySqlParser::CharFunctionCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPositionFunctionCall(MySqlParser::PositionFunctionCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSubstrFunctionCall(MySqlParser::SubstrFunctionCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTrimFunctionCall(MySqlParser::TrimFunctionCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWeightFunctionCall(MySqlParser::WeightFunctionCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExtractFunctionCall(MySqlParser::ExtractFunctionCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGetFormatFunctionCall(MySqlParser::GetFormatFunctionCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCaseFuncAlternative(MySqlParser::CaseFuncAlternativeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLevelWeightList(MySqlParser::LevelWeightListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLevelWeightRange(MySqlParser::LevelWeightRangeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLevelInWeightListElement(MySqlParser::LevelInWeightListElementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAggregateWindowedFunction(MySqlParser::AggregateWindowedFunctionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitScalarFunctionName(MySqlParser::ScalarFunctionNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPasswordFunctionClause(MySqlParser::PasswordFunctionClauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionArgs(MySqlParser::FunctionArgsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionArg(MySqlParser::FunctionArgContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIsExpression(MySqlParser::IsExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNotExpression(MySqlParser::NotExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLogicalExpression(MySqlParser::LogicalExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPredicateExpression(MySqlParser::PredicateExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSoundsLikePredicate(MySqlParser::SoundsLikePredicateContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpressionAtomPredicate(MySqlParser::ExpressionAtomPredicateContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInPredicate(MySqlParser::InPredicateContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSubqueryComparasionPredicate(MySqlParser::SubqueryComparasionPredicateContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBetweenPredicate(MySqlParser::BetweenPredicateContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBinaryComparasionPredicate(MySqlParser::BinaryComparasionPredicateContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIsNullPredicate(MySqlParser::IsNullPredicateContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLikePredicate(MySqlParser::LikePredicateContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRegexpPredicate(MySqlParser::RegexpPredicateContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnaryExpressionAtom(MySqlParser::UnaryExpressionAtomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCollateExpressionAtom(MySqlParser::CollateExpressionAtomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSubqueryExpessionAtom(MySqlParser::SubqueryExpessionAtomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMysqlVariableExpressionAtom(MySqlParser::MysqlVariableExpressionAtomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNestedExpressionAtom(MySqlParser::NestedExpressionAtomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNestedRowExpressionAtom(MySqlParser::NestedRowExpressionAtomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMathExpressionAtom(MySqlParser::MathExpressionAtomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIntervalExpressionAtom(MySqlParser::IntervalExpressionAtomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExistsExpessionAtom(MySqlParser::ExistsExpessionAtomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstantExpressionAtom(MySqlParser::ConstantExpressionAtomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionCallExpressionAtom(MySqlParser::FunctionCallExpressionAtomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBinaryExpressionAtom(MySqlParser::BinaryExpressionAtomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFullColumnNameExpressionAtom(MySqlParser::FullColumnNameExpressionAtomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBitExpressionAtom(MySqlParser::BitExpressionAtomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnaryOperator(MySqlParser::UnaryOperatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitComparisonOperator(MySqlParser::ComparisonOperatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLogicalOperator(MySqlParser::LogicalOperatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBitOperator(MySqlParser::BitOperatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMathOperator(MySqlParser::MathOperatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCharsetNameBase(MySqlParser::CharsetNameBaseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTransactionLevelBase(MySqlParser::TransactionLevelBaseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPrivilegesBase(MySqlParser::PrivilegesBaseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIntervalTypeBase(MySqlParser::IntervalTypeBaseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDataTypeBase(MySqlParser::DataTypeBaseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitKeywordsCanBeId(MySqlParser::KeywordsCanBeIdContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionNameBase(MySqlParser::FunctionNameBaseContext *ctx) override {
    return visitChildren(ctx);
  }


};


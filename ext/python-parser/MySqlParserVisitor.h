
// Generated from MySqlParser.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "MySqlParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by MySqlParser.
 */
class  MySqlParserVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by MySqlParser.
   */
    virtual antlrcpp::Any visitRoot(MySqlParser::RootContext *context) = 0;

    virtual antlrcpp::Any visitSqlStatements(MySqlParser::SqlStatementsContext *context) = 0;

    virtual antlrcpp::Any visitSqlStatement(MySqlParser::SqlStatementContext *context) = 0;

    virtual antlrcpp::Any visitEmptyStatement(MySqlParser::EmptyStatementContext *context) = 0;

    virtual antlrcpp::Any visitDdlStatement(MySqlParser::DdlStatementContext *context) = 0;

    virtual antlrcpp::Any visitDmlStatement(MySqlParser::DmlStatementContext *context) = 0;

    virtual antlrcpp::Any visitTransactionStatement(MySqlParser::TransactionStatementContext *context) = 0;

    virtual antlrcpp::Any visitReplicationStatement(MySqlParser::ReplicationStatementContext *context) = 0;

    virtual antlrcpp::Any visitPreparedStatement(MySqlParser::PreparedStatementContext *context) = 0;

    virtual antlrcpp::Any visitCompoundStatement(MySqlParser::CompoundStatementContext *context) = 0;

    virtual antlrcpp::Any visitAdministrationStatement(MySqlParser::AdministrationStatementContext *context) = 0;

    virtual antlrcpp::Any visitUtilityStatement(MySqlParser::UtilityStatementContext *context) = 0;

    virtual antlrcpp::Any visitCreateDatabase(MySqlParser::CreateDatabaseContext *context) = 0;

    virtual antlrcpp::Any visitCreateEvent(MySqlParser::CreateEventContext *context) = 0;

    virtual antlrcpp::Any visitCreateIndex(MySqlParser::CreateIndexContext *context) = 0;

    virtual antlrcpp::Any visitCreateLogfileGroup(MySqlParser::CreateLogfileGroupContext *context) = 0;

    virtual antlrcpp::Any visitCreateProcedure(MySqlParser::CreateProcedureContext *context) = 0;

    virtual antlrcpp::Any visitCreateFunction(MySqlParser::CreateFunctionContext *context) = 0;

    virtual antlrcpp::Any visitCreateServer(MySqlParser::CreateServerContext *context) = 0;

    virtual antlrcpp::Any visitCopyCreateTable(MySqlParser::CopyCreateTableContext *context) = 0;

    virtual antlrcpp::Any visitQueryCreateTable(MySqlParser::QueryCreateTableContext *context) = 0;

    virtual antlrcpp::Any visitColumnCreateTable(MySqlParser::ColumnCreateTableContext *context) = 0;

    virtual antlrcpp::Any visitCreateTablespaceInnodb(MySqlParser::CreateTablespaceInnodbContext *context) = 0;

    virtual antlrcpp::Any visitCreateTablespaceNdb(MySqlParser::CreateTablespaceNdbContext *context) = 0;

    virtual antlrcpp::Any visitCreateTrigger(MySqlParser::CreateTriggerContext *context) = 0;

    virtual antlrcpp::Any visitCreateView(MySqlParser::CreateViewContext *context) = 0;

    virtual antlrcpp::Any visitCreateDatabaseOption(MySqlParser::CreateDatabaseOptionContext *context) = 0;

    virtual antlrcpp::Any visitOwnerStatement(MySqlParser::OwnerStatementContext *context) = 0;

    virtual antlrcpp::Any visitPreciseSchedule(MySqlParser::PreciseScheduleContext *context) = 0;

    virtual antlrcpp::Any visitIntervalSchedule(MySqlParser::IntervalScheduleContext *context) = 0;

    virtual antlrcpp::Any visitTimestampValue(MySqlParser::TimestampValueContext *context) = 0;

    virtual antlrcpp::Any visitIntervalExpr(MySqlParser::IntervalExprContext *context) = 0;

    virtual antlrcpp::Any visitIntervalType(MySqlParser::IntervalTypeContext *context) = 0;

    virtual antlrcpp::Any visitEnableType(MySqlParser::EnableTypeContext *context) = 0;

    virtual antlrcpp::Any visitIndexType(MySqlParser::IndexTypeContext *context) = 0;

    virtual antlrcpp::Any visitIndexOption(MySqlParser::IndexOptionContext *context) = 0;

    virtual antlrcpp::Any visitProcedureParameter(MySqlParser::ProcedureParameterContext *context) = 0;

    virtual antlrcpp::Any visitFunctionParameter(MySqlParser::FunctionParameterContext *context) = 0;

    virtual antlrcpp::Any visitRoutineComment(MySqlParser::RoutineCommentContext *context) = 0;

    virtual antlrcpp::Any visitRoutineLanguage(MySqlParser::RoutineLanguageContext *context) = 0;

    virtual antlrcpp::Any visitRoutineBehavior(MySqlParser::RoutineBehaviorContext *context) = 0;

    virtual antlrcpp::Any visitRoutineData(MySqlParser::RoutineDataContext *context) = 0;

    virtual antlrcpp::Any visitRoutineSecurity(MySqlParser::RoutineSecurityContext *context) = 0;

    virtual antlrcpp::Any visitServerOption(MySqlParser::ServerOptionContext *context) = 0;

    virtual antlrcpp::Any visitCreateDefinitions(MySqlParser::CreateDefinitionsContext *context) = 0;

    virtual antlrcpp::Any visitColumnDeclaration(MySqlParser::ColumnDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitConstraintDeclaration(MySqlParser::ConstraintDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitIndexDeclaration(MySqlParser::IndexDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitColumnDefinition(MySqlParser::ColumnDefinitionContext *context) = 0;

    virtual antlrcpp::Any visitNullColumnConstraint(MySqlParser::NullColumnConstraintContext *context) = 0;

    virtual antlrcpp::Any visitDefaultColumnConstraint(MySqlParser::DefaultColumnConstraintContext *context) = 0;

    virtual antlrcpp::Any visitAutoIncrementColumnConstraint(MySqlParser::AutoIncrementColumnConstraintContext *context) = 0;

    virtual antlrcpp::Any visitPrimaryKeyColumnConstraint(MySqlParser::PrimaryKeyColumnConstraintContext *context) = 0;

    virtual antlrcpp::Any visitUniqueKeyColumnConstraint(MySqlParser::UniqueKeyColumnConstraintContext *context) = 0;

    virtual antlrcpp::Any visitCommentColumnConstraint(MySqlParser::CommentColumnConstraintContext *context) = 0;

    virtual antlrcpp::Any visitFormatColumnConstraint(MySqlParser::FormatColumnConstraintContext *context) = 0;

    virtual antlrcpp::Any visitStorageColumnConstraint(MySqlParser::StorageColumnConstraintContext *context) = 0;

    virtual antlrcpp::Any visitReferenceColumnConstraint(MySqlParser::ReferenceColumnConstraintContext *context) = 0;

    virtual antlrcpp::Any visitCollateColumnConstraint(MySqlParser::CollateColumnConstraintContext *context) = 0;

    virtual antlrcpp::Any visitGeneratedColumnConstraint(MySqlParser::GeneratedColumnConstraintContext *context) = 0;

    virtual antlrcpp::Any visitSerialDefaultColumnConstraint(MySqlParser::SerialDefaultColumnConstraintContext *context) = 0;

    virtual antlrcpp::Any visitPrimaryKeyTableConstraint(MySqlParser::PrimaryKeyTableConstraintContext *context) = 0;

    virtual antlrcpp::Any visitUniqueKeyTableConstraint(MySqlParser::UniqueKeyTableConstraintContext *context) = 0;

    virtual antlrcpp::Any visitForeignKeyTableConstraint(MySqlParser::ForeignKeyTableConstraintContext *context) = 0;

    virtual antlrcpp::Any visitCheckTableConstraint(MySqlParser::CheckTableConstraintContext *context) = 0;

    virtual antlrcpp::Any visitReferenceDefinition(MySqlParser::ReferenceDefinitionContext *context) = 0;

    virtual antlrcpp::Any visitReferenceAction(MySqlParser::ReferenceActionContext *context) = 0;

    virtual antlrcpp::Any visitReferenceControlType(MySqlParser::ReferenceControlTypeContext *context) = 0;

    virtual antlrcpp::Any visitSimpleIndexDeclaration(MySqlParser::SimpleIndexDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitSpecialIndexDeclaration(MySqlParser::SpecialIndexDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitTableOptionEngine(MySqlParser::TableOptionEngineContext *context) = 0;

    virtual antlrcpp::Any visitTableOptionAutoIncrement(MySqlParser::TableOptionAutoIncrementContext *context) = 0;

    virtual antlrcpp::Any visitTableOptionAverage(MySqlParser::TableOptionAverageContext *context) = 0;

    virtual antlrcpp::Any visitTableOptionCharset(MySqlParser::TableOptionCharsetContext *context) = 0;

    virtual antlrcpp::Any visitTableOptionChecksum(MySqlParser::TableOptionChecksumContext *context) = 0;

    virtual antlrcpp::Any visitTableOptionCollate(MySqlParser::TableOptionCollateContext *context) = 0;

    virtual antlrcpp::Any visitTableOptionComment(MySqlParser::TableOptionCommentContext *context) = 0;

    virtual antlrcpp::Any visitTableOptionCompression(MySqlParser::TableOptionCompressionContext *context) = 0;

    virtual antlrcpp::Any visitTableOptionConnection(MySqlParser::TableOptionConnectionContext *context) = 0;

    virtual antlrcpp::Any visitTableOptionDataDirectory(MySqlParser::TableOptionDataDirectoryContext *context) = 0;

    virtual antlrcpp::Any visitTableOptionDelay(MySqlParser::TableOptionDelayContext *context) = 0;

    virtual antlrcpp::Any visitTableOptionEncryption(MySqlParser::TableOptionEncryptionContext *context) = 0;

    virtual antlrcpp::Any visitTableOptionIndexDirectory(MySqlParser::TableOptionIndexDirectoryContext *context) = 0;

    virtual antlrcpp::Any visitTableOptionInsertMethod(MySqlParser::TableOptionInsertMethodContext *context) = 0;

    virtual antlrcpp::Any visitTableOptionKeyBlockSize(MySqlParser::TableOptionKeyBlockSizeContext *context) = 0;

    virtual antlrcpp::Any visitTableOptionMaxRows(MySqlParser::TableOptionMaxRowsContext *context) = 0;

    virtual antlrcpp::Any visitTableOptionMinRows(MySqlParser::TableOptionMinRowsContext *context) = 0;

    virtual antlrcpp::Any visitTableOptionPackKeys(MySqlParser::TableOptionPackKeysContext *context) = 0;

    virtual antlrcpp::Any visitTableOptionPassword(MySqlParser::TableOptionPasswordContext *context) = 0;

    virtual antlrcpp::Any visitTableOptionRowFormat(MySqlParser::TableOptionRowFormatContext *context) = 0;

    virtual antlrcpp::Any visitTableOptionRecalculation(MySqlParser::TableOptionRecalculationContext *context) = 0;

    virtual antlrcpp::Any visitTableOptionPersistent(MySqlParser::TableOptionPersistentContext *context) = 0;

    virtual antlrcpp::Any visitTableOptionSamplePage(MySqlParser::TableOptionSamplePageContext *context) = 0;

    virtual antlrcpp::Any visitTableOptionTablespace(MySqlParser::TableOptionTablespaceContext *context) = 0;

    virtual antlrcpp::Any visitTableOptionUnion(MySqlParser::TableOptionUnionContext *context) = 0;

    virtual antlrcpp::Any visitTablespaceStorage(MySqlParser::TablespaceStorageContext *context) = 0;

    virtual antlrcpp::Any visitPartitionDefinitions(MySqlParser::PartitionDefinitionsContext *context) = 0;

    virtual antlrcpp::Any visitPartitionFunctionHash(MySqlParser::PartitionFunctionHashContext *context) = 0;

    virtual antlrcpp::Any visitPartitionFunctionKey(MySqlParser::PartitionFunctionKeyContext *context) = 0;

    virtual antlrcpp::Any visitPartitionFunctionRange(MySqlParser::PartitionFunctionRangeContext *context) = 0;

    virtual antlrcpp::Any visitPartitionFunctionList(MySqlParser::PartitionFunctionListContext *context) = 0;

    virtual antlrcpp::Any visitSubPartitionFunctionHash(MySqlParser::SubPartitionFunctionHashContext *context) = 0;

    virtual antlrcpp::Any visitSubPartitionFunctionKey(MySqlParser::SubPartitionFunctionKeyContext *context) = 0;

    virtual antlrcpp::Any visitPartitionComparision(MySqlParser::PartitionComparisionContext *context) = 0;

    virtual antlrcpp::Any visitPartitionListAtom(MySqlParser::PartitionListAtomContext *context) = 0;

    virtual antlrcpp::Any visitPartitionListVector(MySqlParser::PartitionListVectorContext *context) = 0;

    virtual antlrcpp::Any visitPartitionSimple(MySqlParser::PartitionSimpleContext *context) = 0;

    virtual antlrcpp::Any visitPartitionDefinerAtom(MySqlParser::PartitionDefinerAtomContext *context) = 0;

    virtual antlrcpp::Any visitPartitionDefinerVector(MySqlParser::PartitionDefinerVectorContext *context) = 0;

    virtual antlrcpp::Any visitSubpartitionDefinition(MySqlParser::SubpartitionDefinitionContext *context) = 0;

    virtual antlrcpp::Any visitPartitionOptionEngine(MySqlParser::PartitionOptionEngineContext *context) = 0;

    virtual antlrcpp::Any visitPartitionOptionComment(MySqlParser::PartitionOptionCommentContext *context) = 0;

    virtual antlrcpp::Any visitPartitionOptionDataDirectory(MySqlParser::PartitionOptionDataDirectoryContext *context) = 0;

    virtual antlrcpp::Any visitPartitionOptionIndexDirectory(MySqlParser::PartitionOptionIndexDirectoryContext *context) = 0;

    virtual antlrcpp::Any visitPartitionOptionMaxRows(MySqlParser::PartitionOptionMaxRowsContext *context) = 0;

    virtual antlrcpp::Any visitPartitionOptionMinRows(MySqlParser::PartitionOptionMinRowsContext *context) = 0;

    virtual antlrcpp::Any visitPartitionOptionTablespace(MySqlParser::PartitionOptionTablespaceContext *context) = 0;

    virtual antlrcpp::Any visitPartitionOptionNodeGroup(MySqlParser::PartitionOptionNodeGroupContext *context) = 0;

    virtual antlrcpp::Any visitAlterSimpleDatabase(MySqlParser::AlterSimpleDatabaseContext *context) = 0;

    virtual antlrcpp::Any visitAlterUpgradeName(MySqlParser::AlterUpgradeNameContext *context) = 0;

    virtual antlrcpp::Any visitAlterEvent(MySqlParser::AlterEventContext *context) = 0;

    virtual antlrcpp::Any visitAlterFunction(MySqlParser::AlterFunctionContext *context) = 0;

    virtual antlrcpp::Any visitAlterInstance(MySqlParser::AlterInstanceContext *context) = 0;

    virtual antlrcpp::Any visitAlterLogfileGroup(MySqlParser::AlterLogfileGroupContext *context) = 0;

    virtual antlrcpp::Any visitAlterProcedure(MySqlParser::AlterProcedureContext *context) = 0;

    virtual antlrcpp::Any visitAlterServer(MySqlParser::AlterServerContext *context) = 0;

    virtual antlrcpp::Any visitAlterTable(MySqlParser::AlterTableContext *context) = 0;

    virtual antlrcpp::Any visitAlterTablespace(MySqlParser::AlterTablespaceContext *context) = 0;

    virtual antlrcpp::Any visitAlterView(MySqlParser::AlterViewContext *context) = 0;

    virtual antlrcpp::Any visitAlterByTableOption(MySqlParser::AlterByTableOptionContext *context) = 0;

    virtual antlrcpp::Any visitAlterByAddColumn(MySqlParser::AlterByAddColumnContext *context) = 0;

    virtual antlrcpp::Any visitAlterByAddColumns(MySqlParser::AlterByAddColumnsContext *context) = 0;

    virtual antlrcpp::Any visitAlterByAddIndex(MySqlParser::AlterByAddIndexContext *context) = 0;

    virtual antlrcpp::Any visitAlterByAddPrimaryKey(MySqlParser::AlterByAddPrimaryKeyContext *context) = 0;

    virtual antlrcpp::Any visitAlterByAddUniqueKey(MySqlParser::AlterByAddUniqueKeyContext *context) = 0;

    virtual antlrcpp::Any visitAlterByAddSpecialIndex(MySqlParser::AlterByAddSpecialIndexContext *context) = 0;

    virtual antlrcpp::Any visitAlterByAddForeignKey(MySqlParser::AlterByAddForeignKeyContext *context) = 0;

    virtual antlrcpp::Any visitAlterByAddCheckTableConstraint(MySqlParser::AlterByAddCheckTableConstraintContext *context) = 0;

    virtual antlrcpp::Any visitAlterBySetAlgorithm(MySqlParser::AlterBySetAlgorithmContext *context) = 0;

    virtual antlrcpp::Any visitAlterByChangeDefault(MySqlParser::AlterByChangeDefaultContext *context) = 0;

    virtual antlrcpp::Any visitAlterByChangeColumn(MySqlParser::AlterByChangeColumnContext *context) = 0;

    virtual antlrcpp::Any visitAlterByRenameColumn(MySqlParser::AlterByRenameColumnContext *context) = 0;

    virtual antlrcpp::Any visitAlterByLock(MySqlParser::AlterByLockContext *context) = 0;

    virtual antlrcpp::Any visitAlterByModifyColumn(MySqlParser::AlterByModifyColumnContext *context) = 0;

    virtual antlrcpp::Any visitAlterByDropColumn(MySqlParser::AlterByDropColumnContext *context) = 0;

    virtual antlrcpp::Any visitAlterByDropPrimaryKey(MySqlParser::AlterByDropPrimaryKeyContext *context) = 0;

    virtual antlrcpp::Any visitAlterByRenameIndex(MySqlParser::AlterByRenameIndexContext *context) = 0;

    virtual antlrcpp::Any visitAlterByDropIndex(MySqlParser::AlterByDropIndexContext *context) = 0;

    virtual antlrcpp::Any visitAlterByDropForeignKey(MySqlParser::AlterByDropForeignKeyContext *context) = 0;

    virtual antlrcpp::Any visitAlterByDisableKeys(MySqlParser::AlterByDisableKeysContext *context) = 0;

    virtual antlrcpp::Any visitAlterByEnableKeys(MySqlParser::AlterByEnableKeysContext *context) = 0;

    virtual antlrcpp::Any visitAlterByRename(MySqlParser::AlterByRenameContext *context) = 0;

    virtual antlrcpp::Any visitAlterByOrder(MySqlParser::AlterByOrderContext *context) = 0;

    virtual antlrcpp::Any visitAlterByConvertCharset(MySqlParser::AlterByConvertCharsetContext *context) = 0;

    virtual antlrcpp::Any visitAlterByDefaultCharset(MySqlParser::AlterByDefaultCharsetContext *context) = 0;

    virtual antlrcpp::Any visitAlterByDiscardTablespace(MySqlParser::AlterByDiscardTablespaceContext *context) = 0;

    virtual antlrcpp::Any visitAlterByImportTablespace(MySqlParser::AlterByImportTablespaceContext *context) = 0;

    virtual antlrcpp::Any visitAlterByForce(MySqlParser::AlterByForceContext *context) = 0;

    virtual antlrcpp::Any visitAlterByValidate(MySqlParser::AlterByValidateContext *context) = 0;

    virtual antlrcpp::Any visitAlterByAddPartition(MySqlParser::AlterByAddPartitionContext *context) = 0;

    virtual antlrcpp::Any visitAlterByDropPartition(MySqlParser::AlterByDropPartitionContext *context) = 0;

    virtual antlrcpp::Any visitAlterByDiscardPartition(MySqlParser::AlterByDiscardPartitionContext *context) = 0;

    virtual antlrcpp::Any visitAlterByImportPartition(MySqlParser::AlterByImportPartitionContext *context) = 0;

    virtual antlrcpp::Any visitAlterByTruncatePartition(MySqlParser::AlterByTruncatePartitionContext *context) = 0;

    virtual antlrcpp::Any visitAlterByCoalescePartition(MySqlParser::AlterByCoalescePartitionContext *context) = 0;

    virtual antlrcpp::Any visitAlterByReorganizePartition(MySqlParser::AlterByReorganizePartitionContext *context) = 0;

    virtual antlrcpp::Any visitAlterByExchangePartition(MySqlParser::AlterByExchangePartitionContext *context) = 0;

    virtual antlrcpp::Any visitAlterByAnalyzePartition(MySqlParser::AlterByAnalyzePartitionContext *context) = 0;

    virtual antlrcpp::Any visitAlterByCheckPartition(MySqlParser::AlterByCheckPartitionContext *context) = 0;

    virtual antlrcpp::Any visitAlterByOptimizePartition(MySqlParser::AlterByOptimizePartitionContext *context) = 0;

    virtual antlrcpp::Any visitAlterByRebuildPartition(MySqlParser::AlterByRebuildPartitionContext *context) = 0;

    virtual antlrcpp::Any visitAlterByRepairPartition(MySqlParser::AlterByRepairPartitionContext *context) = 0;

    virtual antlrcpp::Any visitAlterByRemovePartitioning(MySqlParser::AlterByRemovePartitioningContext *context) = 0;

    virtual antlrcpp::Any visitAlterByUpgradePartitioning(MySqlParser::AlterByUpgradePartitioningContext *context) = 0;

    virtual antlrcpp::Any visitDropDatabase(MySqlParser::DropDatabaseContext *context) = 0;

    virtual antlrcpp::Any visitDropEvent(MySqlParser::DropEventContext *context) = 0;

    virtual antlrcpp::Any visitDropIndex(MySqlParser::DropIndexContext *context) = 0;

    virtual antlrcpp::Any visitDropLogfileGroup(MySqlParser::DropLogfileGroupContext *context) = 0;

    virtual antlrcpp::Any visitDropProcedure(MySqlParser::DropProcedureContext *context) = 0;

    virtual antlrcpp::Any visitDropFunction(MySqlParser::DropFunctionContext *context) = 0;

    virtual antlrcpp::Any visitDropServer(MySqlParser::DropServerContext *context) = 0;

    virtual antlrcpp::Any visitDropTable(MySqlParser::DropTableContext *context) = 0;

    virtual antlrcpp::Any visitDropTablespace(MySqlParser::DropTablespaceContext *context) = 0;

    virtual antlrcpp::Any visitDropTrigger(MySqlParser::DropTriggerContext *context) = 0;

    virtual antlrcpp::Any visitDropView(MySqlParser::DropViewContext *context) = 0;

    virtual antlrcpp::Any visitRenameTable(MySqlParser::RenameTableContext *context) = 0;

    virtual antlrcpp::Any visitRenameTableClause(MySqlParser::RenameTableClauseContext *context) = 0;

    virtual antlrcpp::Any visitTruncateTable(MySqlParser::TruncateTableContext *context) = 0;

    virtual antlrcpp::Any visitCallStatement(MySqlParser::CallStatementContext *context) = 0;

    virtual antlrcpp::Any visitDeleteStatement(MySqlParser::DeleteStatementContext *context) = 0;

    virtual antlrcpp::Any visitDoStatement(MySqlParser::DoStatementContext *context) = 0;

    virtual antlrcpp::Any visitHandlerStatement(MySqlParser::HandlerStatementContext *context) = 0;

    virtual antlrcpp::Any visitInsertStatement(MySqlParser::InsertStatementContext *context) = 0;

    virtual antlrcpp::Any visitLoadDataStatement(MySqlParser::LoadDataStatementContext *context) = 0;

    virtual antlrcpp::Any visitLoadXmlStatement(MySqlParser::LoadXmlStatementContext *context) = 0;

    virtual antlrcpp::Any visitReplaceStatement(MySqlParser::ReplaceStatementContext *context) = 0;

    virtual antlrcpp::Any visitSimpleSelect(MySqlParser::SimpleSelectContext *context) = 0;

    virtual antlrcpp::Any visitParenthesisSelect(MySqlParser::ParenthesisSelectContext *context) = 0;

    virtual antlrcpp::Any visitUnionSelect(MySqlParser::UnionSelectContext *context) = 0;

    virtual antlrcpp::Any visitUnionParenthesisSelect(MySqlParser::UnionParenthesisSelectContext *context) = 0;

    virtual antlrcpp::Any visitUpdateStatement(MySqlParser::UpdateStatementContext *context) = 0;

    virtual antlrcpp::Any visitInsertStatementValue(MySqlParser::InsertStatementValueContext *context) = 0;

    virtual antlrcpp::Any visitUpdatedElement(MySqlParser::UpdatedElementContext *context) = 0;

    virtual antlrcpp::Any visitAssignmentField(MySqlParser::AssignmentFieldContext *context) = 0;

    virtual antlrcpp::Any visitLockClause(MySqlParser::LockClauseContext *context) = 0;

    virtual antlrcpp::Any visitSingleDeleteStatement(MySqlParser::SingleDeleteStatementContext *context) = 0;

    virtual antlrcpp::Any visitMultipleDeleteStatement(MySqlParser::MultipleDeleteStatementContext *context) = 0;

    virtual antlrcpp::Any visitHandlerOpenStatement(MySqlParser::HandlerOpenStatementContext *context) = 0;

    virtual antlrcpp::Any visitHandlerReadIndexStatement(MySqlParser::HandlerReadIndexStatementContext *context) = 0;

    virtual antlrcpp::Any visitHandlerReadStatement(MySqlParser::HandlerReadStatementContext *context) = 0;

    virtual antlrcpp::Any visitHandlerCloseStatement(MySqlParser::HandlerCloseStatementContext *context) = 0;

    virtual antlrcpp::Any visitSingleUpdateStatement(MySqlParser::SingleUpdateStatementContext *context) = 0;

    virtual antlrcpp::Any visitMultipleUpdateStatement(MySqlParser::MultipleUpdateStatementContext *context) = 0;

    virtual antlrcpp::Any visitOrderByClause(MySqlParser::OrderByClauseContext *context) = 0;

    virtual antlrcpp::Any visitOrderByExpression(MySqlParser::OrderByExpressionContext *context) = 0;

    virtual antlrcpp::Any visitTableSources(MySqlParser::TableSourcesContext *context) = 0;

    virtual antlrcpp::Any visitTableSourceBase(MySqlParser::TableSourceBaseContext *context) = 0;

    virtual antlrcpp::Any visitTableSourceNested(MySqlParser::TableSourceNestedContext *context) = 0;

    virtual antlrcpp::Any visitAtomTableItem(MySqlParser::AtomTableItemContext *context) = 0;

    virtual antlrcpp::Any visitSubqueryTableItem(MySqlParser::SubqueryTableItemContext *context) = 0;

    virtual antlrcpp::Any visitTableSourcesItem(MySqlParser::TableSourcesItemContext *context) = 0;

    virtual antlrcpp::Any visitIndexHint(MySqlParser::IndexHintContext *context) = 0;

    virtual antlrcpp::Any visitIndexHintType(MySqlParser::IndexHintTypeContext *context) = 0;

    virtual antlrcpp::Any visitInnerJoin(MySqlParser::InnerJoinContext *context) = 0;

    virtual antlrcpp::Any visitStraightJoin(MySqlParser::StraightJoinContext *context) = 0;

    virtual antlrcpp::Any visitOuterJoin(MySqlParser::OuterJoinContext *context) = 0;

    virtual antlrcpp::Any visitNaturalJoin(MySqlParser::NaturalJoinContext *context) = 0;

    virtual antlrcpp::Any visitQueryExpression(MySqlParser::QueryExpressionContext *context) = 0;

    virtual antlrcpp::Any visitQueryExpressionNointo(MySqlParser::QueryExpressionNointoContext *context) = 0;

    virtual antlrcpp::Any visitQuerySpecification(MySqlParser::QuerySpecificationContext *context) = 0;

    virtual antlrcpp::Any visitQuerySpecificationNointo(MySqlParser::QuerySpecificationNointoContext *context) = 0;

    virtual antlrcpp::Any visitUnionParenthesis(MySqlParser::UnionParenthesisContext *context) = 0;

    virtual antlrcpp::Any visitUnionStatement(MySqlParser::UnionStatementContext *context) = 0;

    virtual antlrcpp::Any visitSelectSpec(MySqlParser::SelectSpecContext *context) = 0;

    virtual antlrcpp::Any visitSelectElements(MySqlParser::SelectElementsContext *context) = 0;

    virtual antlrcpp::Any visitSelectStarElement(MySqlParser::SelectStarElementContext *context) = 0;

    virtual antlrcpp::Any visitSelectColumnElement(MySqlParser::SelectColumnElementContext *context) = 0;

    virtual antlrcpp::Any visitSelectFunctionElement(MySqlParser::SelectFunctionElementContext *context) = 0;

    virtual antlrcpp::Any visitSelectExpressionElement(MySqlParser::SelectExpressionElementContext *context) = 0;

    virtual antlrcpp::Any visitSelectIntoVariables(MySqlParser::SelectIntoVariablesContext *context) = 0;

    virtual antlrcpp::Any visitSelectIntoDumpFile(MySqlParser::SelectIntoDumpFileContext *context) = 0;

    virtual antlrcpp::Any visitSelectIntoTextFile(MySqlParser::SelectIntoTextFileContext *context) = 0;

    virtual antlrcpp::Any visitSelectFieldsInto(MySqlParser::SelectFieldsIntoContext *context) = 0;

    virtual antlrcpp::Any visitSelectLinesInto(MySqlParser::SelectLinesIntoContext *context) = 0;

    virtual antlrcpp::Any visitFromClause(MySqlParser::FromClauseContext *context) = 0;

    virtual antlrcpp::Any visitGroupByItem(MySqlParser::GroupByItemContext *context) = 0;

    virtual antlrcpp::Any visitLimitClause(MySqlParser::LimitClauseContext *context) = 0;

    virtual antlrcpp::Any visitLimitClauseAtom(MySqlParser::LimitClauseAtomContext *context) = 0;

    virtual antlrcpp::Any visitStartTransaction(MySqlParser::StartTransactionContext *context) = 0;

    virtual antlrcpp::Any visitBeginWork(MySqlParser::BeginWorkContext *context) = 0;

    virtual antlrcpp::Any visitCommitWork(MySqlParser::CommitWorkContext *context) = 0;

    virtual antlrcpp::Any visitRollbackWork(MySqlParser::RollbackWorkContext *context) = 0;

    virtual antlrcpp::Any visitSavepointStatement(MySqlParser::SavepointStatementContext *context) = 0;

    virtual antlrcpp::Any visitRollbackStatement(MySqlParser::RollbackStatementContext *context) = 0;

    virtual antlrcpp::Any visitReleaseStatement(MySqlParser::ReleaseStatementContext *context) = 0;

    virtual antlrcpp::Any visitLockTables(MySqlParser::LockTablesContext *context) = 0;

    virtual antlrcpp::Any visitUnlockTables(MySqlParser::UnlockTablesContext *context) = 0;

    virtual antlrcpp::Any visitSetAutocommitStatement(MySqlParser::SetAutocommitStatementContext *context) = 0;

    virtual antlrcpp::Any visitSetTransactionStatement(MySqlParser::SetTransactionStatementContext *context) = 0;

    virtual antlrcpp::Any visitTransactionMode(MySqlParser::TransactionModeContext *context) = 0;

    virtual antlrcpp::Any visitLockTableElement(MySqlParser::LockTableElementContext *context) = 0;

    virtual antlrcpp::Any visitLockAction(MySqlParser::LockActionContext *context) = 0;

    virtual antlrcpp::Any visitTransactionOption(MySqlParser::TransactionOptionContext *context) = 0;

    virtual antlrcpp::Any visitTransactionLevel(MySqlParser::TransactionLevelContext *context) = 0;

    virtual antlrcpp::Any visitChangeMaster(MySqlParser::ChangeMasterContext *context) = 0;

    virtual antlrcpp::Any visitChangeReplicationFilter(MySqlParser::ChangeReplicationFilterContext *context) = 0;

    virtual antlrcpp::Any visitPurgeBinaryLogs(MySqlParser::PurgeBinaryLogsContext *context) = 0;

    virtual antlrcpp::Any visitResetMaster(MySqlParser::ResetMasterContext *context) = 0;

    virtual antlrcpp::Any visitResetSlave(MySqlParser::ResetSlaveContext *context) = 0;

    virtual antlrcpp::Any visitStartSlave(MySqlParser::StartSlaveContext *context) = 0;

    virtual antlrcpp::Any visitStopSlave(MySqlParser::StopSlaveContext *context) = 0;

    virtual antlrcpp::Any visitStartGroupReplication(MySqlParser::StartGroupReplicationContext *context) = 0;

    virtual antlrcpp::Any visitStopGroupReplication(MySqlParser::StopGroupReplicationContext *context) = 0;

    virtual antlrcpp::Any visitMasterStringOption(MySqlParser::MasterStringOptionContext *context) = 0;

    virtual antlrcpp::Any visitMasterDecimalOption(MySqlParser::MasterDecimalOptionContext *context) = 0;

    virtual antlrcpp::Any visitMasterBoolOption(MySqlParser::MasterBoolOptionContext *context) = 0;

    virtual antlrcpp::Any visitMasterRealOption(MySqlParser::MasterRealOptionContext *context) = 0;

    virtual antlrcpp::Any visitMasterUidListOption(MySqlParser::MasterUidListOptionContext *context) = 0;

    virtual antlrcpp::Any visitStringMasterOption(MySqlParser::StringMasterOptionContext *context) = 0;

    virtual antlrcpp::Any visitDecimalMasterOption(MySqlParser::DecimalMasterOptionContext *context) = 0;

    virtual antlrcpp::Any visitBoolMasterOption(MySqlParser::BoolMasterOptionContext *context) = 0;

    virtual antlrcpp::Any visitChannelOption(MySqlParser::ChannelOptionContext *context) = 0;

    virtual antlrcpp::Any visitDoDbReplication(MySqlParser::DoDbReplicationContext *context) = 0;

    virtual antlrcpp::Any visitIgnoreDbReplication(MySqlParser::IgnoreDbReplicationContext *context) = 0;

    virtual antlrcpp::Any visitDoTableReplication(MySqlParser::DoTableReplicationContext *context) = 0;

    virtual antlrcpp::Any visitIgnoreTableReplication(MySqlParser::IgnoreTableReplicationContext *context) = 0;

    virtual antlrcpp::Any visitWildDoTableReplication(MySqlParser::WildDoTableReplicationContext *context) = 0;

    virtual antlrcpp::Any visitWildIgnoreTableReplication(MySqlParser::WildIgnoreTableReplicationContext *context) = 0;

    virtual antlrcpp::Any visitRewriteDbReplication(MySqlParser::RewriteDbReplicationContext *context) = 0;

    virtual antlrcpp::Any visitTablePair(MySqlParser::TablePairContext *context) = 0;

    virtual antlrcpp::Any visitThreadType(MySqlParser::ThreadTypeContext *context) = 0;

    virtual antlrcpp::Any visitGtidsUntilOption(MySqlParser::GtidsUntilOptionContext *context) = 0;

    virtual antlrcpp::Any visitMasterLogUntilOption(MySqlParser::MasterLogUntilOptionContext *context) = 0;

    virtual antlrcpp::Any visitRelayLogUntilOption(MySqlParser::RelayLogUntilOptionContext *context) = 0;

    virtual antlrcpp::Any visitSqlGapsUntilOption(MySqlParser::SqlGapsUntilOptionContext *context) = 0;

    virtual antlrcpp::Any visitUserConnectionOption(MySqlParser::UserConnectionOptionContext *context) = 0;

    virtual antlrcpp::Any visitPasswordConnectionOption(MySqlParser::PasswordConnectionOptionContext *context) = 0;

    virtual antlrcpp::Any visitDefaultAuthConnectionOption(MySqlParser::DefaultAuthConnectionOptionContext *context) = 0;

    virtual antlrcpp::Any visitPluginDirConnectionOption(MySqlParser::PluginDirConnectionOptionContext *context) = 0;

    virtual antlrcpp::Any visitGtuidSet(MySqlParser::GtuidSetContext *context) = 0;

    virtual antlrcpp::Any visitXaStartTransaction(MySqlParser::XaStartTransactionContext *context) = 0;

    virtual antlrcpp::Any visitXaEndTransaction(MySqlParser::XaEndTransactionContext *context) = 0;

    virtual antlrcpp::Any visitXaPrepareStatement(MySqlParser::XaPrepareStatementContext *context) = 0;

    virtual antlrcpp::Any visitXaCommitWork(MySqlParser::XaCommitWorkContext *context) = 0;

    virtual antlrcpp::Any visitXaRollbackWork(MySqlParser::XaRollbackWorkContext *context) = 0;

    virtual antlrcpp::Any visitXaRecoverWork(MySqlParser::XaRecoverWorkContext *context) = 0;

    virtual antlrcpp::Any visitPrepareStatement(MySqlParser::PrepareStatementContext *context) = 0;

    virtual antlrcpp::Any visitExecuteStatement(MySqlParser::ExecuteStatementContext *context) = 0;

    virtual antlrcpp::Any visitDeallocatePrepare(MySqlParser::DeallocatePrepareContext *context) = 0;

    virtual antlrcpp::Any visitRoutineBody(MySqlParser::RoutineBodyContext *context) = 0;

    virtual antlrcpp::Any visitBlockStatement(MySqlParser::BlockStatementContext *context) = 0;

    virtual antlrcpp::Any visitCaseStatement(MySqlParser::CaseStatementContext *context) = 0;

    virtual antlrcpp::Any visitIfStatement(MySqlParser::IfStatementContext *context) = 0;

    virtual antlrcpp::Any visitIterateStatement(MySqlParser::IterateStatementContext *context) = 0;

    virtual antlrcpp::Any visitLeaveStatement(MySqlParser::LeaveStatementContext *context) = 0;

    virtual antlrcpp::Any visitLoopStatement(MySqlParser::LoopStatementContext *context) = 0;

    virtual antlrcpp::Any visitRepeatStatement(MySqlParser::RepeatStatementContext *context) = 0;

    virtual antlrcpp::Any visitReturnStatement(MySqlParser::ReturnStatementContext *context) = 0;

    virtual antlrcpp::Any visitWhileStatement(MySqlParser::WhileStatementContext *context) = 0;

    virtual antlrcpp::Any visitCloseCursor(MySqlParser::CloseCursorContext *context) = 0;

    virtual antlrcpp::Any visitFetchCursor(MySqlParser::FetchCursorContext *context) = 0;

    virtual antlrcpp::Any visitOpenCursor(MySqlParser::OpenCursorContext *context) = 0;

    virtual antlrcpp::Any visitDeclareVariable(MySqlParser::DeclareVariableContext *context) = 0;

    virtual antlrcpp::Any visitDeclareCondition(MySqlParser::DeclareConditionContext *context) = 0;

    virtual antlrcpp::Any visitDeclareCursor(MySqlParser::DeclareCursorContext *context) = 0;

    virtual antlrcpp::Any visitDeclareHandler(MySqlParser::DeclareHandlerContext *context) = 0;

    virtual antlrcpp::Any visitHandlerConditionCode(MySqlParser::HandlerConditionCodeContext *context) = 0;

    virtual antlrcpp::Any visitHandlerConditionState(MySqlParser::HandlerConditionStateContext *context) = 0;

    virtual antlrcpp::Any visitHandlerConditionName(MySqlParser::HandlerConditionNameContext *context) = 0;

    virtual antlrcpp::Any visitHandlerConditionWarning(MySqlParser::HandlerConditionWarningContext *context) = 0;

    virtual antlrcpp::Any visitHandlerConditionNotfound(MySqlParser::HandlerConditionNotfoundContext *context) = 0;

    virtual antlrcpp::Any visitHandlerConditionException(MySqlParser::HandlerConditionExceptionContext *context) = 0;

    virtual antlrcpp::Any visitProcedureSqlStatement(MySqlParser::ProcedureSqlStatementContext *context) = 0;

    virtual antlrcpp::Any visitCaseAlternative(MySqlParser::CaseAlternativeContext *context) = 0;

    virtual antlrcpp::Any visitElifAlternative(MySqlParser::ElifAlternativeContext *context) = 0;

    virtual antlrcpp::Any visitAlterUserMysqlV56(MySqlParser::AlterUserMysqlV56Context *context) = 0;

    virtual antlrcpp::Any visitAlterUserMysqlV57(MySqlParser::AlterUserMysqlV57Context *context) = 0;

    virtual antlrcpp::Any visitCreateUserMysqlV56(MySqlParser::CreateUserMysqlV56Context *context) = 0;

    virtual antlrcpp::Any visitCreateUserMysqlV57(MySqlParser::CreateUserMysqlV57Context *context) = 0;

    virtual antlrcpp::Any visitDropUser(MySqlParser::DropUserContext *context) = 0;

    virtual antlrcpp::Any visitGrantStatement(MySqlParser::GrantStatementContext *context) = 0;

    virtual antlrcpp::Any visitGrantProxy(MySqlParser::GrantProxyContext *context) = 0;

    virtual antlrcpp::Any visitRenameUser(MySqlParser::RenameUserContext *context) = 0;

    virtual antlrcpp::Any visitDetailRevoke(MySqlParser::DetailRevokeContext *context) = 0;

    virtual antlrcpp::Any visitShortRevoke(MySqlParser::ShortRevokeContext *context) = 0;

    virtual antlrcpp::Any visitRevokeProxy(MySqlParser::RevokeProxyContext *context) = 0;

    virtual antlrcpp::Any visitSetPasswordStatement(MySqlParser::SetPasswordStatementContext *context) = 0;

    virtual antlrcpp::Any visitUserSpecification(MySqlParser::UserSpecificationContext *context) = 0;

    virtual antlrcpp::Any visitPasswordAuthOption(MySqlParser::PasswordAuthOptionContext *context) = 0;

    virtual antlrcpp::Any visitStringAuthOption(MySqlParser::StringAuthOptionContext *context) = 0;

    virtual antlrcpp::Any visitHashAuthOption(MySqlParser::HashAuthOptionContext *context) = 0;

    virtual antlrcpp::Any visitSimpleAuthOption(MySqlParser::SimpleAuthOptionContext *context) = 0;

    virtual antlrcpp::Any visitTlsOption(MySqlParser::TlsOptionContext *context) = 0;

    virtual antlrcpp::Any visitUserResourceOption(MySqlParser::UserResourceOptionContext *context) = 0;

    virtual antlrcpp::Any visitUserPasswordOption(MySqlParser::UserPasswordOptionContext *context) = 0;

    virtual antlrcpp::Any visitUserLockOption(MySqlParser::UserLockOptionContext *context) = 0;

    virtual antlrcpp::Any visitPrivelegeClause(MySqlParser::PrivelegeClauseContext *context) = 0;

    virtual antlrcpp::Any visitPrivilege(MySqlParser::PrivilegeContext *context) = 0;

    virtual antlrcpp::Any visitCurrentSchemaPriviLevel(MySqlParser::CurrentSchemaPriviLevelContext *context) = 0;

    virtual antlrcpp::Any visitGlobalPrivLevel(MySqlParser::GlobalPrivLevelContext *context) = 0;

    virtual antlrcpp::Any visitDefiniteSchemaPrivLevel(MySqlParser::DefiniteSchemaPrivLevelContext *context) = 0;

    virtual antlrcpp::Any visitDefiniteFullTablePrivLevel(MySqlParser::DefiniteFullTablePrivLevelContext *context) = 0;

    virtual antlrcpp::Any visitDefiniteFullTablePrivLevel2(MySqlParser::DefiniteFullTablePrivLevel2Context *context) = 0;

    virtual antlrcpp::Any visitDefiniteTablePrivLevel(MySqlParser::DefiniteTablePrivLevelContext *context) = 0;

    virtual antlrcpp::Any visitRenameUserClause(MySqlParser::RenameUserClauseContext *context) = 0;

    virtual antlrcpp::Any visitAnalyzeTable(MySqlParser::AnalyzeTableContext *context) = 0;

    virtual antlrcpp::Any visitCheckTable(MySqlParser::CheckTableContext *context) = 0;

    virtual antlrcpp::Any visitChecksumTable(MySqlParser::ChecksumTableContext *context) = 0;

    virtual antlrcpp::Any visitOptimizeTable(MySqlParser::OptimizeTableContext *context) = 0;

    virtual antlrcpp::Any visitRepairTable(MySqlParser::RepairTableContext *context) = 0;

    virtual antlrcpp::Any visitCheckTableOption(MySqlParser::CheckTableOptionContext *context) = 0;

    virtual antlrcpp::Any visitCreateUdfunction(MySqlParser::CreateUdfunctionContext *context) = 0;

    virtual antlrcpp::Any visitInstallPlugin(MySqlParser::InstallPluginContext *context) = 0;

    virtual antlrcpp::Any visitUninstallPlugin(MySqlParser::UninstallPluginContext *context) = 0;

    virtual antlrcpp::Any visitSetVariable(MySqlParser::SetVariableContext *context) = 0;

    virtual antlrcpp::Any visitSetCharset(MySqlParser::SetCharsetContext *context) = 0;

    virtual antlrcpp::Any visitSetNames(MySqlParser::SetNamesContext *context) = 0;

    virtual antlrcpp::Any visitSetPassword(MySqlParser::SetPasswordContext *context) = 0;

    virtual antlrcpp::Any visitSetTransaction(MySqlParser::SetTransactionContext *context) = 0;

    virtual antlrcpp::Any visitSetAutocommit(MySqlParser::SetAutocommitContext *context) = 0;

    virtual antlrcpp::Any visitSetNewValueInsideTrigger(MySqlParser::SetNewValueInsideTriggerContext *context) = 0;

    virtual antlrcpp::Any visitShowMasterLogs(MySqlParser::ShowMasterLogsContext *context) = 0;

    virtual antlrcpp::Any visitShowLogEvents(MySqlParser::ShowLogEventsContext *context) = 0;

    virtual antlrcpp::Any visitShowObjectFilter(MySqlParser::ShowObjectFilterContext *context) = 0;

    virtual antlrcpp::Any visitShowColumns(MySqlParser::ShowColumnsContext *context) = 0;

    virtual antlrcpp::Any visitShowCreateDb(MySqlParser::ShowCreateDbContext *context) = 0;

    virtual antlrcpp::Any visitShowCreateFullIdObject(MySqlParser::ShowCreateFullIdObjectContext *context) = 0;

    virtual antlrcpp::Any visitShowCreateUser(MySqlParser::ShowCreateUserContext *context) = 0;

    virtual antlrcpp::Any visitShowEngine(MySqlParser::ShowEngineContext *context) = 0;

    virtual antlrcpp::Any visitShowGlobalInfo(MySqlParser::ShowGlobalInfoContext *context) = 0;

    virtual antlrcpp::Any visitShowErrors(MySqlParser::ShowErrorsContext *context) = 0;

    virtual antlrcpp::Any visitShowCountErrors(MySqlParser::ShowCountErrorsContext *context) = 0;

    virtual antlrcpp::Any visitShowSchemaFilter(MySqlParser::ShowSchemaFilterContext *context) = 0;

    virtual antlrcpp::Any visitShowRoutine(MySqlParser::ShowRoutineContext *context) = 0;

    virtual antlrcpp::Any visitShowGrants(MySqlParser::ShowGrantsContext *context) = 0;

    virtual antlrcpp::Any visitShowIndexes(MySqlParser::ShowIndexesContext *context) = 0;

    virtual antlrcpp::Any visitShowOpenTables(MySqlParser::ShowOpenTablesContext *context) = 0;

    virtual antlrcpp::Any visitShowProfile(MySqlParser::ShowProfileContext *context) = 0;

    virtual antlrcpp::Any visitShowSlaveStatus(MySqlParser::ShowSlaveStatusContext *context) = 0;

    virtual antlrcpp::Any visitVariableClause(MySqlParser::VariableClauseContext *context) = 0;

    virtual antlrcpp::Any visitShowCommonEntity(MySqlParser::ShowCommonEntityContext *context) = 0;

    virtual antlrcpp::Any visitShowFilter(MySqlParser::ShowFilterContext *context) = 0;

    virtual antlrcpp::Any visitShowGlobalInfoClause(MySqlParser::ShowGlobalInfoClauseContext *context) = 0;

    virtual antlrcpp::Any visitShowSchemaEntity(MySqlParser::ShowSchemaEntityContext *context) = 0;

    virtual antlrcpp::Any visitShowProfileType(MySqlParser::ShowProfileTypeContext *context) = 0;

    virtual antlrcpp::Any visitBinlogStatement(MySqlParser::BinlogStatementContext *context) = 0;

    virtual antlrcpp::Any visitCacheIndexStatement(MySqlParser::CacheIndexStatementContext *context) = 0;

    virtual antlrcpp::Any visitFlushStatement(MySqlParser::FlushStatementContext *context) = 0;

    virtual antlrcpp::Any visitKillStatement(MySqlParser::KillStatementContext *context) = 0;

    virtual antlrcpp::Any visitLoadIndexIntoCache(MySqlParser::LoadIndexIntoCacheContext *context) = 0;

    virtual antlrcpp::Any visitResetStatement(MySqlParser::ResetStatementContext *context) = 0;

    virtual antlrcpp::Any visitShutdownStatement(MySqlParser::ShutdownStatementContext *context) = 0;

    virtual antlrcpp::Any visitTableIndexes(MySqlParser::TableIndexesContext *context) = 0;

    virtual antlrcpp::Any visitSimpleFlushOption(MySqlParser::SimpleFlushOptionContext *context) = 0;

    virtual antlrcpp::Any visitChannelFlushOption(MySqlParser::ChannelFlushOptionContext *context) = 0;

    virtual antlrcpp::Any visitTableFlushOption(MySqlParser::TableFlushOptionContext *context) = 0;

    virtual antlrcpp::Any visitFlushTableOption(MySqlParser::FlushTableOptionContext *context) = 0;

    virtual antlrcpp::Any visitLoadedTableIndexes(MySqlParser::LoadedTableIndexesContext *context) = 0;

    virtual antlrcpp::Any visitSimpleDescribeStatement(MySqlParser::SimpleDescribeStatementContext *context) = 0;

    virtual antlrcpp::Any visitFullDescribeStatement(MySqlParser::FullDescribeStatementContext *context) = 0;

    virtual antlrcpp::Any visitHelpStatement(MySqlParser::HelpStatementContext *context) = 0;

    virtual antlrcpp::Any visitUseStatement(MySqlParser::UseStatementContext *context) = 0;

    virtual antlrcpp::Any visitSignalStatement(MySqlParser::SignalStatementContext *context) = 0;

    virtual antlrcpp::Any visitResignalStatement(MySqlParser::ResignalStatementContext *context) = 0;

    virtual antlrcpp::Any visitSignalConditionInformation(MySqlParser::SignalConditionInformationContext *context) = 0;

    virtual antlrcpp::Any visitDiagnosticsStatement(MySqlParser::DiagnosticsStatementContext *context) = 0;

    virtual antlrcpp::Any visitDiagnosticsConditionInformationName(MySqlParser::DiagnosticsConditionInformationNameContext *context) = 0;

    virtual antlrcpp::Any visitDescribeStatements(MySqlParser::DescribeStatementsContext *context) = 0;

    virtual antlrcpp::Any visitDescribeConnection(MySqlParser::DescribeConnectionContext *context) = 0;

    virtual antlrcpp::Any visitFullId(MySqlParser::FullIdContext *context) = 0;

    virtual antlrcpp::Any visitTableName(MySqlParser::TableNameContext *context) = 0;

    virtual antlrcpp::Any visitFullColumnName(MySqlParser::FullColumnNameContext *context) = 0;

    virtual antlrcpp::Any visitIndexColumnName(MySqlParser::IndexColumnNameContext *context) = 0;

    virtual antlrcpp::Any visitUserName(MySqlParser::UserNameContext *context) = 0;

    virtual antlrcpp::Any visitMysqlVariable(MySqlParser::MysqlVariableContext *context) = 0;

    virtual antlrcpp::Any visitCharsetName(MySqlParser::CharsetNameContext *context) = 0;

    virtual antlrcpp::Any visitCollationName(MySqlParser::CollationNameContext *context) = 0;

    virtual antlrcpp::Any visitEngineName(MySqlParser::EngineNameContext *context) = 0;

    virtual antlrcpp::Any visitUuidSet(MySqlParser::UuidSetContext *context) = 0;

    virtual antlrcpp::Any visitXid(MySqlParser::XidContext *context) = 0;

    virtual antlrcpp::Any visitXuidStringId(MySqlParser::XuidStringIdContext *context) = 0;

    virtual antlrcpp::Any visitAuthPlugin(MySqlParser::AuthPluginContext *context) = 0;

    virtual antlrcpp::Any visitUid(MySqlParser::UidContext *context) = 0;

    virtual antlrcpp::Any visitSimpleId(MySqlParser::SimpleIdContext *context) = 0;

    virtual antlrcpp::Any visitDottedId(MySqlParser::DottedIdContext *context) = 0;

    virtual antlrcpp::Any visitDecimalLiteral(MySqlParser::DecimalLiteralContext *context) = 0;

    virtual antlrcpp::Any visitFileSizeLiteral(MySqlParser::FileSizeLiteralContext *context) = 0;

    virtual antlrcpp::Any visitStringLiteral(MySqlParser::StringLiteralContext *context) = 0;

    virtual antlrcpp::Any visitBooleanLiteral(MySqlParser::BooleanLiteralContext *context) = 0;

    virtual antlrcpp::Any visitHexadecimalLiteral(MySqlParser::HexadecimalLiteralContext *context) = 0;

    virtual antlrcpp::Any visitNullNotnull(MySqlParser::NullNotnullContext *context) = 0;

    virtual antlrcpp::Any visitConstant(MySqlParser::ConstantContext *context) = 0;

    virtual antlrcpp::Any visitStringDataType(MySqlParser::StringDataTypeContext *context) = 0;

    virtual antlrcpp::Any visitNationalStringDataType(MySqlParser::NationalStringDataTypeContext *context) = 0;

    virtual antlrcpp::Any visitNationalVaryingStringDataType(MySqlParser::NationalVaryingStringDataTypeContext *context) = 0;

    virtual antlrcpp::Any visitDimensionDataType(MySqlParser::DimensionDataTypeContext *context) = 0;

    virtual antlrcpp::Any visitSimpleDataType(MySqlParser::SimpleDataTypeContext *context) = 0;

    virtual antlrcpp::Any visitCollectionDataType(MySqlParser::CollectionDataTypeContext *context) = 0;

    virtual antlrcpp::Any visitSpatialDataType(MySqlParser::SpatialDataTypeContext *context) = 0;

    virtual antlrcpp::Any visitCollectionOptions(MySqlParser::CollectionOptionsContext *context) = 0;

    virtual antlrcpp::Any visitConvertedDataType(MySqlParser::ConvertedDataTypeContext *context) = 0;

    virtual antlrcpp::Any visitLengthOneDimension(MySqlParser::LengthOneDimensionContext *context) = 0;

    virtual antlrcpp::Any visitLengthTwoDimension(MySqlParser::LengthTwoDimensionContext *context) = 0;

    virtual antlrcpp::Any visitLengthTwoOptionalDimension(MySqlParser::LengthTwoOptionalDimensionContext *context) = 0;

    virtual antlrcpp::Any visitUidList(MySqlParser::UidListContext *context) = 0;

    virtual antlrcpp::Any visitTables(MySqlParser::TablesContext *context) = 0;

    virtual antlrcpp::Any visitIndexColumnNames(MySqlParser::IndexColumnNamesContext *context) = 0;

    virtual antlrcpp::Any visitExpressions(MySqlParser::ExpressionsContext *context) = 0;

    virtual antlrcpp::Any visitExpressionsWithDefaults(MySqlParser::ExpressionsWithDefaultsContext *context) = 0;

    virtual antlrcpp::Any visitConstants(MySqlParser::ConstantsContext *context) = 0;

    virtual antlrcpp::Any visitSimpleStrings(MySqlParser::SimpleStringsContext *context) = 0;

    virtual antlrcpp::Any visitUserVariables(MySqlParser::UserVariablesContext *context) = 0;

    virtual antlrcpp::Any visitDefaultValue(MySqlParser::DefaultValueContext *context) = 0;

    virtual antlrcpp::Any visitCurrentTimestamp(MySqlParser::CurrentTimestampContext *context) = 0;

    virtual antlrcpp::Any visitExpressionOrDefault(MySqlParser::ExpressionOrDefaultContext *context) = 0;

    virtual antlrcpp::Any visitIfExists(MySqlParser::IfExistsContext *context) = 0;

    virtual antlrcpp::Any visitIfNotExists(MySqlParser::IfNotExistsContext *context) = 0;

    virtual antlrcpp::Any visitSpecificFunctionCall(MySqlParser::SpecificFunctionCallContext *context) = 0;

    virtual antlrcpp::Any visitAggregateFunctionCall(MySqlParser::AggregateFunctionCallContext *context) = 0;

    virtual antlrcpp::Any visitScalarFunctionCall(MySqlParser::ScalarFunctionCallContext *context) = 0;

    virtual antlrcpp::Any visitUdfFunctionCall(MySqlParser::UdfFunctionCallContext *context) = 0;

    virtual antlrcpp::Any visitPasswordFunctionCall(MySqlParser::PasswordFunctionCallContext *context) = 0;

    virtual antlrcpp::Any visitSimpleFunctionCall(MySqlParser::SimpleFunctionCallContext *context) = 0;

    virtual antlrcpp::Any visitDataTypeFunctionCall(MySqlParser::DataTypeFunctionCallContext *context) = 0;

    virtual antlrcpp::Any visitValuesFunctionCall(MySqlParser::ValuesFunctionCallContext *context) = 0;

    virtual antlrcpp::Any visitCaseFunctionCall(MySqlParser::CaseFunctionCallContext *context) = 0;

    virtual antlrcpp::Any visitCharFunctionCall(MySqlParser::CharFunctionCallContext *context) = 0;

    virtual antlrcpp::Any visitPositionFunctionCall(MySqlParser::PositionFunctionCallContext *context) = 0;

    virtual antlrcpp::Any visitSubstrFunctionCall(MySqlParser::SubstrFunctionCallContext *context) = 0;

    virtual antlrcpp::Any visitTrimFunctionCall(MySqlParser::TrimFunctionCallContext *context) = 0;

    virtual antlrcpp::Any visitWeightFunctionCall(MySqlParser::WeightFunctionCallContext *context) = 0;

    virtual antlrcpp::Any visitExtractFunctionCall(MySqlParser::ExtractFunctionCallContext *context) = 0;

    virtual antlrcpp::Any visitGetFormatFunctionCall(MySqlParser::GetFormatFunctionCallContext *context) = 0;

    virtual antlrcpp::Any visitCaseFuncAlternative(MySqlParser::CaseFuncAlternativeContext *context) = 0;

    virtual antlrcpp::Any visitLevelWeightList(MySqlParser::LevelWeightListContext *context) = 0;

    virtual antlrcpp::Any visitLevelWeightRange(MySqlParser::LevelWeightRangeContext *context) = 0;

    virtual antlrcpp::Any visitLevelInWeightListElement(MySqlParser::LevelInWeightListElementContext *context) = 0;

    virtual antlrcpp::Any visitAggregateWindowedFunction(MySqlParser::AggregateWindowedFunctionContext *context) = 0;

    virtual antlrcpp::Any visitScalarFunctionName(MySqlParser::ScalarFunctionNameContext *context) = 0;

    virtual antlrcpp::Any visitPasswordFunctionClause(MySqlParser::PasswordFunctionClauseContext *context) = 0;

    virtual antlrcpp::Any visitFunctionArgs(MySqlParser::FunctionArgsContext *context) = 0;

    virtual antlrcpp::Any visitFunctionArg(MySqlParser::FunctionArgContext *context) = 0;

    virtual antlrcpp::Any visitIsExpression(MySqlParser::IsExpressionContext *context) = 0;

    virtual antlrcpp::Any visitNotExpression(MySqlParser::NotExpressionContext *context) = 0;

    virtual antlrcpp::Any visitLogicalExpression(MySqlParser::LogicalExpressionContext *context) = 0;

    virtual antlrcpp::Any visitPredicateExpression(MySqlParser::PredicateExpressionContext *context) = 0;

    virtual antlrcpp::Any visitSoundsLikePredicate(MySqlParser::SoundsLikePredicateContext *context) = 0;

    virtual antlrcpp::Any visitExpressionAtomPredicate(MySqlParser::ExpressionAtomPredicateContext *context) = 0;

    virtual antlrcpp::Any visitInPredicate(MySqlParser::InPredicateContext *context) = 0;

    virtual antlrcpp::Any visitSubqueryComparasionPredicate(MySqlParser::SubqueryComparasionPredicateContext *context) = 0;

    virtual antlrcpp::Any visitBetweenPredicate(MySqlParser::BetweenPredicateContext *context) = 0;

    virtual antlrcpp::Any visitBinaryComparasionPredicate(MySqlParser::BinaryComparasionPredicateContext *context) = 0;

    virtual antlrcpp::Any visitIsNullPredicate(MySqlParser::IsNullPredicateContext *context) = 0;

    virtual antlrcpp::Any visitLikePredicate(MySqlParser::LikePredicateContext *context) = 0;

    virtual antlrcpp::Any visitRegexpPredicate(MySqlParser::RegexpPredicateContext *context) = 0;

    virtual antlrcpp::Any visitUnaryExpressionAtom(MySqlParser::UnaryExpressionAtomContext *context) = 0;

    virtual antlrcpp::Any visitCollateExpressionAtom(MySqlParser::CollateExpressionAtomContext *context) = 0;

    virtual antlrcpp::Any visitSubqueryExpessionAtom(MySqlParser::SubqueryExpessionAtomContext *context) = 0;

    virtual antlrcpp::Any visitMysqlVariableExpressionAtom(MySqlParser::MysqlVariableExpressionAtomContext *context) = 0;

    virtual antlrcpp::Any visitNestedExpressionAtom(MySqlParser::NestedExpressionAtomContext *context) = 0;

    virtual antlrcpp::Any visitNestedRowExpressionAtom(MySqlParser::NestedRowExpressionAtomContext *context) = 0;

    virtual antlrcpp::Any visitMathExpressionAtom(MySqlParser::MathExpressionAtomContext *context) = 0;

    virtual antlrcpp::Any visitIntervalExpressionAtom(MySqlParser::IntervalExpressionAtomContext *context) = 0;

    virtual antlrcpp::Any visitExistsExpessionAtom(MySqlParser::ExistsExpessionAtomContext *context) = 0;

    virtual antlrcpp::Any visitConstantExpressionAtom(MySqlParser::ConstantExpressionAtomContext *context) = 0;

    virtual antlrcpp::Any visitFunctionCallExpressionAtom(MySqlParser::FunctionCallExpressionAtomContext *context) = 0;

    virtual antlrcpp::Any visitBinaryExpressionAtom(MySqlParser::BinaryExpressionAtomContext *context) = 0;

    virtual antlrcpp::Any visitFullColumnNameExpressionAtom(MySqlParser::FullColumnNameExpressionAtomContext *context) = 0;

    virtual antlrcpp::Any visitBitExpressionAtom(MySqlParser::BitExpressionAtomContext *context) = 0;

    virtual antlrcpp::Any visitUnaryOperator(MySqlParser::UnaryOperatorContext *context) = 0;

    virtual antlrcpp::Any visitComparisonOperator(MySqlParser::ComparisonOperatorContext *context) = 0;

    virtual antlrcpp::Any visitLogicalOperator(MySqlParser::LogicalOperatorContext *context) = 0;

    virtual antlrcpp::Any visitBitOperator(MySqlParser::BitOperatorContext *context) = 0;

    virtual antlrcpp::Any visitMathOperator(MySqlParser::MathOperatorContext *context) = 0;

    virtual antlrcpp::Any visitCharsetNameBase(MySqlParser::CharsetNameBaseContext *context) = 0;

    virtual antlrcpp::Any visitTransactionLevelBase(MySqlParser::TransactionLevelBaseContext *context) = 0;

    virtual antlrcpp::Any visitPrivilegesBase(MySqlParser::PrivilegesBaseContext *context) = 0;

    virtual antlrcpp::Any visitIntervalTypeBase(MySqlParser::IntervalTypeBaseContext *context) = 0;

    virtual antlrcpp::Any visitDataTypeBase(MySqlParser::DataTypeBaseContext *context) = 0;

    virtual antlrcpp::Any visitKeywordsCanBeId(MySqlParser::KeywordsCanBeIdContext *context) = 0;

    virtual antlrcpp::Any visitFunctionNameBase(MySqlParser::FunctionNameBaseContext *context) = 0;


};


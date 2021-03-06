#pragma once

#include <Parsers/ParserQueryWithOutput.h>

namespace DB
{

/** CASE construction
  * Two variants:
  * 1. CASE expr WHEN val1 THEN res1 [WHEN ...] ELSE resN END
  * 2. CASE WHEN cond1 THEN res1 [WHEN ...] ELSE resN END
  * NOTE Until we get full support for NULL values in ClickHouse, ELSE sections are mandatory.
  */
class ParserCase final : public IParserBase
{
protected:
    const char * getName() const override { return "case"; }
    bool parseImpl(Pos & pos, Pos end, ASTPtr & node, Pos & max_parsed_pos, Expected & expected) override;
};

}

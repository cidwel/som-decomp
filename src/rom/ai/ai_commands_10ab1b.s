.setcpu "65816"
.segment "CODE"
.org $AB1B
.include "ai_command_macros.inc"
ai_pc_5c06:
    ai_call_ff $590F
ai_pc_5c09:
    ai_call_ff $5913
ai_pc_5c0c:
    ai_if_field_gt_30_short $0080, $002C, $00FE, $5C0C, $5C2D
ai_pc_5c11:
    ai_call_ff $5913
ai_pc_5c14:
    ai_if_field_gt_30_short $0080, $0064, $0000, $5C14, $5C1E
ai_pc_5c19:
    ai_call_ff $5C30
ai_pc_5c1c:
    ai_jmp_01_short $5C1C, $5C2B
ai_pc_5c1e:
    ai_if_field_gt_30_short $0080, $0064, $0002, $5C1E, $5C28
ai_pc_5c23:
    ai_call_ff $5C6B
ai_pc_5c26:
    ai_jmp_01_short $5C26, $5C2B
ai_pc_5c28:
    ai_call_ff $5CA3
ai_pc_5c2b:
    ai_jmp_01_short $5C2B, $5C0C
ai_pc_5c2d:
    ai_jmp_01_short $5C2D, $5C09

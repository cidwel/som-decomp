; Both byte consumers were produced by original object-program flows.
.setcpu "65816"
.segment "CODE"
.org $7EC6
.macro ai_if_var3_nz_short_overlapping_error source_pc, target_pc
    .byte $05
ai_pc_2fb2_produced_undefined_opcode:
    .byte $80 | ((target_pc - (source_pc + 2)) & $7F)
    .assert ($80 | ((target_pc - (source_pc + 2)) & $7F)) = $85, error, "second entry must retain undefined opcode85"
.endmacro
ai_pc_2fb1:
    ai_if_var3_nz_short_overlapping_error $2FB1, $2FB8

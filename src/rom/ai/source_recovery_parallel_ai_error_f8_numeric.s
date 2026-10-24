; Actual undefined opcode invokes native script error/restart.
.setcpu "65816"
.segment "CODE"
.org $AA16
.macro ai_undefined_opcode_error_restart opcode_code
    .byte opcode_code
.endmacro
ai_pc_5b01_produced_error_restart:
    ai_undefined_opcode_error_restart $F8

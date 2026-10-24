; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $DF64
boss_lz_controls_dadf64:
    ; backreference count 4, distance 73
    .byte $88, $48
    ; literal count 8; subsequent asset bytes excluded
    .byte $07

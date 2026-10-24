; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BD76
boss_lz_controls_dbbd76:
    ; backreference count 3, distance 216
    .byte $80, $D7
    ; backreference count 4, distance 151
    .byte $88, $96
    ; literal count 50; subsequent asset bytes excluded
    .byte $31

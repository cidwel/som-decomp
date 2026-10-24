; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A43B
boss_lz_controls_dba43b:
    ; backreference count 3, distance 336
    .byte $81, $4F
    ; backreference count 3, distance 28
    .byte $80, $1B
    ; literal count 2; subsequent asset bytes excluded
    .byte $01

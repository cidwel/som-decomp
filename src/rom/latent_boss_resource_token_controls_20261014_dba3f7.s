; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A3F7
boss_lz_controls_dba3f7:
    ; backreference count 6, distance 49
    .byte $98, $30
    ; backreference count 3, distance 21
    .byte $80, $14
    ; literal count 2; subsequent asset bytes excluded
    .byte $01

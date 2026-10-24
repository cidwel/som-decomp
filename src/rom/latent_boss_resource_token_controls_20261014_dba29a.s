; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A29A
boss_lz_controls_dba29a:
    ; backreference count 3, distance 46
    .byte $80, $2D
    ; literal count 11; subsequent asset bytes excluded
    .byte $0A

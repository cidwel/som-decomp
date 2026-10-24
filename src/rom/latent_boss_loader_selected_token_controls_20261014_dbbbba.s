; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BBBA
boss_lz_controls_dbbbba:
    ; backreference count 3, distance 250
    .byte $80, $F9
    ; literal count 11; subsequent asset bytes excluded
    .byte $0A

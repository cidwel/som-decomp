; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CAFE
boss_lz_controls_dbcafe:
    ; backreference count 5, distance 232
    .byte $A0, $E7
    ; literal count 11; subsequent asset bytes excluded
    .byte $0A

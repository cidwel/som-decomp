; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CAEF
boss_lz_controls_dbcaef:
    ; backreference count 5, distance 229
    .byte $A0, $E4
    ; literal count 12; subsequent asset bytes excluded
    .byte $0B

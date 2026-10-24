; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CFEB
boss_lz_controls_dbcfeb:
    ; backreference count 3, distance 110
    .byte $80, $6D
    ; literal count 6; subsequent asset bytes excluded
    .byte $05

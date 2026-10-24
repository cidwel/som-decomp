; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $AEAC
boss_lz_controls_dbaeac:
    ; backreference count 3, distance 46
    .byte $80, $2D
    ; literal count 28; subsequent asset bytes excluded
    .byte $1B

; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BEAC
boss_lz_controls_dbbeac:
    ; backreference count 3, distance 541
    .byte $82, $1C
    ; literal count 52; subsequent asset bytes excluded
    .byte $33

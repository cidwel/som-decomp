; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CECC
boss_lz_controls_dacecc:
    ; backreference count 3, distance 1574
    .byte $86, $25
    ; backreference count 3, distance 1900
    .byte $87, $6B
    ; literal count 27; subsequent asset bytes excluded
    .byte $1A

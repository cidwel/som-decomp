; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CDEE
boss_lz_controls_dbcdee:
    ; backreference count 3, distance 1895
    .byte $87, $66
    ; literal count 5; subsequent asset bytes excluded
    .byte $04

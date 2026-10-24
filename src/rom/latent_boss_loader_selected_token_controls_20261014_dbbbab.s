; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BBAB
boss_lz_controls_dbbbab:
    ; backreference count 3, distance 468
    .byte $81, $D3
    ; backreference count 4, distance 608
    .byte $86, $5F
    ; backreference count 3, distance 249
    .byte $80, $F8
    ; literal count 3; subsequent asset bytes excluded
    .byte $02

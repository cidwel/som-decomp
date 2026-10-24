; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $09FE
boss_lz_controls_db09fe:
    ; backreference count 4, distance 2808
    .byte $9A, $F7
    ; literal count 3; subsequent asset bytes excluded
    .byte $02

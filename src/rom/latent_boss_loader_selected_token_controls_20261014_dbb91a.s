; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B91A
boss_lz_controls_dbb91a:
    ; backreference count 10, distance 1
    .byte $9C, $00
    ; literal count 3; subsequent asset bytes excluded
    .byte $02

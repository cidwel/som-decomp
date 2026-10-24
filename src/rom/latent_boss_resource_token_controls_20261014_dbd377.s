; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D377
boss_lz_controls_dbd377:
    ; backreference count 4, distance 325
    .byte $85, $44
    ; literal count 3; subsequent asset bytes excluded
    .byte $02

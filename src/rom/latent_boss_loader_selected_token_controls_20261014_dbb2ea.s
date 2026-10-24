; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B2EA
boss_lz_controls_dbb2ea:
    ; backreference count 4, distance 354
    .byte $85, $61
    ; literal count 3; subsequent asset bytes excluded
    .byte $02

; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B987
boss_lz_controls_dbb987:
    ; backreference count 3, distance 355
    .byte $81, $62
    ; literal count 3; subsequent asset bytes excluded
    .byte $02

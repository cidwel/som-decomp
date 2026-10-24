; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CDF6
boss_lz_controls_dacdf6:
    ; backreference count 4, distance 1405
    .byte $8D, $7C
    ; literal count 3; subsequent asset bytes excluded
    .byte $02

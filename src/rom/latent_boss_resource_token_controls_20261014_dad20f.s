; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D20F
boss_lz_controls_dad20f:
    ; backreference count 5, distance 322
    .byte $91, $41
    ; literal count 3; subsequent asset bytes excluded
    .byte $02

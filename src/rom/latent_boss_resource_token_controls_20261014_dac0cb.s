; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C0CB
boss_lz_controls_dac0cb:
    ; backreference count 4, distance 394
    .byte $85, $89
    ; literal count 3; subsequent asset bytes excluded
    .byte $02

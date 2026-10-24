; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E57A
boss_lz_controls_dae57a:
    ; backreference count 4, distance 315
    .byte $89, $3A
    ; literal count 3; subsequent asset bytes excluded
    .byte $02

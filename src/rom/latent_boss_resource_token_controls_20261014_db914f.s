; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $914F
boss_lz_controls_db914f:
    ; backreference count 3, distance 7
    .byte $80, $06
    ; literal count 3; subsequent asset bytes excluded
    .byte $02

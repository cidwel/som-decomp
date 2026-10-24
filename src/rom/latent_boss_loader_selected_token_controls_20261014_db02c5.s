; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $02C5
boss_lz_controls_db02c5:
    ; backreference count 3, distance 122
    .byte $80, $79
    ; literal count 1; subsequent asset bytes excluded
    .byte $00

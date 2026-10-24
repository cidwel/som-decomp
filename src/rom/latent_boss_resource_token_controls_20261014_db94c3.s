; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $94C3
boss_lz_controls_db94c3:
    ; backreference count 4, distance 9
    .byte $90, $08
    ; literal count 3; subsequent asset bytes excluded
    .byte $02

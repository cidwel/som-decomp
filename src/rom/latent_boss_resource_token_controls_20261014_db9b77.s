; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $9B77
boss_lz_controls_db9b77:
    ; backreference count 5, distance 9
    .byte $90, $08
    ; literal count 3; subsequent asset bytes excluded
    .byte $02

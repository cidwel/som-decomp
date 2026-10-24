; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0592
boss_lz_controls_db0592:
    ; backreference count 6, distance 9
    .byte $B0, $08
    ; literal count 3; subsequent asset bytes excluded
    .byte $02

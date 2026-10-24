; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $08CB
boss_lz_controls_db08cb:
    ; backreference count 6, distance 1417
    .byte $B5, $88
    ; literal count 3; subsequent asset bytes excluded
    .byte $02

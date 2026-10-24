; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0521
boss_lz_controls_db0521:
    ; backreference count 4, distance 1129
    .byte $94, $68
    ; literal count 3; subsequent asset bytes excluded
    .byte $02

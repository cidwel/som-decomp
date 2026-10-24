; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $07D1
boss_lz_controls_db07d1:
    ; backreference count 6, distance 1584
    .byte $B6, $2F
    ; literal count 3; subsequent asset bytes excluded
    .byte $02

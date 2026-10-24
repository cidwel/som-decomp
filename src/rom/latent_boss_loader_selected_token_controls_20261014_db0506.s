; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0506
boss_lz_controls_db0506:
    ; backreference count 4, distance 8
    .byte $90, $07
    ; backreference count 4, distance 1218
    .byte $94, $C1
    ; literal count 3; subsequent asset bytes excluded
    .byte $02

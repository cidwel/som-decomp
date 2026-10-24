; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0740
boss_lz_controls_db0740:
    ; backreference count 6, distance 33
    .byte $B0, $20
    ; backreference count 3, distance 69
    .byte $80, $44
    ; backreference count 5, distance 1379
    .byte $A5, $62
    ; backreference count 5, distance 479
    .byte $A1, $DE
    ; literal count 3; subsequent asset bytes excluded
    .byte $02

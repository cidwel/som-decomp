; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0679
boss_lz_controls_db0679:
    ; backreference count 8, distance 18
    .byte $D0, $11
    ; backreference count 8, distance 1397
    .byte $D5, $74
    ; backreference count 3, distance 556
    .byte $82, $2B
    ; backreference count 7, distance 9
    .byte $C0, $08
    ; literal count 3; subsequent asset bytes excluded
    .byte $02

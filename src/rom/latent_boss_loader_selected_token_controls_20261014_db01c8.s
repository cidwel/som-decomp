; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $01C8
boss_lz_controls_db01c8:
    ; backreference count 3, distance 33
    .byte $80, $20
    ; backreference count 4, distance 9
    .byte $90, $08
    ; literal count 3; subsequent asset bytes excluded
    .byte $02

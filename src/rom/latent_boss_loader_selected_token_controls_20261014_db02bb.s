; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $02BB
boss_lz_controls_db02bb:
    ; backreference count 4, distance 123
    .byte $90, $7A
    ; backreference count 3, distance 71
    .byte $80, $46
    ; backreference count 3, distance 23
    .byte $80, $16
    ; literal count 3; subsequent asset bytes excluded
    .byte $02

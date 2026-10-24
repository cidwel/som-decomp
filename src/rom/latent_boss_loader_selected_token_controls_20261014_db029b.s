; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $029B
boss_lz_controls_db029b:
    ; backreference count 3, distance 381
    .byte $81, $7C
    ; backreference count 5, distance 523
    .byte $A2, $0A
    ; backreference count 3, distance 161
    .byte $80, $A0
    ; backreference count 3, distance 7
    .byte $80, $06
    ; literal count 3; subsequent asset bytes excluded
    .byte $02

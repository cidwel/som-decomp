; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $02ED
boss_lz_controls_db02ed:
    ; backreference count 4, distance 17
    .byte $90, $10
    ; backreference count 5, distance 18
    .byte $A0, $11
    ; backreference count 5, distance 9
    .byte $A0, $08
    ; backreference count 3, distance 18
    .byte $80, $11
    ; backreference count 5, distance 169
    .byte $A0, $A8
    ; backreference count 9, distance 9
    .byte $E0, $08
    ; backreference count 3, distance 131
    .byte $80, $82
    ; literal count 1; subsequent asset bytes excluded
    .byte $00

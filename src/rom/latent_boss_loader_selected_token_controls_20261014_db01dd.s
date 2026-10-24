; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $01DD
boss_lz_controls_db01dd:
    ; backreference count 5, distance 9
    .byte $A0, $08
    ; backreference count 4, distance 282
    .byte $91, $19
    ; backreference count 4, distance 9
    .byte $90, $08
    ; backreference count 4, distance 281
    .byte $91, $18
    ; backreference count 4, distance 124
    .byte $90, $7B
    ; literal count 1; subsequent asset bytes excluded
    .byte $00

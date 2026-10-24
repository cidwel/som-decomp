; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E290
boss_lz_controls_dae290:
    ; backreference count 3, distance 175
    .byte $80, $AE
    ; backreference count 18, distance 1
    .byte $F8, $00
    ; backreference count 18, distance 1
    .byte $F8, $00
    ; backreference count 12, distance 1
    .byte $C8, $00
    ; literal count 6; subsequent asset bytes excluded
    .byte $05

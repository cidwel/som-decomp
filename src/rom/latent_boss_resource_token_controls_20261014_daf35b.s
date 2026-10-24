; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F35B
boss_lz_controls_daf35b:
    ; backreference count 3, distance 2607
    .byte $8A, $2E
    ; backreference count 10, distance 1
    .byte $F0, $00
    ; backreference count 10, distance 1
    .byte $F0, $00
    ; backreference count 10, distance 1
    .byte $F0, $00
    ; literal count 4; subsequent asset bytes excluded
    .byte $03

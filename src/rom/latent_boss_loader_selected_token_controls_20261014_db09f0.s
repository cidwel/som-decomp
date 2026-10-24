; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $09F0
boss_lz_controls_db09f0:
    ; backreference count 4, distance 2926
    .byte $9B, $6D
    ; backreference count 4, distance 172
    .byte $90, $AB
    ; literal count 1; subsequent asset bytes excluded
    .byte $00

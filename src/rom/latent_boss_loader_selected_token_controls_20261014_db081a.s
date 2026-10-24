; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $081A
boss_lz_controls_db081a:
    ; backreference count 4, distance 367
    .byte $91, $6E
    ; backreference count 4, distance 2220
    .byte $98, $AB
    ; backreference count 6, distance 171
    .byte $B0, $AA
    ; literal count 1; subsequent asset bytes excluded
    .byte $00

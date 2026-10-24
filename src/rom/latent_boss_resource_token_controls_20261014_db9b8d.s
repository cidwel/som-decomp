; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $9B8D
boss_lz_controls_db9b8d:
    ; backreference count 18, distance 1
    .byte $F8, $00
    ; backreference count 6, distance 1
    .byte $98, $00
    ; literal count 62; subsequent asset bytes excluded
    .byte $3D

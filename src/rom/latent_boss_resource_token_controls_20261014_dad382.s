; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D382
boss_lz_controls_dad382:
    ; backreference count 6, distance 64
    .byte $98, $3F
    ; literal count 1; subsequent asset bytes excluded
    .byte $00

; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $080C
boss_lz_controls_db080c:
    ; backreference count 5, distance 2199
    .byte $A8, $96
    ; backreference count 6, distance 1378
    .byte $B5, $61
    ; literal count 1; subsequent asset bytes excluded
    .byte $00

; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $90AA
boss_lz_controls_db90aa:
    ; backreference count 6, distance 1
    .byte $B0, $00
    ; literal count 40; subsequent asset bytes excluded
    .byte $27

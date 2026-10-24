; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $063B
boss_lz_controls_db063b:
    ; backreference count 6, distance 1412
    .byte $B5, $83
    ; literal count 1; subsequent asset bytes excluded
    .byte $00

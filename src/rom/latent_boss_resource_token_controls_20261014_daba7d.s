; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BA7D
boss_lz_controls_daba7d:
    ; backreference count 8, distance 54
    .byte $94, $35
    ; literal count 1; subsequent asset bytes excluded
    .byte $00

; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E06C
boss_lz_controls_dae06c:
    ; backreference count 3, distance 45
    .byte $80, $2C
    ; literal count 9; subsequent asset bytes excluded
    .byte $08

; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E1C2
boss_lz_controls_dae1c2:
    ; backreference count 3, distance 265
    .byte $81, $08
    ; literal count 10; subsequent asset bytes excluded
    .byte $09

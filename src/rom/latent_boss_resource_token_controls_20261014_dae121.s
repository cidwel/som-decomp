; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E121
boss_lz_controls_dae121:
    ; backreference count 3, distance 9
    .byte $80, $08
    ; literal count 15; subsequent asset bytes excluded
    .byte $0E

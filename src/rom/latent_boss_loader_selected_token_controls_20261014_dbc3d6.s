; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C3D6
boss_lz_controls_dbc3d6:
    ; backreference count 3, distance 208
    .byte $80, $CF
    ; literal count 10; subsequent asset bytes excluded
    .byte $09

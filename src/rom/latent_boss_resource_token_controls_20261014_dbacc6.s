; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $ACC6
boss_lz_controls_dbacc6:
    ; backreference count 3, distance 132
    .byte $80, $83
    ; literal count 85; subsequent asset bytes excluded
    .byte $54

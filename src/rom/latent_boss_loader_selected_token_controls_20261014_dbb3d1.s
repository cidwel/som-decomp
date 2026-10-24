; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B3D1
boss_lz_controls_dbb3d1:
    ; backreference count 3, distance 127
    .byte $80, $7E
    ; literal count 19; subsequent asset bytes excluded
    .byte $12

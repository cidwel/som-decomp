; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A3D0
boss_lz_controls_dba3d0:
    ; backreference count 4, distance 1330
    .byte $8D, $31
    ; literal count 2; subsequent asset bytes excluded
    .byte $01

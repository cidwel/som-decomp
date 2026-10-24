; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CE3D
boss_lz_controls_dbce3d:
    ; backreference count 3, distance 15
    .byte $80, $0E
    ; literal count 52; subsequent asset bytes excluded
    .byte $33

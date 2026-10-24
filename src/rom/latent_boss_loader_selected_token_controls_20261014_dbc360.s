; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C360
boss_lz_controls_dbc360:
    ; backreference count 3, distance 1401
    .byte $85, $78
    ; literal count 62; subsequent asset bytes excluded
    .byte $3D

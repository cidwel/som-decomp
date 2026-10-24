; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $9D99
boss_lz_controls_db9d99:
    ; backreference count 3, distance 209
    .byte $80, $D0
    ; literal count 62; subsequent asset bytes excluded
    .byte $3D

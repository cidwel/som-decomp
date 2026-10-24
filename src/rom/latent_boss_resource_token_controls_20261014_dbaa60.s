; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $AA60
boss_lz_controls_dbaa60:
    ; backreference count 3, distance 318
    .byte $81, $3D
    ; literal count 2; subsequent asset bytes excluded
    .byte $01

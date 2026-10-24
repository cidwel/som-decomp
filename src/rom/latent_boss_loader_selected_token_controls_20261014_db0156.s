; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0156
boss_lz_controls_db0156:
    ; backreference count 3, distance 14
    .byte $80, $0D
    ; backreference count 3, distance 62
    .byte $80, $3D
    ; literal count 12; subsequent asset bytes excluded
    .byte $0B

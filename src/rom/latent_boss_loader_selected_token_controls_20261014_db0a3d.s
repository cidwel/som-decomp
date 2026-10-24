; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0A3D
boss_lz_controls_db0a3d:
    ; backreference count 4, distance 56
    .byte $90, $37
    ; backreference count 10, distance 2830
    .byte $FB, $0D
    ; backreference count 4, distance 1427
    .byte $95, $92
    ; literal count 1; subsequent asset bytes excluded
    .byte $00

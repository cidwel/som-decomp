; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0065
boss_lz_controls_db0065:
    ; backreference count 4, distance 6
    .byte $90, $05
    ; literal count 6; subsequent asset bytes excluded
    .byte $05

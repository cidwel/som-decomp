; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0167
boss_lz_controls_db0167:
    ; backreference count 3, distance 16
    .byte $80, $0F
    ; literal count 2; subsequent asset bytes excluded
    .byte $01

; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $AF86
boss_lz_controls_dbaf86:
    ; backreference count 3, distance 137
    .byte $80, $88
    ; literal count 16; subsequent asset bytes excluded
    .byte $0F

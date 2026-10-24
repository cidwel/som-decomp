; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $95E8
boss_lz_controls_db95e8:
    ; backreference count 3, distance 202
    .byte $80, $C9
    ; literal count 22; subsequent asset bytes excluded
    .byte $15

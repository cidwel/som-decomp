; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B863
boss_lz_controls_dab863:
    ; backreference count 3, distance 58
    .byte $80, $39
    ; literal count 16; subsequent asset bytes excluded
    .byte $0F

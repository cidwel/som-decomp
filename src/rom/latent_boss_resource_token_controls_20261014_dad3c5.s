; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D3C5
boss_lz_controls_dad3c5:
    ; backreference count 3, distance 17
    .byte $80, $10
    ; literal count 13; subsequent asset bytes excluded
    .byte $0C

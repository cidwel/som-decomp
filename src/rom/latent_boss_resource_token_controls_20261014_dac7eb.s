; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C7EB
boss_lz_controls_dac7eb:
    ; backreference count 3, distance 1010
    .byte $83, $F1
    ; literal count 12; subsequent asset bytes excluded
    .byte $0B

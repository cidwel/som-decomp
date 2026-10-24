; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D6A1
boss_lz_controls_dad6a1:
    ; backreference count 3, distance 11
    .byte $80, $0A
    ; literal count 12; subsequent asset bytes excluded
    .byte $0B

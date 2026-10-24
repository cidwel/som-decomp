; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D55F
boss_lz_controls_dad55f:
    ; backreference count 4, distance 875
    .byte $8B, $6A
    ; literal count 12; subsequent asset bytes excluded
    .byte $0B

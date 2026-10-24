; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D9CF
boss_lz_controls_dad9cf:
    ; backreference count 3, distance 51
    .byte $80, $32
    ; literal count 13; subsequent asset bytes excluded
    .byte $0C

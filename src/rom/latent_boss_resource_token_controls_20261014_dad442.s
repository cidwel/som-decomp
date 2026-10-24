; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D442
boss_lz_controls_dad442:
    ; backreference count 3, distance 13
    .byte $80, $0C
    ; literal count 12; subsequent asset bytes excluded
    .byte $0B

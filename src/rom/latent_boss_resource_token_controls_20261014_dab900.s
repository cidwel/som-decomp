; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B900
boss_lz_controls_dab900:
    ; backreference count 3, distance 55
    .byte $80, $36
    ; literal count 4; subsequent asset bytes excluded
    .byte $03

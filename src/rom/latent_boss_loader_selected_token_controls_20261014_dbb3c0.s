; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B3C0
boss_lz_controls_dbb3c0:
    ; backreference count 3, distance 55
    .byte $80, $36
    ; literal count 14; subsequent asset bytes excluded
    .byte $0D

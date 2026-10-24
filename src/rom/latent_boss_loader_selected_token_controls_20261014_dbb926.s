; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B926
boss_lz_controls_dbb926:
    ; backreference count 3, distance 12
    .byte $80, $0B
    ; literal count 17; subsequent asset bytes excluded
    .byte $10

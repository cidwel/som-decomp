; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $DE27
boss_lz_controls_dade27:
    ; backreference count 3, distance 81
    .byte $80, $50
    ; literal count 101; subsequent asset bytes excluded
    .byte $64

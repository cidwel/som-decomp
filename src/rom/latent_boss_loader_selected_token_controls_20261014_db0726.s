; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0726
boss_lz_controls_db0726:
    ; backreference count 6, distance 40
    .byte $B0, $27
    ; literal count 2; subsequent asset bytes excluded
    .byte $01

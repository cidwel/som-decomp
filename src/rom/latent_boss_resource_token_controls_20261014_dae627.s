; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E627
boss_lz_controls_dae627:
    ; backreference count 3, distance 17
    .byte $80, $10
    ; literal count 12; subsequent asset bytes excluded
    .byte $0B

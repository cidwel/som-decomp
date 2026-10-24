; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E15D
boss_lz_controls_dae15d:
    ; backreference count 3, distance 415
    .byte $81, $9E
    ; literal count 13; subsequent asset bytes excluded
    .byte $0C

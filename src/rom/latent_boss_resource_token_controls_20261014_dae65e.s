; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E65E
boss_lz_controls_dae65e:
    ; backreference count 3, distance 11
    .byte $80, $0A
    ; literal count 62; subsequent asset bytes excluded
    .byte $3D

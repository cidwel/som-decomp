; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $AD1E
boss_lz_controls_dbad1e:
    ; backreference count 3, distance 36
    .byte $80, $23
    ; literal count 10; subsequent asset bytes excluded
    .byte $09

; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $91A7
boss_lz_controls_db91a7:
    ; backreference count 3, distance 279
    .byte $81, $16
    ; backreference count 3, distance 517
    .byte $82, $04
    ; literal count 9; subsequent asset bytes excluded
    .byte $08

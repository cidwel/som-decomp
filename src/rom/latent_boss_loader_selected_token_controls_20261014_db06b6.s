; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $06B6
boss_lz_controls_db06b6:
    ; backreference count 4, distance 1635
    .byte $96, $62
    ; backreference count 3, distance 370
    .byte $81, $71
    ; backreference count 4, distance 1571
    .byte $96, $22
    ; backreference count 3, distance 475
    .byte $81, $DA
    ; backreference count 3, distance 351
    .byte $81, $5E
    ; literal count 1; subsequent asset bytes excluded
    .byte $00

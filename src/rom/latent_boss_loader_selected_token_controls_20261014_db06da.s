; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $06DA
boss_lz_controls_db06da:
    ; backreference count 5, distance 997
    .byte $A3, $E4
    ; backreference count 5, distance 1416
    .byte $A5, $87
    ; literal count 2; subsequent asset bytes excluded
    .byte $01

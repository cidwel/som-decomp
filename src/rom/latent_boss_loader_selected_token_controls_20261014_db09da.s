; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $09DA
boss_lz_controls_db09da:
    ; backreference count 8, distance 2754
    .byte $DA, $C1
    ; backreference count 5, distance 334
    .byte $A1, $4D
    ; backreference count 7, distance 1348
    .byte $C5, $43
    ; backreference count 4, distance 907
    .byte $93, $8A
    ; backreference count 3, distance 3681
    .byte $8E, $60
    ; backreference count 4, distance 9
    .byte $90, $08
    ; literal count 1; subsequent asset bytes excluded
    .byte $00

; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $069F
boss_lz_controls_db069f:
    ; backreference count 5, distance 9
    .byte $A0, $08
    ; backreference count 5, distance 1137
    .byte $A4, $70
    ; backreference count 3, distance 1565
    .byte $86, $1C
    ; backreference count 6, distance 751
    .byte $B2, $EE
    ; backreference count 7, distance 772
    .byte $C3, $03
    ; literal count 1; subsequent asset bytes excluded
    .byte $00

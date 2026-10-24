; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0452
boss_lz_controls_db0452:
    ; backreference count 4, distance 752
    .byte $92, $EF
    ; backreference count 3, distance 480
    .byte $81, $DF
    ; backreference count 3, distance 89
    .byte $80, $58
    ; backreference count 5, distance 10
    .byte $A0, $09
    ; backreference count 7, distance 105
    .byte $C0, $68
    ; literal count 2; subsequent asset bytes excluded
    .byte $01

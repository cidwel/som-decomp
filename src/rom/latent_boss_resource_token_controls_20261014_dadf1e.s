; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $DF1E
boss_lz_controls_dadf1e:
    ; backreference count 3, distance 690
    .byte $82, $B1
    ; backreference count 7, distance 147
    .byte $A0, $92
    ; backreference count 3, distance 695
    .byte $82, $B6
    ; literal count 2; subsequent asset bytes excluded
    .byte $01

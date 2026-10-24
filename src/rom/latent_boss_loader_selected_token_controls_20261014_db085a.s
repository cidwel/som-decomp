; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $085A
boss_lz_controls_db085a:
    ; backreference count 3, distance 781
    .byte $83, $0C
    ; backreference count 4, distance 1332
    .byte $95, $33
    ; backreference count 4, distance 3015
    .byte $9B, $C6
    ; literal count 1; subsequent asset bytes excluded
    .byte $00

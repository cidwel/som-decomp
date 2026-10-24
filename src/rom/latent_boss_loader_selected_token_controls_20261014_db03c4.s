; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $03C4
boss_lz_controls_db03c4:
    ; backreference count 5, distance 65
    .byte $A0, $40
    ; backreference count 4, distance 840
    .byte $93, $47
    ; backreference count 6, distance 17
    .byte $B0, $10
    ; backreference count 6, distance 16
    .byte $B0, $0F
    ; literal count 1; subsequent asset bytes excluded
    .byte $00

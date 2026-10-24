; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $05CF
boss_lz_controls_db05cf:
    ; backreference count 5, distance 704
    .byte $A2, $BF
    ; backreference count 4, distance 328
    .byte $91, $47
    ; backreference count 3, distance 918
    .byte $83, $95
    ; backreference count 6, distance 450
    .byte $B1, $C1
    ; literal count 2; subsequent asset bytes excluded
    .byte $01

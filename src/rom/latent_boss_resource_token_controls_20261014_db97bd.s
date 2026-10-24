; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $97BD
boss_lz_controls_db97bd:
    ; backreference count 3, distance 456
    .byte $81, $C7
    ; backreference count 4, distance 596
    .byte $92, $53
    ; literal count 11; subsequent asset bytes excluded
    .byte $0A

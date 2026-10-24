; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0970
boss_lz_controls_db0970:
    ; backreference count 6, distance 876
    .byte $B3, $6B
    ; backreference count 4, distance 940
    .byte $93, $AB
    ; literal count 1; subsequent asset bytes excluded
    .byte $00

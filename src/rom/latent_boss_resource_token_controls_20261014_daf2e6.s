; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F2E6
boss_lz_controls_daf2e6:
    ; backreference count 4, distance 1379
    .byte $95, $62
    ; backreference count 3, distance 809
    .byte $83, $28
    ; literal count 2; subsequent asset bytes excluded
    .byte $01

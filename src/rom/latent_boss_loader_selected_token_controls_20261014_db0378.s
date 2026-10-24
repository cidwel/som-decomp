; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0378
boss_lz_controls_db0378:
    ; backreference count 4, distance 39
    .byte $90, $26
    ; backreference count 4, distance 763
    .byte $92, $FA
    ; backreference count 4, distance 187
    .byte $90, $BA
    ; backreference count 3, distance 982
    .byte $83, $D5
    ; literal count 2; subsequent asset bytes excluded
    .byte $01

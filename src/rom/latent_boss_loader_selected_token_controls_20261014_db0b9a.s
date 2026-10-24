; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0B9A
boss_lz_controls_db0b9a:
    ; backreference count 4, distance 2114
    .byte $98, $41
    ; backreference count 3, distance 2479
    .byte $89, $AE
    ; backreference count 3, distance 291
    .byte $81, $22
    ; literal count 2; subsequent asset bytes excluded
    .byte $01

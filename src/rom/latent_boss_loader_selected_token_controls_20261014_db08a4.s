; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $08A4
boss_lz_controls_db08a4:
    ; backreference count 4, distance 11
    .byte $90, $0A
    ; backreference count 4, distance 142
    .byte $90, $8D
    ; backreference count 3, distance 2697
    .byte $8A, $88
    ; backreference count 4, distance 1372
    .byte $95, $5B
    ; backreference count 4, distance 2731
    .byte $9A, $AA
    ; backreference count 4, distance 680
    .byte $92, $A7
    ; backreference count 4, distance 2642
    .byte $9A, $51
    ; backreference count 3, distance 2669
    .byte $8A, $6C
    ; backreference count 4, distance 2775
    .byte $9A, $D6
    ; backreference count 4, distance 1291
    .byte $95, $0A
    ; literal count 1; subsequent asset bytes excluded
    .byte $00

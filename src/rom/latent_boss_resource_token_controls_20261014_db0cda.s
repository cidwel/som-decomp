; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0CDA
boss_lz_controls_db0cda:
    ; backreference count 59, distance 256
    .byte $F0, $FF
    ; backreference count 62, distance 247
    .byte $F6, $F6
    ; backreference count 66, distance 255
    .byte $FE, $FE
    ; literal count 61; subsequent asset bytes excluded
    .byte $3C

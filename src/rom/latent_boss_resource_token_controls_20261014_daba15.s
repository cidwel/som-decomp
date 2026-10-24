; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BA15
boss_lz_controls_daba15:
    ; backreference count 4, distance 395
    .byte $85, $8A
    ; backreference count 3, distance 288
    .byte $81, $1F
    ; literal count 34; subsequent asset bytes excluded
    .byte $21

; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $044A
boss_lz_controls_db044a:
    ; backreference count 4, distance 1339
    .byte $95, $3A
    ; backreference count 7, distance 33
    .byte $C0, $20
    ; backreference count 3, distance 229
    .byte $80, $E4
    ; literal count 1; subsequent asset bytes excluded
    .byte $00

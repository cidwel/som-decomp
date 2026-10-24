; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C2FA
boss_lz_controls_dbc2fa:
    ; backreference count 3, distance 270
    .byte $81, $0D
    ; backreference count 4, distance 78
    .byte $88, $4D
    ; literal count 12; subsequent asset bytes excluded
    .byte $0B

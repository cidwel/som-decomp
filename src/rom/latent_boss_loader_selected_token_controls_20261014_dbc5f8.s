; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C5F8
boss_lz_controls_dbc5f8:
    ; backreference count 3, distance 416
    .byte $81, $9F
    ; literal count 11; subsequent asset bytes excluded
    .byte $0A

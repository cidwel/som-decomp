; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C17A
boss_lz_controls_dbc17a:
    ; backreference count 3, distance 16
    .byte $80, $0F
    ; literal count 5; subsequent asset bytes excluded
    .byte $04

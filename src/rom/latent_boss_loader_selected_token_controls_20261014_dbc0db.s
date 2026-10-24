; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C0DB
boss_lz_controls_dbc0db:
    ; backreference count 3, distance 829
    .byte $83, $3C
    ; literal count 13; subsequent asset bytes excluded
    .byte $0C

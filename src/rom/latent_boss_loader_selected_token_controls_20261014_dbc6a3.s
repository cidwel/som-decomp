; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C6A3
boss_lz_controls_dbc6a3:
    ; backreference count 4, distance 66
    .byte $90, $41
    ; literal count 128; subsequent asset bytes excluded
    .byte $7F

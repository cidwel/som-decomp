; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C84B
boss_lz_controls_dbc84b:
    ; backreference count 3, distance 317
    .byte $81, $3C
    ; literal count 15; subsequent asset bytes excluded
    .byte $0E

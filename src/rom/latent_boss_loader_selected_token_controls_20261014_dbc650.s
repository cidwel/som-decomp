; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C650
boss_lz_controls_dbc650:
    ; backreference count 3, distance 1
    .byte $80, $00
    ; literal count 41; subsequent asset bytes excluded
    .byte $28

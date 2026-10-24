; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CF92
boss_lz_controls_dacf92:
    ; backreference count 5, distance 14
    .byte $90, $0D
    ; literal count 17; subsequent asset bytes excluded
    .byte $10

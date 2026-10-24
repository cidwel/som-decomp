; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $94AC
boss_lz_controls_db94ac:
    ; backreference count 4, distance 15
    .byte $90, $0E
    ; literal count 16; subsequent asset bytes excluded
    .byte $0F

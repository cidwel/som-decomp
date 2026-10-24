; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $EC43
boss_lz_controls_daec43:
    ; backreference count 4, distance 98
    .byte $90, $61
    ; literal count 12; subsequent asset bytes excluded
    .byte $0B

; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $00E8
boss_lz_controls_db00e8:
    ; backreference count 4, distance 5
    .byte $90, $04
    ; literal count 5; subsequent asset bytes excluded
    .byte $04

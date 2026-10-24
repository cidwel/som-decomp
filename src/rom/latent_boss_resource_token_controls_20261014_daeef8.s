; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $EEF8
boss_lz_controls_daeef8:
    ; backreference count 3, distance 1820
    .byte $87, $1B
    ; literal count 23; subsequent asset bytes excluded
    .byte $16

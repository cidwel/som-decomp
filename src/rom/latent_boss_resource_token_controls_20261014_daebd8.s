; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $EBD8
boss_lz_controls_daebd8:
    ; backreference count 4, distance 5
    .byte $90, $04
    ; literal count 12; subsequent asset bytes excluded
    .byte $0B

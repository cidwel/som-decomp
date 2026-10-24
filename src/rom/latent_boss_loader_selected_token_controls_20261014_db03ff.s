; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $03FF
boss_lz_controls_db03ff:
    ; backreference count 4, distance 88
    .byte $90, $57
    ; literal count 4; subsequent asset bytes excluded
    .byte $03

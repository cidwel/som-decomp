; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $93AA
boss_lz_controls_db93aa:
    ; backreference count 4, distance 64
    .byte $90, $3F
    ; literal count 4; subsequent asset bytes excluded
    .byte $03

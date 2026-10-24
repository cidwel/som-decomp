; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0822
boss_lz_controls_db0822:
    ; backreference count 7, distance 2190
    .byte $C8, $8D
    ; backreference count 4, distance 55
    .byte $90, $36
    ; literal count 4; subsequent asset bytes excluded
    .byte $03

; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0582
boss_lz_controls_db0582:
    ; backreference count 4, distance 48
    .byte $90, $2F
    ; backreference count 3, distance 9
    .byte $80, $08
    ; literal count 2; subsequent asset bytes excluded
    .byte $01

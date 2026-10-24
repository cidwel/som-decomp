; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $93EE
boss_lz_controls_db93ee:
    ; backreference count 3, distance 16
    .byte $80, $0F
    ; literal count 13; subsequent asset bytes excluded
    .byte $0C

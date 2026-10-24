; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0121
boss_lz_controls_db0121:
    ; backreference count 3, distance 51
    .byte $80, $32
    ; literal count 4; subsequent asset bytes excluded
    .byte $03

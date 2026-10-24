; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $9762
boss_lz_controls_db9762:
    ; backreference count 3, distance 90
    .byte $80, $59
    ; literal count 11; subsequent asset bytes excluded
    .byte $0A

; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $9F89
boss_lz_controls_db9f89:
    ; backreference count 3, distance 38
    .byte $80, $25
    ; literal count 5; subsequent asset bytes excluded
    .byte $04

; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $018B
boss_lz_controls_db018b:
    ; backreference count 3, distance 276
    .byte $81, $13
    ; backreference count 3, distance 231
    .byte $80, $E6
    ; literal count 5; subsequent asset bytes excluded
    .byte $04

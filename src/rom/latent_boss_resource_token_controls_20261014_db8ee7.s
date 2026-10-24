; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $8EE7
boss_lz_controls_db8ee7:
    ; backreference count 3, distance 25
    .byte $80, $18
    ; literal count 44; subsequent asset bytes excluded
    .byte $2B

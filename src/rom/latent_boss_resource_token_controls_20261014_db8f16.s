; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $8F16
boss_lz_controls_db8f16:
    ; backreference count 3, distance 98
    .byte $80, $61
    ; literal count 45; subsequent asset bytes excluded
    .byte $2C

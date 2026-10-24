; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BD18
boss_lz_controls_dbbd18:
    ; backreference count 3, distance 54
    .byte $80, $35
    ; literal count 91; subsequent asset bytes excluded
    .byte $5A

; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CB72
boss_lz_controls_dbcb72:
    ; backreference count 4, distance 1344
    .byte $95, $3F
    ; literal count 96; subsequent asset bytes excluded
    .byte $5F

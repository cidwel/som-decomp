; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CEDA
boss_lz_controls_dbceda:
    ; backreference count 3, distance 2103
    .byte $88, $36
    ; literal count 11; subsequent asset bytes excluded
    .byte $0A

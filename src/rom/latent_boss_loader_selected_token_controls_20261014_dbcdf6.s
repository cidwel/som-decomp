; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CDF6
boss_lz_controls_dbcdf6:
    ; backreference count 3, distance 113
    .byte $80, $70
    ; literal count 10; subsequent asset bytes excluded
    .byte $09

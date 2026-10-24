; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $AF10
boss_lz_controls_dbaf10:
    ; backreference count 4, distance 55
    .byte $84, $36
    ; literal count 66; subsequent asset bytes excluded
    .byte $41

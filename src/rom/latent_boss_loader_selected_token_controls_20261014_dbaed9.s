; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $AED9
boss_lz_controls_dbaed9:
    ; backreference count 3, distance 90
    .byte $80, $59
    ; literal count 20; subsequent asset bytes excluded
    .byte $13

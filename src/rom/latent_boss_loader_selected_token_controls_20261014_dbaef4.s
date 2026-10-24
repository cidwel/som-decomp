; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $AEF4
boss_lz_controls_dbaef4:
    ; backreference count 4, distance 27
    .byte $84, $1A
    ; backreference count 3, distance 55
    .byte $80, $36
    ; literal count 5; subsequent asset bytes excluded
    .byte $04

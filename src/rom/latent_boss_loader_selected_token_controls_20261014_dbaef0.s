; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $AEF0
boss_lz_controls_dbaef0:
    ; backreference count 3, distance 5
    .byte $80, $04
    ; literal count 1; subsequent asset bytes excluded
    .byte $00

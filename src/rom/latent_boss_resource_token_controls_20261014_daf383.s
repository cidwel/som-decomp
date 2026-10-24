; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F383
boss_lz_controls_daf383:
    ; backreference count 3, distance 563
    .byte $82, $32
    ; backreference count 4, distance 3747
    .byte $9E, $A2
    ; literal count 6; subsequent asset bytes excluded
    .byte $05

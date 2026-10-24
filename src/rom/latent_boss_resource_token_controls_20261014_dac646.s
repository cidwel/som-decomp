; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C646
boss_lz_controls_dac646:
    ; backreference count 3, distance 5
    .byte $80, $04
    ; literal count 51; subsequent asset bytes excluded
    .byte $32

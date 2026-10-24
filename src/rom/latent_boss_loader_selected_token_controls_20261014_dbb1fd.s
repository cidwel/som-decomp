; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B1FD
boss_lz_controls_dbb1fd:
    ; backreference count 3, distance 1016
    .byte $83, $F7
    ; literal count 12; subsequent asset bytes excluded
    .byte $0B

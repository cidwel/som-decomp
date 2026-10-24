; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C1FD
boss_lz_controls_dbc1fd:
    ; backreference count 3, distance 75
    .byte $80, $4A
    ; literal count 21; subsequent asset bytes excluded
    .byte $14

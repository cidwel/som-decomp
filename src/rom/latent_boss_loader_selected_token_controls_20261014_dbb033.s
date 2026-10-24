; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B033
boss_lz_controls_dbb033:
    ; backreference count 3, distance 120
    .byte $80, $77
    ; literal count 6; subsequent asset bytes excluded
    .byte $05

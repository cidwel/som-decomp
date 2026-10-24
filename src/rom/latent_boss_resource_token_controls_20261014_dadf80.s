; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $DF80
boss_lz_controls_dadf80:
    ; backreference count 5, distance 221
    .byte $90, $DC
    ; literal count 31; subsequent asset bytes excluded
    .byte $1E

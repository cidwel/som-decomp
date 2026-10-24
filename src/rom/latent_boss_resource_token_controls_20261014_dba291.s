; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A291
boss_lz_controls_dba291:
    ; backreference count 4, distance 1280
    .byte $8C, $FF
    ; literal count 6; subsequent asset bytes excluded
    .byte $05

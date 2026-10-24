; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $ECDB
boss_lz_controls_daecdb:
    ; backreference count 4, distance 1357
    .byte $95, $4C
    ; literal count 4; subsequent asset bytes excluded
    .byte $03

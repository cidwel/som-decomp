; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A256
boss_lz_controls_dba256:
    ; backreference count 16, distance 1007
    .byte $EB, $EE
    ; literal count 12; subsequent asset bytes excluded
    .byte $0B

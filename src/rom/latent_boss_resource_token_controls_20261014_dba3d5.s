; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A3D5
boss_lz_controls_dba3d5:
    ; backreference count 4, distance 52
    .byte $88, $33
    ; literal count 5; subsequent asset bytes excluded
    .byte $04

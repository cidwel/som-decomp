; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A3E5
boss_lz_controls_dba3e5:
    ; backreference count 6, distance 51
    .byte $98, $32
    ; literal count 11; subsequent asset bytes excluded
    .byte $0A

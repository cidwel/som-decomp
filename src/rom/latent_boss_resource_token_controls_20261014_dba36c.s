; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A36C
boss_lz_controls_dba36c:
    ; backreference count 3, distance 1100
    .byte $84, $4B
    ; literal count 16; subsequent asset bytes excluded
    .byte $0F

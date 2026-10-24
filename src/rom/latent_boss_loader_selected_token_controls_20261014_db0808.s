; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0808
boss_lz_controls_db0808:
    ; backreference count 4, distance 109
    .byte $90, $6C
    ; literal count 1; subsequent asset bytes excluded
    .byte $00

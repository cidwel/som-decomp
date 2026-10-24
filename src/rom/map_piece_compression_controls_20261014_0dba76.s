.setcpu "65816"
.segment "CODE"
.org $BA76
map_control_0dba76:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance

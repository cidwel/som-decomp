.setcpu "65816"
.segment "CODE"
.org $1BB0
map_control_0d1bb0:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C6 ; same-value copy count/distance

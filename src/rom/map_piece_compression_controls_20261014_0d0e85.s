.setcpu "65816"
.segment "CODE"
.org $0E85
map_control_0d0e85:
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C6 ; same-value copy count/distance

.setcpu "65816"
.segment "CODE"
.org $F677
map_control_0df677:
    .byte $D7 ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count

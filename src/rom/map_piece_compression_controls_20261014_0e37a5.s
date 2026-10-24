.setcpu "65816"
.segment "CODE"
.org $37A5
map_control_0e37a5:
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance

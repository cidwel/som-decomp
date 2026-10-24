.setcpu "65816"
.segment "CODE"
.org $D968
map_control_0fd968:
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $D9 ; same-value copy count/distance

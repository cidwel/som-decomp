.setcpu "65816"
.segment "CODE"
.org $C637
map_control_0fc637:
    .byte $D2 ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count

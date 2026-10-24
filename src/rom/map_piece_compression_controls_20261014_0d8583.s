.setcpu "65816"
.segment "CODE"
.org $8583
map_control_0d8583:
    .byte $CB ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $AB55
map_control_0eab55:
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance

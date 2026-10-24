.setcpu "65816"
.segment "CODE"
.org $0BA7
map_control_0f0ba7:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $CB ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count

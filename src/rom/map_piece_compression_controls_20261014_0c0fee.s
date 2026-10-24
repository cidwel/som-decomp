.setcpu "65816"
.segment "CODE"
.org $0FEE
map_control_0c0fee:
    .byte $D1 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count

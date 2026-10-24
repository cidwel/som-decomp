.setcpu "65816"
.segment "CODE"
.org $0D75
map_control_0e0d75:
    .byte $C2 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $A4E8
map_control_0fa4e8:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $CE ; same-value copy count/distance

.setcpu "65816"
.segment "CODE"
.org $A944
map_control_0fa944:
    .byte $CD ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count

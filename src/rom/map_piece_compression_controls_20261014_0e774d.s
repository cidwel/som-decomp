.setcpu "65816"
.segment "CODE"
.org $774D
map_control_0e774d:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance

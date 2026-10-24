.setcpu "65816"
.segment "CODE"
.org $8C87
map_control_0d8c87:
    .byte $C2 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count

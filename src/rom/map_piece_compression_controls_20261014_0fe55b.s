.setcpu "65816"
.segment "CODE"
.org $E55B
map_control_0fe55b:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance

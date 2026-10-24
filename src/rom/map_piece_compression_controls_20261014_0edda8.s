.setcpu "65816"
.segment "CODE"
.org $DDA8
map_control_0edda8:
    .byte $C2 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count

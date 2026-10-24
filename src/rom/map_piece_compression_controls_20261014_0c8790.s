.setcpu "65816"
.segment "CODE"
.org $8790
map_control_0c8790:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance

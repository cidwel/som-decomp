.setcpu "65816"
.segment "CODE"
.org $D412
map_control_0fd412:
    .byte $C7 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count

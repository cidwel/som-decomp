.setcpu "65816"
.segment "CODE"
.org $E91F
map_control_0fe91f:
    .byte $C2 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C7 ; same-value copy count/distance

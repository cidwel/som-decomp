.setcpu "65816"
.segment "CODE"
.org $48C1
map_control_0d48c1:
    .byte $C2 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count

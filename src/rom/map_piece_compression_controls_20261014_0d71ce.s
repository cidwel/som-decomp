.setcpu "65816"
.segment "CODE"
.org $71CE
map_control_0d71ce:
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance

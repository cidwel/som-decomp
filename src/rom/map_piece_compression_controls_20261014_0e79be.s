.setcpu "65816"
.segment "CODE"
.org $79BE
map_control_0e79be:
    .byte $E9 ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance

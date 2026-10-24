.setcpu "65816"
.segment "CODE"
.org $329D
map_control_0f329d:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count

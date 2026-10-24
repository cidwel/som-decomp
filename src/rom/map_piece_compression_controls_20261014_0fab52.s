.setcpu "65816"
.segment "CODE"
.org $AB52
map_control_0fab52:
    .byte $C1 ; same-value copy count/distance
    .byte $E5 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count

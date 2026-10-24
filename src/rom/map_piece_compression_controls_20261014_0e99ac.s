.setcpu "65816"
.segment "CODE"
.org $99AC
map_control_0e99ac:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E1 ; previous-row copy count

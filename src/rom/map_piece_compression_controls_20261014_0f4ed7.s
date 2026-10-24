.setcpu "65816"
.segment "CODE"
.org $4ED7
map_control_0f4ed7:
    .byte $E7 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count

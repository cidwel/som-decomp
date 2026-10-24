.setcpu "65816"
.segment "CODE"
.org $3F86
map_control_0c3f86:
    .byte $E1 ; previous-row copy count
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $7E4D
map_control_0d7e4d:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E1 ; previous-row copy count

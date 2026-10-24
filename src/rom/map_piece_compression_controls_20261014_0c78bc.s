.setcpu "65816"
.segment "CODE"
.org $78BC
map_control_0c78bc:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E3 ; previous-row copy count

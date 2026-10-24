.setcpu "65816"
.segment "CODE"
.org $27D4
map_control_0e27d4:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E7 ; previous-row copy count

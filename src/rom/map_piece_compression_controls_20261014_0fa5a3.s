.setcpu "65816"
.segment "CODE"
.org $A5A3
map_control_0fa5a3:
    .byte $E1 ; previous-row copy count
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count

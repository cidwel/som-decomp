.setcpu "65816"
.segment "CODE"
.org $A4A5
map_control_0ea4a5:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E1 ; previous-row copy count

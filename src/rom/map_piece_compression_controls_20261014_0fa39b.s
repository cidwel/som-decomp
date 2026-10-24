.setcpu "65816"
.segment "CODE"
.org $A39B
map_control_0fa39b:
    .byte $E2 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E2 ; previous-row copy count

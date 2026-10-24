.setcpu "65816"
.segment "CODE"
.org $43E2
map_control_0c43e2:
    .byte $E2 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count

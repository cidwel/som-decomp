.setcpu "65816"
.segment "CODE"
.org $3B7C
map_control_0e3b7c:
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E2 ; previous-row copy count

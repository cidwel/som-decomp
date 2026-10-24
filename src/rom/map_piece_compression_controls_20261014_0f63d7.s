.setcpu "65816"
.segment "CODE"
.org $63D7
map_control_0f63d7:
    .byte $E1 ; previous-row copy count
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count

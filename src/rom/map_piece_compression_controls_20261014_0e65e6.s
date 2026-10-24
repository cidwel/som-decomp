.setcpu "65816"
.segment "CODE"
.org $65E6
map_control_0e65e6:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E3 ; previous-row copy count

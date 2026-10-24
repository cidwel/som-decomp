.setcpu "65816"
.segment "CODE"
.org $27DA
map_control_0e27da:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E4 ; previous-row copy count

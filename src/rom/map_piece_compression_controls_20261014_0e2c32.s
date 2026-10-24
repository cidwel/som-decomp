.setcpu "65816"
.segment "CODE"
.org $2C32
map_control_0e2c32:
    .byte $E1 ; previous-row copy count
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E1 ; previous-row copy count

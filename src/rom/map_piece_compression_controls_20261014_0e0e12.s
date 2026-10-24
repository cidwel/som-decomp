.setcpu "65816"
.segment "CODE"
.org $0E12
map_control_0e0e12:
    .byte $E1 ; previous-row copy count
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count

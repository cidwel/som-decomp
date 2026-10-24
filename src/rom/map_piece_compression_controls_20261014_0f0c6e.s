.setcpu "65816"
.segment "CODE"
.org $0C6E
map_control_0f0c6e:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E1 ; previous-row copy count

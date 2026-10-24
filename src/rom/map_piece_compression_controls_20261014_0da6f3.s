.setcpu "65816"
.segment "CODE"
.org $A6F3
map_control_0da6f3:
    .byte $E5 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E7 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $84 ; distance low bit/count

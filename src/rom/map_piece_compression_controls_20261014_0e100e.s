.setcpu "65816"
.segment "CODE"
.org $100E
map_control_0e100e:
    .byte $ED ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count

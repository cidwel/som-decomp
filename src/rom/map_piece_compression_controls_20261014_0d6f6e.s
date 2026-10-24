.setcpu "65816"
.segment "CODE"
.org $6F6E
map_control_0d6f6e:
    .byte $E7 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count

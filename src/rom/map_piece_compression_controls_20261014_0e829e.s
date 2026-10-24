.setcpu "65816"
.segment "CODE"
.org $829E
map_control_0e829e:
    .byte $E1 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count

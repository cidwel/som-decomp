.setcpu "65816"
.segment "CODE"
.org $E761
map_control_0ee761:
    .byte $E1 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count

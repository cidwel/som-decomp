.setcpu "65816"
.segment "CODE"
.org $D8C9
map_control_0fd8c9:
    .byte $E6 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $4A ; row-distance/count

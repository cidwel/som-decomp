.setcpu "65816"
.segment "CODE"
.org $D692
map_control_0fd692:
    .byte $EA ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $E3 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $9D ; row-distance/count

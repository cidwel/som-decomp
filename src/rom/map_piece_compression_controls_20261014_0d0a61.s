.setcpu "65816"
.segment "CODE"
.org $0A61
map_control_0d0a61:
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $E4 ; previous-row copy count

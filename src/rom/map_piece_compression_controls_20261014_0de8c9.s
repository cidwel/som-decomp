.setcpu "65816"
.segment "CODE"
.org $E8C9
map_control_0de8c9:
    .byte $E8 ; backreference distance high bits
    .byte $13 ; distance low bit/count
    .byte $E6 ; previous-row copy count

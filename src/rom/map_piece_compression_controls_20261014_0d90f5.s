.setcpu "65816"
.segment "CODE"
.org $90F5
map_control_0d90f5:
    .byte $E2 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count

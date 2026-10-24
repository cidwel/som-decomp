.setcpu "65816"
.segment "CODE"
.org $2430
map_control_0e2430:
    .byte $E4 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count

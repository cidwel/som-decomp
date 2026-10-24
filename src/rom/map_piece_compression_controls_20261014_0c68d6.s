.setcpu "65816"
.segment "CODE"
.org $68D6
map_control_0c68d6:
    .byte $E2 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count

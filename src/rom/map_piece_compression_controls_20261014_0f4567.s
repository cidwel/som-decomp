.setcpu "65816"
.segment "CODE"
.org $4567
map_control_0f4567:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $E7 ; previous-row copy count

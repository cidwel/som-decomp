.setcpu "65816"
.segment "CODE"
.org $3F8F
map_control_0f3f8f:
    .byte $E6 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count

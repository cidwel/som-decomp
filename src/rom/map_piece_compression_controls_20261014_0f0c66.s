.setcpu "65816"
.segment "CODE"
.org $0C66
map_control_0f0c66:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E1 ; previous-row copy count

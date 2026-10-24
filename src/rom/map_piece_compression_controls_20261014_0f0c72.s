.setcpu "65816"
.segment "CODE"
.org $0C72
map_control_0f0c72:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E1 ; previous-row copy count

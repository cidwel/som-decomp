.setcpu "65816"
.segment "CODE"
.org $0C4B
map_control_0d0c4b:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E2 ; previous-row copy count

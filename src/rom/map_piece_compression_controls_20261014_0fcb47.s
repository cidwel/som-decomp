.setcpu "65816"
.segment "CODE"
.org $CB47
map_control_0fcb47:
    .byte $E2 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count

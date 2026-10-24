.setcpu "65816"
.segment "CODE"
.org $716C
map_control_0d716c:
    .byte $E3 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count

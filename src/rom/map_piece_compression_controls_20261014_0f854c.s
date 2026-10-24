.setcpu "65816"
.segment "CODE"
.org $854C
map_control_0f854c:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $E2 ; previous-row copy count

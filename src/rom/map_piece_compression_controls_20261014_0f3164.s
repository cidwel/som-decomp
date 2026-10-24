.setcpu "65816"
.segment "CODE"
.org $3164
map_control_0f3164:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $E2 ; previous-row copy count

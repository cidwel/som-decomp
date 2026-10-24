.setcpu "65816"
.segment "CODE"
.org $1EEC
map_control_0f1eec:
    .byte $E6 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $0A ; distance low bit/count

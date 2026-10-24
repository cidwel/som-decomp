.setcpu "65816"
.segment "CODE"
.org $88CD
map_control_0f88cd:
    .byte $E8 ; backreference distance high bits
    .byte $1A ; distance low bit/count
    .byte $E2 ; previous-row copy count

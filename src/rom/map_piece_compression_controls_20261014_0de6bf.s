.setcpu "65816"
.segment "CODE"
.org $E6BF
map_control_0de6bf:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $E4 ; previous-row copy count

.setcpu "65816"
.segment "CODE"
.org $78A5
map_control_0c78a5:
    .byte $E2 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count

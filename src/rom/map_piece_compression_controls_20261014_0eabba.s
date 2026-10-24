.setcpu "65816"
.segment "CODE"
.org $ABBA
map_control_0eabba:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $E6 ; previous-row copy count

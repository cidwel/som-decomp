.setcpu "65816"
.segment "CODE"
.org $BF9C
map_control_0ebf9c:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E5 ; previous-row copy count

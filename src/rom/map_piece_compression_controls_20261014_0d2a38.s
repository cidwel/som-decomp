.setcpu "65816"
.segment "CODE"
.org $2A38
map_control_0d2a38:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E1 ; previous-row copy count

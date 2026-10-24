.setcpu "65816"
.segment "CODE"
.org $B087
map_control_0fb087:
    .byte $E9 ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $E7 ; previous-row copy count

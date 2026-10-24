.setcpu "65816"
.segment "CODE"
.org $2826
map_control_0e2826:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $E1 ; previous-row copy count

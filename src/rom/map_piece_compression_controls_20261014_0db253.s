.setcpu "65816"
.segment "CODE"
.org $B253
map_control_0db253:
    .byte $E4 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count

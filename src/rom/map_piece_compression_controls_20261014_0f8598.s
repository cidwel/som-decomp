.setcpu "65816"
.segment "CODE"
.org $8598
map_control_0f8598:
    .byte $E8 ; backreference distance high bits
    .byte $1B ; distance low bit/count
    .byte $E1 ; previous-row copy count

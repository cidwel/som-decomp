.setcpu "65816"
.segment "CODE"
.org $859C
map_control_0f859c:
    .byte $E8 ; backreference distance high bits
    .byte $1B ; distance low bit/count
    .byte $E1 ; previous-row copy count

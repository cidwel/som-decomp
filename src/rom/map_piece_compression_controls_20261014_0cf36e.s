.setcpu "65816"
.segment "CODE"
.org $F36E
map_control_0cf36e:
    .byte $E8 ; backreference distance high bits
    .byte $1B ; distance low bit/count
    .byte $E5 ; previous-row copy count

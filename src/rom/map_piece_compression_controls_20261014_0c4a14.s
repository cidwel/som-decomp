.setcpu "65816"
.segment "CODE"
.org $4A14
map_control_0c4a14:
    .byte $E8 ; backreference distance high bits
    .byte $1B ; distance low bit/count
    .byte $E1 ; previous-row copy count

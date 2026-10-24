.setcpu "65816"
.segment "CODE"
.org $4201
map_control_0d4201:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E3 ; previous-row copy count

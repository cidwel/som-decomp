.setcpu "65816"
.segment "CODE"
.org $1118
map_control_0c1118:
    .byte $EC ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E3 ; previous-row copy count

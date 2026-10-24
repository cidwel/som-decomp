.setcpu "65816"
.segment "CODE"
.org $C202
map_control_0dc202:
    .byte $E3 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $1A ; distance low bit/count

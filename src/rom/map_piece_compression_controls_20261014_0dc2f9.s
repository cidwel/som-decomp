.setcpu "65816"
.segment "CODE"
.org $C2F9
map_control_0dc2f9:
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count

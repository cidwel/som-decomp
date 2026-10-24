.setcpu "65816"
.segment "CODE"
.org $8936
map_control_0e8936:
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count

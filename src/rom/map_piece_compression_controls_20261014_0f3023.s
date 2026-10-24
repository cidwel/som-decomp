.setcpu "65816"
.segment "CODE"
.org $3023
map_control_0f3023:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $1B ; distance low bit/count

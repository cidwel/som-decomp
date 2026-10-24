.setcpu "65816"
.segment "CODE"
.org $66A7
map_control_0e66a7:
    .byte $EA ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count

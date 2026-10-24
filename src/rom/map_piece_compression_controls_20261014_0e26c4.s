.setcpu "65816"
.segment "CODE"
.org $26C4
map_control_0e26c4:
    .byte $DA ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count

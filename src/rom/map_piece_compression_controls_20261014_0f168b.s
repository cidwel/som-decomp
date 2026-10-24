.setcpu "65816"
.segment "CODE"
.org $168B
map_control_0f168b:
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count

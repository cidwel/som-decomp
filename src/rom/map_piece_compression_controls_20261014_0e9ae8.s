.setcpu "65816"
.segment "CODE"
.org $9AE8
map_control_0e9ae8:
    .byte $E0 ; previous-row copy escape
    .byte $B4 ; row-distance/count
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count

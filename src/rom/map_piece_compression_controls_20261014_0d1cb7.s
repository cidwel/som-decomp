.setcpu "65816"
.segment "CODE"
.org $1CB7
map_control_0d1cb7:
    .byte $D6 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count

.setcpu "65816"
.segment "CODE"
.org $2AFB
map_control_0e2afb:
    .byte $EA ; backreference distance high bits
    .byte $07 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
    .byte $C3 ; same-value copy count/distance

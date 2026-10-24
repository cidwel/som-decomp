.setcpu "65816"
.segment "CODE"
.org $0302
map_control_0f0302:
    .byte $EA ; backreference distance high bits
    .byte $07 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count

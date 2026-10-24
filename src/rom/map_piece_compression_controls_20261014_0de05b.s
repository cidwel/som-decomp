.setcpu "65816"
.segment "CODE"
.org $E05B
map_control_0de05b:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $C3 ; same-value copy count/distance

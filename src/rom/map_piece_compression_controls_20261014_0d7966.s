.setcpu "65816"
.segment "CODE"
.org $7966
map_control_0d7966:
    .byte $D1 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count

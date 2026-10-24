.setcpu "65816"
.segment "CODE"
.org $D545
map_control_0ed545:
    .byte $D1 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count

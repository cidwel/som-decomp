.setcpu "65816"
.segment "CODE"
.org $6219
map_control_0f6219:
    .byte $D7 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count

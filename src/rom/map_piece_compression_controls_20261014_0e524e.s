.setcpu "65816"
.segment "CODE"
.org $524E
map_control_0e524e:
    .byte $D1 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count

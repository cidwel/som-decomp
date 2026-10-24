.setcpu "65816"
.segment "CODE"
.org $3196
map_control_0d3196:
    .byte $DF ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $30 ; row-distance/count

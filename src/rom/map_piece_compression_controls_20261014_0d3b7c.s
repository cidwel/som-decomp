.setcpu "65816"
.segment "CODE"
.org $3B7C
map_control_0d3b7c:
    .byte $C4 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $1B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count

.setcpu "65816"
.segment "CODE"
.org $5D2A
map_control_0d5d2a:
    .byte $C1 ; same-value copy count/distance
    .byte $DA ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $9A ; row-distance/count
    .byte $C2 ; same-value copy count/distance

.setcpu "65816"
.segment "CODE"
.org $B542
map_control_0db542:
    .byte $CD ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $2E ; row-distance/count

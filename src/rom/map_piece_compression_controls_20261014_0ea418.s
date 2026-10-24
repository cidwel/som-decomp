.setcpu "65816"
.segment "CODE"
.org $A418
map_control_0ea418:
    .byte $C2 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count

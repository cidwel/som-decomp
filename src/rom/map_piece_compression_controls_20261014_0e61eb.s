.setcpu "65816"
.segment "CODE"
.org $61EB
map_control_0e61eb:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
    .byte $C5 ; same-value copy count/distance

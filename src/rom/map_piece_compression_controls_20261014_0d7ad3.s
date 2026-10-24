.setcpu "65816"
.segment "CODE"
.org $7AD3
map_control_0d7ad3:
    .byte $E0 ; previous-row copy escape
    .byte $26 ; row-distance/count
    .byte $C3 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $3F ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $63EE
map_control_0f63ee:
    .byte $E3 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count

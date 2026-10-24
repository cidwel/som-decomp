.setcpu "65816"
.segment "CODE"
.org $AF10
map_control_0eaf10:
    .byte $EC ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $96 ; row-distance/count
    .byte $C6 ; same-value copy count/distance
    .byte $E4 ; previous-row copy count
    .byte $C6 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $3A ; row-distance/count

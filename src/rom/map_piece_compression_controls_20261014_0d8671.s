.setcpu "65816"
.segment "CODE"
.org $8671
map_control_0d8671:
    .byte $E1 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
    .byte $C4 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count

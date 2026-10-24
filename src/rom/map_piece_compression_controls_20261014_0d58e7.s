.setcpu "65816"
.segment "CODE"
.org $58E7
map_control_0d58e7:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $8D ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count

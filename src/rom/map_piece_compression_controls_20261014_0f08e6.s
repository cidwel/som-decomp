.setcpu "65816"
.segment "CODE"
.org $08E6
map_control_0f08e6:
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
    .byte $C4 ; same-value copy count/distance

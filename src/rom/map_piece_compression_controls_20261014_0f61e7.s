.setcpu "65816"
.segment "CODE"
.org $61E7
map_control_0f61e7:
    .byte $E0 ; previous-row copy escape
    .byte $99 ; row-distance/count
    .byte $E7 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $47 ; row-distance/count

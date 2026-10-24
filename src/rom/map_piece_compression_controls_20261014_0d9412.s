.setcpu "65816"
.segment "CODE"
.org $9412
map_control_0d9412:
    .byte $E0 ; previous-row copy escape
    .byte $89 ; row-distance/count
    .byte $C4 ; same-value copy count/distance

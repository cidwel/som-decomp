.setcpu "65816"
.segment "CODE"
.org $66D9
map_control_0e66d9:
    .byte $CD ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $26 ; row-distance/count
    .byte $C7 ; same-value copy count/distance

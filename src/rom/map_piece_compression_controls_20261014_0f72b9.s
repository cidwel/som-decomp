.setcpu "65816"
.segment "CODE"
.org $72B9
map_control_0f72b9:
    .byte $E0 ; previous-row copy escape
    .byte $8A ; row-distance/count
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
    .byte $DC ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $88 ; row-distance/count

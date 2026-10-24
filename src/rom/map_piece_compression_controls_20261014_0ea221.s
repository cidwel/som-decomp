.setcpu "65816"
.segment "CODE"
.org $A221
map_control_0ea221:
    .byte $E2 ; previous-row copy count
    .byte $DC ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count

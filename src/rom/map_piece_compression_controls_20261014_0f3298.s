.setcpu "65816"
.segment "CODE"
.org $3298
map_control_0f3298:
    .byte $C7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count

.setcpu "65816"
.segment "CODE"
.org $C227
map_control_0ec227:
    .byte $E0 ; previous-row copy escape
    .byte $2E ; row-distance/count
    .byte $C6 ; same-value copy count/distance

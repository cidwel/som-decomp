.setcpu "65816"
.segment "CODE"
.org $216C
map_control_0f216c:
    .byte $DB ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count

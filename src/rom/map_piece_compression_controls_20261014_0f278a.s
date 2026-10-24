.setcpu "65816"
.segment "CODE"
.org $278A
map_control_0f278a:
    .byte $E1 ; previous-row copy count
    .byte $D4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $8B ; row-distance/count

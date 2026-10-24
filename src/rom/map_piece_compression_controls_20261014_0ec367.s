.setcpu "65816"
.segment "CODE"
.org $C367
map_control_0ec367:
    .byte $E0 ; previous-row copy escape
    .byte $2B ; row-distance/count
    .byte $C2 ; same-value copy count/distance

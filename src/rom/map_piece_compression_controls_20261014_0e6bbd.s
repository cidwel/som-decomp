.setcpu "65816"
.segment "CODE"
.org $6BBD
map_control_0e6bbd:
    .byte $C7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count

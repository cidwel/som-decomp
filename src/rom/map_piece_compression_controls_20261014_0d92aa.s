.setcpu "65816"
.segment "CODE"
.org $92AA
map_control_0d92aa:
    .byte $DD ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $3B ; row-distance/count

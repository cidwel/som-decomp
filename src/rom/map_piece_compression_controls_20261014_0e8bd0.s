.setcpu "65816"
.segment "CODE"
.org $8BD0
map_control_0e8bd0:
    .byte $C1 ; same-value copy count/distance
    .byte $DC ; same-value copy count/distance
    .byte $E3 ; previous-row copy count

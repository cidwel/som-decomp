.setcpu "65816"
.segment "CODE"
.org $FAD5
map_control_0cfad5:
    .byte $E1 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance

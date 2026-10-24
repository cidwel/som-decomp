.setcpu "65816"
.segment "CODE"
.org $766C
map_control_0e766c:
    .byte $E6 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance

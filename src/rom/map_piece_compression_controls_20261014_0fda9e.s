.setcpu "65816"
.segment "CODE"
.org $DA9E
map_control_0fda9e:
    .byte $D2 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count

.setcpu "65816"
.segment "CODE"
.org $6BA0
map_control_0d6ba0:
    .byte $C1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $D2 ; same-value copy count/distance

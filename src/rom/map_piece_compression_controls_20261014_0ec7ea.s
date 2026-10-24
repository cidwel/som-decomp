.setcpu "65816"
.segment "CODE"
.org $C7EA
map_control_0ec7ea:
    .byte $C1 ; same-value copy count/distance
    .byte $E5 ; previous-row copy count

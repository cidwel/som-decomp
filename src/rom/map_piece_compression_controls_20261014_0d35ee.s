.setcpu "65816"
.segment "CODE"
.org $35EE
map_control_0d35ee:
    .byte $C7 ; same-value copy count/distance
    .byte $E4 ; previous-row copy count

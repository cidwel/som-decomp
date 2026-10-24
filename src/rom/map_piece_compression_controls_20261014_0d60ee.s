.setcpu "65816"
.segment "CODE"
.org $60EE
map_control_0d60ee:
    .byte $E1 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance

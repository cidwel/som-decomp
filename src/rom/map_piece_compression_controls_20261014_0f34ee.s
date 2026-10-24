.setcpu "65816"
.segment "CODE"
.org $34EE
map_control_0f34ee:
    .byte $C3 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count

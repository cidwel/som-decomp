.setcpu "65816"
.segment "CODE"
.org $9050
map_control_0f9050:
    .byte $D1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count

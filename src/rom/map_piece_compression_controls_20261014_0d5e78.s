.setcpu "65816"
.segment "CODE"
.org $5E78
map_control_0d5e78:
    .byte $D1 ; same-value copy count/distance
    .byte $E6 ; previous-row copy count

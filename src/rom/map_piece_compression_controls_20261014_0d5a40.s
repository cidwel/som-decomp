.setcpu "65816"
.segment "CODE"
.org $5A40
map_control_0d5a40:
    .byte $D7 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count

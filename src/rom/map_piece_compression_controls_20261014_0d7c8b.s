.setcpu "65816"
.segment "CODE"
.org $7C8B
map_control_0d7c8b:
    .byte $D4 ; same-value copy count/distance
    .byte $E6 ; previous-row copy count

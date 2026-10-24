.setcpu "65816"
.segment "CODE"
.org $8B14
map_control_0d8b14:
    .byte $E5 ; previous-row copy count
    .byte $D1 ; same-value copy count/distance

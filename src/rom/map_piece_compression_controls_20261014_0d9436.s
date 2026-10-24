.setcpu "65816"
.segment "CODE"
.org $9436
map_control_0d9436:
    .byte $E3 ; previous-row copy count
    .byte $D1 ; same-value copy count/distance

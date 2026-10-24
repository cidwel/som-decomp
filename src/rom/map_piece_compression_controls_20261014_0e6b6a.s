.setcpu "65816"
.segment "CODE"
.org $6B6A
map_control_0e6b6a:
    .byte $D4 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count

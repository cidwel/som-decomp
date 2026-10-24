.setcpu "65816"
.segment "CODE"
.org $6767
map_control_0d6767:
    .byte $E1 ; previous-row copy count
    .byte $D4 ; same-value copy count/distance

.setcpu "65816"
.segment "CODE"
.org $CB89
map_control_0fcb89:
    .byte $D9 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count

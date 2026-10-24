.setcpu "65816"
.segment "CODE"
.org $B6EC
map_control_0db6ec:
    .byte $C6 ; same-value copy count/distance
    .byte $E6 ; previous-row copy count

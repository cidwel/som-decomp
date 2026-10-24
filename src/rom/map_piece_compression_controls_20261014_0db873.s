.setcpu "65816"
.segment "CODE"
.org $B873
map_control_0db873:
    .byte $E4 ; previous-row copy count
    .byte $C7 ; same-value copy count/distance

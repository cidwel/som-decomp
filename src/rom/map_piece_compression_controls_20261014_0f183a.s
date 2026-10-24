.setcpu "65816"
.segment "CODE"
.org $183A
map_control_0f183a:
    .byte $E3 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance

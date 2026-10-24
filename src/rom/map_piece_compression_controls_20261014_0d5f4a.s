.setcpu "65816"
.segment "CODE"
.org $5F4A
map_control_0d5f4a:
    .byte $C2 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count

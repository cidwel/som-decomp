.setcpu "65816"
.segment "CODE"
.org $5C5A
map_control_0c5c5a:
    .byte $C2 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count

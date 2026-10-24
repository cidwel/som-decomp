.setcpu "65816"
.segment "CODE"
.org $025A
map_control_0f025a:
    .byte $C2 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count

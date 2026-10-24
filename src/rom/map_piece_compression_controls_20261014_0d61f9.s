.setcpu "65816"
.segment "CODE"
.org $61F9
map_control_0d61f9:
    .byte $E1 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance

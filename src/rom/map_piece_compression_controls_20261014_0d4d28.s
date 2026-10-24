.setcpu "65816"
.segment "CODE"
.org $4D28
map_control_0d4d28:
    .byte $E7 ; previous-row copy count
    .byte $C6 ; same-value copy count/distance

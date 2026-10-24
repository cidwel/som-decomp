.setcpu "65816"
.segment "CODE"
.org $A9DF
map_control_0ea9df:
    .byte $E3 ; previous-row copy count
    .byte $D1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count

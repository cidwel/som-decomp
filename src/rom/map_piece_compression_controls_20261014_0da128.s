.setcpu "65816"
.segment "CODE"
.org $A128
map_control_0da128:
    .byte $E4 ; previous-row copy count
    .byte $D9 ; same-value copy count/distance

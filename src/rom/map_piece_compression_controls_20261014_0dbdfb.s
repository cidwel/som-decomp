.setcpu "65816"
.segment "CODE"
.org $BDFB
map_control_0dbdfb:
    .byte $C2 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count

.setcpu "65816"
.segment "CODE"
.org $1825
map_control_0f1825:
    .byte $E4 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance

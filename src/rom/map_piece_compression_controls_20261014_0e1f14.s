.setcpu "65816"
.segment "CODE"
.org $1F14
map_control_0e1f14:
    .byte $E1 ; previous-row copy count
    .byte $C5 ; same-value copy count/distance

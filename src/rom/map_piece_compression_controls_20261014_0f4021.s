.setcpu "65816"
.segment "CODE"
.org $4021
map_control_0f4021:
    .byte $E0 ; previous-row copy escape
    .byte $40 ; row-distance/count
    .byte $C6 ; same-value copy count/distance

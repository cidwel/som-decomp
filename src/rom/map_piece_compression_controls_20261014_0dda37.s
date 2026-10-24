.setcpu "65816"
.segment "CODE"
.org $DA37
map_control_0dda37:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count

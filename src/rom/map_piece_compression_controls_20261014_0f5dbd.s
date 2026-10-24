.setcpu "65816"
.segment "CODE"
.org $5DBD
map_control_0f5dbd:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $A2 ; row-distance/count

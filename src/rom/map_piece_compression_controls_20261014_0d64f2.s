.setcpu "65816"
.segment "CODE"
.org $64F2
map_control_0d64f2:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
    .byte $C2 ; same-value copy count/distance

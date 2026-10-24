.setcpu "65816"
.segment "CODE"
.org $25B1
map_control_0d25b1:
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count

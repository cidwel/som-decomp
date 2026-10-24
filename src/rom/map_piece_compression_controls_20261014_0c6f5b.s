.setcpu "65816"
.segment "CODE"
.org $6F5B
map_control_0c6f5b:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $C9 ; same-value copy count/distance

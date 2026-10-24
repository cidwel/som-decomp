.setcpu "65816"
.segment "CODE"
.org $7441
map_control_0c7441:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
    .byte $C2 ; same-value copy count/distance

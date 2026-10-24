.setcpu "65816"
.segment "CODE"
.org $AE1C
map_control_0dae1c:
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
    .byte $C2 ; same-value copy count/distance

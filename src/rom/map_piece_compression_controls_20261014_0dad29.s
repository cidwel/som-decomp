.setcpu "65816"
.segment "CODE"
.org $AD29
map_control_0dad29:
    .byte $E0 ; previous-row copy escape
    .byte $DD ; row-distance/count
    .byte $C1 ; same-value copy count/distance

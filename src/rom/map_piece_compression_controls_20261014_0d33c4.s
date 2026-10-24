.setcpu "65816"
.segment "CODE"
.org $33C4
map_control_0d33c4:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $C3 ; same-value copy count/distance

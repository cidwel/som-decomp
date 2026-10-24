.setcpu "65816"
.segment "CODE"
.org $11E3
map_control_0c11e3:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $D2 ; same-value copy count/distance

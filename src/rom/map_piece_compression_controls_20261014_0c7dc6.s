.setcpu "65816"
.segment "CODE"
.org $7DC6
map_control_0c7dc6:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $99 ; row-distance/count

.setcpu "65816"
.segment "CODE"
.org $6AC2
map_control_0f6ac2:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
    .byte $C6 ; same-value copy count/distance

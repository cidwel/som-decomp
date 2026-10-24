.setcpu "65816"
.segment "CODE"
.org $7FBB
map_control_0d7fbb:
    .byte $E1 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count

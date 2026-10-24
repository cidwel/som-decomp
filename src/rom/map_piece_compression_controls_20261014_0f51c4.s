.setcpu "65816"
.segment "CODE"
.org $51C4
map_control_0f51c4:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count

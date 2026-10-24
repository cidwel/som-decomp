.setcpu "65816"
.segment "CODE"
.org $661C
map_control_0c661c:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $C1 ; same-value copy count/distance

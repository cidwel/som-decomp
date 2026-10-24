.setcpu "65816"
.segment "CODE"
.org $2748
map_control_0c2748:
    .byte $DF ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count

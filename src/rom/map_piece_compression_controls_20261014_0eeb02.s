.setcpu "65816"
.segment "CODE"
.org $EB02
map_control_0eeb02:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
    .byte $C1 ; same-value copy count/distance

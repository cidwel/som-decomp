.setcpu "65816"
.segment "CODE"
.org $B276
map_control_0db276:
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count

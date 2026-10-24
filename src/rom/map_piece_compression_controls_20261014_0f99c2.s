.setcpu "65816"
.segment "CODE"
.org $99C2
map_control_0f99c2:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
    .byte $CB ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $54 ; row-distance/count

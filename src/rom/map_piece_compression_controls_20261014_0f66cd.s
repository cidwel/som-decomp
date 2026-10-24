.setcpu "65816"
.segment "CODE"
.org $66CD
map_control_0f66cd:
    .byte $E2 ; previous-row copy count
    .byte $CB ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count

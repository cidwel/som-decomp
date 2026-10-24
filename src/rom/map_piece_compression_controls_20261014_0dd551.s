.setcpu "65816"
.segment "CODE"
.org $D551
map_control_0dd551:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $2E ; row-distance/count

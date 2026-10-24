.setcpu "65816"
.segment "CODE"
.org $2608
map_control_0f2608:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
    .byte $C6 ; same-value copy count/distance

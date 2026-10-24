.setcpu "65816"
.segment "CODE"
.org $9067
map_control_0f9067:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count

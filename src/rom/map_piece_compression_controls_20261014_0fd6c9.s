.setcpu "65816"
.segment "CODE"
.org $D6C9
map_control_0fd6c9:
    .byte $D1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $99 ; row-distance/count
    .byte $E2 ; previous-row copy count

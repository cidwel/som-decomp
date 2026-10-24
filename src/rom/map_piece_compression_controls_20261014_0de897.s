.setcpu "65816"
.segment "CODE"
.org $E897
map_control_0de897:
    .byte $C5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count

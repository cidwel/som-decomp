.setcpu "65816"
.segment "CODE"
.org $47C6
map_control_0f47c6:
    .byte $E0 ; previous-row copy escape
    .byte $4F ; row-distance/count
    .byte $C4 ; same-value copy count/distance

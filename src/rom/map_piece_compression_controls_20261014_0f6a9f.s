.setcpu "65816"
.segment "CODE"
.org $6A9F
map_control_0f6a9f:
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
    .byte $C9 ; same-value copy count/distance

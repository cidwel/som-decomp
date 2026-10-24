.setcpu "65816"
.segment "CODE"
.org $069B
map_control_0f069b:
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
    .byte $CC ; same-value copy count/distance

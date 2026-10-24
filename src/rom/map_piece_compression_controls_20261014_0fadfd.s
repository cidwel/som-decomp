.setcpu "65816"
.segment "CODE"
.org $ADFD
map_control_0fadfd:
    .byte $CB ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $2F ; row-distance/count

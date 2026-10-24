.setcpu "65816"
.segment "CODE"
.org $EFEE
map_control_0eefee:
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count

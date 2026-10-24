.setcpu "65816"
.segment "CODE"
.org $4CCD
map_control_0f4ccd:
    .byte $E0 ; previous-row copy escape
    .byte $60 ; row-distance/count
    .byte $C7 ; same-value copy count/distance

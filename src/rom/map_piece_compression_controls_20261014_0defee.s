.setcpu "65816"
.segment "CODE"
.org $EFEE
map_control_0defee:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count

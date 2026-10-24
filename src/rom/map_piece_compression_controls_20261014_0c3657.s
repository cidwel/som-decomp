.setcpu "65816"
.segment "CODE"
.org $3657
map_control_0c3657:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count

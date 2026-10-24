.setcpu "65816"
.segment "CODE"
.org $9894
map_control_0f9894:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count

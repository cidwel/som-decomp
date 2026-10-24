.setcpu "65816"
.segment "CODE"
.org $AED6
map_control_0eaed6:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count

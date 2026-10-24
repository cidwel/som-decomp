.setcpu "65816"
.segment "CODE"
.org $AE83
map_control_0fae83:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count

.setcpu "65816"
.segment "CODE"
.org $ACD4
map_control_0eacd4:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count

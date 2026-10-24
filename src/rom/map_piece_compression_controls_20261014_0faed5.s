.setcpu "65816"
.segment "CODE"
.org $AED5
map_control_0faed5:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count

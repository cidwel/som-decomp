.setcpu "65816"
.segment "CODE"
.org $8748
map_control_0c8748:
    .byte $E0 ; previous-row copy escape
    .byte $89 ; row-distance/count

.setcpu "65816"
.segment "CODE"
.org $9E67
map_control_0f9e67:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count

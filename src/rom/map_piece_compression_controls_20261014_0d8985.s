.setcpu "65816"
.segment "CODE"
.org $8985
map_control_0d8985:
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count

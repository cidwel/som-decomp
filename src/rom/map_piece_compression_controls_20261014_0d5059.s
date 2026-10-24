.setcpu "65816"
.segment "CODE"
.org $5059
map_control_0d5059:
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count

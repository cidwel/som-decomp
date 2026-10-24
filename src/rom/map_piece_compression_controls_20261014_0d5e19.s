.setcpu "65816"
.segment "CODE"
.org $5E19
map_control_0d5e19:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count

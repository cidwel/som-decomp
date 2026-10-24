.setcpu "65816"
.segment "CODE"
.org $5A48
map_control_0d5a48:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count

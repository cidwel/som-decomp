.setcpu "65816"
.segment "CODE"
.org $6065
map_control_0f6065:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count

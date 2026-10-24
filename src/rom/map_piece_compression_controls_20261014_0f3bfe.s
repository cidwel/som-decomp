.setcpu "65816"
.segment "CODE"
.org $3BFE
map_control_0f3bfe:
    .byte $E0 ; previous-row copy escape
    .byte $60 ; row-distance/count

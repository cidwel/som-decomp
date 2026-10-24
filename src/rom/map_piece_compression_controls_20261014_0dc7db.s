.setcpu "65816"
.segment "CODE"
.org $C7DB
map_control_0dc7db:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count

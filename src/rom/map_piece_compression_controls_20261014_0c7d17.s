.setcpu "65816"
.segment "CODE"
.org $7D17
map_control_0c7d17:
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count

.setcpu "65816"
.segment "CODE"
.org $4160
map_control_0c4160:
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count

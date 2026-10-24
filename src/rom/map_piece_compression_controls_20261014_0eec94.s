.setcpu "65816"
.segment "CODE"
.org $EC94
map_control_0eec94:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count

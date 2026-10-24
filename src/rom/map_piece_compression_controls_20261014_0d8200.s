.setcpu "65816"
.segment "CODE"
.org $8200
map_control_0d8200:
    .byte $E0 ; previous-row copy escape
    .byte $4D ; row-distance/count

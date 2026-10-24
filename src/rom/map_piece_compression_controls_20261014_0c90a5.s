.setcpu "65816"
.segment "CODE"
.org $90A5
map_control_0c90a5:
    .byte $E0 ; previous-row copy escape
    .byte $8D ; row-distance/count

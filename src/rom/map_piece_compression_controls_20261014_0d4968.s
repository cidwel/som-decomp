.setcpu "65816"
.segment "CODE"
.org $4968
map_control_0d4968:
    .byte $E0 ; previous-row copy escape
    .byte $5D ; row-distance/count

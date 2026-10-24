.setcpu "65816"
.segment "CODE"
.org $7F78
map_control_0f7f78:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count

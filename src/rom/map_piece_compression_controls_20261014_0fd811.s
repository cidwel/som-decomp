.setcpu "65816"
.segment "CODE"
.org $D811
map_control_0fd811:
    .byte $E0 ; previous-row copy escape
    .byte $8A ; row-distance/count

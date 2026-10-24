.setcpu "65816"
.segment "CODE"
.org $634D
map_control_0f634d:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count

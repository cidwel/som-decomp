.setcpu "65816"
.segment "CODE"
.org $41BB
map_control_0f41bb:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count

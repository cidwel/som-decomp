.setcpu "65816"
.segment "CODE"
.org $64BB
map_control_0f64bb:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count

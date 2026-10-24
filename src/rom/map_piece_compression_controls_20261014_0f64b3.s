.setcpu "65816"
.segment "CODE"
.org $64B3
map_control_0f64b3:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count

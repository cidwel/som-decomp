.setcpu "65816"
.segment "CODE"
.org $64FC
map_control_0f64fc:
    .byte $E0 ; previous-row copy escape
    .byte $26 ; row-distance/count

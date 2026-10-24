.setcpu "65816"
.segment "CODE"
.org $58CC
map_control_0d58cc:
    .byte $E0 ; previous-row copy escape
    .byte $8D ; row-distance/count

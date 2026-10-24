.setcpu "65816"
.segment "CODE"
.org $BD9D
map_control_0fbd9d:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count

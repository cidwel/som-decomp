.setcpu "65816"
.segment "CODE"
.org $626A
map_control_0c626a:
    .byte $E0 ; previous-row copy escape
    .byte $36 ; row-distance/count

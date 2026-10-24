.setcpu "65816"
.segment "CODE"
.org $57BF
map_control_0f57bf:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count

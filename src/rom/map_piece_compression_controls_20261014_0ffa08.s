.setcpu "65816"
.segment "CODE"
.org $FA08
map_control_0ffa08:
    .byte $E0 ; previous-row copy escape
    .byte $48 ; row-distance/count

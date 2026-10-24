.setcpu "65816"
.segment "CODE"
.org $DD10
map_control_0ddd10:
    .byte $E0 ; previous-row copy escape
    .byte $72 ; row-distance/count

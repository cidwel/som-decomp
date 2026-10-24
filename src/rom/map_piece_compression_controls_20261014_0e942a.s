.setcpu "65816"
.segment "CODE"
.org $942A
map_control_0e942a:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count

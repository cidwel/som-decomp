.setcpu "65816"
.segment "CODE"
.org $381A
map_control_0e381a:
    .byte $E0 ; previous-row copy escape
    .byte $78 ; row-distance/count

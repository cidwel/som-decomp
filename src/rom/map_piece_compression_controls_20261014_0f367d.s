.setcpu "65816"
.segment "CODE"
.org $367D
map_control_0f367d:
    .byte $E0 ; previous-row copy escape
    .byte $9D ; row-distance/count

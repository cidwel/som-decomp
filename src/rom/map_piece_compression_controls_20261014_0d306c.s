.setcpu "65816"
.segment "CODE"
.org $306C
map_control_0d306c:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count

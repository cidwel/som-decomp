.setcpu "65816"
.segment "CODE"
.org $FD3C
map_control_0efd3c:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count

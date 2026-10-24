.setcpu "65816"
.segment "CODE"
.org $832C
map_control_0d832c:
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count

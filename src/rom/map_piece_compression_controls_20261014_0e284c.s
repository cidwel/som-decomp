.setcpu "65816"
.segment "CODE"
.org $284C
map_control_0e284c:
    .byte $E0 ; previous-row copy escape
    .byte $2C ; row-distance/count

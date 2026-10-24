.setcpu "65816"
.segment "CODE"
.org $FADD
map_control_0efadd:
    .byte $E0 ; previous-row copy escape
    .byte $98 ; row-distance/count

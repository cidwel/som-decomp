.setcpu "65816"
.segment "CODE"
.org $CEFD
map_control_0fcefd:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count

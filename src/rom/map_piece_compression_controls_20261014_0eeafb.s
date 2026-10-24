.setcpu "65816"
.segment "CODE"
.org $EAFB
map_control_0eeafb:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count

.setcpu "65816"
.segment "CODE"
.org $DECE
map_control_0edece:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count

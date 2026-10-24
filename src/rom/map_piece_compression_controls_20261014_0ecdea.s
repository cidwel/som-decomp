.setcpu "65816"
.segment "CODE"
.org $CDEA
map_control_0ecdea:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count

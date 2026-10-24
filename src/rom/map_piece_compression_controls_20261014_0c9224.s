.setcpu "65816"
.segment "CODE"
.org $9224
map_control_0c9224:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count

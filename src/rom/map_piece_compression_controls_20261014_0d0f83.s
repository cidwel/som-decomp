.setcpu "65816"
.segment "CODE"
.org $0F83
map_control_0d0f83:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count

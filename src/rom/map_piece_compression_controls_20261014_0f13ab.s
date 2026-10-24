.setcpu "65816"
.segment "CODE"
.org $13AB
map_control_0f13ab:
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count

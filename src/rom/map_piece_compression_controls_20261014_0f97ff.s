.setcpu "65816"
.segment "CODE"
.org $97FF
map_control_0f97ff:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count

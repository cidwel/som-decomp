.setcpu "65816"
.segment "CODE"
.org $7670
map_control_0d7670:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count

.setcpu "65816"
.segment "CODE"
.org $2771
map_control_0c2771:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count

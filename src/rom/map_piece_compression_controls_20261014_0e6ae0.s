.setcpu "65816"
.segment "CODE"
.org $6AE0
map_control_0e6ae0:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count

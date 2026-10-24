.setcpu "65816"
.segment "CODE"
.org $7919
map_control_0f7919:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count

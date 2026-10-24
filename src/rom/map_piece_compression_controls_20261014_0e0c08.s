.setcpu "65816"
.segment "CODE"
.org $0C08
map_control_0e0c08:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count

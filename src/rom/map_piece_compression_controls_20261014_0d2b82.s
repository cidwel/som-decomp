.setcpu "65816"
.segment "CODE"
.org $2B82
map_control_0d2b82:
    .byte $E0 ; previous-row copy escape
    .byte $97 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count

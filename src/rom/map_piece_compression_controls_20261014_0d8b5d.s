.setcpu "65816"
.segment "CODE"
.org $8B5D
map_control_0d8b5d:
    .byte $E0 ; previous-row copy escape
    .byte $97 ; row-distance/count

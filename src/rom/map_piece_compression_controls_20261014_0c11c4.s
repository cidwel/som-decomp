.setcpu "65816"
.segment "CODE"
.org $11C4
map_control_0c11c4:
    .byte $E0 ; previous-row copy escape
    .byte $97 ; row-distance/count

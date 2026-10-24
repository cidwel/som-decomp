.setcpu "65816"
.segment "CODE"
.org $80B2
map_control_0d80b2:
    .byte $E0 ; previous-row copy escape
    .byte $97 ; row-distance/count

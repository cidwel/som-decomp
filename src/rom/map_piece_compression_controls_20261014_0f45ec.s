.setcpu "65816"
.segment "CODE"
.org $45EC
map_control_0f45ec:
    .byte $E0 ; previous-row copy escape
    .byte $97 ; row-distance/count

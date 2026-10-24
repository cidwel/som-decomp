.setcpu "65816"
.segment "CODE"
.org $CD5A
map_control_0ecd5a:
    .byte $E0 ; previous-row copy escape
    .byte $97 ; row-distance/count

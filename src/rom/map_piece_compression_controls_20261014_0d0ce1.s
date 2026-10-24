.setcpu "65816"
.segment "CODE"
.org $0CE1
map_control_0d0ce1:
    .byte $E0 ; previous-row copy escape
    .byte $97 ; row-distance/count

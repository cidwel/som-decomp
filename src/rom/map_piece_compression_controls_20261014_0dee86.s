.setcpu "65816"
.segment "CODE"
.org $EE86
map_control_0dee86:
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count

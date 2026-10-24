.setcpu "65816"
.segment "CODE"
.org $B095
map_control_0db095:
    .byte $E0 ; previous-row copy escape
    .byte $97 ; row-distance/count

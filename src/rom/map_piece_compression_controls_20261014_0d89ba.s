.setcpu "65816"
.segment "CODE"
.org $89BA
map_control_0d89ba:
    .byte $E0 ; previous-row copy escape
    .byte $35 ; row-distance/count

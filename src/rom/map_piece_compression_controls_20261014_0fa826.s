.setcpu "65816"
.segment "CODE"
.org $A826
map_control_0fa826:
    .byte $E0 ; previous-row copy escape
    .byte $8F ; row-distance/count

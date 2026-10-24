.setcpu "65816"
.segment "CODE"
.org $A5B9
map_control_0fa5b9:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count

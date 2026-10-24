.setcpu "65816"
.segment "CODE"
.org $A177
map_control_0fa177:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count

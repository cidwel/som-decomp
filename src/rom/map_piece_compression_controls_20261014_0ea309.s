.setcpu "65816"
.segment "CODE"
.org $A309
map_control_0ea309:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count

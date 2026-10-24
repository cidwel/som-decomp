.setcpu "65816"
.segment "CODE"
.org $A769
map_control_0fa769:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count

.setcpu "65816"
.segment "CODE"
.org $A72E
map_control_0fa72e:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count

.setcpu "65816"
.segment "CODE"
.org $A186
map_control_0fa186:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count

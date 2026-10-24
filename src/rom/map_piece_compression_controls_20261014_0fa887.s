.setcpu "65816"
.segment "CODE"
.org $A887
map_control_0fa887:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count

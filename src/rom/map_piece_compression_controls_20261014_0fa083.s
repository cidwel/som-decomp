.setcpu "65816"
.segment "CODE"
.org $A083
map_control_0fa083:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count

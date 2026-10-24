.setcpu "65816"
.segment "CODE"
.org $A090
map_control_0fa090:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count

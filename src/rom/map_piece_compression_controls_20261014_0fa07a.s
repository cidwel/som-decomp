.setcpu "65816"
.segment "CODE"
.org $A07A
map_control_0fa07a:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count

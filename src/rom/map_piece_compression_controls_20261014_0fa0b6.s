.setcpu "65816"
.segment "CODE"
.org $A0B6
map_control_0fa0b6:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count

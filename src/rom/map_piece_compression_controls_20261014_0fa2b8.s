.setcpu "65816"
.segment "CODE"
.org $A2B8
map_control_0fa2b8:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count

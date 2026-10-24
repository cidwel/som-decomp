.setcpu "65816"
.segment "CODE"
.org $A286
map_control_0fa286:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count

.setcpu "65816"
.segment "CODE"
.org $A746
map_control_0fa746:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count

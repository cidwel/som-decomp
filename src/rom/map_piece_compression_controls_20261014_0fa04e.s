.setcpu "65816"
.segment "CODE"
.org $A04E
map_control_0fa04e:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count

.setcpu "65816"
.segment "CODE"
.org $35EF
map_control_0c35ef:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count

.setcpu "65816"
.segment "CODE"
.org $A256
map_control_0ea256:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count

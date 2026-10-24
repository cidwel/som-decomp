.setcpu "65816"
.segment "CODE"
.org $35B1
map_control_0f35b1:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count

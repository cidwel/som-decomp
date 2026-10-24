.setcpu "65816"
.segment "CODE"
.org $89EC
map_control_0d89ec:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count

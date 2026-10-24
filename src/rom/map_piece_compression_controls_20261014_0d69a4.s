.setcpu "65816"
.segment "CODE"
.org $69A4
map_control_0d69a4:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count

.setcpu "65816"
.segment "CODE"
.org $3C86
map_control_0f3c86:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count

.setcpu "65816"
.segment "CODE"
.org $19CE
map_control_0f19ce:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count

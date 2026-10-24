.setcpu "65816"
.segment "CODE"
.org $68EC
map_control_0e68ec:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count

.setcpu "65816"
.segment "CODE"
.org $73AB
map_control_0c73ab:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count

.setcpu "65816"
.segment "CODE"
.org $5D07
map_control_0e5d07:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count

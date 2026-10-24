.setcpu "65816"
.segment "CODE"
.org $FAB8
map_control_0dfab8:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count

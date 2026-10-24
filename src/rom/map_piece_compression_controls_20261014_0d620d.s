.setcpu "65816"
.segment "CODE"
.org $620D
map_control_0d620d:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count

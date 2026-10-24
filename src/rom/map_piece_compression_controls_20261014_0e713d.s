.setcpu "65816"
.segment "CODE"
.org $713D
map_control_0e713d:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count

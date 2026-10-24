.setcpu "65816"
.segment "CODE"
.org $743D
map_control_0c743d:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count

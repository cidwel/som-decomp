.setcpu "65816"
.segment "CODE"
.org $6AF6
map_control_0e6af6:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count

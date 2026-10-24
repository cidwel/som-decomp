.setcpu "65816"
.segment "CODE"
.org $BA14
map_control_0dba14:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count

.setcpu "65816"
.segment "CODE"
.org $72E4
map_control_0c72e4:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count

.setcpu "65816"
.segment "CODE"
.org $D383
map_control_0ed383:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count

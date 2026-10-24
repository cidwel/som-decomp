.setcpu "65816"
.segment "CODE"
.org $EEE6
map_control_0feee6:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count

.setcpu "65816"
.segment "CODE"
.org $EAAF
map_control_0deaaf:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count

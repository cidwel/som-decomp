.setcpu "65816"
.segment "CODE"
.org $EFCE
map_control_0fefce:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count

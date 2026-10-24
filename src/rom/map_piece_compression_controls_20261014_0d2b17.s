.setcpu "65816"
.segment "CODE"
.org $2B17
map_control_0d2b17:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count

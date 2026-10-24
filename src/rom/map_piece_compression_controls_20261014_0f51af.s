.setcpu "65816"
.segment "CODE"
.org $51AF
map_control_0f51af:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count

.setcpu "65816"
.segment "CODE"
.org $6994
map_control_0c6994:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count

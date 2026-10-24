.setcpu "65816"
.segment "CODE"
.org $6A30
map_control_0c6a30:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count

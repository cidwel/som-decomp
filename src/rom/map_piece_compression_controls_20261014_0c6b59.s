.setcpu "65816"
.segment "CODE"
.org $6B59
map_control_0c6b59:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count

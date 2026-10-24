.setcpu "65816"
.segment "CODE"
.org $5A72
map_control_0e5a72:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count

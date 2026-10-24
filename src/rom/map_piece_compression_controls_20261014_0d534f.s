.setcpu "65816"
.segment "CODE"
.org $534F
map_control_0d534f:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count

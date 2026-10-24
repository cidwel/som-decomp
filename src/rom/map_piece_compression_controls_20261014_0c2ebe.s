.setcpu "65816"
.segment "CODE"
.org $2EBE
map_control_0c2ebe:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count

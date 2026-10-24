.setcpu "65816"
.segment "CODE"
.org $C24C
map_control_0ec24c:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count

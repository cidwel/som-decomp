.setcpu "65816"
.segment "CODE"
.org $F4DC
map_control_0ff4dc:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count

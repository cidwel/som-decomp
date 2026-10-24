.setcpu "65816"
.segment "CODE"
.org $5B01
map_control_0e5b01:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count

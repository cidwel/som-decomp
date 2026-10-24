.setcpu "65816"
.segment "CODE"
.org $4719
map_control_0c4719:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count

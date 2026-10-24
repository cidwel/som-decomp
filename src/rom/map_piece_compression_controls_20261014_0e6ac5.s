.setcpu "65816"
.segment "CODE"
.org $6AC5
map_control_0e6ac5:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count

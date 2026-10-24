.setcpu "65816"
.segment "CODE"
.org $4AC1
map_control_0c4ac1:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count

.setcpu "65816"
.segment "CODE"
.org $4AA1
map_control_0c4aa1:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count

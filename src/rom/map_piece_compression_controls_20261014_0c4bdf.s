.setcpu "65816"
.segment "CODE"
.org $4BDF
map_control_0c4bdf:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count

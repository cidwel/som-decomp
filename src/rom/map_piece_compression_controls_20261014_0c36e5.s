.setcpu "65816"
.segment "CODE"
.org $36E5
map_control_0c36e5:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count

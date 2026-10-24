.setcpu "65816"
.segment "CODE"
.org $36C3
map_control_0c36c3:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count

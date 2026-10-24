.setcpu "65816"
.segment "CODE"
.org $36B1
map_control_0f36b1:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count

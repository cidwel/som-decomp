.setcpu "65816"
.segment "CODE"
.org $36E5
map_control_0d36e5:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count

.setcpu "65816"
.segment "CODE"
.org $3E96
map_control_0e3e96:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count

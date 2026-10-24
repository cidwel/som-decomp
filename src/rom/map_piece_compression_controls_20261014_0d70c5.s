.setcpu "65816"
.segment "CODE"
.org $70C5
map_control_0d70c5:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count

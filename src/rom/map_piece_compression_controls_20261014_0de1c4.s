.setcpu "65816"
.segment "CODE"
.org $E1C4
map_control_0de1c4:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count

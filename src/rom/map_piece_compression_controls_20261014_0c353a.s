.setcpu "65816"
.segment "CODE"
.org $353A
map_control_0c353a:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count

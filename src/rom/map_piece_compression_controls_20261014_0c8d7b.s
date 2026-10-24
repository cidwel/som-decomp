.setcpu "65816"
.segment "CODE"
.org $8D7B
map_control_0c8d7b:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count

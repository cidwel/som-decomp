.setcpu "65816"
.segment "CODE"
.org $5B7B
map_control_0c5b7b:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count

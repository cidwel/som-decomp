.setcpu "65816"
.segment "CODE"
.org $6906
map_control_0e6906:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count

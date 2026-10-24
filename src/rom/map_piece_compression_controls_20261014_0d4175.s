.setcpu "65816"
.segment "CODE"
.org $4175
map_control_0d4175:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count

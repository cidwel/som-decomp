.setcpu "65816"
.segment "CODE"
.org $6F46
map_control_0e6f46:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count

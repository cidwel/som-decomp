.setcpu "65816"
.segment "CODE"
.org $0097
map_control_0e0097:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count

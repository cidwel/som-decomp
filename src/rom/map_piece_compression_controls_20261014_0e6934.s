.setcpu "65816"
.segment "CODE"
.org $6934
map_control_0e6934:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count

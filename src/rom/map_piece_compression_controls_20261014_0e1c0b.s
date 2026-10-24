.setcpu "65816"
.segment "CODE"
.org $1C0B
map_control_0e1c0b:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count

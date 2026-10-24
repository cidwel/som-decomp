.setcpu "65816"
.segment "CODE"
.org $9015
map_control_0f9015:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count

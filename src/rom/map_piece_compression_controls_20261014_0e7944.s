.setcpu "65816"
.segment "CODE"
.org $7944
map_control_0e7944:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count

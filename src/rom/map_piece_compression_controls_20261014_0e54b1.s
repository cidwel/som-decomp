.setcpu "65816"
.segment "CODE"
.org $54B1
map_control_0e54b1:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count

.setcpu "65816"
.segment "CODE"
.org $83AE
map_control_0e83ae:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count

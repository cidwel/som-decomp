.setcpu "65816"
.segment "CODE"
.org $538B
map_control_0d538b:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count

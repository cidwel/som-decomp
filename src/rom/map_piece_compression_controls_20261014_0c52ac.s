.setcpu "65816"
.segment "CODE"
.org $52AC
map_control_0c52ac:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count

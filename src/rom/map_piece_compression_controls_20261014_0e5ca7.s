.setcpu "65816"
.segment "CODE"
.org $5CA7
map_control_0e5ca7:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count

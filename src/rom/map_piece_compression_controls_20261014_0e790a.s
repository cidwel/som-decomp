.setcpu "65816"
.segment "CODE"
.org $790A
map_control_0e790a:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count

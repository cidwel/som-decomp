.setcpu "65816"
.segment "CODE"
.org $285A
map_control_0e285a:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count

.setcpu "65816"
.segment "CODE"
.org $0EDE
map_control_0e0ede:
    .byte $E0 ; previous-row copy escape
    .byte $29 ; row-distance/count

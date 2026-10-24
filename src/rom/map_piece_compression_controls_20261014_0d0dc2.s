.setcpu "65816"
.segment "CODE"
.org $0DC2
map_control_0d0dc2:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count

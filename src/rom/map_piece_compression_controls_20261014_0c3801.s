.setcpu "65816"
.segment "CODE"
.org $3801
map_control_0c3801:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count

.setcpu "65816"
.segment "CODE"
.org $42C3
map_control_0e42c3:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count

.setcpu "65816"
.segment "CODE"
.org $193A
map_control_0c193a:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count

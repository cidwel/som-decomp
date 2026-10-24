.setcpu "65816"
.segment "CODE"
.org $51CA
map_control_0d51ca:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count

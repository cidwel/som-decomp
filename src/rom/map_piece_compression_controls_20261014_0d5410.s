.setcpu "65816"
.segment "CODE"
.org $5410
map_control_0d5410:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count

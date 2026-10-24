.setcpu "65816"
.segment "CODE"
.org $BE0D
map_control_0fbe0d:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count

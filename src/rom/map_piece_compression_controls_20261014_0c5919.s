.setcpu "65816"
.segment "CODE"
.org $5919
map_control_0c5919:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count

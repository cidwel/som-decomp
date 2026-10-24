.setcpu "65816"
.segment "CODE"
.org $0D29
map_control_0e0d29:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count

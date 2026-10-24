.setcpu "65816"
.segment "CODE"
.org $7ECD
map_control_0d7ecd:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count

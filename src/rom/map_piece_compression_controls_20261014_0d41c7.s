.setcpu "65816"
.segment "CODE"
.org $41C7
map_control_0d41c7:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count

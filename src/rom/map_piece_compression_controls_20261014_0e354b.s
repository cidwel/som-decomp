.setcpu "65816"
.segment "CODE"
.org $354B
map_control_0e354b:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count

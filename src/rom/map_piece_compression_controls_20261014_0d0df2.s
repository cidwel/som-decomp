.setcpu "65816"
.segment "CODE"
.org $0DF2
map_control_0d0df2:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count

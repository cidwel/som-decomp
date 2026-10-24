.setcpu "65816"
.segment "CODE"
.org $0EB0
map_control_0d0eb0:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count

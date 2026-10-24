.setcpu "65816"
.segment "CODE"
.org $57D6
map_control_0c57d6:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count

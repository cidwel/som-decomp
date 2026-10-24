.setcpu "65816"
.segment "CODE"
.org $50BD
map_control_0c50bd:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count

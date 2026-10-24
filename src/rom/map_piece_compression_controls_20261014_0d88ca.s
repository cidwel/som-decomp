.setcpu "65816"
.segment "CODE"
.org $88CA
map_control_0d88ca:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count

.setcpu "65816"
.segment "CODE"
.org $88CA
map_control_0f88ca:
    .byte $E0 ; previous-row copy escape
    .byte $98 ; row-distance/count
